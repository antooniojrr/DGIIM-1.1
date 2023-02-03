/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 7. Nº11.
// VII_ConjuntoOrdenado_Clase.cpp: escribe un programa que cuente con la clase
// "ConjuntoOrdenado", con métodos para calcular la unión, la intersección y
// añadir elementos al conjunto.
//
//Entrada: valores para el conjunto
//Salida: unión e intersección de dos conjuntos
//
/************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/************************************************************************/
// Declaración de la clase "ConjuntoOrdenado", que contendrá un conjunto de
// enteros ordenados y no repetidos, contando con métodos para obtener la
// unión y la intersección con otros conjuntos.
//

class ConjuntoOrdenado {
	
	private:
		
		static const int TAMANIO = 100;		// Tamaño de cada conjunto
		int vector_privado[TAMANIO];
		int elementos;						// Componentes usados
		// PRE: 0 <= elementos <= TAMANIO
		
	public:
		
		// Constructor sin argumentos.
		
		ConjuntoOrdenado(): elementos(0) {}
		
		/////////////////////////////////////////////////////////////
		// Método booleano para comprobar si un valor entero ya se encuentra
		// en el conjunto. Este repasará todos los componentes usados del
		// vector privado comparandolos con el entero introducido.
		//
		// Entrada: entero
		// Salida: "true" o "false"
		
		bool Existe ( int entero ) {
			
			bool existe = false;
			
			int pos = 0;
			
			while ( pos < elementos && !existe ) {
				
				if ( vector_privado[pos] == entero ) existe = true;
				
				pos ++;
				
			}
			
			return existe;
			
		}
		
		/////////////////////////////////////////////////////////////
		// Método para añadir un nuevo elemento al conjunto. Este lo pondrá
		// en su lugar por orden creciente de los valores siempre y cuando
		// no se encuentre repetido ya en el vector privado.
		//
		// Entrada: entero
		// Salida: ---------------
		
		void Aniade ( int entero ) {
			
			int pos = 0;
			
			if ( !Existe ( entero ) && elementos < TAMANIO ) {
				
				while ( pos < elementos && entero > vector_privado[pos])
					
					pos ++;
					
				for ( int i = elementos ; i > pos ; i -- )
					
					vector_privado[i] = vector_privado[i-1];
					
				vector_privado[pos] = entero;
				elementos ++;
				
			}
			
		}
		
		/////////////////////////////////////////////////////////////
		// Método para devolver el número de elementos que posee el conjunto,
		// el campo "elementos"
		//
		// Entrada: ----------------
		// Salida: "elementos"
		
		int GetNumElementos () {
			
			return elementos;
			
		}
		
		/////////////////////////////////////////////////////////////
		// Método para devolver un componente del campo "vector_privado" a
		// partir de su índice, que es lo que recibirá
		//
		// Entrada: i
		// Salida: "vector_privado[i]"
		
		int GetElemento ( int i ) {
			
			return vector_privado[i];
			
		}		
		
		/////////////////////////////////////////////////////////////
		// Método para calcular la unión de dos conjuntos ordenados. Esta
		// recibirá otro objeto de la clase "ConjuntoOrdenado" y devolverá otro
		// de esta clase
		//
		// Entrada: ConjuntoOrdenado otro
		// Salida: ConjuntoOrdenado unidos
		
		ConjuntoOrdenado Union ( ConjuntoOrdenado otro ) {
			
			ConjuntoOrdenado unidos;
			
			unidos = otro;
			
			for ( int i = 0; i < elementos; i ++ )
				
				unidos.Aniade( vector_privado[i] );
				
			return unidos;
			
		}
		
		/////////////////////////////////////////////////////////////
		// Método para calcular la intersección de dos conjuntos ordenados. 
		// Esta recibirá otro objeto de la clase "ConjuntoOrdenado" y devolverá 
		// otro de esta clase
		//
		// Entrada: ConjuntoOrdenado otro
		// Salida: ConjuntoOrdenado interseccion
		
