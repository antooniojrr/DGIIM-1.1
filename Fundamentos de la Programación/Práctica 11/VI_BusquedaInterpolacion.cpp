/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 36. Nº6.
// VI_BusquedaInterpolacion.cpp: escribe un programa que contenga la clase
// "RedSocial" para controlar los usuarios registrados en tal red social
// y las relacionnes de amistad que mantengan entre ellos. El programa
// sugerirá los amigos potenciales de cada usuario y sus amigos
// circunstanciales
//
//Entrada: usuarios y amistades
//Salida: amigos potenciales y circunstanciales
//
/************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Declaración de la clase "SecuenciaEnteros", la cual procesará una secuencia
// de enteros, será capaz de guardar estos, ordenarlos y buscar la posición
// del valor que introduzca que se desee.

class SecuenciaEnteros
{
	
	private:
		
		static const int TAMANIO = 100;
		
		int secuencia[TAMANIO];
		int utilizados;					// PRE: utilizados >= 0
		
	public:
		
		// Declaración de un constructor sin argumentos
		
		//SecuenciaEnteros(): utilizados(0) {}
		
		////////////////////////////////////////////////////////
		// Método para definir el valor de un elemento de "secuencia".
		//
		// Entrada: índice y valor
		// Salida: -----------------
		// PRE: 0 <= índice <= TAMANIO
		
		void SetElemento( int i, int valor) {
			
			secuencia[i] = valor;
			
		}
		
		////////////////////////////////////////////////////////
		// Método para definir el valor del campo "utilizados.
		//
		// Entrada: valor nuevo
		// Salida: -----------------
		// PRE: 0 <= nuevo
		
		void SetUtilizados( int nuevo) {
			
			utilizados = nuevo;
			
		}
		
		////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "utilizados.
		//
		// Entrada: -----------------
		// Salida: valor de "utilizados
		
		int GetUtilizados() {
			
			return utilizados;
			
		}
		
		////////////////////////////////////////////////////////
		// Método para ordenar los componentes del array "secuencia" 
		// en orden creciente según sus valores
		//
		// Entrada: -----------------
		// Salida: -----------------
		
		void OrdenaSecuencia () {
			
			int lectura;
			int escritura = 0;
			int auxiliar;
			
			while ( escritura < utilizados ) {
				
				lectura = escritura;
				
				while ( lectura < utilizados ) {
					
					if ( secuencia[lectura] < secuencia[escritura] ) {
						
						auxiliar = secuencia[escritura];
						secuencia[escritura] = secuencia[lectura];
						secuencia[lectura] = auxiliar;
						
					}
					
					lectura ++;
					
				}
				
				escritura ++;
				
			}
			
		}
		
		
		////////////////////////////////////////////////////////
		// Método para buscar por interpolación un valor que esté situado
		// entre dos posiciones del array ( "izda" y "dcha" ). Una vez
		// encontrado el valor, devolverá su posición
		//
		// Entrada: valor buscado, "izda" y "dcha"
		// Salida: posición del valor buscado o, si no está, devolverá "-1"
		// PRE: la sucesión debe estar ordenada
		// PRE: 0 <= izda < dcha <= TAMANIO
		
		int BuscarPorInterpolacion ( int valor, int izda, int dcha ) {
			
			int pos;
			bool encontrado = false;
			const int VALOR_FALLO = -1;
			double pos_aprox;
			int contador_seg = 0;
			
			do {
				
				pos_aprox = (valor-secuencia[izda]) * 0.1 /
										(secuencia[dcha]-secuencia[izda]);
				pos_aprox = ( pos_aprox * ( dcha - izda ) ) + izda;
				
				pos = round(pos_aprox);
				if ( secuencia[pos] == valor ) encontrado = true;
				
				else if ( valor < secuencia[pos] ) dcha = pos;
				
				else izda = pos;
				
				contador_seg ++;  // En el caso de que no lo encuentre, que
								  // salga del bucle cuando de tantas vueltas
								  // como componentes tiene la secuencia
				
			} while ( !encontrado && ( dcha - izda > 1 ) 
											&& contador_seg <= utilizados );
			
			if ( !encontrado ) pos = VALOR_FALLO;
			
			return pos;
			
		}
	
		////////////////////////////////////////////////////////
		// Método para devolver el valor de la constante "TAMANIO".
		//
		// Entrada: -----------------
		// Salida: valor de "TAMANIO"
		
		int GetTamanio() {
			
			return TAMANIO;
			
		}
	
		////////////////////////////////////////////////////////
		// Método para devolver el valor de uno de los componentes
		// del array "secuencia".
		//
		// Entrada: índice del componente "i"
		// Salida: valor de "secuencia[i]"
		// PRE: 0 <= i <= utilizados
		
		int GetElemento( int i) {
			
			return secuencia[i];
			
		}
		
		////////////////////////////////////////////////////////
		
};


/************************************************************************/
// Función para leer un entero en un rango determinado,
// sirviendo esta de filtro. Pedirá un número hasta que se le introduzca
// uno correcto.
//
// Entrada: título a mostrar, máximo y mínimo del rango.
// Salida: número entero.
/************************************************************************/

