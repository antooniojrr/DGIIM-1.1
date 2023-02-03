/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Cambio.cpp: Escribe un programa que indique cuantas monedas se deberán
//entregar al cliente para completar su vuelta
//
//Entrada: dinero a pagar, dinero pagado
//Salida: monedas de 1€, de 50 cents, de 10 cents, de 5 cents y de 1 cents.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double pagar, pagado;  //Declaración de variables de entrada
	
	int vuelta;        //Variable intermedia
	
	int cambioeur, cambio50, cambio10, cambio5, cambio1;   //Resultado
	
	//Entrada
	
	cout <<"Introduzca el dinero a pagar en euros: ";
	cin >> pagar;
	cout <<endl;
	cout <<"Introduzca el dinero entregado en euros: ";
	cin >> pagado;
	
	//Cálculos
	
	vuelta = (pagado - pagar) * 100;
	
	cambioeur = (vuelta - ( vuelta % 100)) / 100;
	vuelta = vuelta % 100;
	
	cambio50 = (vuelta - ( vuelta % 50)) / 50;
	vuelta = vuelta % 50;
	
	cambio10 = (vuelta - ( vuelta % 10)) / 10;
	vuelta = vuelta % 10;
	
	cambio5 = (vuelta - ( vuelta % 5)) / 5;
	vuelta = vuelta % 5;
	
	cambio1 = vuelta;
	
	
	//Salida
	
	cout <<endl;
	cout <<"Se le deberá entregar al cliente: " <<endl;
	cout <<"Monedas de 1 euro: " <<cambioeur <<endl;
	cout <<"Monedas de 50 cents: " <<cambio50 <<endl;
	cout <<"Monedas de 10 cents: " <<cambio10 <<endl;
	cout <<"Monedas de 5 cents: " <<cambio5 <<endl;
	cout <<"Monedas de 1 cents: " <<cambio1;
	
	return 0;
}
