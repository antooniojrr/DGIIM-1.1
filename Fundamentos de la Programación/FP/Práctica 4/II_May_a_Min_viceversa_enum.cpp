/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº21.
//
//II_May_a_Min_viceversa_enum.cpp: escribe un pograma que identifique un
//caracter según sea mayúscula, minúscula o no letra. Más tarde, si es letra,
//la pasará de minúscula a mayúscula o viceversa
//
//Entrada: edad y salario
//Salida: aumento aplicado, salario final
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       //Inclusión de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//Constantes
	
	
	//Entrada de datos
	char caracter;           //Declaración de variable de entrada
	
	char caracter_convertido;  //Declaración de variable de salida
	
	cout <<"Introduzca un caracter: ";
	cin >> caracter;
	
	//Cálculos
	
	enum class TipoCaracter { mayuscula, minuscula,};
	
	TipoCaracter tipo_de_caracter;
	
	if ((int)caracter > (int)'a' && (int)caracter < (int)'z') {
		tipo_de_caracter = TipoCaracter::minuscula;
		caracter_convertido = (int)caracter - ('a' - 'A');
	}
				
	if ((int)caracter > (int)'A' && (int)caracter < (int)'Z')  {
		tipo_de_caracter = TipoCaracter::mayuscula;
		caracter_convertido = (int)caracter + ('a' - 'A');
	}
	
	//Presentación de resultados
	
	
	switch (tipo_de_caracter) {
		case (TipoCaracter::minuscula) :
			
			cout <<"El caracter era una letra minuscula, "
				 <<"y en mayuscula seria: " <<caracter_convertido;
				 break;
				 
		case (TipoCaracter::mayuscula) :
			
			cout <<"El caracter era una letra mayuscula, "
				 <<"y en minuscula seria: " <<caracter_convertido;
				 break;
				 
		default :
			
			cout <<"El caracter no era una letra";
			break;
	}
	
	return 0;
	
}
				 
