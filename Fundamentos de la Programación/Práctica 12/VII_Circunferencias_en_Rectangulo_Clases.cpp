/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 7. N�37.
// VII_Circunferencias_en_Rectangulo_Clases.cpp: escribe un programa que
// cuente con las clases "Punto2D", "Circunferencia" y "Rectangulo" y que
// guarde en un array todas las circunferencias inscritas en un rect�ngulo
// definido previamente.
//
//Entrada: puntos del rect�ngulo
//Salida: n�mero de circunferencias y radio de todas ellas
//
/************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Declaraci�n de la clase "Punto2D", la cual recoger� la ordenada y la abcisa
// de uno adem�s de recoger algunos m�todos b�sicos para operar con el mismo
// punto y con otros.

class Punto2D
{

	private:
	
		double x;
		double y;
	
	public:
		
		//////////////////////////////////////////////////////
		// Constructor que iniciar� los campos x e y con valores que se
		// le introduzcan.
		
		Punto2D (double la_x, double la_y):
			
			x(la_x),
			y(la_y)
			
		{}
		
		//////////////////////////////////////////////////////
		// Constructor sin argumentos. Inicializar� los campos x e y en 0
		
		Punto2D ():
			
			x(0),
			y(0)
			
		{}
		
		//////////////////////////////////////////////////////
		// M�todo para establecer las coordenadas de un punto despu�s de
		// haber inicializado este. Permitir� cambiar los valores de los
		// campos x e y por los introducidos
		//
		// Entrada: valor de "x" y de "y"
		// Salida: ------------
		
		void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
		{
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo "x".
		//
		// Entrada: -------------
		// Salida: "x"
		
		double GetX() {
			
			return x;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo "y".
		//
		// Entrada: -------------
		// Salida: "y"
		
		double GetY() {
			
			return y;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para calcular la distancia entre dos objetos "Punto2D".
		//
		// Entrada: el otro punto
		// Salida: distancia entre los puntos 
	
		double DistanciaCon (Punto2D otro) {
			
			double dif_x = pow (x - otro.GetX() , 2);
			double dif_y = pow (y - otro.GetY() , 2);
	
			return (sqrt(dif_x + dif_y));
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver una cadena con las coordenadas de un punto
		//
		// Entrada: -------------
		// Salida: "[ x , y ] "
		
		string To_String () {
			
			string abscisas = to_string(x);
			int pos;
			
			for ( int i = 1; i < abscisas.length() ; i ++ ) {
				
				if ( abscisas.at(i) != '0' && abscisas.at(i) != '.' ) pos = i;
				
			}
			
			abscisas = abscisas.substr(0, pos + 1);
			
			string ordenada = to_string(y);
			
			for ( int i = 1; i < ordenada.length() ; i ++ ) {
				
				if ( ordenada.at(i) != '0' && ordenada.at(i) != '.' ) pos = i;
				
			}
			
			ordenada = ordenada.substr(0, pos + 1);
			
			string cad = "[ " + abscisas + " , " + ordenada + " ]";
			
			return cad;
			
		}
		
};

// Declaraci�n de la clase circunferencia, que contar� con un campo
// "Punto2D centro" y otro "double radio".

class Circunferencia {
	
	private:
		
		static const double PI; 
		Punto2D centro;
		double radio; //PRE: 0 < radio
		
	public:
		
		//Constructor que inicializar� los campos de radio y de centro con
		// valores que se le introduzca
		
		Circunferencia (Punto2D el_centro, double el_radio):
			
			centro(el_centro),
			radio(el_radio)
			
		{}
		
		// Constructor sin argumentos que inizializar� el radio a 0.5 y el
		// centro en el punto [ 0, 0 ]
		
		Circunferencia(): radio(0.5) {
			
			Punto2D cero( 0, 0 );
			
			centro = cero;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el objeto " centro ".
		//
		// Entrada: -------------
		// Salida: "Punto2D centro"
		
		Punto2D GetCentro (void) {
			
			return centro;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo " radio ".
		//
		// Entrada: -------------
		// Salida: "double radio"
		
		double GetRadio(void)
		{
			return radio;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del di�metro de la circunferencia,
		// es decir, radio * 2
		//
		// Entrada: -------------
		// Salida: radio * 2
		
		double GetDiametro () {
			
			return (radio*2);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor de la longitud de la circunferencia
		//
		// Entrada: -------------
		// Salida: longitud
		
		double Longitud (void) {
			
			return (2 * PI * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del �rea de la circunferencia
		//
		// Entrada: -------------
		// Salida: �rea
		
		double Area (void) {
			
			return (PI * radio * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo booleano para comprobar si un punto pertenece a la
		// circunferencia o no.
		//
		// Entrada: objeto " Punto2D "
		// Salida: "true" o "false"
		
		bool Contiene (Punto2D un_punto) {
			
			Punto2D el_centro = centro;
			double distancia = el_centro.DistanciaCon(un_punto);
			
			return (distancia <= radio);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para cambiar el valor del campo "radio" por uno que recibe
		// este.
		//
		// Entrada: nuevo valor del radio
		// Salida: -------------
		
		void SetRadio ( double nuevo_radio ) {
			
			radio = nuevo_radio;
			
		}
		
}; 	
	
	const double Circunferencia::PI = 3.141526;
	
// Declaraci�n de la clase " Rectangulo", que cuenta con dos campos de la
// clase "Punto2D" que definen a cada objeto

class Rectangulo{

	private: 
	
		Punto2D co_sup_izq;
		Punto2D co_inf_der;
		
	public:
		
		// Constructor que asigna a cada campo del objeto los valores
		// introducidos.
		
		Rectangulo(Punto2D co_sup_izq_inic, Punto2D co_inf_der_inic)
		
			: co_sup_izq(co_sup_izq_inic),
			  co_inf_der(co_inf_der_inic)
			  
		{}
		
		///////////////////////////////////////////////////////////////////
		// M�todo para devolver la esquina superior izquierda.
		//
		// Entrada: ---------------
		// Salida: co_sup_izq
		
		Punto2D GetCoSupIzq(){
			
			return co_sup_izq;
			
		}
		
		///////////////////////////////////////////////////////////////////
		// M�todo para devolver la longitud del lado peque�o del rect�ngulo.
		//
		// Entrada: ---------------
		// Salida: longitud del lado peque�o
		
		double LadoPeq() {
			
			double lado1 = abs(co_sup_izq.GetX() - co_inf_der.GetX());
			double lado2 = abs(co_sup_izq.GetY() - co_inf_der.GetY());
			
			double pequeno = ( lado1 > lado2 ) ? lado2 : lado1;
			
			return pequeno;
			
		}
		
		///////////////////////////////////////////////////////////////////
		// M�todo para devolver la longitud del lado grande del rect�ngulo.
		//
		// Entrada: ---------------
		// Salida: longitud del lado grande
		
		double LadoGran() {
			
			double lado1 = abs(co_sup_izq.GetX() - co_inf_der.GetX());
			double lado2 = abs(co_sup_izq.GetY() - co_inf_der.GetY());
			
			double grande = ( lado1 > lado2 ) ? lado1 : lado2;
			
			return grande;
			
		}
		
		///////////////////////////////////////////////////////////////////
		// M�todo para devolver la esquina superior izquierda.
		//
		// Entrada: ---------------
		// Salida: co_sup_der
		
		Punto2D GetCoInfDer(){
			
			return co_inf_der;
			
		}
		
		//////////////////////////////////////////////////////////////////
		// M�todo para calcular y devolver el �rea del rect�ngulo
		//
		// Entrada: ---------------
		// Salida: �rea del rect�ngulo								
		
		double Area(){
			
			double incremento_x, incremento_y;
			double area;
			
			incremento_x = co_inf_der.GetX() - co_sup_izq.GetX();		 
			incremento_y = co_sup_izq.GetY() - co_inf_der.GetY();
			
			area = abs(incremento_x * incremento_y);	 
			
			return (area);
			
		}
		
		//////////////////////////////////////////////////////////////////
		// M�todo para calcular y devolver el centro del rect�ngulo
		//
		// Entrada: ---------------
		// Salida: �rea del rect�ngulo
			
		Punto2D Centro() {
			
			Punto2D centro;
			
			double incremento_x, incremento_y;
			
			incremento_x = co_inf_der.GetX() - co_sup_izq.GetX();
			
			incremento_y = co_sup_izq.GetY() - co_inf_der.GetY();
			
			double x, y;
			
			x = co_sup_izq.GetX() + (incremento_x * 0.5);
			y = co_sup_izq.GetY() - (incremento_y * 0.5);
						 
			centro.SetCoordenadas( x, y );
			
			return (centro);
		}
};

/********************************************************************/
/*	Funci�n que lee un rect�ngulo a trav�s de sus vertices superior izquierdo
	e inferior derecho

	Entrada: --------
	Salida: El rect�ngulo (variable de tipo "Rect�ngulo")			*/
	
