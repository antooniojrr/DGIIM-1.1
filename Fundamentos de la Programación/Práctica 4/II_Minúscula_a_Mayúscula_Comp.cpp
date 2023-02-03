/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//II_Min�scula_a_May�scula_Comp.cpp: Escribe un programa que lea un car�cter y 
//lo pase de min�scula a may�scula. Manda un mensaje de error cuando no se
//introduzca un caracter correcto.
//
//Entrada: letra en min�scula
//Salida: letra en may�scula
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char caracter;  //Declaraci�n de variables de entrada y salida
	
	const int DIFERENCIA_MIN_MAY = 'a' - 'A';
	
	//Entrada de valores
	
	cout <<"Introduzca un caracter en minuscula: ";
	cin >> caracter;
	
	//Comprobaci�n de errores
	
	if ((int)caracter < 'a' || (int)caracter > 'z') {
		
		cout <<"----------------ERROR----------------" <<endl;
		
		cout <<"Introduzca un caracter valido (Minuscula): ";
		
		cin >> caracter;
	}
		
	//C�lculos
	
	caracter = (int)caracter - DIFERENCIA_MIN_MAY;
	
	//Presentaci�n de resutados
	
	cout <<endl;
	
	cout <<"En mayuscula, su caracter es " <<caracter;
	
	return 0;
	
}
