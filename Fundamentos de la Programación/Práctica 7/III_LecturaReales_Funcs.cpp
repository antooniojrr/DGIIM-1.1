/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 3. N�18.
//III_LecturaReales_Funcs.cpp: escribe un programa que conste de una funci�n
// que actuen como filtro para n�meros reales.
//
//Entrada: n�meros
//Salida: n�mero real
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"

using namespace std;

/************************************************************************/
// Funci�n "booleana" para comprobar la validez de un car�cter para que la
// cadena sea un n�mero real.
//
// Entrada: caracter.
// Salida: "true" o "false"
/************************************************************************/

bool Es_Valido ( char caracter)
{
	
	bool valido = ( caracter >= '0' && caracter <= '9');
	
	return valido;
	
}

/************************************************************************/
// Funci�n para leer un real, sirviendo esta de filtro. Pedir� un n�mero
// hasta que se le introduzca uno correcto.
//
// Entrada: t�tulo a mostrar en pantalla a la hora de pedir el n�mero.
// Salida: n�mero real.
/************************************************************************/

double LeeReal ( string titulo)
{
	
	string num;
	double real;
	bool Es_Real;
	int longitud;
	bool ya_punto = false;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Real = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Real ; pos ++ ) {
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') {
				
				if ( (num.at(pos) == '.' || num.at(pos) == ',') && !ya_punto )
				
				ya_punto = true;
				
				else Es_Real = false;
				
				if ( (num.at(pos) == '+' || num.at(pos) == '-') && pos == 0 )
		
				Es_Real = true;
			
			}
			
		}


	} while ( !Es_Real );
	
	real = stod(num);
	
	return real;
	
}

int main ()                         // Programa principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	double real = LeeReal ( "Introduzca un numero real: " );
	
	cout << endl;
	cout << "Real introducido: " <<setw(8) << real;
	
	return 0;
	
}
	


