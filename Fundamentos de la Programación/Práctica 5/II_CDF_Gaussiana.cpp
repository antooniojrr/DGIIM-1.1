/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº51.
//II_CDF_Gaussiana.cpp: escribe un programa que calcule el valor del CDF
//de una función Gaussiana entre dos valores del eje de abcisas.
//
//Entrada: parámetros de la función y valores de la abcisa
//Salida: valor del CDF
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>    // Formato 
#include <cmath>       //Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const double DELTA = 1;    //Diferencia entre 2 valores consec.
	const double PI = 3.141592;
	
	//Entrada de variables
	
	double sigma, mu, x;
	
	cout <<"Introduzca el valor del parámetro SIGMA de la expresión: ";
	cin >> sigma;
	
	cout <<endl;
	cout <<"Introduzca el valor del parámetro MU de la expresión: ";
	cin >> mu;
	
	cout <<endl;
	cout <<"Escribe X hasta la que calcular el CDF de la Gaussiana: ";
	cin >> x;
	
	//Cálculos
	
	double x_inicial = mu - (3 * sigma);
	double x_inter, suma = 0, gauss;
	
	if ( x_inicial < x) {
		
		x_inter = x_inicial;
		
		while (x_inter <= x ) {
			
			gauss = (1 /(sigma * sqrt (2 * PI))) * exp(-0.5 *(pow((x_inter-mu)
					/ sigma,2)));
			
			suma = suma + gauss;
			
			x_inter = x_inter + DELTA;
			
		}
		
	}
	
	else {
		
		x_inter = x;
		
		while (x_inter <= x_inicial ) {
			
			gauss = (1 /(sigma * sqrt (2 * PI))) * exp(-0.5 *(pow((x_inter-mu)
					/ sigma,2)));
			
			suma = suma + gauss;
			
			x_inter = x_inter + DELTA;
			
		}
		
	}
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"La CDF de la Gaussiana hasta " <<x <<" es: " <<suma;
	
	return 0;
}
	
