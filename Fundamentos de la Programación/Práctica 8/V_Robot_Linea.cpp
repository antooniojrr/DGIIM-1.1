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

// Declaración de constantes

const string TERMINADOR = "FIN";
const char DERECHA = 'D';
const string DERE = "D";
const string IZQ = "I";
const char IZQUIERDA = 'I';
const char TERM = 'F';

/************************************************************************/
//
// Función para eliminar los primeros espacios de un string.
//
// Entrada: cadena de caracteres.
// Salida: cadena sin espacios al principio.
//
/************************************************************************/

string EliminaPrimerosSeparadores (string cadena)
{
	int posicion = 0;
	int tamanio = cadena.length();
	
	while (isspace(cadena.at(posicion)) && posicion < tamanio) {
		
		posicion++;
	}
	
	string local;
	while (posicion < tamanio) {
		local.push_back(cadena.at(posicion));
		posicion++;
	}
		
	return local;
}

/************************************************************************/
//
// Función para eliminar los últimos espacios de un string.
//
// Entrada: cadena de caracteres.
// Salida: cadena sin espacios al final.
//
/************************************************************************/


string EliminaUltimosSeparadores (string cadena)
{
	int longitud = cadena.length();
	
   	while (longitud > 0 && isspace(cadena.back())) {
		cadena.pop_back();
		longitud = cadena.length();
	}
        
	return cadena;
}

/************************************************************************/
//
// Función para eliminar todos los espacios de un string.
//
// Entrada: cadena de caracteres.
// Salida: cadena sin espacios.
//
/************************************************************************/

string EliminaSeparadoresTotales (string cadena)
{	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

/************************************************************************/

/************************************************************************/
//
// Función para leer las instrucciones del robot ( I o D ). Servirá también
// filtro por si se introducen valores no válidos. Aceptará también un
// terminador para dejar de lee instrucciones ( "FIN" )
//
// Entrada: título a mostrar.
// Salida: instrucción o terminador ( En forma de char: 'F' )
//
/************************************************************************/

char LeerInstruccion ( string titulo ) {
	
	string instruccion;
	bool Es_Valido;
	int longitud;
	
	do {
		
		cout << titulo;
		getline ( cin , instruccion );
		
		instruccion = EliminaSeparadoresTotales (instruccion);
		
		longitud = instruccion.length();
		
		for ( int i = 0 ; i < longitud ; i ++ )
			
			instruccion.at(i) = toupper ( instruccion.at(i) );
		
		Es_Valido = ( instruccion == IZQ || instruccion == DERE
			|| instruccion == TERMINADOR );
		
		if ( !Es_Valido ) cout << "¡ERROR! ";
		
	} while ( !Es_Valido );
			
	char final = instruccion.at(0);
			
	return final;
	
}

/************************************************************************/

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
		
		num = EliminaSeparadoresTotales (num);
		Es_Valido = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
			
		if ( Es_Valido && ( stoi(num) > max || stoi(num) < min ) )
		
			Es_Valido = false;
		
		if ( !Es_Valido ) cout << " ¡ERROR! ";
			
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}

/************************************************************************/

int main ()                           // Programa principal
{

	// Declaración de constantes
	
	const int LON = 20;
	const int POSICIONES = 101;    // El primer elemento del array será la
								   // pos 0 ( No valida ya que 1 <= pos <= 100)
	const int MAX = 100;
	const int MIN = 1;
	
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
	pos = LeeEnteroEnRango ( titulo, MAX, MIN );
	cout << endl << endl;
	bool terminar = false;
	
	for ( int i = 0 ; i < LON && !terminar ; i ++ ) {
		
		ordenes[i] = LeerInstruccion ( "Introduzca una orden: " );
		
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
	
