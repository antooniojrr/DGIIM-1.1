/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº83.
//II_DecToBin_EnRango.cpp: escribe un programa que pase cualquier número entero
//positivo de decimal a binario. Se introducirá el número de bits en un
//primero momento.
//
//Entrada: número de bits y número decimal a representar.
//Salida: número binario
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      //Formato 
#include <cmath>        //Inclusión de los recursos matemáticos
#include <string>       //Inclusión de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Entrada de valores
	
	int numero_dec, num_bits;
	
	do {
		
		cout <<"Introduzca un numero de bits valido (>0): ";
		cin >> num_bits;
		
	} while ( num_bits < 0);
	
	do {
		
		cout <<"Introduzca un numero entero positivo representable ";
		cout <<"con el numero de bits introducidos: ";
		cin >> numero_dec;
		
	} while ( numero_dec < 0 || numero_dec > pow(2,(num_bits-1)));
	
	//Cálculos
	
	string numero_bin;
		
	int resto = numero_dec, exponente = num_bits - 1;
	
	while ( exponente >= 0 ) {
		
		if ( pow(2,exponente) <=  resto ) {
			
			resto = resto - pow(2,exponente);
			numero_bin.push_back('1');
			
			exponente --;
			
		}
		
		else {
			
			numero_bin.push_back('0');
			
			exponente --;
			
		}
		
	}
	
	//Salida
	
	cout << endl;
	cout <<"Numero DECIMAL = " << numero_dec << endl;
	cout <<"Numero BINARIO = " << numero_bin << endl;
	
	return 0;
	
}
			
			
	
	
	
	
	
