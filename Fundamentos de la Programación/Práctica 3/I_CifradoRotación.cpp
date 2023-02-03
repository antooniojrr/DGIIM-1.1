/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_CifradoRotación.cpp: Escribe un programa que aplique una codificación a un
//caracter introducido según una clave también introducida por el usuario.
//
//Entrada: letra en mayúscula, clave de codificación
//Salida: letra en mayúscula (Codificada)
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char letra;            //Declaración de variables de entrada
	int clave;
	
	//Para simplificar el programa, usaré la variable char letra para expresar
	//el resultado.
	
	//Entrada de valores
	
	cout <<"Introduzca la clave de codificación: ";
	cin >>clave;
	
	cout <<endl;
	cout <<"Introduzca la letra (Mayuscula) a codificar: ";
	cin >>letra;
	
	//Cálculos
	letra = (int)letra + clave;
	
	if ((int)letra > 90 ) {
		letra = (int)letra - 25;
	}
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"Letra codificada: " <<letra;
	
	return 0;
	
}
	
