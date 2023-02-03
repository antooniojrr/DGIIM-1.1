/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_ConversionUnidadesDistancia.cpp: Escribe un programa que muestre la
//conversión de metros a distintas unidades de medida
//
//Entrada: metros
//Salida: conversión a pulgadas, pies, yardas y millas.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double metro;  //Declaración de variables de entrada
	
	double pulgada, pie, yarda, milla;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca el número de metros: ";
	cin >> metro;
	
	//Cálculos
	
	pulgada = metro / (25.4 / 1000);
	
	pie = metro / (30.48 / 100);
	
	yarda = metro / 0.9144;
	
	milla = metro / (1.609344 * 1000);
	
	//Salida
	
	cout <<endl;
	cout <<"Conversión:" <<endl;
	cout <<pulgada <<" pulgadas" <<endl;
	cout <<pie <<" pies" <<endl;
	cout <<yarda <<" yardas" <<endl;
	cout <<milla <<" millas" <<endl;
	
	return 0;
	
}
	
