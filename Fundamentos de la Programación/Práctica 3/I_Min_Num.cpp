/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_Min_Num_Bits.cpp: Escribe un programa que calcule el m�nimo n�mero de bits
//necesarios para representar un n�mero entero positivo
//
//Entrada: n�mero entero
//Salida: n�mero de bits
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <cmath>        //Inclusi�n de operaciones matem�ticas complejas

using namespace std;

int main ()             //Programa Principal
{
	int numero; //Declaraci�n de variables de entrada
	
	int bits;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca un numero entero positivo: ";
	cin >> numero;
	
	//C�lculos
	
	bits = log2 (numero) + 1; //Esta expresi�n viene de que con n bits, podremos
	                          //expresar un numero menor o igual que 2^(n-1)

	
	//Salida de resultados
	
	cout << endl;
	cout <<"Se necesitaran " <<bits <<" bits para expresar el numero " <<numero;
	
	return 0;
	
}
	
	
	
