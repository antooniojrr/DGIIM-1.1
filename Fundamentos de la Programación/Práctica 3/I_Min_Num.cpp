/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Min_Num_Bits.cpp: Escribe un programa que calcule el mínimo número de bits
//necesarios para representar un número entero positivo
//
//Entrada: número entero
//Salida: número de bits
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>        //Inclusión de operaciones matemáticas complejas

using namespace std;

int main ()             //Programa Principal
{
	int numero; //Declaración de variables de entrada
	
	int bits;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca un numero entero positivo: ";
	cin >> numero;
	
	//Cálculos
	
	bits = log2 (numero) + 1; //Esta expresión viene de que con n bits, podremos
	                          //expresar un numero menor o igual que 2^(n-1)

	
	//Salida de resultados
	
	cout << endl;
	cout <<"Se necesitaran " <<bits <<" bits para expresar el numero " <<numero;
	
	return 0;
	
}
	
	
	
