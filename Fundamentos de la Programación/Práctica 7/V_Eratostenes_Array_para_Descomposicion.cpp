/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 15. N�5.
// V_Eratostenes_Array_para_Descomposicion.cpp: escribe un programa que 
// descomponga un n�mero indefinido de veces un entero positivo que se le
// introduzca usando la Criba de Eratostenes para averiguar los primeros
// primos
//
//Entrada: n�meros a descomponer
//Salida: descomposici�n en factores primos
//
/************************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cmath>        // Inclusi�n de los recursos matem�ticos

using namespace std;

/************************************************************************/

// Declaraci�n del tipo de datos "struct Pareja"
//
// PRE: ambos componentes de Pareja ser�n enteros positivos.

struct Pareja {
	
	int primo;
	int potencia;
	
};
/************************************************************************/

/************************************************************************/
// Funci�n para leer un entero mayor o igual que una referencia,
// sirviendo esta de filtro. Pedir� un n�mero hasta que se le introduzca
// uno correcto.
//
// Entrada: t�tulo a mostrar, referencia.
// Salida: n�mero entero mayor o igual a referencia.
/************************************************************************/

int LeeEnteroPositivo ( string titulo )
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
		
		if ( stoi(num) < 0 ) Es_Valido = false;
		
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}
/************************************************************************/

/************************************************************************/
// Funci�n para expresar la descomposici�n de un n�mero en pantalla
//
// Entrada: descomposici�n y n�mero de factores
// Salida: descomposici�n escrita por pantalla
//
// PRE: descomposicion debe ser un array de tipo Pareja
/************************************************************************/

void Expresa_Descomp ( Pareja descomposicion[], int factores ) {
	
	cout << " = ";
	
	for ( int i = 0 ; i < factores ; i++ ) {
		
		cout << "( " << descomposicion[i].primo;
		cout  << " ^ " << descomposicion[i].potencia << " )";
		
		if ( i < factores - 1 ) cout << " * ";
		
	}
	
}





int main ()									// Funci�n principal
{
	
	// Declaraci�n de constantes
	
	const int CASILLAS_DESCOMPOSICION = 50;
	const int MAX_PRIMO = 5000;
	const int PRIMER_PRIMO = 2;
	
	// Declaraci�n del array
	
	Pareja descomposicion[CASILLAS_DESCOMPOSICION] ;
	
	// Criba de Erat�stenes para averiguar los primeros n�meros primos
	
	bool son_primos [MAX_PRIMO];
	
	for ( int i = 0 ; i < MAX_PRIMO ; i++ ) 
		
		son_primos[i] = true;
	
	son_primos[0] = son_primos[1] = false;
	
	for ( int i = PRIMER_PRIMO ; i < MAX_PRIMO ; i ++ ) {
		
		if ( son_primos[i] ) {
			
			for ( int j = PRIMER_PRIMO ; ( j * i ) < MAX_PRIMO ; j ++ )
			
				son_primos [ (j*i) ] = false;
			
		
		}
		
	}
	
	// Entrada de valores
	
	int entero;
	int pos_factores;
	int divisor;
	
	entero = LeeEnteroPositivo ( "Introduzca un numero a descomponer: ");
	
	while ( entero != 0 ) {
		
		for ( int i = 0; i < pos_factores ; i ++ ) {
			
			descomposicion[i].potencia = 0;
			descomposicion[i].primo = 0;
			
		}
		
		pos_factores = 0;
		divisor = entero;
		
		// C�lculos
		
		for ( int i = PRIMER_PRIMO ; i <= entero && divisor != 1 ; i ++ ) {
			
			if ( son_primos[i] && divisor % i == 0 ) {
				
				while ( divisor % i == 0 ) {
					
					descomposicion[pos_factores].primo = i;
					descomposicion[pos_factores].potencia ++;
					divisor = divisor / i;
					
				}
				
				pos_factores ++;
			
			}		
				
		}
		
		// Salida de resultados
		
		cout << "\t---> " << entero;
		Expresa_Descomp ( descomposicion, pos_factores );		
		
		// Entrada de datos
		
		cout << endl;
		entero = LeeEnteroPositivo ( "Introduzca un numero a descomponer: ");
			
	}
		
	
	return 0;
	
	
}
		
		
	
	
	
	













