/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_RitmoVelocidad.cpp: Escribe un programa, que transforme minutos y segundos
//por km a kilometros por hora
//Entrada: minutos y segundos por km
//Salida: km/h.
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std;

int main ()             //Programa Principal
{
	double minutos, segundos;  //Declaraci�n de variables de entrada
	
	double kmhora;   //Resultado
	
	//Entrada de variables
	
	cout <<"Introduce ritmo por km:" <<endl;
	
	cout <<"Minutos: ";
	cin >> minutos;
	cout <<endl;
	
	cout <<"Segundos: ";
	cin >> segundos;
	cout <<endl;
	
	//C�lculos
	
	kmhora = 1 / ( (minutos + segundos / 60) / 60 );
	
	//Presentaci�n de resultados
	
	cout <<"Lleva una velocidad de " <<kmhora <<" km/h";
	
	return 0;
}
