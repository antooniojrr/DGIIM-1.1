/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº47.
//II_Descomposicion_Factores_Primos.cpp: escribe un programa que descomponga
//un entero en sus factores primos y los exprese de dos formas distintas.
//
//Entrada: número a descomponer
//Salida: descomposición
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>    // Formato
#include <cmath>       //Inclusión de los recursos matemáticos
#include <string>      //Inclusión del tipo string

using namespace std;

string descomponer (int numero)     //1er método para descomponer el num.
{									// Entrada: número a descomponer
									// Salida: descomposición en "string"
	
	string factores;
	int factor = 1;
	bool primer_factor = true;
	
	if ( numero == 0 ) factores = "0 no tiene factores primos";
	
	else {
		
		do {
		
			if ( numero % factor == 0 ) {
	
				if (!primer_factor) factores = factores + "* ";				
				
				factores = factores + to_string(factor) + " ";
				
				numero = numero / factor;
				
				if (primer_factor) {
					
					primer_factor = false;
					factor ++;
					
				}
					
			}
			
			else factor ++;
			
			
		} while (numero > 1);
		
	}
	
	return (factores);
	
}

string descomponer2 (int numero)     //2º método para descomponer el num.
{									 // Entrada: número a descomponer
									 // Salida: descomposición en "string"
	string factores;
	int factor = 2;
	bool primer_factor = true;
	bool ultimo_factor = false;
	int exponente = 0;
	
	if ( numero == 0 ) factores = "0 no tiene factores primos";
	
	else {
		
		do {
			
			if ( numero == 1 ) ultimo_factor = true;
			
			if ( numero % factor == 0 ) {
	
				exponente ++;
				
				numero = numero / factor;
				
			}
			
			else {
				
				if (exponente != 0) {
					
					if (!primer_factor) factores = factores + "* ";
				
					else primer_factor = false;				
					
					factores = factores + to_string(factor) + "^";
					factores = factores + to_string(exponente) + " ";
					
					exponente = 0;
					
				}
				
				factor ++;
					
			}
			
			
			
			
		} while ( numero > 1 || ultimo_factor == false );
		
	}
	
	return (factores);
	
}
	
		

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Entrada de valores
	
	int entero;
	string descomposicion, descomposicion2;
		
	do {
		
		cout << "Introduzca un numero entero positivo para descomponer: ";
		cin >> entero;
		
	} while ( entero < 0 );
	
	//Cálculos
	
	descomposicion = descomponer( entero );
	
	descomposicion2 = descomponer2 ( entero );
	
	//Salida de datos
	
	if ( entero == 0 ) cout << "\t" << descomposicion;
		
	else {
		
		cout << "\t" << entero << " = " << descomposicion << endl;
		
		cout << "\t" << entero << " = " << descomposicion2 << endl;
		
	}
	
	return 0;
	
}
		
		
	
	
	
	
	
	
	
	
	
	
