/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 29. Nº5.
// V_MatrizAleatoria_1.cpp: escribe un programa que genere una matriz
// de valores aleatorios
//
//Entrada: --------------
//Salida: intentos en cada casilla, media de intentos, valores de la matriz
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cctype>
#include <cmath>        // Inclusión de los recursos matemáticos
#include<ctime>
#include<cstdlib>

using namespace std;

// Declaración del tipo "struct Casilla ", que guardará el valor de cada
// casilla y los intentos que se han requerido para asignarle un valor
// aleatoriamente.

struct Casilla {
	
	int valor;				//PRE: 1 <= valor <= NUM_FILAS * NUM_COLUM
	int intentos;			//PRE: 0 < intentos
	
};

int main ()					// Función principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	// Declaración de constantes.
	
	const int NUM_FILAS = 5;
	const int NUM_COLUM = 5;
	const int NUM_VALORES = NUM_FILAS * NUM_COLUM;
	const int VALOR_MIN = 1;
	
	// Declaración de la matriz
	
	Casilla matriz_al[NUM_FILAS][NUM_COLUM] = {{0,0}};
	
	// (No existe entrada de datos)
	
	// Cálculos
	
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de núms. aleatorios
						// con el reloj del sistema (hora actual)
	
	int valor;
	bool coincide;
	
	for ( int i = 0; i < NUM_FILAS; i++ ) {
		
		
		for ( int j = 0; j < NUM_COLUM; j++ ) {
			
			do {
				
				coincide = false;
				
				valor = (rand() % NUM_VALORES) + VALOR_MIN; // Asigna a "valor" 
													// un num aleatorio entre
													// los buscados.
				
				for ( int k = 0 ; k <= i && !coincide ; k++ ) {
					
					for ( int h = 0 ; h < NUM_COLUM && !coincide ; h++)
						
						if ( valor == matriz_al[k][h].valor ) coincide = true;
					
				}
				
				if ( coincide ) matriz_al[i][j].intentos ++;
				
				else {
					
					matriz_al[i][j].valor = valor;
					matriz_al[i][j].intentos ++;
					
				}
					
			} while ( coincide );
			
		}
		
	}
	
	int intentos_totales = 0;
	
	for ( int i = 0; i < NUM_FILAS ; i ++ ) {
		
		for ( int j = 0; j < NUM_COLUM ; j++ ) 
			
			intentos_totales += matriz_al[i][j].intentos;
					
	}
	
	double media = intentos_totales * 1.0 / NUM_VALORES;
	
	// Salida de resultados
	
	cout << "Intentos para alojar los valores:" << endl;
	
	for ( int i = 0; i < NUM_FILAS ; i ++ ) {
		
		for ( int j = 0; j < NUM_COLUM ; j++ ) 
			
			cout << setw(3) << matriz_al[i][j].intentos;
			
		cout << endl;
		
	}
	
	cout << endl;
	cout << "Intentos totales" << setw(8) << intentos_totales << endl;
	cout << "Media           " << setw(8) <<setprecision(3) << media;
	cout << endl << endl;
	
	cout << "Matriz de valores:" << endl;
	
	for ( int i = 0; i < NUM_FILAS ; i ++ ) {
		
		cout <<"\t";
		
		for ( int j = 0; j < NUM_COLUM ; j++ ) 
			
			cout << setw(4) << matriz_al[i][j].valor;
			
		cout << endl;
		
	}
	
	return 0;
	
}
			
			
	
