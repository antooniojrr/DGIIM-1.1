/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 3. Nº36.
//III_Comprueba_NIF_NIE.cpp: escribe un programa que lea y compruebe la
//validez de documentos NIF y NIE indefinidamente hasta introducir "FIN"
//
//Entrada: NIFs y NIEs
//Salida: validez de los introducidos
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

/************************************************************************/
// Función "booleana" para comprobar que el supuesto NIF es correcto.
// Comprobará tanto la correspondencia del digito de control como la validez
// de todos sus digitos.
//
// Entrada: NIF
// Salida: "True" o "false"
//
/************************************************************************/

bool ComprobarNIF ( string nif ) {
	
	char digito1 = nif.at(0);
	string dividendo;
	int longitud = nif.length();
	bool error = false;
	const int DIVISOR = 23;
	int resto;
	char digitocontrol;
	
	const string VALORX = "0";
	const string VALORY = "1";
	const string VALORZ = "2";
	
	if ( digito1 == 'X' ) 
					
			dividendo = VALORX;
			
	else if ( digito1 == 'Y' )
			
		dividendo = VALORY;
		
	else if ( digito1 == 'Z' )
	
		dividendo = VALORZ;
		
	for ( int pos = 1 ; pos <= longitud - 2 && !error ; pos ++ )
		
		if ( nif.at(pos) < '0' || nif.at(pos) > '9' ) error = true;
		
	
	if ( !error ) {
		
		dividendo = dividendo + nif.substr(1,7);
		resto = stoi(dividendo) % DIVISOR;
	
		switch (resto) {
			
			case ( 0 ):
				
				digitocontrol = 'T';
				break;
				
			case ( 1 ):
				
				digitocontrol = 'R';
				break;
			
			case ( 2 ):
				
				digitocontrol = 'W';
				break;
				
			case ( 3 ):
				
				digitocontrol = 'A';
				break;
			
			case ( 4 ):
				
				digitocontrol = 'G';
				break;
				
			case ( 5 ):
				
				digitocontrol = 'M';
				break;
				
			case ( 6 ):
				
				digitocontrol = 'Y';
				break;
				
			case ( 7 ):
				
				digitocontrol = 'F';
				break;
			
			case ( 8 ):
				
				digitocontrol = 'P';
				break;
				
			case ( 9 ):
				
				digitocontrol = 'D';
				break;
				
			case ( 10 ):
				
				digitocontrol = 'X';
				break;
				
			case ( 11 ):
				
				digitocontrol = 'B';
				break;
			
			case ( 12 ):
				
				digitocontrol = 'N';
				break;
				
			case ( 13 ):
				
				digitocontrol = 'J';
				break;
				
			case ( 14 ):
				
				digitocontrol = 'Z';
				break;
			
			case ( 15 ):
				
				digitocontrol = 'S';
				break;
			
			case ( 16 ):
				
				digitocontrol = 'Q';
				break;
				
			case ( 17 ):
				
				digitocontrol = 'V';
				break;
				
			case ( 18 ):
				
				digitocontrol = 'H';
				break;
				
			case ( 19 ):
				
				digitocontrol = 'L';
				break;
		
			case ( 20 ):
				
				digitocontrol = 'C';
				break;
				
			case ( 21 ):
				
				digitocontrol = 'K';
				break;
			
			case ( 22 ):
				
				digitocontrol = 'E';
				break;

		}
		
		if ( digitocontrol != nif.at(8) ) error = true;
		
	}
	
	return ( !error );
	
}
		
/************************************************************************/
// Función "booleana" para comprobar que el supuesto DNI es correcto.
// Comprobará tanto la correspondencia del digito de control como la validez
// de todos sus digitos.
//
// Entrada: NIF
// Salida: "True" o "false"
//
/************************************************************************/

