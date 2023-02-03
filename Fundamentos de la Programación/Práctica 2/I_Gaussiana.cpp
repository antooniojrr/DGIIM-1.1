/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Gaussiana.cpp: Escribe un programa que calcule el valor de la gaussiana de x 
//según la expresión de la función gaussiana, pidiendo los valores de los 
//parámetros sigma y mu.
//Entrada: sigma, mu, x
//Salida: gaussiana (x)
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	double PI;
	double sigma, mu, x;  //Declaración de variables de entrada
	
	double gauss;   //Resultado
	
	//Entrada de variables
	
	PI = 3.141592;
	cout <<"Introduzca el valor del parámetro SIGMA de la expresión: ";
	cin >> sigma;
	
	cout <<endl;
	cout <<"Introduzca el valor del parámetro MU de la expresión: ";
	cin >> mu;
	
	cout <<endl;
	cout <<"Escribe el valor de X al que calcular su gaussiana: ";
	cin >> x;
	
	//Cálculos
	
	gauss = (1 /(sigma * sqrt (2 * PI))) * exp(-0.5 *(pow((x - mu) / sigma,2)));
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"La Gaussiana de " <<x <<" es: " <<gauss;
	
	return 0;
}
