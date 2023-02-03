/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 29. N�5.
// V_MatrizAleatoria_2.cpp: escribe un programa que genere una matriz
// de valores aleatorios comprendidos entre un rango y muestre m�s tarde
// la frecuencia relativa de cada uno de ellos
//
//Entrada: --------------
//Salida: matriz aleatoria, frecuencia de cada valor, su frec. relativa y
// verificaci�n de la integridad.
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cctype>
#include <cmath>        // Inclusi�n de los recursos matem�ticos
#include<ctime>
#include<cstdlib>

using namespace std;

// Declaraci�n del tipo "struct Pos_Valores", el cual recoger� el valor en s�,
// su frecuencia absoluta en la matriz y la relativa.

struct Pos_Valores {
	
	int valor;    		//PRE: MIN_VALOR <= valor <= MAX_VALOR
	int frec_abs;		//PRE: frec_abs >= 0
	double frec_relat;  //PRE: 0 <= frec_relat <= 100 (%)
	
};


int main ()					// Funci�n principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	// Declaraci�n de constantes
	
	const int NUM_FILAS = 5;
	const int NUM_COLUM = 5;
	const int NUM_VALORES = NUM_FILAS * NUM_COLUM;
	const int MIN_VALOR = 4;
	const int MAX_VALOR = 10;
	const int VALORES = MAX_VALOR - MIN_VALOR;
	
	// (No existe entrada de datos)
	
	// C�lculos
	
	int matriz_al[NUM_FILAS][NUM_COLUM];
	int valor_al;
	
	Pos_Valores valores[VALORES];	// Array con todos los valores y sus
									// frecuencias absolutas
	
	for ( int i = 0; i < VALORES ; i ++ )
		
		valores[i].valor = MIN_VALOR + i;
		
		
	for ( int i = 0 ; i < NUM_FILAS ; i ++ ) {
		
		for ( int j = 0 ; j < NUM_COLUM ; j ++ ) {
			
			valor_al = (rand() % VALORES) + MIN_VALOR;
			valores[valor_al - MIN_VALOR].frec_abs ++;
			
			matriz_al[i][j] = valor_al;
			
		}
			
	}
	
	// Para comprobar la integridad, sumar� todas las frec. absolutas y
	// calcular� las frec. relativas.
	
	int suma = 0;
	
	for ( int i = 0; i < VALORES ; i ++ ) {
		
		valores[i].frec_relat = valores[i].frec_abs * 100.0 / NUM_VALORES;
		suma += valores[i].frec_abs;
	
	}
	
	// Salida de resultados
	
	cout << "Generando valores entre " << MIN_VALOR << " y " << MAX_VALOR;
	cout << ":" << endl << endl;
	
	cout << "Matriz de valores: " << endl;
	
	for ( int i = 0; i < NUM_FILAS ; i ++ ) {
		
		cout <<"\t";
		
		for ( int j = 0; j < NUM_COLUM ; j++ ) 
			
			cout << setw(4) << matriz_al[i][j];
			
		cout << endl;
		
	}
	
	cout << endl;
	
	if ( suma == NUM_VALORES ) cout << "Integridad verificada" << endl;
	
	cout << endl;
	
	cout << "Repeticiones: " << endl;
	
	for ( int i = 0 ; i < VALORES ; i ++ ) {
		
		cout << setw(3) << valores[i].valor << ":";
		cout << setw(6) << valores[i].frec_abs;
		cout << setw(8) << setprecision(2) << valores[i].frec_relat << "%";
		cout << endl;
		
	}
	
	return 0;
	
}
	
		
	
			
	
	
