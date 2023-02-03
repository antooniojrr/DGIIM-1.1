/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 5. Nº3.
//V_Media_y_Comparar_ArraysInt.cpp: escribe un programa que asigne un número
//indeterminado de datos enteros a una estructura "array", haga la media de
//todos ellos y más tarde la compare con otro vector.
//
//Entrada: componentes de dos "arrays" de datos enteros
//Salida: media de todos los valores y comparación de ambos vectores
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

/************************************************************************/
// Función para leer un entero, sirviendo esta de filtro. Pedirá un número
// hasta que se le introduzca uno correcto.
//
// Entrada: título a mostrar en pantalla a la hora de pedir el número.
// Salida: número entero.
//
// PRE: modificado para aceptar y devolver el terminador aunque no sea entero.
/************************************************************************/

// Declaración de constantes globales

const string TERMINADOR = "FIN";
	
string LeeEntero ( string titulo)
{

	// Declaración de variables
	
	string num;
	bool Es_Entero;
	int longitud;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Entero = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ;
			pos <= longitud - 1 && Es_Entero && num != TERMINADOR ; pos ++ )
			
			if (num.at(pos) > '9' || num.at(pos) < '0') {
				
				for ( int i = 0 ; i < longitud ; i ++ )
					
					num.at(i) = toupper(num.at(i));
				
				if ( num != TERMINADOR ) Es_Entero = false;
			
			}
			
	} while ( !Es_Entero );
	
	return num;
	
}


/************************************************************************/

int main ()
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Declaración de constantes
	
	const int TOPE = 100;     //Tope arbitrario
	const string TITULO = "Introduzca un valor: ";
	
	// Declaración de "arrays"
	
	int array1 [TOPE];
	int array2 [TOPE];
	
	bool terminar = false;
	string valor;
	int util1;
	
	// Entrada de datos.
	
	cout << "TECLEE FIN CUANDO DESEE FINALIZAR EL ARRAY" << endl;
	cout << "-----------------------|ARRAY 1|-----------------------" << endl;
	cout << endl;
	
	for ( int i = 0 ; i < TOPE && !terminar ; i ++ ) {
		
		valor = LeeEntero ( TITULO );
		
		if ( valor == TERMINADOR ) {
			
			terminar = true;
			util1 = i;               // Util será el número de componentes 
		}							// en los que se ha guardado un dato.
		
		else		
			
			array1[i] = stoi(valor);
			
	}
	
	cout << endl;
	cout << "-----------------------|ARRAY 2|-----------------------" << endl;
	cout << endl;
	
	int util2;
	valor = "";
	terminar = false;
	
	for ( int i = 0 ; i < TOPE && !terminar ; i ++ ) {
		
		valor = LeeEntero ( TITULO );
		
		if ( valor == TERMINADOR ) {
			
			terminar = true;
			util2 = i;               // Util será el número de componentes 
		}							// en los que se ha guardado un dato.
		
		else		
			
			array2[i] = stoi(valor);
			
	}
	
	// Cálculos.
	
	// Cálculo de la media de los valores.
	
	int suma = 0;
	
	// Array 1
	
	for ( int i = 0 ; i <= util1 - 1 ; i ++ )
		
		suma += array1[i];
		
	double media1 = suma * 1.0 / util1;
	
	suma = 0;
	
	// Array 2
	
	for ( int i = 0 ; i <= util2 - 1 ; i ++ )
		
		suma += array2[i];
		
	double media2 = suma * 1.0 / util2;
	
	// Comparación de ambos array, realizará una primera "criba" comprobando
	// si tiene el mismo número de elementos.
	
	bool iguales = true;
	
	if ( util1 != util2 ) iguales = false;
	
	else {
		
		for ( int i = 0 ; i < util1 && iguales ; i++ ) 
			
			if ( array1[i] != array2[i] ) iguales = false;
			
	}
	
	// Salida de resultados
	
	cout << endl << endl;

	cout << "--------------------|RESULTADOS|--------------------" << endl;
	cout << endl;
	cout <<"\t--> Media del ARRAY 1 = " << setw(5) <<setprecision(3);
	cout << media1 << endl;
	cout <<"\t--> Media del ARRAY 2 = " << setw(5) << media2 << endl << endl;
	
	if ( iguales ) 
		
		cout << "\tAMBOS ARRAYS SON IGUALES";
		
	else
	
		cout << "\tLOS ARRAYS SON DISTINTOS";
		
	
	return 0;
	
}
	
		
	
	
	
		
	
	
	
	

