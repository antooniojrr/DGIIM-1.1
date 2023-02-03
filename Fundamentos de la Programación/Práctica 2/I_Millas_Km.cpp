/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Millas_Km.cpp: Escribe un programa que pase de millas a km y posteriormente
//de km a millas. Usaré las variables de entrada como de salida también
//
//Entrada: metros
//Salida: conversión a pulgadas, pies, yardas y millas.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double millas, km;  //Declaración de variables de entrada y salida
	
	//Entrada de valores
	
	cout <<"Introduzca un numero de millas: ";
	cin >>millas;
	
	//Cálculos
	
	km = millas * 1.609;
	
	//Presentación de resultados
	
	cout <<"Km: " <<km;
	cout <<endl;
	
	//Segunda parte: pasar de km a millas
	
	cout <<endl;
	cout <<"Introduzca un numero de km: ";
	cin >> km;
	
	//Cálculos
	
	millas = km / 1.609;
	
	//Presentación de resultados
	
	cout <<"Millas: " <<millas;
	
	return 0;
	
}
