/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 3. N�38.
//III_BinToDec_Funcs.cpp: escribe un programa que,
//a trav�s de funciones, realice la conversi�n de binario a decimal de un
//n�mero comprobando antes su correcta escritura, simplificandolo y
//finalmente, convirtiendolo.
//
//Entrada: n�mero binario
//Salida: n�mero decimal
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>      //Formato
#include <cmath>        //Inclusi�n de los recursos matem�ticos
#include <string>       //Inclusi�n del tipo string

using namespace std;

// Funci�n booleana para comprobar su correcta escritura
//
// Entrada: n�mero binario
// Salida: "true" o "false"

bool bin_ok ( string num_bin ) {
	
	bool todo_ok = true;
	
	string binario = num_bin;
	
	int i = num_bin.length() - 1;
		
	while (i >= 0 && todo_ok) {
		
		if (num_bin.at(i) != '1' && num_bin.at(i) != '0' ) todo_ok = false;
		
		i --;
		
	}
	
	return ( todo_ok );
	
}

// Funci�n para simplificar la cadena antes de convertirla.
//
// Entrada: n�mero binario
// Salida: n�mero binario simplificado

string simplifica ( string num_bin ) {
	
	int pos = 0;
	
	int longitud = num_bin.length();
	
	while ( num_bin.at(pos) == '0' && pos <= (longitud - 1) ) {
		
		pos ++;
	}
	
	string num_simp;
	
	num_simp = num_bin.substr (pos);
	
	return num_simp;
	
}

// Funci�n para convertir el n�mero binario a decimal.
//
// Entrada: n�mero binario
// Salida: n�mero decimal

int BinToDec ( string num_bin ) {

	int num_dec = 0;
	int longitud = num_bin.length();
	int posicion = 0;
	int exponente = longitud - 1;
	
	
	while ( posicion <= ( longitud - 1) ) {
		
		if (num_bin.at(posicion) == '1')
		 
			num_dec = num_dec + pow(2,exponente);
			
		exponente --;
		posicion ++;
		
	}
	
	return num_dec;
	
}

int main () {                   // Programa principal
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	//Entrada de valores
	
	string num_bin;
	
	cout << "Introduzca un numero en su forma binaria: ";
	cin >> num_bin;
	
	if (!bin_ok( num_bin ) ) {
		
		do {
			
			cout << "Cadena no valida, por favor,";
			cout <<"introduzca un numero binario: ";
			cin >> num_bin;
			
		} while ( !bin_ok( num_bin ) );
		
	}
	
	// C�lculos
	
	string bin_simple = simplifica ( num_bin );
	
	int num_dec = BinToDec ( bin_simple );
	
	// Salida de resultados
	
	cout << endl;
	
	cout << "\tCADENA INTRODUCIDA: |" << num_bin << "|" << endl;
	
	cout << "\tCADENA SIMPLIFICADA: |" << bin_simple << "|" << endl;
	
	cout << "\tVALOR DECIMAL = " << num_dec;
	
	
	return 0;
	
}
	
	
		
		
	
	
	
	
	




	


