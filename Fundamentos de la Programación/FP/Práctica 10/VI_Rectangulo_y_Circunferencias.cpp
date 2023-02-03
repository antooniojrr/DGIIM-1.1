/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 6. Nº6.
// VI_Rectangulo_y_Circunferencias.cpp: escribe un programa que, usando
// la clase "Rectangulo", lea dos puntos de este, consiga su área y
// construya una circunferencia de centro igual al del rectángulo y área mayor
// que la del rectángulo (La mínima posible aumentando el radio de este
// 0.25 comenzando por 0.5)
//
//Entrada: puntos del rectángulo
//Salida: datos del rectángulo y de la circunferencia
//
/************************************************************************/

#include <iostream>						// Inclusión de recursos E/S		
#include <cmath>						// Inclusión de recursos matemáticos

using namespace std;

struct Punto2D{	 // Dato "struct" para los valores de un punto de 2 dimensiones

	double abscisa;
	double ordenada;
	
};

class Rectangulo{	 // Clase que define el rectángulo

	private: 
	
		Punto2D co_sup_izq;
		Punto2D co_inf_der;
		
	public:
		
		Rectangulo(Punto2D co_sup_izq_inic, Punto2D co_inf_der_inic)
		
			: co_sup_izq(co_sup_izq_inic),
			  co_inf_der(co_inf_der_inic)
			  
		{}
		
		Punto2D GetCoSupIzq(){
			
			return co_sup_izq;
			
		}	
		
		Punto2D GetCoInfDer(){
			
			return co_inf_der;
			
		}
		
	/********************************************************************/
	/*	Función que calcula el area de un rectángulo
	
		Entrada: --------
		Salida: área del rectángulo								*/		
		
		double CalculaArea(){
			
			double incremento_x, incremento_y;
			double area;
			
			incremento_x = co_inf_der.abscisa - co_sup_izq.abscisa;		 
			incremento_y = co_sup_izq.ordenada - co_inf_der.ordenada;
			
			area = abs(incremento_x * incremento_y);	 
			
			return (area);
			
		}
		
	/********************************************************************/
	/*	Función que calcula el centro de un rectángulo.

		Entrada: --------
		Salida: centro del rectángulo.								*/
			
		Punto2D CalculaCentro() {
			
			Punto2D centro;
			
			double incremento_x, incremento_y;
			
			incremento_x = co_inf_der.abscisa - co_sup_izq.abscisa;
			
			incremento_y = co_sup_izq.ordenada - co_inf_der.ordenada;
						 
			centro.abscisa = (incremento_x * 0.5);
			centro.ordenada = (incremento_y * 0.5);
			
			return (centro);
		}
};

class Circunferencia{  // Clase que define circunferencia
	private:
		
		Punto2D centro;
		
		double radio;
		
	public: 
		Circunferencia(Punto2D centro_inic, double radio_inic)
			: centro(centro_inic),
			  radio(radio_inic)
		{}
		
		Punto2D GetCentro(){
			
			return centro;
			
		}	
		
		double GetRadio(){
			
			return radio;
			
		}
		
	/********************************************************************/
	/*	Función que calcula el area de un círculo.
	
		Entrada: --------
		Devuelve: área del círculo.										*/		
		
		double CalculaArea(){
			
			const double PI = 3.141592;
			double area;
			
			area = PI * pow(radio, 2);
			
			return (area);
			
		}

	/********************************************************************/
	/*	Función que actualiza el radio de un círculo
	
		Entrada: valor del radio nuevo que la circunferencia debe adoptar
		Devuelve: Nada													 */		
		
		void SetRadio(double radio_nuevo){
			
			radio = radio_nuevo;
			
		}
		
};


/********************************************************************/
/*	Función que lee un rectángulo a través de sus vertices superior izquierdo
	e inferior derecho

	Entrada: --------
	Salida: El rectángulo (variable de tipo "Rectángulo")			*/
	
Rectangulo LeeRectangulo (){
	
	Punto2D co_sup_izq, co_inf_der;
	
	cout << endl << "Introduzca la abscisa de la coordenada de la esquina "
		 << "superior izquierda: ";
	cin >> co_sup_izq.abscisa;
	cout << endl << "Introduzca la ordenada de la coordenada de la esquina "
		 << "superior izquierda: ";
	cin >> co_sup_izq.ordenada;
	
	cout << endl << endl <<"Introduzca la abscisa de la coordenada de la "
		 << "esquina inferior derecha: ";
	cin >> co_inf_der.abscisa;
	cout << endl << "Introduzca la ordenada de la coordenada de la esquina "
		 << "inferior derecha: ";
	cin >> co_inf_der.ordenada;
	
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
	
	area_rect = rectangulo.CalculaArea();

	centro = rectangulo.CalculaCentro();
	
	Circunferencia circunferencia(centro, radio);
	
	area_circ = circunferencia.CalculaArea();	
	
	while (area_circ < area_rect){
		
		radio += SALTO;
		
		circunferencia.SetRadio(radio);
		
		area_circ = circunferencia.CalculaArea();
		
	}
	
	// Salida de datos
	
	cout << endl << "El area del rectangulo es " << area_rect << " unidades ";
	cout << "cuadradas. " << endl;
	
	cout << "El area menor del circulo que supera ";
	cout << "al area rectangulo es " << area_circ << " unidades cuadradas. ";
	cout << endl;
	
	
	cout << "La circunferencia tiene de centro (" << centro.abscisa;
	cout << ", " << centro.ordenada << ")" << " y de radio " << radio;
	cout << " unidades.";
	
	
	return 0;
	
}
