/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 28. Nº5.
// V_Robot_Linea.cpp: escribe un programa que mueva un robot por una fila
// según las instrucciones que introduzca el usuario e indique las veces
// que ha estado en cada posición y si esa secuencia de instrucciones es
// correcta.
//
//
//Entrada: instrucciones y posición inicial
//Salida: correcto o incorrecto, número de veces que ha estado en cada
// posición
//
/************************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;


int main ()                           // Programa principal
{

	// Declaración de constantes
	
	const int LON = 20;
	const int POSICIONES = 101;    // El primer elemento del array será la
								   // pos 0 ( No valida ya que 1 <= pos <= 100)
	const int MAX = 100;
	const int MIN = 1;
	
	const string TERMINADOR = "FIN";
	const char DERECHA = 'D';
	const string DERE = "D";
	const string IZQ = "I";
	const char IZQUIERDA = 'I';
	const char TERM = 'F';

	
	// Declaración de arrays
	
	char ordenes[LON];
	int util = 0;                  // Saber cuantos componentes de "ordenes"
								   // se usan
	int posiciones [POSICIONES];
	
		// Inicialización de todos sus componentes a 0
		
	for ( int i = 0 ; i < POSICIONES ; i ++ ) posiciones[i] = 0;
	
	// Entrada de valores
	
	cout << " --------------|INICIALIZACION DEL ROBOT|-------------- ";
	cout << endl;
	
	
	int pos;
	string titulo;
	titulo = " Introduzca la posicion inicial del robot ( 1 <= pos <= 100 ): ";
	
	string num;
	bool Es_Valido;
	int longitud;
	int casilla = 0;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		longitud = num.length();
		
		// Eliminará los espacios previos al número
		
		while (isspace(num.at(casilla)) && casilla < longitud ) {
			
			casilla++;
		}
		
		string sin_espacios;
		
		sin_espacios = num.substr(casilla);
		
		// Eliminará los espacios posteriores al número
		
		while (longitud > 0 && isspace(sin_espacios.back())) {
			
			sin_espacios.pop_back();
			longitud = sin_espacios.length();
			
		}
        
		num = sin_espacios;
		
		Es_Valido = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
			
		if ( Es_Valido && ( stoi(num) > MAX || stoi(num) < MIN ) )
		
			Es_Valido = false;
		
		if ( !Es_Valido ) cout << " ¡ERROR! ";
			
	} while ( !Es_Valido );
	
	pos = stoi(num);
	
	
	bool terminar = false;
	
	string instruccion;
	char final;
	
	// Introducir las órdenes que seguirá el robot ( 'I', 'D' o "FIN" )
	
	for ( int i = 0 ; i < LON && !terminar ; i ++ ) {
		
	
		do {
			
			cout << "Introduzca una orden: ";
			getline ( cin , instruccion );
			
			longitud = instruccion.length();
		
			casilla = 0;
			
			// Eliminará los espacios previos al número
			
			while (isspace(instruccion.at(casilla)) && casilla < longitud ) {
				
				casilla++;
			}
			
			string sin_espacios;
			
			sin_espacios = instruccion.substr(casilla);
			
			// Eliminará los espacios posteriores al número
			
			while (longitud > 0 && isspace(sin_espacios.back())) {
				
				sin_espacios.pop_back();
				longitud = sin_espacios.length();
				
			}
	        
			instruccion = sin_espacios;
			
			longitud = instruccion.length();
			
			for ( int i = 0 ; i < longitud ; i ++ )
				
				instruccion.at(i) = toupper ( instruccion.at(i) );
			
			Es_Valido = ( instruccion == IZQ || instruccion == DERE
				|| instruccion == TERMINADOR );
			
			if ( !Es_Valido ) cout << "¡ERROR! ";
			
		} while ( !Es_Valido );
				
		final = instruccion.at(0);
				
		ordenes[i] = final;					
			
		if ( ordenes[i] == TERM ) terminar = true;
		
		else util ++;
		
	}
	
	
	// Cálculos
	
	int ordenes_hechas = 0;
	terminar = false;
	
	for ( int i = 0 ; i <= util && !terminar ; i++ )  {
	
		posiciones[pos] ++ ;
		
		if ( ordenes[i] == DERECHA ) pos ++;
		
		else pos --;
	
		if ( pos < MIN || pos > MAX ) terminar = true;
		
		else ordenes_hechas ++;
		
	}
	
	// Salida de resultados
	
	if ( terminar ) {
		
		cout << endl << endl,
		cout << "¡SECUENCIA DE ORDENES INCORRECTA!" << endl;
		cout << "\tOrdenes realizadas: " << ordenes_hechas;
		
	}
	
	else {
		
		cout << endl << endl,
		cout << "SECUENCIA DE ORDENES CORRECTA" << endl;
		cout << "\tOrdenes realizadas: " << ordenes_hechas << endl;
		cout << "\tPosicion final = " << pos << endl;
		cout << "\tPosiciones utilizadas ( [Posicion , Veces ] ):" << endl;
		
		for ( int i = MIN ; i <= MAX ; i ++ ) {
			
			if ( posiciones[i] > 0 )
				
				cout << "[ " << i << " , " << posiciones[i] << " ]  ";
				
		}
		
	}
		
	
	
	return 0;
	
}
	






