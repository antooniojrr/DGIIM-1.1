/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 14. Nº6.
// VI_ManipuladorString.cpp: escribe un programa que realice complejas
// funciones en un dato de tipo "string".
//
//Entrada: dato de tipo "string"
//Salida: el dato con las modificaciones realizadas
//
/************************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"

using namespace std; 

class ManipuladorString{
	
	private: 
	
		string cadena;
		
	public: 
	
		ManipuladorString(string la_cadena)
		
			: cadena(la_cadena)
			
		{}
		
		string GetCadena(){
			
			return cadena;
		}
		
/***************************************************************************/
// Recibe una cadena y devuelve otra, resultante de eliminar los primeros 
// caracteres separadores de "cadena".
//
// Usaremos la función "isspace()" para simplificar el proceso. 
// 
// Entrada: -------------
// Salida: -------------
/***************************************************************************/
		
		void EliminaPrimerosSeparadores ()
		{	
			// Buscar el primer carácter no espacio
			
			unsigned int pos = 0;
			
			while ( pos <cadena.length() && isspace(cadena.at(pos))) pos++;
		
			string local; 
			
			// Copiar todos los que quedan
			while (pos <cadena.length()) {
				local.push_back(cadena.at(pos));
				pos++;
			}
			
			cadena = local;
		}
		
/***************************************************************************/
// Recibe una cadena y devuelve otra, resultante de eliminar los últimos 
// caracteres separadores de "cadena".
//
// Usaremos la función "isspace()" para simplificar el proceso. 
// 
// Entrada: -------------
// Salida: -------------
/***************************************************************************/
		
		
		void EliminaUltimosSeparadores () {
			
		   	while (cadena.length() > 0 && isspace(cadena.back()))
		   	
				cadena.pop_back();
				
		}
		
/***************************************************************************/
// Recibe una cadena y devuelve otra, resultante de eliminar todos los 
// caracteres separadores de "cadena" (Espacios, saltos de línea y tab.).
//
// Usaremos la función "isspace()" para simplificar el proceso. 
// 
// Entrada: -------------
// Salida: -------------
/***************************************************************************/
		
		void EliminaPrimerosYUltimosSeparadores () {
			
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
				
		}
		
		void ConvierteAMayusculas (){
			
			string cadena_en_mayusculas;
			
			for (unsigned int i = 0; i < cadena.length(); i++)
			
				cadena_en_mayusculas += toupper(cadena.at(i));
			
			cadena = cadena_en_mayusculas;
		}
		
		void ConvierteAMinusculas (){
			
			string cadena_en_minusculas;
			
			for (unsigned int i = 0; i < cadena.length(); i++)
			
				cadena_en_minusculas += tolower(cadena.at(i));
				
			cadena = cadena_en_minusculas;
		}
		
};


int main()					// Función principal
{
	
	string cadena_primera, cadena_modificada;
	
	cout << endl << "Introduzca una cadena que quiera modificar: ";
	getline (cin, cadena_primera);
	
	ManipuladorString m (cadena_primera);
	
	m.EliminaPrimerosYUltimosSeparadores(); 
	
	cout << endl << "Quitamos los primeros y los últimos separadores: "
		 << m.GetCadena();
	
	m.ConvierteAMinusculas();
	
	cout << endl << "Pasamos a minúscula todos los términos de la cadena: "
	
		 << m.GetCadena();
		 
	cadena_modificada = m.GetCadena();
	
	cout << endl << "Su nueva cadena es: |" << cadena_modificada << "|";
	
	
	return 0;
	
}		
