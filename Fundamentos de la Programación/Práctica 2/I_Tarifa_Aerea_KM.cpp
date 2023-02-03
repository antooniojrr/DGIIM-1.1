/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Tarifa_Aerea_KM.cpp: Escribe un programa que calcule el precio de un vuelo
//teniendo en cuenta que son 150€ de base a la que se le sumarán 10 cts por km
//
//Entrada: número de kilómetros.
//Salida: precio del vuelo.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double km;  //Declaración de variables de entrada
	
	double precio;   //Resultado
	
	//Entrada de valores
	cout <<"Introduzca el numero de km hasta su destino: ";
	cin >> km;
	
	//Cálculos
	
	precio = 150 + (0.1 * km);
	
	//Salida
	
	cout <<endl;
	cout <<"El precio del viaje es: " <<precio;
	cout <<" euros";
	
	return 0;
	
}