bool ComprobarDNI ( string dni ) {
	
	int longitud = dni.length();
	bool error = false;
	const int DIVISOR = 23;
	int resto;
	char digitocontrol;
	int numero;
	
	if (longitud != 9 ) error = true;
	
	for ( int pos = 0 ; pos <= longitud - 2 && !error ; pos ++ ) 
		
		if ( dni.at(pos) < '0' || dni.at(pos) > '9' ) error = true;
		
	
	if ( !error ) {
		
		numero = stoi(dni.substr(0,8));
		
		resto = numero % DIVISOR;
		
		switch (resto) {
			
			case ( 0 ):
				
				digitocontrol = 'T';
				break;
				
			case ( 1 ):
				
				digitocontrol = 'R';
				break;
			
			case ( 2 ):
				
				digitocontrol = 'W';
				break;
				
			case ( 3 ):
				
				digitocontrol = 'A';
				break;
			
			case ( 4 ):
				
				digitocontrol = 'G';
				break;
				
			case ( 5 ):
				
				digitocontrol = 'M';
				break;
				
			case ( 6 ):
				
				digitocontrol = 'Y';
				break;
				
			case ( 7 ):
				
				digitocontrol = 'F';
				break;
			
			case ( 8 ):
				
				digitocontrol = 'P';
				break;
				
			case ( 9 ):
				
				digitocontrol = 'D';
				break;
				
			case ( 10 ):
				
				digitocontrol = 'X';
				break;
				
			case ( 11 ):
				
				digitocontrol = 'B';
				break;
			
			case ( 12 ):
				
				digitocontrol = 'N';
				break;
				
			case ( 13 ):
				
				digitocontrol = 'J';
				break;
				
			case ( 14 ):
				
				digitocontrol = 'Z';
				break;
			
			case ( 15 ):
				
				digitocontrol = 'S';
				break;
			
			case ( 16 ):
				
				digitocontrol = 'Q';
				break;
				
			case ( 17 ):
				
				digitocontrol = 'V';
				break;
				
			case ( 18 ):
				
				digitocontrol = 'H';
				break;
				
			case ( 19 ):
				
				digitocontrol = 'L';
				break;
		
			case ( 20 ):
				
				digitocontrol = 'C';
				break;
				
			case ( 21 ):
				
				digitocontrol = 'K';
				break;
			
			case ( 22 ):
				
				digitocontrol = 'E';
				break;
				
		}
		
		if ( digitocontrol != dni.at(8) ) error = true;
		
		
	}
	
	return ( !error );
	
}	
			

int main () {
	
	// Declaración de constantes
	
	const string TERMINADOR = "FIN";
	
	// Declaración de variables
	
	string NumeroIdent;
	enum class TipoDoc { DNI, NIF };
	char digito1;
	
	TipoDoc documento;

	
	// Entrada de datos
	
	bool valido;
	
	cout << "Introduzca un DNI o NIF: ";
	getline (cin, NumeroIdent);
	
	while ( NumeroIdent != TERMINADOR ) {
		
		digito1 = NumeroIdent.at(0);
		
		if ( digito1 == 'X' || digito1 == 'Y' || digito1 == 'Z' ) 
			
			documento = TipoDoc::NIF;
			
			
		else 
			
			documento = TipoDoc::DNI;
			
		
		switch (documento){
			
			case (TipoDoc::NIF):
				
				valido = ComprobarNIF (NumeroIdent);
				break;
				
			case (TipoDoc::DNI):
				
				valido = ComprobarDNI (NumeroIdent);
				break;
				
		}
		
		if (valido) {
			
			cout << "NUMERO DE IDENTIFICACION INTRODUCIDO: |";
			cout << NumeroIdent << "|" << endl;
			
			if ( documento == TipoDoc::DNI) cout << "\tTipo de documento: DNI";
			
			else cout << "\tTipo de documento: NIF";
			cout << endl;
			cout << "\tDOCUMENTO VALIDO" << endl << endl;
			
		}
			
		else {
			
			cout << "NUMERO DE IDENTIFICACION INTRODUCIDO: |";
			cout << NumeroIdent << "|" << endl;
			cout << "\tTipo de documento: ??? ";
			cout << endl;
			cout << "\tDOCUMENTO NO VALIDO" << endl << endl;
			
		}
		
		cout << "Introduzca un DNI o NIF: ";
		getline (cin, NumeroIdent);
		
	}
	
	return 0;
	
}
			
				
				
				
				
					
				
				
				
			
				
	
