/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_CifradoRotaci�n.cpp: Escribe un programa que aplique una codificaci�n a un
//caracter introducido seg�n una clave tambi�n introducida por el usuario.
//
//Entrada: letra en may�scula, clave de codificaci�n
//Salida: letra en may�scula (Codificada)
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	char letra;            //Declaraci�n de variables de entrada
	int clave;
	
	//Para simplificar el programa, usar� la variable char letra para expresar
	//el resultado.
	
	//Entrada de valores
	
	cout <<"Introduzca la clave de codificaci�n: ";
	cin >>clave;
	
	cout <<endl;
	cout <<"Introduzca la letra (Mayuscula) a codificar: ";
	cin >>letra;
	
	//C�lculos
	letra = (int)letra + clave;
	
	if ((int)letra > 90 ) {
		letra = (int)letra - 25;
	}
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"Letra codificada: " <<letra;
	
	return 0;
	
}
	
