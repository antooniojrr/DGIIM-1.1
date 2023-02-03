/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 3. Nº18.
//III_LecturaEnteros_Funcs.cpp: escribe un programa que conste de funciones
// que actuen como filtro para números enteros, en un rango o mayores o iguales
// que una referencia.
//
//Entrada: números
//Salida: números enteros, en un rango o mayor o igual que una referencia
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"

using namespace std;

/************************************************************************/
// Función para leer un entero, sirviendo esta de filtro. Pedirá un número
// hasta que se le introduzca uno correcto.
//
// Entrada: título a mostrar en pantalla a la hora de pedir el número.
// Salida: número entero.
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
// Función para leer un entero en un rango determinado,
// sirviendo esta de filtro. Pedirá un número hasta que se le introduzca
// uno correcto.
//
// Entrada: título a mostrar, máximo y mínimo del rango.
// Salida: número entero.
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
// Función para leer un entero mayor o igual que una referencia,
// sirviendo esta de filtro. Pedirá un número hasta que se le introduzca
// uno correcto.
//
// Entrada: título a mostrar, referencia.
// Salida: número entero mayor o igual a referencia.
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


int main ()                            // Función principal
{
	
	//Declaración de constantes
	const int MAX = 100;
	const int MIN = 10;
	
	const int REFERENCIA = 36;
	
	// ( Son números al azar para comprobar el correcto funcionamieno del
	// programa )
	
	//Declaración de variables
	
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
	
	// (No existen cálculos fuera de las funciones)
	
	// Salida.
	
	cout << endl;
	cout << " Enteros introducidos: " << endl;
	cout <<"\tEntero 1 = " << entero1 << endl;
	cout <<"\tEntero 2 = " << entero2 << endl;
	cout <<"\tEntero 3 = " << entero3 << endl;
	
	return 0;
	
}
			
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
