/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Tarifa_Aerea_KM_descuento.cpp: Escribe un programa que calcule el precio de
//un vueloteniendo en cuenta que son 150€ de base a la que se le sumarán 10 cts
//por km. Exprese el precio aplicandole un descuento que indicaremos previamente
//
//Entrada: número de kilómetros, descuento
//Salida: precio del vuelo.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double km, desc;  //Declaración de variables de entrada
	
	double precio;   //Resultado
	
	//Entrada de valores
	cout <<"Introduzca el numero de km hasta su destino: ";
	cin >> km;
	
	cout <<endl;
	cout <<"Introduzca el descuento a aplicar en %: ";
	cin >> desc;

	
	//Cálculos
	
	precio = 150 + (0.1 * km);
	precio = precio - (precio * (desc / 100));
	
	//Salida
	
	cout <<endl;
	cout <<"El precio del viaje es: " <<precio;
	cout <<" euros";
	
	return 0;
	
}
