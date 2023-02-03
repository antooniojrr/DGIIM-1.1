/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_IncrementoSalario.cpp: Escribe un programa que calcule el valor del salario
//incrementado en un 2% del introducido 
//
//Entrada: salario_base
//Salida: salario_base incrementado
//
//He elegido la tercera opci�n ofrecida por el enunciado debido a que me parece
//la m�s sencilla y m�s clara en t�rminos de c�digo.
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double salario_base;  //Declaraci�n de variables de entrada (y tambi�n de salida)
		
		
	//Entrada de variables
	
	cout <<"Introduzca el salario base: ";
	cin >>salario_base;
	
	//C�lculos
	
	salario_base = salario_base * 1.02;
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"Salario incrementado en un 2%: " <<salario_base;
	
	return 0;
	
}
