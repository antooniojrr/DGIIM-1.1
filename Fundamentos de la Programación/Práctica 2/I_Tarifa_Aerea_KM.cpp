/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_Tarifa_Aerea_KM.cpp: Escribe un programa que calcule el precio de un vuelo
//teniendo en cuenta que son 150� de base a la que se le sumar�n 10 cts por km
//
//Entrada: n�mero de kil�metros.
//Salida: precio del vuelo.
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double km;  //Declaraci�n de variables de entrada
	
	double precio;   //Resultado
	
	//Entrada de valores
	cout <<"Introduzca el numero de km hasta su destino: ";
	cin >> km;
	
	//C�lculos
	
	precio = 150 + (0.1 * km);
	
	//Salida
	
	cout <<endl;
	cout <<"El precio del viaje es: " <<precio;
	cout <<" euros";
	
	return 0;
	
}
