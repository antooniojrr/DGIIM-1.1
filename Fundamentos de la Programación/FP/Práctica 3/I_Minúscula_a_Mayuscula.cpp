/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Minúscula_a_Mayúscula.cpp: Escribe un programa que lea un carácter y lo pase
//de minúscula a mayúscula.
//
//Entrada: letra en minúscula
//Salida: letra en mayúscula
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char caracter;  //Declaración de variables de entrada y salida
	
	//Entrada de valores
	
	cout <<"Introduzca un caracter en minuscula: ";
	cin >> caracter;
	
	//Cálculos
	
	caracter = (int)caracter - 32;
	
	//Presentación de resutados
	
	cout <<endl;
	
	cout <<"En mayuscula, su caracter es " <<caracter;
	
	return 0;
	
}
