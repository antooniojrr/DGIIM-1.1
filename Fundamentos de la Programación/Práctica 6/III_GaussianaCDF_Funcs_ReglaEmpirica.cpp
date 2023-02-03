/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 3. Nº13.
//III_GaussianaCDF_Funcs_ReglaEmpirica.cpp: escribe un programa que,
//a través de funciones, realice la evaluación de la gaussiana en un x
//determinado y CDF de la función de dos formas diferentes
//
//Entrada: parámetros de la función y x donde y hasta donde evaluar.
//Salida: g(x), CDF de ambos métodos.
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        //Inclusión de los recursos matemáticos

using namespace std;

// Función para calcular la gaussiana en un x determinado

double gaussiana ( double sigma, double mu, double x ) {
	
	const double PI = 3.1415;
	double gauss;
	
	gauss = (1 /(sigma * sqrt (2 * PI))) *
									exp(-0.5 *(pow((x - mu) / sigma,2)));
									
	return gauss;
	
}

// Método 1 para calcular el CDF de la gaussiana. Este método consiste en
// simular una integral con la suma de diferenciales de 0.25.

double CDF_met1 ( double sigma, double mu, double x ) {
	
	const double DELTA = 0.25;
	
	double x_inicial = mu - (3 * sigma);
	double x_inter, suma = 0, gauss;
	
	if ( x_inicial < x) {
		
		x_inter = x_inicial;
		
		while (x_inter <= x ) {
			
			gauss = gaussiana ( sigma, mu , x_inter );
			
			suma = suma + gauss;
			
			x_inter = x_inter + DELTA;
			
		}
		
	}
	
	else {
		
		x_inter = x;
		
		while (x_inter <= x_inicial ) {
			
			gauss = gaussiana ( sigma, mu , x_inter );
			
			suma = suma + gauss;
			
			x_inter = x_inter + DELTA;
			
		}
		
	}
	
	return ( suma * DELTA );
	
}

// Método 2 para calcular el CDF de la gaussiana. Este se basa en una
// expresión predefinida.

double CDF_met2 ( double sigma, double mu, double x ) {
	
	const double B0 = 0.2316419, B1 = 0.319381530, B2 = -0.356563782;
	const double B3 = 1.781477937, B4 = -1.821255978, B5 = 1.330274429;
	
	double t = 1 / 1 + ( B0 * abs ( x ) );
	
	double term;
	
	term = (B1 * t) + (B2 * pow(t,2)) + (B3 * pow(t,3)) + (B4 * pow(t,4))
			+ (B5 * pow(t,5));
	double cdf = 1 - ( gaussiana (sigma, mu, abs(x) ) * term );
	
	if ( x >= 0 ) return cdf;
	
	else return (1 - cdf);
	
}

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
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
	
	
	// Cálculos
	
	double gauss = gaussiana (sigma, mu, x);
	
	double cdf_1 = CDF_met1 ( sigma, mu, x );
	
	double cdf_2 = CDF_met2 ( sigma, mu, x );
	
	//Resultados
	
	cout << "--------------------|RESULTADOS|--------------------";
	cout << endl << endl;
	
	cout << "\tGaussiana (" << x << ") = " << gauss << endl;
	cout << "\tCDF (Metodo 1) = " << cdf_1 << endl;
	cout << "\tCDF (Metodo 2) = " << cdf_2 << endl;
	
	return 0;
	
}
	
	


	
									
	
