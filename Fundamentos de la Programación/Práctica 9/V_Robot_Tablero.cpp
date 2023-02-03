/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 29. N�5.
// V_Robot_Tablero.cpp: escribe un programa que registre una posici�n inicial
// del robot, una serie de instrucciones y muestre el recorrido de este
// por un tablero.
//
//Entrada: posici�n inicial e instrucciones.
//Salida: mapa del tablero y si la secuencia de instrucciones es v�lida
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cmath>        // Inclusi�n de los recursos matem�ticos

using namespace std;

// Declaraci�n de dato "struct Posicion2D".

struct Posicion2D {
	
	int fila;		//PRE: 1 <= fila <= 10
	int columna;	//PRE: 1 <= columna <= 10
	
};


// Declaraci�n de constantes

const char DERECHA = 'D';
const char IZQUIERDA = 'I';
const char ARRIBA = 'A';
const char ABAJO = 'B';
const int MINIMO = 1;
const int MAXIMO = 10;
const int NUM_FILASyCOLUM = MAXIMO - MINIMO + 2;
const int TOPE = 100;

/************************************************************************/
//
// Funci�n para eliminar los primeros espacios de un string.
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
// Funci�n para eliminar los �ltimos espacios de un string.
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
// Funci�n para eliminar todos los espacios de un string.
//
// Entrada: cadena de caracteres.
// Salida: cadena sin espacios.
//
/************************************************************************/

string EliminaSeparadores (string cadena)
{	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

/************************************************************************/

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
		
		if ( longitud == 0 ) Es_Valido = false;
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ ) {
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
			
			else if ( stoi(num) > max || stoi(num) < min ) Es_Valido = false;
			
		}
			
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}

/************************************************************************/

/************************************************************************/
// Funci�n para comprobar que una secuencia de ordenes es valida, es decir,
// que todos los caracteres de la cadena son apropiados ( D, I, A o B ).
//
// Entrada: cadena de ordenes
// Salida: "true" o "false"
/************************************************************************/

bool ord_correctas ( string cad_ordenes ) {
	
	bool correcta = true;
	int longitud = cad_ordenes.length();
	char c;
	
	for ( int i = 0; i < longitud && correcta ; i++ ) {
		
		c = cad_ordenes.at(i);
		
		if ( c != 'A' && c != 'B' && c != 'D' && c != 'I' ) correcta = false;
		
	}
	
	return correcta;
	
}

/************************************************************************/
// Funci�n para comprobar que una posici�n del robot es correcta, es decir,
// se encuentra dentro del tablero
//
// Entrada: dato tipo Posicion2D
// Salida: "true" o "false"
/************************************************************************/

bool PosValida ( Posicion2D pos ) {
	
	return ( pos.columna >= MINIMO && pos.columna <= MAXIMO 
			&& pos.fila >= MINIMO && pos.fila <= MAXIMO );
			
}

/************************************************************************/

