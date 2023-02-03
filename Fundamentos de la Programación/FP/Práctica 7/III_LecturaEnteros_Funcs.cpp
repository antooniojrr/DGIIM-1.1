/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 3. N�18.
//III_LecturaEnteros_Funcs.cpp: escribe un programa que conste de funciones
// que actuen como filtro para n�meros enteros, en un rango o mayores o iguales
// que una referencia.
//
//Entrada: n�meros
//Salida: n�meros enteros, en un rango o mayor o igual que una referencia
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"

using namespace std;

/************************************************************************/
// Funci�n para leer un entero, sirviendo esta de filtro. Pedir� un n�mero
// hasta que se le introduzca uno correcto.
//
// Entrada: t�tulo a mostrar en pantalla a la hora de pedir el n�mero.
// Salida: n�mero entero.
/************************************************************************/

int LeeEntero ( string titulo)
{
	
	string num;
	int entero;
	bool Es_Entero;
	int longitud;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Entero = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Entero ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Entero = false;
			
	} while ( !Es_Entero );
	
	entero = stoi(num);
	
	return entero;
	
}


/************************************************************************/
// Funci�n para leer un entero en un rango determinado,
// sirviendo esta de filtro. Pedir� un n�mero hasta que se le introduzca
// uno correcto.
//
// Entrada: t�tulo a mostrar, m�ximo y m�nimo del rango.
// Salida: n�mero entero.
/************************************************************************/

int LeeEnteroEnRango ( string titulo, int max, int min)
{
	
	string num;
	int entero;
	bool Es_Valido;
	int longitud;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Valido = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
			
		if ( stoi(num) > max || stoi(num) < min ) Es_Valido = false;
			
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}


/************************************************************************/
// Funci�n para leer un entero mayor o igual que una referencia,
// sirviendo esta de filtro. Pedir� un n�mero hasta que se le introduzca
// uno correcto.
//
// Entrada: t�tulo a mostrar, referencia.
// Salida: n�mero entero mayor o igual a referencia.
/************************************************************************/

int LeeEnteroMayorOIgual ( string titulo, int referencia)
{
	
	string num;
	int entero;
	bool Es_Valido;
	int longitud;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Valido = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
		
		if ( stoi(num) < referencia ) Es_Valido = false;
		
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}


int main ()                            // Funci�n principal
{
	
	//Declaraci�n de constantes
	const int MAX = 100;
	const int MIN = 10;
	
	const int REFERENCIA = 36;
	
	// ( Son n�meros al azar para comprobar el correcto funcionamieno del
	// programa )
	
	//Declaraci�n de variables
	
	int entero1, entero2, entero3;
	
	const string titulo1 = "Introduzca un numero entero: ";
	const string titulo2 = "Introduzca un numero entero entre " +
							to_string (MIN) + " y " + to_string (MAX) +
							": ";
	const string titulo3 = "Introduzca un numero entero mayor o igual que "
							+ to_string(REFERENCIA) + ": ";
	
	
	// Entrada de datos
	
	entero1 = LeeEntero ( titulo1 );
	
	entero2 = LeeEnteroEnRango ( titulo2, MAX, MIN );
	
	entero3 = LeeEnteroMayorOIgual ( titulo3, REFERENCIA );
	
	// (No existen c�lculos fuera de las funciones)
	
	// Salida.
	
	cout << endl;
	cout << " Enteros introducidos: " << endl;
	cout <<"\tEntero 1 = " << entero1 << endl;
	cout <<"\tEntero 2 = " << entero2 << endl;
	cout <<"\tEntero 3 = " << entero3 << endl;
	
	return 0;
	
}
			
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
