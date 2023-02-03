/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 3. N�38.
//III_DecToBin_Funcs.cpp: escribe un programa que,
//a trav�s de funciones, realice la conversi�n de decimal a binario de los
//n�mero comprendidos entre el 0 y otro introducido
//
//Entrada: n�mero decimal y n�mero de bits
//Salida: n�meros en binario
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>      //Formato
#include <cmath>        //Inclusi�n de los recursos matem�ticos
#include <string>       //Inclusi�n del tipo string

using namespace std;

//Funci�n conversora de decimal a binario.

string DecToBin ( int num_decimal, int num_bits ) {
	
	string numero_bin;
	
	int resto = num_decimal;
	
	int exponente = ( ( pow ( 2, (num_bits - 1) ) >= num_decimal ) ? 
				num_bits - 1 : log2 ( num_decimal ) );
	
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
	
	
	return (numero_bin);
	
}

string DecToBin_Estricto ( int numero_dec ) {
	
	int num_bits;
	string numero_bin;
	
	num_bits = ( (numero_dec == 0 ) ? 1 : (log2 (numero_dec) + 1) );
	
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
	
	return numero_bin;
}
	

int main () {
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	//Entrada de valores
	
	int num_decimal, num_bits;
	
	do {
		
		cout << "Introduzca un numero entero positivo ";
		cout << "hasta el que convertir: ";
		cin >> num_decimal;
		
	}while ( num_decimal < 0 );
	
	do {
		
		cout << "Introduzca el numero de bits para representarlo: ";
		cin >> num_bits;
		
	}while ( num_bits <= 0 );
	
	// C�lculos
	
	string numero_bin;
	string num_bin_estric;
	
	cout << endl;
	
	cout << " |NUMEROS EN BINARIO HASTA EL (" << num_decimal <<")|";
	cout << endl << endl;
	cout <<	"|  X  ||  ESTRICTO  ||   " << num_bits << " BITS   |" << endl;
	cout << "------------------------------------" << endl;
	
	
	for ( int i = 0; i <= num_decimal ; i ++ ) {
		
		numero_bin = DecToBin ( i, num_bits ) ;
		num_bin_estric = DecToBin_Estricto ( i );
		
		// Salida de resultados
		
		cout << "|" << setw(5) <<  i << "||" << setw(12) << num_bin_estric;
		cout << "||" << setw(13) << numero_bin << "|" << endl;
		
	}
	
	return 0;
	
}
	
	
	
	
	
	
	
