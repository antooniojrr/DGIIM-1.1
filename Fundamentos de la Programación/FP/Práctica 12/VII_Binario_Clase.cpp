/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 7. Nº6.
// VII_Binario_Clase.cpp: escribe un programa que cuente con la clase
// binario "Bin", con todos los métodos necesarios para modificar y expresar
// el valor que se introduzca
//
//Entrada: valores binarios
//Salida: resultados y modificaciones realizadas
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;


const int MAX_BITS = 32;
const long long int MAX_DEC = pow (2 , MAX_BITS );
	
/************************************************************************/
// Declaración de la clase Binario "Bin", la cual contará con un campo privado
// que contendrá el valor de un dato "unsigned int" con el que trabajará.
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

class Bin {
	
	private:
		
		unsigned int valor_bin;     // PRE: 0 <= valor_bin < 2^(32)
		
		/*************************************************************/
		// Método para convertir cualquier número decimal en un dato "string"
		// con su expresión en binario.
		//
		// Entrada: número decimal y número de bits
		// Salida: número binario
		//
		/*************************************************************/
		
		string DecToBin ( int num_decimal, int num_bits ) {
	
			string numero_bin;
			
			int resto = num_decimal;
			
			int exponente = ( ( pow ( 2, (num_bits - 1) ) >= num_decimal ) ? 
						num_bits - 1 : log2 ( num_decimal ) );
			
			while ( exponente >= 0 ) {
				
				if ( pow(2,exponente) <=  resto ) {
					
					resto = resto - pow(2,exponente);
					numero_bin.push_back('1');
					
					exponente --;
					
				}
				
				else {
					
					numero_bin.push_back('0');
					
					exponente --;
					
				}
				
			}
			
			
			return (numero_bin);
			
		}
		
		/*************************************************************/
		// Método para convertir cualquier número binario en su forma
		// "string" a su forma decimal
		//
		// Entrada: número binario
		// Salida: número decimal
		//
		/*************************************************************/
		
		unsigned int BinToDec ( string num_bin ) {

			unsigned int num_dec = 0;
			int exponente = num_bin.length() - 1;
			unsigned int posicion = 0;
			
			while ( posicion <= (num_bin.length() - 1) ) {
				
				if (num_bin.at(posicion) == '1')
				 
					num_dec = num_dec + pow(2,exponente);
					
				exponente --;
				posicion ++;
				
			}
			
			return num_dec;
			
		}
		
	public:
		
		////////////////////////////////////////////////////////////////
		// Declaración de los constructores:
		//	---> 1º: constructor sin argumentos
		//	---> 2º: constructor al que se le introduce el valor de "valor_bin"
		//	---> 3º: constructor al que se le introduce un "string" con
		//			el valor de "valor_bin
		//
		////////////////////////////////////////////////////////////////
		
		Bin (void):
			
			valor_bin(0)
			
			{}
			
		////////////////////////////////////////////////////////////////
		
		Bin ( unsigned int el_valor_inicial):
			
			valor_bin(el_valor_inicial)
			
			{}
			
		////////////////////////////////////////////////////////////////
		// PRE: " string el_valor_inicial" tiene que ser un dato válido para
		// convertir en uno entero.
		
		Bin ( string el_valor_inicial )
			
			{
					int longitud = el_valor_inicial.length();
				int valor = 0;
				int exponente = longitud - 1;
			
				for ( int i = 0 ; i < longitud ; i++ ) {
					
					if ( el_valor_inicial.at(i) == '1' ) 
						valor += pow ( 2, exponente );
					
					exponente --;
					
				}
				
				valor_bin = valor;
				
			}
		
		////////////////////////////////////////////////////////////////
		// Métodos para asignar un valor nuevo al campo "valor_bin", tanto
		// introduciendo un dato "unsigned int" como un "string" ( Que será
		// un dato binario válido )
		//
		// Entrada: valor nuevo
		// Salida: ---------------
		
		void SetValor ( unsigned int el_valor ) {
			
			valor_bin = el_valor;
			
		}
		
