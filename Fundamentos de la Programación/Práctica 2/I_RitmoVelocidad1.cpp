/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_RitmoVelocidad.cpp: Escribe un programa, que transforme minutos y segundos
//por km a kilometros por hora
//Entrada: minutos y segundos por km
//Salida: km/h.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	double minutos, segundos;  //Declaración de variables de entrada
	
	double kmhora;   //Resultado
	
	//Entrada de variables
	
	cout <<"Introduce ritmo por km:" <<endl;
	
	cout <<"Minutos: ";
	cin >> minutos;
	cout <<endl;
	
	cout <<"Segundos: ";
	cin >> segundos;
	cout <<endl;
	
	//Cálculos
	
	kmhora = 1 / ( (minutos + segundos / 60) / 60 );
	
	//Presentación de resultados
	
	cout <<"Lleva una velocidad de " <<kmhora <<" km/h";
	
	return 0;
}
