/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 7. Nº11.
// VII_Rectangulo_y_Circunferencias.cpp: escribe un programa que, usando
// la clase "Rectangulo", lea dos puntos de este, consiga su área y
// construya una circunferencia de centro igual al del rectángulo y área mayor
// que la del rectángulo (La mínima posible aumentando el radio de este
// 0.25 comenzando por 0.5)
//
//
//Entrada: puntos del rectángulo
//Salida: datos del rectángulo y de la circunferencia
//
/************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Declaración de la clase "Punto2D", la cual recogerá la ordenada y la abcisa
// de uno además de recoger algunos métodos básicos para operar con el mismo
// punto y con otros.

class Punto2D
{

	private:
	
		double x;
		double y;
	
	public:
		
		//////////////////////////////////////////////////////
		// Constructor que iniciará los campos x e y con valores que se
		// le introduzcan.
		
		Punto2D (double la_x, double la_y):
			
			x(la_x),
			y(la_y)
			
		{}
		
		//////////////////////////////////////////////////////
		// Constructor sin argumentos. Inicializará los campos x e y en 0
		
		Punto2D ():
			
			x(0),
			y(0)
			
		{}
		
		//////////////////////////////////////////////////////
		// Método para establecer las coordenadas de un punto después de
		// haber inicializado este. Permitirá cambiar los valores de los
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
		// Método para devolver el valor del campo "x".
		//
		// Entrada: -------------
		// Salida: "x"
		
		double GetX() {
			
			return x;
			
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver el valor del campo "y".
		//
		// Entrada: -------------
		// Salida: "y"
		
		double GetY() {
			
			return y;
			
		}
		
		//////////////////////////////////////////////////////
		// Método para calcular la distancia entre dos objetos "Punto2D".
		//
		// Entrada: el otro punto
		// Salida: distancia entre los puntos 
	
		double DistanciaCon (Punto2D otro) {
			
			double dif_x = pow (x - otro.GetX() , 2);
			double dif_y = pow (y - otro.GetY() , 2);
	
			return (sqrt(dif_x + dif_y));
			
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver una cadena con las coordenadas de un punto
		//
		// Entrada: -------------
		// Salida: "[ x , y ] "
		
		string To_String () {
			
			string cad = "[ " + to_string(x) + " , " + to_string(y) + " ]";
			
			return cad;
			
		}
		
};

// Declaración de la clase circunferencia, que contará con un campo
// "Punto2D centro" y otro "double radio".

class Circunferencia {
	
	private:
		
		static const double PI; 
		Punto2D centro;
		double radio; //PRE: 0 < radio
		
	public:
		
		//Constructor que inicializará los campos de radio y de centro con
		// valores que se le introduzca
		
		Circunferencia (Punto2D el_centro, double el_radio):
			
			centro(el_centro),
			radio(el_radio)
			
		{}
		
		//////////////////////////////////////////////////////
		// Método para devolver el objeto " centro ".
		//
		// Entrada: -------------
		// Salida: "Punto2D centro"
		
		Punto2D GetCentro (void) {
			
			return centro;
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver el valor del campo " radio ".
		//
		// Entrada: -------------
		// Salida: "double radio"
		
		double GetRadio(void)
		{
			return radio;
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver el valor del diámetro de la circunferencia,
		// es decir, radio * 2
		//
		// Entrada: -------------
		// Salida: radio * 2
		
		double GetDiametro () {
			
			return (radio*2);
			
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver el valor de la longitud de la circunferencia
		//
		// Entrada: -------------
		// Salida: longitud
		
		double Longitud (void) {
			
			return (2 * PI * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// Método para devolver el valor del área de la circunferencia
		//
		// Entrada: -------------
		// Salida: área
		
		double Area (void) {
			
			return (PI * radio * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// Método booleano para comprobar si un punto pertenece a la
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
		// Método para cambiar el valor del campo "radio" por uno que recibe
		// este.
		//
		// Entrada: nuevo valor del radio
		// Salida: -------------
		
		void SetRadio ( double nuevo_radio ) {
			
			radio = nuevo_radio;
			
		}
		
}; 	
	
	const double Circunferencia::PI = 3.141526;
	
// Declaración de la clase " Rectangulo", que cuenta con dos campos de la
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
		// Método para devolver la esquina superior izquierda.
		//
		// Entrada: ---------------
		// Salida: co_sup_izq
		
		Punto2D GetCoSupIzq(){
			
			return co_sup_izq;
			
		}	
		
		///////////////////////////////////////////////////////////////////
		// Método para devolver la esquina superior izquierda.
		//
		// Entrada: ---------------
		// Salida: co_sup_der
		
		Punto2D GetCoInfDer(){
			
			return co_inf_der;
			
		}
		
		//////////////////////////////////////////////////////////////////
		// Método para calcular y devolver el área del rectángulo
		//
		// Entrada: ---------------
		// Salida: área del rectángulo								
		
		double Area(){
			
			double incremento_x, incremento_y;
			double area;
			
			incremento_x = co_inf_der.GetX() - co_sup_izq.GetX();		 
			incremento_y = co_sup_izq.GetY() - co_inf_der.GetY();
			
			area = abs(incremento_x * incremento_y);	 
			
			return (area);
			
		}
		
		//////////////////////////////////////////////////////////////////
		// Método para calcular y devolver el centro del rectángulo
		//
		// Entrada: ---------------
		// Salida: área del rectángulo
			
		Punto2D Centro() {
			
			Punto2D centro;
			
			double incremento_x, incremento_y;
			
			incremento_x = co_inf_der.GetX() - co_sup_izq.GetX();
			
			incremento_y = co_sup_izq.GetY() - co_inf_der.GetY();
						 
			centro.SetCoordenadas(incremento_x * 0.5, incremento_y * 0.5);
			
			return (centro);
		}
};

/********************************************************************/
/*	Función que lee un rectángulo a través de sus vertices superior izquierdo
	e inferior derecho

	Entrada: --------
	Salida: El rectángulo (variable de tipo "Rectángulo")			*/
	
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

	// Declaración de variables

	double radio = 0.5;
	const double SALTO = 0.25; 	
	double area_rect, area_circ;
	Punto2D centro;

	// Entrada de datos
	
	Rectangulo rectangulo = LeeRectangulo();
	
	// Cálculos
	
	area_rect = rectangulo.Area();

	centro = rectangulo.Centro();
	
	Circunferencia circunferencia(centro, radio);
	
	area_circ = circunferencia.Area();	
	
	while (area_circ < area_rect){
		
		radio += SALTO;
		
		circunferencia.SetRadio(radio);
		
		area_circ = circunferencia.Area();
		
	}
	
	// Salida de datos
	
	cout << endl << "El area del rectangulo es " << setw(5) << setprecision(3);
	cout << area_rect << " unidades ";
	cout << "cuadradas. " << endl;
	
	cout << "El area menor del circulo que supera ";
	cout << "al area rectangulo es " << setw(5) << setprecision(3);
	cout << area_circ << " unidades cuadradas. ";
	cout << endl;
	
	
	cout << "La circunferencia tiene de centro " << centro.To_String();
	cout << " y de radio " << setw(5) << setprecision(3) << radio;
	cout << " unidades.";
	
	
	return 0;
	
}
