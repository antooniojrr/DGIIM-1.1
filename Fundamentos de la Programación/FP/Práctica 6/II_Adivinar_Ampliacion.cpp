/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº47.
//II_Adivinar_Ampliacion.cpp: escribe un programa que calcule un número
//aleatorio entre el 1 y el 100 para jugar a adivinarlo. Además, dará la
//posibilidad de jugar de nuevo al terminar.
//
//Entrada: números para intentar averiguar el aleatorio
// 			(Al terminar) SI (Para jugar de nuevo) o NO (Para finalizar)
//Salida: número aleatorio e indicaciones (Mayor o menor)
//
/************************************************************************/

#include <iostream>    //Inclusión de los recursos de E/S
#include <iomanip>     // Formato 
#include <string>      //Inclusión del tipo string
#include<ctime>
#include<cstdlib>

using namespace std;

int main ()
{
	
	// Constantes
	
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX-MIN + 1; // Número de valores posibles
	const int TERMINADOR = -1;
	const string AFIRM = "SI";
	const string NEGAT = "NO";
	
	
	// La modularización E/C/S del programa se realizará dentro del bucle
	// principal
	
	time_t t;
	srand(time(&t)); 	// Inicializa el generador de núms. aleatorios
						// con el reloj del sistema (hora actual)
	int incognita; 		// Número aleatorio que se genera
	
	int intento;
	bool terminar = false;
	bool fin;
	string si_no;
	
	cout << "Cuando quiera dejar de jugar introduzca el valor \"-1\" ";
	cout << endl;
		
	do {
		
		incognita = (rand() % NUM_VALORES) + MIN; //Cálculo de número
												  //aleatorio
		
		cout << "CALCULADO NUMERO ALEATORIO ENTRE EL 1 Y EL 100. AVERIGUALO";
		cout << endl;
	
		while ( !terminar ) {
			
			// Entrada de datos
			
			do {
			
				cout << "Introduzca un valor valido: ";
				cin >> intento;
			
			}while ((intento < MIN || intento > MAX) && intento != TERMINADOR);
			
			// Cálculos y salida
			
			if ( intento == TERMINADOR ) {
				
				cout << "JUEGO TERMINADO" << endl;
				terminar = true;
				
			}
			
			else if ( intento < incognita ) 
				
				cout << "El numero es mayor que " << intento << endl;
				
			else if ( intento > incognita )
			
				cout << "El numero es menor que " << intento << endl;
				
			else if ( intento == incognita ) {
				
				cout << "¡ENHORABUENA! Ha averiguado el numero." << endl;
				terminar = true;
				
			}
			
		}
		
		do {
			
			cout << "¿Quiere volver a jugar? Introduzca \"SI\" o \"NO\": ";
			cin >> si_no;
			
		} while ( si_no != AFIRM && si_no != NEGAT );
		
		if (si_no == AFIRM ) {
			
			fin = false;
			terminar = false;
			cout << endl << endl;
			
		}
			
		
		else fin = true;       //En caso de que diga "NO"
		
	}while ( !fin );
	
	return 0;
	
}
		
		
	
	
		
	
	
	
	
	
	
	
	
	
	
	
 
