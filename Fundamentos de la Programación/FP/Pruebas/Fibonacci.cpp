/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 22. N�6.
// VI_Eratostenes_Clase.cpp: escribe un programa que cuente con la clase
// "Fibonacci", la cual se caracterice, por el campo "orden". Esta clase
// ser� capaz de calcular los "k" primeros t�rminos de la sucesi�n de
// fibonacci del orden que se le introduzca
//
//Entrada: orden de la sucesi�n, t�rminos a calcular
//Salida: elementos de la sucesi�n calculados
//
/************************************************************************/

#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std; 

// PRE: para ordenes grandes de la sucesi�n y calcular grandes cantidades
// de elementos, el programa puede fallar

class Fibonacci {
	
	private:
		
		int orden;							// Caracteriza a cada objeto
											// PRE: orden > 0
											
		static const int TAMANIO = 100;		// Tama�o del "array"									
		int elementos[TAMANIO];				// "Array" de elementos															
		
		int calculados;						// Elementos calculados
											// PRE: calculados > 0
	
	public:
	
		// Declaraci�n de un constructor que asigne el valor que se introduzca
		// al campo orden e inicie "calculados a 0
		
		Fibonacci ( int ord ) :
			
			orden(ord),
			calculados(0)
			{
				elementos[0] = 1;
				elementos[1] = 1;
			
			}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para definir el valor del campo " calculados " de un objeto
		// de esta clase
		//
		// Entrada: entero
		// Salida: -------------- 
		//PRE: entero >= 0
		
		void SetCalculados ( int calc ) {
			
			calculados = calc;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para calcular los "k" primeros elementos de la sucesi�n
		// de Fibonacci
		//
		// Entrada: k
		// Salida: elementos 
		//
		// PRE: k >= 0
		// PRE: si k >= TAMANIO ----> calculados = TAMANIO
		
		void CalculaPrimeros ( int k ) {
			
			if ( k >= TAMANIO ) k = TAMANIO;
			
			SetCalculados(k);
			
			int suma;
			int primer_sum;
			
			for ( int i = 2; i < k ; i ++ ) {
				
				suma = 0;
				primer_sum = i - k;
				
				if ( primer_sum < 0 ) primer_sum = 0;
				
				for ( int j = primer_sum ; j < i ; j ++ )
					
					suma += elementos[j];
					
				elementos[i] = suma;
				
			}
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para obtener el valor del campo " orden " de un objeto
		// de esta clase
		//
		// Entrada: --------------
		// Salida: orden 
		//
		
		int GetOrden () {
			
			return orden;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para definir el valor del campo " orden " de un objeto
		// de esta clase
		//
		// Entrada: entero
		// Salida: -------------- 
		//
		
		void SetOrden ( int ord ) {
			
			orden = ord;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para obtener el valor del campo " calculados " de un objeto
		// de esta clase
		//
		// Entrada: --------------
		// Salida: calculados 
		//
		
		int TotalCalculados () {
			
			return calculados;
			
		}
		
		/////////////////////////////////////////////////////////////////
		
		// M�todo para obtener el valor del "elemento[i]" siendo "i" un
		// entero pedido.
		//
		// Entrada: i
		// Salida: elemento[i]
		//PRE: i >= 0
		
		int Elemento ( int i ) {
			
			return elementos[i];
			
		}
		
		
};

int main ()				// Funci�n principal
{
	
	const int VALORES_PEDIDOS = 150;
	
	Fibonacci fib(4);
	fib.CalculaPrimeros(VALORES_PEDIDOS);
	
	cout << "Creada sucesion de Fibonacci de orden "
		 << fib.GetOrden() << endl;
	
	cout << "Pedidos los primeros "
		 << VALORES_PEDIDOS << " valores. " << endl;
		 
	cout << "Obtenidos los primeros "
		 << fib.TotalCalculados() << " valores. " << endl;
	cout << endl;
	
	cout << "Valores calculados: " << endl;
	
	for (int i=0; i < fib.TotalCalculados() ; i++ )
	
		cout << setw(5) << fib.Elemento(i) << ",";
		
	return 0;
	
}

