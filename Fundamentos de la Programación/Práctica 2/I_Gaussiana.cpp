/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_Gaussiana.cpp: Escribe un programa que calcule el valor de la gaussiana de x 
//seg�n la expresi�n de la funci�n gaussiana, pidiendo los valores de los 
//par�metros sigma y mu.
//Entrada: sigma, mu, x
//Salida: gaussiana (x)
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std;

int main ()             //Programa Principal
{
	double PI;
	double sigma, mu, x;  //Declaraci�n de variables de entrada
	
	double gauss;   //Resultado
	
	//Entrada de variables
	
	PI = 3.141592;
	cout <<"Introduzca el valor del par�metro SIGMA de la expresi�n: ";
	cin >> sigma;
	
	cout <<endl;
	cout <<"Introduzca el valor del par�metro MU de la expresi�n: ";
	cin >> mu;
	
	cout <<endl;
	cout <<"Escribe el valor de X al que calcular su gaussiana: ";
	cin >> x;
	
	//C�lculos
	
	gauss = (1 /(sigma * sqrt (2 * PI))) * exp(-0.5 *(pow((x - mu) / sigma,2)));
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"La Gaussiana de " <<x <<" es: " <<gauss;
	
	return 0;
}
