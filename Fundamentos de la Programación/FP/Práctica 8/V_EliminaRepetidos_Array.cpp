/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 5. N�13.
//V_EliminaRepetidos_Array.cpp: escribe un programa que elimine en un array
//los componentes repetidos y aglutine los no repetidos en los primeros
//puestos del vector
//
//Entrada: datos positivos
//Salida: array sin repetidos
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cmath>        // Inclusi�n de los recursos matem�ticos

using namespace std;

/************************************************************************/
// Funci�n para leer un real, sirviendo esta de filtro. Pedir� un n�mero
// hasta que se le introduzca uno correcto.
//
// Entrada: t�tulo a mostrar en pantalla a la hora de pedir el n�mero.
// Salida: n�mero real.
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


int main ()                           // Funci�n principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Declaraci�n del array
	
	const int TOPE = 50;          
	
	double datos[TOPE];
	
	// Entrada de datos
	
	cout << "Los datos positivos introducidos se guardar�n en el vector.";
	cout << endl;
	cout <<"Si desea dejar de introducir datos, introduzca un n�mero negativo";
	cout << endl << endl;
	
	int util;                       // Ser� el n�mero de componentes del vector
	bool terminar = false;			// usados
	for ( util = 0; util <= TOPE - 1 && !terminar ; util ++ ) {
		
		datos[util] = LeeReal ( "Introduce un dato: " );
		
		if ( datos[util] < 0 ) terminar = true;
		
	}
		
	// C�lculos
	
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
			
	
	
	
	
	
	





