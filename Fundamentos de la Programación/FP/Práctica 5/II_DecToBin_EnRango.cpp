/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�83.
//II_DecToBin_EnRango.cpp: escribe un programa que pase cualquier n�mero entero
//positivo de decimal a binario. Se introducir� el n�mero de bits en un
//primero momento.
//
//Entrada: n�mero de bits y n�mero decimal a representar.
//Salida: n�mero binario
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>      //Formato 
#include <cmath>        //Inclusi�n de los recursos matem�ticos
#include <string>       //Inclusi�n de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
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
	
	//C�lculos
	
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
			
			
	
	
	
	
	
