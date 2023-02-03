/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_RitmoVelocidad.cpp: Escribe un programa, que transforme km por hora
//a minutos y segundos por km
//Entrada: minutos y segundos por km
//Salida: km/h.
//
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std;

int main ()             //Programa Principal
{
	double kmhora;  //Declaraci�n de variables de entrada
	
	int minutos, segundos;   //Resultado
	
	//Entrada de variables
	
	cout <<"Introduce la velocidad en km/h: ";
	cin >> kmhora;
	cout <<endl;
	
	//C�lculos
	
	segundos = (1 / kmhora)  * 3600;
	minutos = (segundos - (segundos % 60) ) / 60;
	segundos = segundos % 60;
	
	//Presentaci�n de resultados
	
	cout <<"Lleva un ritmo de " <<minutos <<" minutos y " <<segundos;
	cout <<" segundos por km";
	
	return 0;
}
