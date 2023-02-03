/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�45.
//II_RLE.cpp: escribe un programa que codifique una sucesi�n de numeros enteros
//positivos seg�n el m�todo RLE y termine de pedir valores cuando lea el -1.
//
//Entrada: valores enteros
//Salida: secuencia codificada
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato 
#include <string>       //Inclusi�n de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const int TERMINADOR = -1;	
	
	//Declaraci�n de variables de entradas
	
	int entero, contador = 0, valor_repetido;
	string sucesion_codif, sucesion;
	
	//Entrada de datos y algoritmo de codificaci�n de la cadena
	
	cout <<"Para indicar el fin de la sucesion introduzca el -1." <<endl;
	
	do {
		
		cout <<"Introduzca un entero del 0 al 9: ";
		cin >> entero;
		valor_repetido = entero;
		
		
	} while ( entero < TERMINADOR || entero > 9 );
	
	while ( entero != TERMINADOR ) {
		
		sucesion = sucesion + to_string(entero);
		 
		if ( valor_repetido == entero ) { 
		
			contador ++ ;
		
			if ( contador > 9 ) {
				
				sucesion_codif = sucesion_codif + to_string(contador);
				sucesion_codif = sucesion_codif + to_string(valor_repetido);
				
				contador = 1;
			}
			
		}
		
		else {
			
			sucesion_codif = sucesion_codif + to_string(contador);
			sucesion_codif = sucesion_codif + to_string(valor_repetido);
			
			contador = 1;
			valor_repetido = entero;

		}
		
		do {
		
			cout <<"Introduzca un entero del 0 al 9: ";
			cin >> entero;
			
		} while ( entero < TERMINADOR || entero > 9 );
		
	}
	
	sucesion_codif = sucesion_codif + to_string(contador);
	sucesion_codif = sucesion_codif + to_string(valor_repetido);
	
	//Salida de datos
	
	cout << "SUCESION INTRODUCIDA: " << endl;
	cout << "| " << sucesion <<" |" << endl << endl;
	cout << "SUCESION CODIFICADA: " << endl;
	cout << "| " << sucesion_codif <<" |" << endl;
	
	return 0;
	
}
	
		
			
		
		
		
	