		////////////////////////////////////////////////////////////////
		//
		void SetValor ( string el_valor ) {
			
			int longitud = el_valor.length();
			int valor = 0;
			int exponente = longitud - 1;
			
			for ( int i = 0 ; i < longitud ; i++ ) {
				
				if ( el_valor.at(i) == '1' ) valor += pow ( 2, exponente );
				
				exponente --;
				
			}
			
			valor_bin = valor;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para devolver el número mínimo de bits necesarios para
		// representar "valor_bin" en binario.
		//
		// Entrada: -----------
		// Salida: mínimo número de bits
		
		int MinNumBits () {
			
			int min_bits;
			
			min_bits = ( valor_bin == 0 ) ? 1 : log2(valor_bin) + 1;
			
			return (min_bits);
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para devolver el valor decimal que contiene el campo
		// "valor_bin"
		//
		// Entrada: -----------
		// Salida: valor decimal
		
		unsigned int GetValorDecimal () {
			
			return valor_bin;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para devolver el valor binario que contiene el campo
		// "valor_bin" en un string. El número contará con el num de casillas
		// que se le introduzca al método
		//
		// Entrada: número de casillas PRE: 0 <= num_casillas
		// Salida: "[<valor_bin>]"
		
		string To_String ( int num_casillas ) {
			
			string cad = "[" + DecToBin ( valor_bin, num_casillas ) + "]";
			
			return cad;
			
		}
		
		
		////////////////////////////////////////////////////////////////
		// Método para calcular la suma de dos números decimales que creará un
		// nuevo objeto "Bin"
		//
		// Entrada: objeto "Bin"
		// Salida: objeto "Bin" (Suma de los otros dos)
		
		Bin Suma ( Bin otro ) {
			
			int suma = valor_bin + otro.GetValorDecimal();
			Bin nuevo ( suma );
			
			return nuevo;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para calcular la resta de dos números decimales que creará un
		// nuevo objeto "Bin"
		//
		// Entrada: objeto "Bin"
		// Salida: objeto "Bin" ( El primero menos el segundo)
		// PRE: valor_bin >= otro.GetValorDecimal. Si ocurriese lo contrario
		// el resultado será 0.
		
		Bin Resta ( Bin otro ) {
			
			int resta = valor_bin - otro.GetValorDecimal();
			
			if ( resta < 0 ) resta = 0;
			
			Bin nuevo ( resta );
			
			return nuevo;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para calcular el producto "AND" de dos números decimales
		// creando un nuevo objeto "Bin" con el resultado.
		//
		// Entrada: objeto "Bin"
		// Salida: objeto "Bin" (Producto "AND" de los otros dos)
		
		Bin AND ( Bin otro ) {
			
			string valor1 = DecToBin(valor_bin, MAX_BITS/2);
			string valor2 = DecToBin( otro.GetValorDecimal(), MAX_BITS/2);
			
			string resultado;
			
			if ( valor1.length() > valor2.length() ) {
				
				while ( valor2.length() < valor1.length() ) 
					
					valor2 = "0" + valor2;
					
			}
			
			else {
				
				while ( valor1.length() < valor2.length() ) 
					
					valor1 = "0" + valor1;
				
			}
			
			int longitud = valor1.length();
			
			for ( int j = 0; j < longitud ; j ++ ) {
				
				if ( valor1.at(j) == valor2.at(j) )
					
					resultado.push_back(valor1.at(j));
					
				else resultado.push_back('0');
					
			}
			
			Bin nuevo ( resultado );
			
			return nuevo;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para calcular el producto "OR" de dos números decimales
		// creando un nuevo objeto "Bin" con el resultado.
		//
		// Entrada: objeto "Bin"
		// Salida: objeto "Bin" (Producto "OR" de los otros dos)
		
		Bin OR ( Bin otro ) {
			
			string valor1 = DecToBin(valor_bin, MAX_BITS/2);
			string valor2 = DecToBin( otro.GetValorDecimal(), MAX_BITS/2);
			
			string resultado;
			
			if ( valor1.length() > valor2.length() ) {
				
				while ( valor2.length() < valor1.length() ) 
					
					valor2 = "0" + valor2;
					
			}
			
			else {
				
				while ( valor1.length() < valor2.length() ) 
					
					valor1 = "0" + valor1;
				
			}
			
			int longitud = valor1.length();
			
			for ( int i = 0; i < longitud ; i ++ ) 
				
				resultado += "0";
			
			for ( int j = 0; j < longitud ; j ++ ) {
				
				if ( valor1.at(j) == '1' || valor2.at(j) == '1' )
					
					resultado.push_back('1');
				
				else resultado.push_back('0');
					
			}
			
			Bin nuevo ( resultado );
			
			return nuevo;
			
		}
		
		////////////////////////////////////////////////////////////////
		// Método para crear un nuevo objeto de clase "Bin" desplazando
		// a la izquierda o a la derecha los bits añadiendo '0' o eliminando
		// bits
		//
		// Entrada: objeto "Bin"
		// Salida: objeto "Bin" (Producto de desplazar los bits)
		
		Bin DespDcha ( int veces ) {
			
			int valor_nuevo = valor_bin / pow (2 , veces);;
			
			Bin nuevo ( valor_nuevo );
			
			return nuevo;
			
		}
		
		////////////////////////////////////////////////////////////////
		
		Bin DespIzda ( int veces ) {
			
			int valor_nuevo = valor_bin * pow ( 2 , veces );
			
			Bin nuevo ( valor_nuevo );
			
			return nuevo;
			
		}
		
};

/************************************************************************/
// Función para leer un entero en un rango determinado,
// sirviendo esta de filtro. Pedirá un número hasta que se le introduzca
// uno correcto.
//
// Entrada: título a mostrar, máximo y mínimo del rango.
// Salida: número entero.
/************************************************************************/

int LeeEnteroEnRango ( string titulo, long long int max, int min)
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
		
		for ( int pos = 0 ; pos < longitud && Es_Valido ; pos ++ )
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') Es_Valido = false;
		
		if ( Es_Valido) 
		
			if ( stoi(num) > max || stoi(num) < min ) Es_Valido = false;
			
	} while ( !Es_Valido );
	
	entero = stoi(num);
	
	return entero;
	
}

/************************************************************************/
// Función para leer un número binario con una longitud máxima,
// sirviendo esta de filtro. Pedirá un número binario hasta que se 
// le introduzca uno correcto.
//
// Entrada: título a mostrar, bits máximos.
// Salida: número binario.
/************************************************************************/

string LeeBinMenorDe ( string titulo, unsigned int num_bits ) {
	
	string num;
	bool valido;
	unsigned int pos;
	
	do {
		
		pos = 0;
		valido = true;
		
		cout << titulo;
		getline ( cin, num );
		
		while ( pos < num.length() && isspace(num.at(pos)) ) pos ++;
		
		num = num.substr(pos);
		
		while ( isspace(num.back()) ) num.pop_back();
		
		if ( num.length() > num_bits ) valido = false;
		
		if ( valido ) {
			
			for ( unsigned int i = 0; i < num.length() && valido ; i ++ ) {
				
				if ( num.at(i) != '1' && num.at(i) != '0' ) valido = false;
				
			}
			
		}
		
	} while (!valido);
	
	return num;
	
}
		
/************************************************************************/		
		
int main ()			// Función principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	string titulo = "Introduzca un numero positivo ( < 2^32 ): ";
	
	unsigned int entero = LeeEnteroEnRango ( titulo, MAX_DEC, 0 );

	Bin num_bin1 ( entero );
	
	string titulo2 = "Introduzca un numero binario de menos de 32 bits: ";
	string num_binario = LeeBinMenorDe( titulo2, MAX_BITS);
	
	Bin num_bin2 ( num_binario );
	
	// Cálculos
	
	Bin suma = num_bin1.Suma(num_bin2);
	Bin resta = num_bin1.Resta(num_bin2);
	Bin prod_and = num_bin1.AND(num_bin2);
	Bin prod_or = num_bin1.OR(num_bin2);
	Bin dcha = num_bin1.DespDcha(1);
	Bin izda = num_bin1.DespIzda(1);
	
	// Salida
	
	cout << endl << endl;
	cout << "---------------|RESULTADOS|---------------";
	cout << endl << endl;

	cout << "\t NUM1 + NUM2 = " << suma.To_String(suma.MinNumBits()) << endl;
	cout << "\t NUM1 - NUM2 = " << resta.To_String(resta.MinNumBits()) << endl;
	cout << "\t NUM1 (AND) NUM2 = ";
	cout << prod_and.To_String(prod_and.MinNumBits()) << endl;
	cout << "\t NUM1 (OR) NUM2 = ";
	cout << prod_or.To_String(prod_or.MinNumBits()) << endl;
	cout << "\t NUM1 desplazado a la DCHA = ";
	cout << dcha.To_String(dcha.MinNumBits()) << endl;
	cout << "\t NUM1 desplazado a la IZDA = ";
	cout << izda.To_String(izda.MinNumBits()) << endl;
	
	
	return 0;
	
}
	
	
	
			
			
			
			
				
				
				
				
		
			
			
				
				
	
	
	
	
	
	
	