Rectangulo LeeRectangulo () {
	
	double x, y;
	
	cout << endl << "Introduzca la abscisa de la coordenada de la esquina "
		 << "superior izquierda: ";
	cin >> x;
	cout << endl << "Introduzca la ordenada de la coordenada de la esquina "
		 << "superior izquierda: ";
	cin >> y;
	
	Punto2D co_sup_izq( x, y );
	
	cout << endl << endl <<"Introduzca la abscisa de la coordenada de la "
		 << "esquina inferior derecha: ";
	cin >> x;
	cout << endl << "Introduzca la ordenada de la coordenada de la esquina "
		 << "inferior derecha: ";
	cin >> y;
	
	Punto2D co_inf_der( x, y );
	
	Rectangulo rectangulo(co_sup_izq, co_inf_der);
	
	return (rectangulo);
	
}

/********************************************************************/

int main(){										// Programa principal
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Declaraci�n de variables

	double radio = 0.5;
	const double SALTO = 0.25; 	
	Punto2D centro;
	const int MAXIMO = 100;			// M�ximo n�mero de circunferencias

	// Entrada de datos
	
	Rectangulo rectangulo = LeeRectangulo();
	
	// C�lculos
	
		// La circunferencia estar� inscrita en el rect�ngulo mientras
		// su radio sea menor que la mitad del lado peque�o del rect�ngulo
		
	double max_radio = rectangulo.LadoPeq() * 0.5;
	
	centro = rectangulo.Centro();
	
		// Creamos el vector de circunferencias.
		
	Circunferencia inscritas[MAXIMO];
	
	Circunferencia circunferencia ( centro, radio );
	int num_circunf = 0;
	
	while ( radio <= max_radio && num_circunf < MAXIMO ) {
		
		inscritas[num_circunf] = circunferencia;
		
		num_circunf ++;
		radio += SALTO;
		circunferencia.SetRadio(radio);
		
	}
	
	// Salida de datos
	
	cout << endl << endl;
	cout << "----------------|RESULTADOS|----------------" << endl << endl;
	
	cout << "\t Inscritas en el rectangulo, encontramos " << num_circunf;
	cout << " circunferencias:" << endl;
	cout << "\t| INDICE ||      CENTRO      ||  RADIO  |" << endl;
	cout << "\t----------------------------------------------" << endl;
	
	for ( int i = 0; i < num_circunf ; i ++ ) {
		
		cout <<"\t|" << setw(8) << i + 1 << "||";
		cout << setw(18) << setprecision(2) << centro.To_String() << "||";
		cout << setw(9) << setprecision(2) << inscritas[i].GetRadio();
		cout << "|" << endl;
		
	}
	
	cout << "\t----------------------------------------------" << endl;
	
	return 0;
	
}
		
		
		
		


