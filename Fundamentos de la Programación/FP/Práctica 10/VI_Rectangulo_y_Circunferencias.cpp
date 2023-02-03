/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 6. N�6.
// VI_Rectangulo_y_Circunferencias.cpp: escribe un programa que, usando
// la clase "Rectangulo", lea dos puntos de este, consiga su �rea y
// construya una circunferencia de centro igual al del rect�ngulo y �rea mayor
// que la del rect�ngulo (La m�nima posible aumentando el radio de este
// 0.25 comenzando por 0.5)
//
//Entrada: puntos del rect�ngulo
//Salida: datos del rect�ngulo y de la circunferencia
//
/************************************************************************/

#include <iostream>						// Inclusi�n de recursos E/S		
#include <cmath>						// Inclusi�n de recursos matem�ticos

using namespace std;

struct Punto2D{	 // Dato "struct" para los valores de un punto de 2 dimensiones

	double abscisa;
	double ordenada;
	
};

class Rectangulo{	 // Clase que define el rect�ngulo

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
	/*	Funci�n que calcula el area de un rect�ngulo
	
		Entrada: --------
		Salida: �rea del rect�ngulo								*/		
		
		double CalculaArea(){
			
			double incremento_x, incremento_y;
			double area;
			
			incremento_x = co_inf_der.abscisa - co_sup_izq.abscisa;		 
			incremento_y = co_sup_izq.ordenada - co_inf_der.ordenada;
			
			area = abs(incremento_x * incremento_y);	 
			
			return (area);
			
		}
		
	/********************************************************************/
	/*	Funci�n que calcula el centro de un rect�ngulo.

		Entrada: --------
		Salida: centro del rect�ngulo.								*/
			
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
	/*	Funci�n que calcula el area de un c�rculo.
	
		Entrada: --------
		Devuelve: �rea del c�rculo.										*/		
		
		double CalculaArea(){
			
			const double PI = 3.141592;
			double area;
			
			area = PI * pow(radio, 2);
			
			return (area);
			
		}

	/********************************************************************/
	/*	Funci�n que actualiza el radio de un c�rculo
	
		Entrada: valor del radio nuevo que la circunferencia debe adoptar
		Devuelve: Nada													 */		
		
		void SetRadio(double radio_nuevo){
			
			radio = radio_nuevo;
			
		}
		
};


/********************************************************************/
/*	Funci�n que lee un rect�ngulo a trav�s de sus vertices superior izquierdo
	e inferior derecho

	Entrada: --------
	Salida: El rect�ngulo (variable de tipo "Rect�ngulo")			*/
	
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

	// Declaraci�n de variables

	double radio = 0.5;
	const double SALTO = 0.25; 	
	double area_rect, area_circ;
	Punto2D centro;

	// Entrada de datos
	
	Rectangulo rectangulo = LeeRectangulo();
	
	// C�lculos
	
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
