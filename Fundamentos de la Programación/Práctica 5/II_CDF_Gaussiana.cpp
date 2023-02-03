/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�51.
//II_CDF_Gaussiana.cpp: escribe un programa que calcule el valor del CDF
//de una funci�n Gaussiana entre dos valores del eje de abcisas.
//
//Entrada: par�metros de la funci�n y valores de la abcisa
//Salida: valor del CDF
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato 
#include <cmath>       //Inclusi�n de los recursos matem�ticos

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const double DELTA = 1;    //Diferencia entre 2 valores consec.
	const double PI = 3.141592;
	
	//Entrada de variables
	
	double sigma, mu, x;
	
	cout <<"Introduzca el valor del par�metro SIGMA de la expresi�n: ";
	cin >> sigma;
	
	cout <<endl;
	cout <<"Introduzca el valor del par�metro MU de la expresi�n: ";
	cin >> mu;
	
	cout <<endl;
	cout <<"Escribe X hasta la que calcular el CDF de la Gaussiana: ";
	cin >> x;
	
	//C�lculos
	
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
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"La CDF de la Gaussiana hasta " <<x <<" es: " <<suma;
	
	return 0;
}
	