int LeeEnteroEnRango ( string titulo, int max, int min)
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
			
		if ( stoi(num) > max || stoi(num) < min ) Es_Valido = false;
			
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}

int LeeEntero ( string titulo)
{
	
	string num;
	int entero;
	bool Es_Entero;
	int longitud;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Entero = true;
		
		int i = 0;
		
		while ( isspace(num.at(i)) ) i ++;
		num = num.substr(i);
		
		longitud = num.length();
		
		int pos = 0;
		
		if ( num.at(pos) == '+' || num.at(pos) == '-' ) {
			
			pos ++;
			if ( longitud == 1 ) Es_Entero = false;
			
		}
		
		for ( ; pos <= longitud - 1 && Es_Entero ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Entero = false;
		
		if ( longitud == 0 ) Es_Entero = false;
		
	} while ( !Es_Entero );
	
	entero = stoi(num);
	
	return entero;
	
}


/************************************************************************/
// Función para leer un entero mayor o igual que una referencia,
// sirviendo esta de filtro. Pedirá un número hasta que se le introduzca
// uno correcto.
//
// Entrada: título a mostrar, referencia.
// Salida: número entero mayor o igual a referencia.
/************************************************************************/

int LeeEnteroMayorOIgual ( string titulo, int referencia)
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
		
		if ( stoi(num) < referencia ) Es_Valido = false;
		
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}
		
/************************************************************************/

bool EsEnteroOTerm ( string num )
{
	
	bool Es_Valido;
	int longitud;
	const string TERM = "#";
	

		
	Es_Valido = true;
	
	longitud = num.length();
	
	for ( int pos = 0 ; pos <= longitud - 1 && Es_Valido ; pos ++ )
		
		if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
	
	if ( !Es_Valido )
		
		if ( num == TERM ) Es_Valido = true;
			
	return Es_Valido;
	
}

int main ()				// Función principal
{

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	const string TERM = "#";
	SecuenciaEnteros secuencia;
	
	cout << "INTRODUZCA LOS VALORES DE LA SECUENCIA" << endl;
	cout << "Si desea parar, introduzca \"#\"" << endl << endl;
	
	int i = 0;
	string num;
	
	do {
		
		cout << "\tValor " << i + 1 << " = ";
		getline(cin, num);
			
	}while ( !EsEnteroOTerm(num) );
		
		
	while ( num != TERM && i < secuencia.GetTamanio() ) {
		
		secuencia.SetElemento(i, stoi(num));
		secuencia.SetUtilizados( (i + 1) );
		i++;
				
		do {
		
			cout << "\tValor " << i + 1 << " = ";
			getline(cin, num);
			
		} while ( !EsEnteroOTerm(num) );
		
	}
	
	int buscar;
	
	cout << endl << endl;
	
	buscar = LeeEntero ( "Introduzca el valor a buscar: " );
	
	cout << "Introduzca las posiciones entre las que buscarlo:" << endl;
	int izda = LeeEnteroEnRango ( "\tLimite izquierdo = ",
									secuencia.GetUtilizados() - 1, 0 );
	
	int dcha;
	
	do {
		
		dcha = LeeEnteroEnRango ( "\tLimite derecho = ",
											secuencia.GetUtilizados(), 0 );	
											
	} while ( izda >= dcha );
	
	izda --;  
	dcha --;
	
	// Se le resta uno a ambos para pasar de las posiciones que se le muestran
	// al usuario ( Comenzando por 1 ) a los índices de los componentes
	// de la secuencia ( Comenzando por 0 )
	
	// Cálculos
	
	secuencia.OrdenaSecuencia();
	
	int pos_buscar = secuencia.BuscarPorInterpolacion( buscar, izda, dcha);
	const int VALOR_FALLO = -1;
	
	// Salida de resultados
	
	cout << endl << endl;
	cout << "-----------------|RESULTADOS|-----------------" << endl << endl;
	
	if ( pos_buscar == VALOR_FALLO ) {
		
		cout << " No se ha encontrado el valor " << buscar << " entre las";
		cout << " posiciones " << izda << " y " << dcha;
		
	}
	
	else {
		
		cout << " El valor " << buscar << " ha sido encontrado en la posicion"
			 << " " << pos_buscar;
			 
	}
	
	cout << endl << endl;
	
	cout << "SECUENCIA ORDENADA:" << endl;
	
	cout << "\t";
	for ( int i = 0; i < secuencia.GetUtilizados() ; i ++ )
		
		cout << setw(5) << secuencia.GetElemento( i );
	
	return 0;
	
}
	
		
			
		
		
		
		
		
		
		
		
		
		
		
		
		
