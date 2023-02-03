/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//II_Minúscula_a_Mayúscula_Comp.cpp: Escribe un programa que lea un carácter y 
//lo pase de minúscula a mayúscula. Manda un mensaje de error cuando no se
//introduzca un caracter correcto.
//
//Entrada: letra en minúscula
//Salida: letra en mayúscula
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char caracter;  //Declaración de variables de entrada y salida
	
	const int DIFERENCIA_MIN_MAY = 'a' - 'A';
	
	//Entrada de valores
	
	cout <<"Introduzca un caracter en minuscula: ";
	cin >> caracter;
	
	//Comprobación de errores
	
	if ((int)caracter < 'a' || (int)caracter > 'z') {
		
		cout <<"----------------ERROR----------------" <<endl;
		
		cout <<"Introduzca un caracter valido (Minuscula): ";
		
		cin >> caracter;
	}
		
	//Cálculos
	
	caracter = (int)caracter - DIFERENCIA_MIN_MAY;
	
	//Presentación de resutados
	
	cout <<endl;
	
	cout <<"En mayuscula, su caracter es " <<caracter;
	
	return 0;
	
}
