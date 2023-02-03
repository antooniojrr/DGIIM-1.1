/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 29. Nº5.
// V_Histograma_Letras.cpp escribe un programa que realice un histograma
// completo de todas las letras del alfabeto español a partir de un texto.
//
//Entrada: texto
//Salida: histograma en forma de matriz
//
/************************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cctype>
#include <cmath>        // Inclusión de los recursos matemáticos
#include <clocale>  

using namespace std; 

/***************************************************************************/
// Devuelve "true" si "c" es un caracter especial del alfabeto español
//
/***************************************************************************/

bool EsCaracterEspecialEspaniol (unsigned char c) 
{
	
	return (c==225  ||c==160 ||c==161 ||c==162 ||c==163  || c==129 || c==154 || 
				c==164 || c==165 ||  c==233 || c==237 || c==243 || c==250 || 
				c==241 || c==193 || c==201 || c==205 || c==211 || c==218 || 
				c==209 || c==252);
}

/***************************************************************************/
// Convierte un carácter especial "c" a su equivalente estándar
//
//
// Si "c" no requiere transformación devuelve el mismo valor

/***************************************************************************/

char TransformaCaracterEspecialEspaniol (unsigned char c) 
{
	char nuevo; 
	
	switch (c) {
		
		case (225) : 
		case (160) : 
		case (193) : nuevo = 'a'; 
					 break; 
		case (233) : 
		case (201) : nuevo = 'e'; 
					 break; 
		case (237) :
		case (161) :  
		case (205) : nuevo = 'i'; 
					 break; 
		case (243) :
		case (162) :  
		case (211) : nuevo = 'o'; 
					 break; 
		case (250) : 
		case (218) : 
		case (129) : 
		case (154) :  
		case (163) : 
		case (252) : nuevo = 'u'; 
					 break; 
		case (241) : 
		case (164) : 
		case (165) :
		case (209) : nuevo = 'n'; 
					 break;
					 
					 
		default: 	nuevo = c; 
					break; 		 	
	}
	
	return (nuevo);
}

/***************************************************************************/

int main ()					// Programa principal
{ 		

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	

	const char TERMINADOR = '*';

	// Numero de caracteres a considerar
	
	const int NUM_CARACTERES = 'z'-'a'+1;
	
	// Letras a procesar
	
	char letras [NUM_CARACTERES];
	
	int contador_letras[NUM_CARACTERES] = {0}; 	// Array para contar las
												// veces que se repite cada
												// letra, se inicia a 0


	// Dimensiones de la matriz que representará el histograma
	
	const int NUM_FILAS = 500; // Núm. de filas
	
	const int NUM_COLS = NUM_CARACTERES; // Núm. de columnas
	
	char histograma [NUM_FILAS][NUM_COLS] = {' '}; //Se inicializa vacío 
		
	
	// Rellenar las_letras con la letra correspondiente
	
	char letra = 'a';
	
	for( int i = 0 ; i < NUM_CARACTERES ; i ++ ) {
		
		letras[i]= letra;
		letra++;
		
	}

	char c;
	
	// Datos de entrada
	
	c = cin.get();    // Lectura anticipada 
	
	while (c!= TERMINADOR){
		
		if ( isalpha(c) ) {  // Comprobará primero si se trata de una letra
			
			if (EsCaracterEspecialEspaniol(c))
			
				c = TransformaCaracterEspecialEspaniol(c);
			
			for( int pos = 0 ; pos < NUM_CARACTERES ; pos ++ ) {
				
				if(letras[pos] == tolower(c) )
				
					contador_letras[pos]++;
					
			}
			
		}
		
		c = cin.get();
		
	}
	cout << endl << endl;
	
	
	// Cálculos
	
	// Encontrará la letra más repetida y cuantas veces se repite
	
	int max_repeticiones = 0;
	int posicion;
	
	for( int i = 0; i < NUM_CARACTERES; i ++ ) {
		
			if( contador_letras[i] > max_repeticiones ) {
				
				max_repeticiones = contador_letras[i];
				posicion = i;
				
			}
	}
	
	// Rellenará la matriz "histograma"
	
	int num_rep = 1; // numero de veces que se repiten 
	
	for ( int i = 0; i < max_repeticiones; i++ ) {
		
		for ( int j = 0 ; j < NUM_COLS ; j ++ ) {
			
			if ( contador_letras[j] >= num_rep )
			
				histograma[i][j] = '*';
					
			else
			
				histograma[i][j] = '.';
				
		}
		
		num_rep++;	
		
	}
	
	// Mostramos la matriz 
	
	const int NUM_VALORES_FILA = 5;
	int linea = 0;
	
	for(int i = (max_repeticiones - 1) ; i >= 0 ; i-- ) { 
	
	// Comenzaremos a "imprimir" la matriz desde el final.
														
		if( ( (i % NUM_VALORES_FILA) == 0) && (i != 0) ) {
			
			linea = i;
			
			cout << setw(2) << linea / NUM_VALORES_FILA;
			
		}
		
		else
		
			cout << "  ";
			
		for ( int j = 0 ; j < NUM_COLS; j++ )
			cout << setw(4) << histograma[i][j];	
		cout << endl;
	}
	
	cout << "  " ;
	
	// Mostrará las letras en el eje x del histograma
	 
	for ( int i = 0; i < NUM_CARACTERES ; i++ )
	
		cout << "   "  << letras[i];
	
	
	cout << endl << endl;

	
	return 0;
}
