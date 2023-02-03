/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 5. Nº13.
//V_EliminaRepetidos_Array.cpp: escribe un programa que elimine en un array
//los componentes repetidos y aglutine los no repetidos en los primeros
//puestos del vector
//
//Entrada: datos positivos
//Salida: array sin repetidos
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

/************************************************************************/
// Función para leer un real, sirviendo esta de filtro. Pedirá un número
// hasta que se le introduzca uno correcto.
//
// Entrada: título a mostrar en pantalla a la hora de pedir el número.
// Salida: número real.
/************************************************************************/

double LeeReal ( string titulo)
{
	
	string num;
	double real;
	bool Es_Real;
	int longitud;
	bool ya_punto = false;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Real = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Real ; pos ++ ) {
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') {
				
				if ( (num.at(pos) == '.' || num.at(pos) == ',') && !ya_punto )
				
				ya_punto = true;
				
				else Es_Real = false;
				
				if ( (num.at(pos) == '+' || num.at(pos) == '-') && pos == 0 )
		
				Es_Real = true;
			
			}
			
		}


	} while ( !Es_Real );
	
	real = stod(num);
	
	return real;
	
}


/************************************************************************/


int main ()                           // Función principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Declaración del array
	
	const int TOPE = 50;          
	
	double datos[TOPE];
	
	// Entrada de datos
	
	cout << "Los datos positivos introducidos se guardarán en el vector.";
	cout << endl;
	cout <<"Si desea dejar de introducir datos, introduzca un número negativo";
	cout << endl << endl;
	
	int util;                       // Será el número de componentes del vector
	bool terminar = false;			// usados
	for ( util = 0; util <= TOPE - 1 && !terminar ; util ++ ) {
		
		datos[util] = LeeReal ( "Introduce un dato: " );
		
		if ( datos[util] < 0 ) terminar = true;
		
	}
		
	// Cálculos
	
	int pos_lectura;
	int pos_escritura = 1;
	bool diferente;
	
	for ( pos_lectura = 0 ; pos_lectura < util - 1 ; pos_lectura ++ ) {
		
		diferente = true;
		
		for ( int i = 0 ; i < pos_escritura && diferente ; i ++ )
			
			if ( datos[i] == datos[pos_lectura] ) diferente = false;
		
		if ( diferente ) {
			
			datos[pos_escritura] = datos[pos_lectura];
			pos_escritura ++;
			
		}
		
	}
	
	// Salida de resultados
	
	cout << endl;
	cout << "-----------------|CADENA SIN REPETIDOS|-----------------";
	cout << endl << endl;
	
	cout << "\tDatos = { ";
	
	for ( int i = 0; i < pos_escritura ; i ++ )
		
		cout << datos[i] << " , ";
		
	cout << "}";
	
	return 0;
	
}
			
	
	
	
	
	
	