int main ()					// Funci�n principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	// Entrada de datos
	
		// Posici�n inicial
	cout << "----------|INTRODUZCA LA POSICION INICIAL DEL ROBOT|----------";
	cout << endl << endl;
	
	string titulo_fila = "\tNumero de fila ( 1 <= n <= 10 ) = ";
	string titulo_columna = "\tNumero de columna ( 1 <= n <= 10 ) = ";
	Posicion2D pos_inicial;
	
	pos_inicial.columna = LeeEnteroEnRango ( titulo_columna, MAXIMO, MINIMO );
	
	pos_inicial.fila = LeeEnteroEnRango ( titulo_fila, MAXIMO, MINIMO );
	
	
	
		// Instrucciones
	
	string cad_ordenes;
	cout << "----------|INTRODUZCA LAS INSTRUCCIONES A SEGUIR|----------" ;
	cout << endl << endl;
	
	cout << "Introduzca ( seguidas ) todas las instrucciones que seguir� el";
	cout << " robot, teniendo en cuenta que: " << endl;
	cout << "\tARRIBA    ------> 'A'" << endl;
	cout << "\tABAJO     ------> 'B'" << endl;
	cout << "\tDERECHA   ------> 'D'" << endl;
	cout << "\tIZQUIERDA ------> 'I'" << endl << endl;
	
	do {
		
		cout << "SECUENCIA DE ORDENES: ";
		getline ( cin, cad_ordenes );
		
		cad_ordenes = EliminaSeparadores (cad_ordenes);
		
		for ( int i = 0 ; i < cad_ordenes.length() ; i++ ) 
		
			cad_ordenes.at(i) = toupper(cad_ordenes.at(i));
		
	} while ( !ord_correctas(cad_ordenes) );
	
	int lon = cad_ordenes.length();  // N�mero de componentes �tiles del
									 // array "ord".
	
	// C�LCULOS
	
	Posicion2D pos = pos_inicial;
	
	int cont_posiciones[NUM_FILASyCOLUM][NUM_FILASyCOLUM] = {0};
	
	string posiciones[NUM_FILASyCOLUM][NUM_FILASyCOLUM] = { "." };
	
	for ( int i = 0 ; i <= MAXIMO ; i ++ ) {
		
		posiciones[0][i] = ":";
		
		for ( int j = 1 ; j <= MAXIMO ; j ++ )
			
			posiciones[j][i] = ".";
			
	}
	
	char ord[TOPE];
	
	for ( int i = 0 ; i < lon ; i++ )
		
		ord[i] = cad_ordenes.at(i);
	
	int ord_hechas = 0;
	bool valido = true;     // Servir� para determinar cuando el robot se
							// saldr�a del tablero.
							
	while ( ord_hechas <= lon && valido ) {
	
		cont_posiciones[pos.columna][pos.fila] ++;
		
		posiciones[pos.columna][pos.fila] = 
							to_string(cont_posiciones[pos.columna][pos.fila]);
		
		switch ( ord[ord_hechas] ) {
			
			case (DERECHA):
			
				pos.columna ++;
				break;
			
			case (IZQUIERDA):
				
				pos.columna --;
				break;
				
			case (ARRIBA):
				
				pos.fila ++;
				break;
			
			case (ABAJO):
				
				pos.fila --;
				break;
			
		}
		
		if ( !PosValida (pos) ) valido = false;
		
		else ord_hechas ++;
		
	}
	
	
	// S�lida de resultados
	
	cout << endl << endl;
	cout << "---------------------|RESULTADOS|---------------------" << endl;
	cout << endl;
	
	cout << "VALORES INICIALES:" << endl << endl;
	cout << "\tPosicion inicial = [ " << pos_inicial.columna << " , ";
	cout << pos_inicial.fila << " ] " << endl;
	cout << "\tOrdenes =  " << cad_ordenes << endl << endl;
	cout << "--------------------------------------";
	cout << endl << endl;
	
	if ( valido ) {
		
		cout << "\tLa serie de ordenes es: correcta" << endl;
		cout << "\tSe ejecutaron " << lon << " ordenes." << endl << endl;
		
		
	}
	
	else {
		
		cout << "\tLa serie de ordenes es: incorrecta" << endl;
		cout << "\tSe ejecutaron " <<ord_hechas << " ordenes." << endl << endl;
		
	}
	
	cout << "    :";
		
	for ( int i = MINIMO ; i <= MAXIMO ; i ++ ) 
		
		cout << setw(3) << i;
	
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	
	for ( int i = 0 ; i < MAXIMO ; i ++ ) {
		
		cout << setw(3) << MAXIMO - i << " :";
		
		for ( int j = MINIMO ; j <= MAXIMO ; j ++ )
			
			cout << setw(3) << posiciones[j][MAXIMO - i];
		
		cout << " :" << setw(3) << MAXIMO - i << endl;
		
	}
	
	cout << "---------------------------------------------------" << endl;
	
	cout << "    :";
	
	for ( int i = MINIMO ; i <= MAXIMO ; i ++ ) 
		
		cout << setw(3) << i;
	
	cout << " :";
	cout << endl;
	
	return 0;
	
}

		
		


