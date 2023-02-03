/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�76.
//II_Secuenciable.cpp: escribe un programa que indique el n�mero de
//descomposiciones posibles de un entero positivo en suma de secuencias de
//enteros.
//
//Entrada: n�mero a descomponer
//Salida: n�mero de descomposiciones posibles
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato
#include <cmath>       //Inclusi�n de los recursos matem�ticos

using namespace std;

//Funci�n sumatorio (Para calcular la suma de secuencias)

int sum (int inicio, int fin) {
	
	int suma;
	
	suma = ( fin * ( fin + 1 ) / 2 ) - ( (inicio - 1) * inicio / 2 );
	
	return suma;
	
}



int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Entrada de valores
	
	int numero;
	
	do {
		
		cout << "Introduzca un numero entero positivo a descomponer: ";
		cin >> numero;
		
	}while (numero <= 0 );
	
	// C�lculos
	
	int descomp = 0;
	
	int num_final = 2, num_inicial;
	
	if ( log2(numero) - (int)log2(numero) != 0 ) {
		
		while ( num_final < numero ) {
			
			num_inicial = 1;
			
			while ( num_inicial < num_final ) {
				
				if ( sum ( num_inicial, num_final) == numero )
					
					descomp ++;
								
				num_inicial ++;
				
				
			}
			
			num_final ++;
			
		}
		
	}
	
	//Salida de resultados
	
	cout << endl;
	cout << "\t" <<numero <<" tiene " <<descomp <<" descomposiciones posibles";
	
	return 0;
	
}
		
		
		
		
		
		
		
	
