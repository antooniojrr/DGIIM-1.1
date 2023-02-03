/******************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//II_Min_Num_Bits_Comp.cpp: Escribe un programa que calcule el mínimo
//número de bits necesarios para representar un número entero positivo. Este
//comprobará que el numero introducido es positivo.
//
//Entrada: número entero
//Salida: número de bits
//
/******************************************************************/

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
	
	//Comprobación de erorres
	if (numero < 0 ) {
		cout <<"----------------ERROR----------------" <<endl <<endl;
		cout <<"El numero introducido debe ser positivo. Introduzca uno: ";
		cin >> numero;
	}
	
	//Cálculos
	
	bits = (numero == 0 ) ? 1 : log2 (numero) + 1;
	
		  //Esta expresión viene de que con n bits, podremos expresar un
		  //numero menor o igual que 2^(n-1). Por otro lado, cuando
		  //numero = 0, le asignará 1 a bits directamente.
	

	//Salida de resultados
	
	cout << endl;
	cout <<"Se necesitaran "<<bits<<" bits para expresar el numero "<<numero;
	
	return 0;
	
}
	
	
	
