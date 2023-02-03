/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 3. Nº38.
//III_DecToBin_BinToDec_Funcs.cpp: escribe un programa que,
//a través de funciones, realice la conversión de decimal a binario de un
//número y compruebe esta conversión volviendolo a pasar a decimal.
//
//Entrada: número decimal y número de bits
//Salida: tabla con conversión a binario y de vuelta a decimal
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      //Formato
#include <cmath>        //Inclusión de los recursos matemáticos
#include <string>       //Inclusión del tipo string

using namespace std;

//Función conversora de decimal a binario.

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

string DecToBin_Estricto ( int numero_dec ) {  // Función conversora
											   //(Con los bits necesarios)
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

// Función para convertir de binario a decimal

int BinToDec ( string num_bin ) {

	int num_dec = 0;
	int exponente = num_bin.length() - 1;
	int posicion = 0;
	
	while ( posicion <= (num_bin.length() - 1) ) {
		
		if (num_bin.at(posicion) == '1')
		 
			num_dec = num_dec + pow(2,exponente);
			
		exponente --;
		posicion ++;
		
	}
	
	return num_dec;
	
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
	
	// Cálculos
	
	string numero_bin;
	string num_bin_estric;
	int num_comprobacion;
	
	cout << endl;
	
	cout << " |NUMEROS EN BINARIO HASTA EL (" << num_decimal <<")|";
	cout << endl << endl;
	cout <<	"|  X  ||  ESTRICTO  ||   " << num_bits << " BITS   || DEC |";
	cout << endl;
	cout << "-------------------------------------------" << endl;
	
	
	for ( int i = 0; i <= num_decimal ; i ++ ) {
		
		numero_bin = DecToBin ( i, num_bits ) ;
		num_bin_estric = DecToBin_Estricto ( i );
		num_comprobacion = BinToDec ( numero_bin );
		
		// Salida de datos
		
		cout << "|" << setw(5) <<  i << "||" << setw(12) << num_bin_estric;
		cout << "||" << setw(13) << numero_bin << "||";
		cout << setw(5) << num_comprobacion <<"|" << endl;
		
	}
	
	return 0;
	
}
	
	
	
	
	
	
	


