/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_IncrementoSalario.cpp: Escribe un programa que calcule el valor del salario
//incrementado en un 2% del introducido 
//
//Entrada: salario_base
//Salida: salario_base incrementado
//
//He elegido la tercera opción ofrecida por el enunciado debido a que me parece
//la más sencilla y más clara en términos de código.
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double salario_base;  //Declaración de variables de entrada (y también de salida)
		
		
	//Entrada de variables
	
	cout <<"Introduzca el salario base: ";
	cin >>salario_base;
	
	//Cálculos
	
	salario_base = salario_base * 1.02;
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"Salario incrementado en un 2%: " <<salario_base;
	
	return 0;
	
}
