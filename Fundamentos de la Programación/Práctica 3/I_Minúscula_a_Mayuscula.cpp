/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_Min�scula_a_May�scula.cpp: Escribe un programa que lea un car�cter y lo pase
//de min�scula a may�scula.
//
//Entrada: letra en min�scula
//Salida: letra en may�scula
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char caracter;  //Declaraci�n de variables de entrada y salida
	
	//Entrada de valores
	
	cout <<"Introduzca un caracter en minuscula: ";
	cin >> caracter;
	
	//C�lculos
	
	caracter = (int)caracter - 32;
	
	//Presentaci�n de resutados
	
	cout <<endl;
	
	cout <<"En mayuscula, su caracter es " <<caracter;
	
	return 0;
	
}