		ConjuntoOrdenado Interseccion ( ConjuntoOrdenado otro ) {
			
			ConjuntoOrdenado intersec;
			int elementos_otro = otro.GetNumElementos();
			
			if ( elementos <= elementos_otro ) {
				
				for ( int i = 0; i < elementos ; i ++ ) {
					
					if ( otro.Existe(vector_privado[i]) )
						
						intersec.Aniade(vector_privado[i]);
					
				}
				
			}
			
			else {
				
				for ( int i = 0; i < elementos_otro ; i ++ ) {
					
					if ( Existe(otro.GetElemento(i)) ) 
						
						intersec.Aniade(otro.GetElemento(i));
						
				}
				
			}
			
			return intersec;
			
		}
		
		/////////////////////////////////////////////////////////////
		// Método para devolver un dato de tipo "string" con todos los
		// elementos del vector privado
		//
		// Entrada: ----------------
		// Salida: string de todos los elementos
		
		string To_String () {
			
			string cad = "( ";
			
			if ( elementos > 0 ) cad += to_string(vector_privado[0]);
			
			for ( int i = 1; i < elementos ; i ++ ) 
				
				cad += ", " + to_string(vector_privado[i]);
				
			cad += " )";
			
			return cad;
			
		}
		
};

/************************************************************************/
// Función para comprobar si una cadena de caracteres que recibe es un
// numero entero válido.
//
// Entrada: cadena de caracteres
// Salida: "true" o "false"
/************************************************************************/

int EsEntero ( string num )
{

	bool Es_Entero;
	int longitud;
		
	Es_Entero = true;
	
	longitud = num.length();
	int pos = 0;
	
	if ( longitud == 0 ) Es_Entero = false;
	
	if ( Es_Entero && (num.at(0) == '+' || num.at(0) == '-') && longitud > 1 )
		
		pos ++;
	
	for ( ; pos < longitud && Es_Entero ; pos ++ )
		
		if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Entero = false;
			
	
	return Es_Entero;
	
}

/********************************************************************/

int main ()				// Función principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	cout << "------------|Valores CONJUNTO A|------------" << endl;
	cout << "Cuando quiera dejar de introducir valores, escriba ";
	cout << "#" << endl << endl;
	
	ConjuntoOrdenado conjunto_a;
	int index = 1;
	string num;
	const string TERMINADOR = "#";
	
	do{
		
		cout << "\t Valor " << index << " = ";
		getline ( cin, num );
		
	} while ( !EsEntero(num) && num != TERMINADOR );
	
	while ( num != TERMINADOR ) {
		
		index ++;
		
		conjunto_a.Aniade( stoi(num) );
		
		do {
			
			cout << "\t Valor " << index << " = ";
			getline ( cin, num );
			
		} while ( !EsEntero(num) && num != TERMINADOR );
		
	}
	
	cout << endl << endl;
	cout << "------------|Valores CONJUNTO B|------------" << endl << endl;
	
	ConjuntoOrdenado conjunto_b;
	index = 1;
	
	do{
		
		cout << "\t Valor " << index << " = ";
		getline ( cin, num );
		
	} while ( !EsEntero(num) && num != TERMINADOR );
	
	while ( num != TERMINADOR ) {
		
		index ++;
		
		conjunto_b.Aniade( stoi(num) );
		
		do {
			
			cout << "\t Valor " << index << " = ";
			getline ( cin, num );
			
		} while ( !EsEntero(num) && num != TERMINADOR );
		
	}
	
	// Cálculos
	
	ConjuntoOrdenado unidos = conjunto_a.Union( conjunto_b );
	ConjuntoOrdenado intersec = conjunto_a.Interseccion( conjunto_b );
	
	// Salida de resultados
	
	cout << endl << endl;
	
	cout << "----------------|RESULTADOS|----------------" << endl << endl;
	
	cout << "\tA = " << conjunto_a.To_String() << endl;
	cout << "\tB = " << conjunto_b.To_String() << endl;
	cout << "\tA (UNION) B = " << unidos.To_String() << endl;
	cout << "\tA (INTERSEC) B = " << intersec.To_String() << endl;
	
	cout << endl;
	
	
	return 0;
	
}
	
	
	
		
		
		
		
		
		
		
		
		
		
