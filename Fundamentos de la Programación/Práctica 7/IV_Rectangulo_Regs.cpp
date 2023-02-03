/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 4. Nº4.
//IV_Rectangulo_Regs.cpp: escribe un programa que calcule el área de un
//rectángulo definido por dos puntos y calcule la circunferencia de área mínima
//pero más grande que la del rectángulo
//
//Entrada: puntos que definen el rectángulo
//Salida: área del rectángulo, área y radio de la circunferencia.
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

// Declaración de constantes
	
	const double PI = 3.141592653;
	
//Declaración de los tipos struct:

struct Punto2D
{
	double abcisa;
	double ordenada;
};

struct Rectangulo
{
	double largo;
	double ancho;
	double area;
};

struct Circunferencia
{
	double radio;
	double area;
};



int main ()
{
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);
	
	
	
	// Declaración de variables
	
	struct Punto2D punto1, punto2;
	
	cout << "Introduzca la coordenada X del punto 1 (Abcisa): ";
	cin >> punto1.abcisa;
	
	cout << "Introduzca la coordenada Y del punto 1 (Ordenada): ";
	cin >> punto1.ordenada;
	
	
	cout << "Introduzca la coordenada X del punto 2 (Abcisa): ";
	cin >> punto2.abcisa;
	
	cout << "Introduzca la coordenada Y del punto 2 (Ordenada): ";
	cin >> punto2.ordenada;
	
	
	// Cálculos
	
	struct Rectangulo rectangulo;
	
	rectangulo.ancho = abs(punto1.ordenada - punto2.ordenada);
	rectangulo.largo = abs(punto2.abcisa - punto1.abcisa);
	
	rectangulo.area = rectangulo.ancho * rectangulo.largo;
	
	struct Circunferencia circunferencia;
	
	circunferencia.radio = 0.5;
	const double DELTA = 0.25;
	
	while ( circunferencia.area < rectangulo.area ) {
		
		circunferencia.radio += DELTA;
		circunferencia.area = circunferencia.radio * circunferencia.radio * PI;
	}
		
	// Resultados
	
	cout << endl;
	cout << "-------------------|RESULTADOS|-------------------" << endl;
	cout << endl;
	cout << "PUNTOS INTRODUCIDOS: " << endl;
	cout << "\tPunto 1: ( " << punto1.abcisa << " , " << punto1.ordenada;
	cout << " )" << endl;
	cout << "\tPunto 2: ( " << punto2.abcisa << " , " << punto2.ordenada;
	cout << " )" << endl << endl;
	
	cout << "AREA DEL RECTANGULO = " <<setw(8) <<setprecision(3);
	cout << rectangulo.area << endl << endl;
	
	cout << "AREA DE LA CIRCUNFERENCIA BUSCADA = " << circunferencia.area;
	cout << endl;
	cout << "RADIO DE LA CIRCUNFERENCIA BUSCADA = " << circunferencia.radio;
	
	
	return 0;
	
}
	
	
