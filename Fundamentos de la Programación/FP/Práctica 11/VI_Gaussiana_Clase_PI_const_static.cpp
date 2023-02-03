/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 7. N�6.
// VI_Gaussiana_Clase_PI_const_static.cpp: escribe un programa que calcule
// la gaussiana, el CDF de las dos formas posibles pero sin usar funciones
// sino una clase
//
//Entrada: par�metros de la gaussiana, abscisa donde calcular su imagen y hasta
// la cual calcular la CDF
//Salida: resultados obtenidos
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std; 

/************************************************************************/
// Declaraci�n de la clase "Gaussiana", la cual guardar� los par�metros que
// diferencian a cada una de ellas ( Media y desviaci�n t�pica ) y poseer� 
// m�todos para calcular la imagen de una abscisa introducida, el CDF 
// hasta otra que el usuario quiera.
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

class Gaussiana
{
	
	private:
		
		double desviacion;    // Sigma. PRE: sigma > 0
		double media;		 // Mu.
		
	public:
		
		// Declaraci�n de un constructor que asigne a cada par�metro el
		// valor que se introduzca.
		
		Gaussiana( double mu, double sigma)
		
			: media (mu),
			  desviacion (sigma)
			  
		{}
		
		/////////////////////////////////////////////////////////////////
		
		// Funci�n para calcular la gaussiana en un x determinado
		//
		// Entrada: abscisa sobre la que calcular ( x ).
		// Salida: gaussiana en x
		//
		
		double CalcularEnX ( double x ) {
			
			const double PI = 3.1415;
			double g;
			
			g = ( 1 / ( desviacion * sqrt ( 2 * PI ) ) ) *
				exp( -0.5 *( pow ( (x - media ) / desviacion , 2 ) ) );
											
			return g;
			
		}
			
		/////////////////////////////////////////////////////////////////
		
		// Funci�n para obtener la desviacion de la gaussiana
		//
		// Entrada: ----------------
		// Salida: desviaci�n
		//
		
