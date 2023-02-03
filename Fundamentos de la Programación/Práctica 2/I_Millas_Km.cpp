/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_Millas_Km.cpp: Escribe un programa que pase de millas a km y posteriormente
//de km a millas. Usar� las variables de entrada como de salida tambi�n
//
//Entrada: metros
//Salida: conversi�n a pulgadas, pies, yardas y millas.
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double millas, km;  //Declaraci�n de variables de entrada y salida
	
	//Entrada de valores
	
	cout <<"Introduzca un numero de millas: ";
	cin >>millas;
	
	//C�lculos
	
	km = millas * 1.609;
	
	//Presentaci�n de resultados
	
	cout <<"Km: " <<km;
	cout <<endl;
	
	//Segunda parte: pasar de km a millas
	
	cout <<endl;
	cout <<"Introduzca un numero de km: ";
	cin >> km;
	
	//C�lculos
	
	millas = km / 1.609;
	
	//Presentaci�n de resultados
	
	cout <<"Millas: " <<millas;
	
	return 0;
	
}
