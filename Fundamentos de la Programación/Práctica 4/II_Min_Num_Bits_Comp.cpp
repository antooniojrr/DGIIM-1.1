/******************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//II_Min_Num_Bits_Comp.cpp: Escribe un programa que calcule el m�nimo
//n�mero de bits necesarios para representar un n�mero entero positivo. Este
//comprobar� que el numero introducido es positivo.
//
//Entrada: n�mero entero
//Salida: n�mero de bits
//
/******************************************************************/

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
	
	//Comprobaci�n de erorres
	if (numero < 0 ) {
		cout <<"----------------ERROR----------------" <<endl <<endl;
		cout <<"El numero introducido debe ser positivo. Introduzca uno: ";
		cin >> numero;
	}
	
	//C�lculos
	
	bits = (numero == 0 ) ? 1 : log2 (numero) + 1;
	
		  //Esta expresi�n viene de que con n bits, podremos expresar un
		  //numero menor o igual que 2^(n-1). Por otro lado, cuando
		  //numero = 0, le asignar� 1 a bits directamente.
	

	//Salida de resultados
	
	cout << endl;
	cout <<"Se necesitaran "<<bits<<" bits para expresar el numero "<<numero;
	
	return 0;
	
}
	
	
	