		double GetDesviacion () {
		
			return desviacion;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// Funci�n para obtener la media de la gaussiana
		//
		// Entrada: ----------------
		// Salida: media
		//
		
		double GetMedia () {
			
			return media;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// Funci�n para definir la desviaci�n de una gaussiana
		//
		// Entrada: desviaci�n nueva
		// Salida: ----------------
		//
		
		void SetDesviacion ( double desviacion_nueva ) {
			
			desviacion = desviacion_nueva;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// Funci�n para definir la media de una gaussiana.
		//
		// Entrada: media nueva
		// Salida: ----------------
		//
		// PRE: media_nueva >= 0
		
		void SetMedia ( double media_nueva ) {
			
			media = media_nueva;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo 1 para calcular el CDF de la gaussiana. Este m�todo consiste
		// en simular una integral con la suma de diferenciales de 0.25.
		//
		// Entrada: abscisas hasta la que calcular el �rea
		// Salida: CDF
		//
		
		double CalculaCDF_met1 ( double x ) {
	
			const double DELTA = 0.25;
			
			double x_inicial = media - (3 * desviacion);
			double x_inter, suma = 0, g, x_final;
			
			if ( x_inicial < x ) {
				
				x_inter = x_inicial;
				x_final = x;
				
				while (x_inter <= x_final ) {
					
					g = CalcularEnX ( x_inter );
					
					suma = suma + g;
					
					x_inter = x_inter + DELTA;
					
				}
				
			}
			
			else {
				
				x_inter = x;
				
				while (x_inter <= x_inicial ) {
					
					g = CalcularEnX ( x_inter );
					
					suma = suma + g ;
					
					x_inter = x_inter + DELTA;
					
					x = x_inter;
					
				}
				
			}
			
			return ( suma * DELTA );
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// Normaliza la gaussiana, cambiando tambi�n sus par�metros por:
		//
		//	Desviaci�n = 1 
		//	Media = 0
		//
		// Adem�s, la x tambi�n variar� para cualquiera que fuera la tarea
		// que este usando la gaussiana, por lo que devolver� la nueva
		// "x_estand"
		//
		// Entrada: -----------
		// Salida: ----------
		//
		
		double NormalizaGaussiana ( double x ) {
			
			double x_estand;
			
			x_estand = ( x - media ) / desviacion;
			
			SetMedia(0);
			SetDesviacion(1);
			
			return x_estand;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo 2 para calcular el CDF de la gaussiana. Este se basa en una
		// expresi�n predefinida.
		//
		// Entrada: abscisas hasta la que calcular el CDF de la gaussiana
		// Salida: CDF
		
		double CalcularCDF_met2 ( double x ) {
	
			const double B0 = 0.2316419, B1 = 0.319381530, B2 = -0.356563782;
			const double B3 = 1.781477937, B4 = -1.821255978, B5 = 1.330274429;
			
			double x_estand = NormalizaGaussiana(x);
				
			double t = 1.0 / 1 + ( B0 * abs ( x_estand ) );
			
			double term;
			
			term = (B1 * t)+(B2 * pow(t,2))+(B3 * pow(t,3))+(B4 * pow(t,4))
					+(B5 * pow(t,5));
			
			double cdf = 1 - ( CalcularEnX(x_estand) * term );
			
			if ( x_estand < 0 ) cdf = 1 - cdf ;
			
			return cdf;
			
		}

		/////////////////////////////////////////////////////////////////
		
		// M�todo para expresar los campos del objeto "Gaussiana" en una
		// cadena de caracteres y devolver esta
		//
		// Entrada: -----------
		// Salida: cadena de caracteres
		
		string ToString () {
			
			string cad = "N (";
			cad = cad + to_string(GetMedia()) + " , ";
			cad = cad + to_string(GetDesviacion());
			cad = cad + " )";
			
			return cad;
			
		}
			
};

/************************************************************************/

/************************************************************************/
// Funci�n para leer un real, sirviendo esta de filtro. Pedir� un n�mero
// hasta que se le introduzca uno correcto.
//
// Entrada: t�tulo a mostrar en pantalla a la hora de pedir el n�mero.
// Salida: n�mero real.
/************************************************************************/

double LeeReal ( string titulo)
{
	
	string num;
	double real;
	bool Es_Real;
	int longitud;
	bool ya_punto = false;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Real = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Real ; pos ++ ) {
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') {
				
				if ( (num.at(pos) == '.' || num.at(pos) == ',') && !ya_punto )
				
				ya_punto = true;
				
				else Es_Real = false;
				
				if ( (num.at(pos) == '+' || num.at(pos) == '-') && pos == 0 )
		
				Es_Real = true;
			
			}
			
		}


	} while ( !Es_Real );
	
	real = stod(num);
	
	return real;
	
}

/************************************************************************/

int main ()				// Funci�n principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	cout << "----------------|PARAMETROS GAUSSIANA|----------------" << endl;
	cout << endl;
	
	double media = LeeReal("\tIntroduzca la MEDIA: ");
	
	double desviacion;
	
	do {
		
		desviacion =  LeeReal("\tIntroduzca una DESVIACION valida ( > 0 ): ");
		
	} while ( desviacion <= 0 );
	
		// Creaci�n de un objeto de la clase "Gaussiana"
		
	Gaussiana g ( media , desviacion );
	
	string titulo_x = "\tIntroduzca un abscisas hasta donde realizar los";
	titulo_x += " c�lculos: ";
	
	double x = LeeReal(titulo_x);
	
	// C�lculos
	
	string parametros = g.ToString();
	
	double gauss_en_x = g.CalcularEnX( x );
	
	double cdf1 = g.CalculaCDF_met1( x );
	double cdf2 = g.CalcularCDF_met2( x );
	
	// Salida de resultados
	
	cout << endl << endl;
	
	cout << "----------------|RESULTADOS|----------------" << endl << endl;
	cout << "\tGaussiana introducida = " << parametros << endl;
	cout << "\tValor en X ( X = " << setprecision(3) << x << " ) = ";
	cout << setw(8) << setprecision(3) << gauss_en_x << endl;
	cout << "\tValor del CDF hasta X ( M�todo 1 ) = ";
	cout << setw(8) << setprecision(3) << cdf1 << endl;
	cout << "\tValor del CDF hasta X ( M�todo 2 ) = ";
	cout << setw(8) << setprecision(3) << cdf2 << endl;
	
	
	return 0;
	
}
			
