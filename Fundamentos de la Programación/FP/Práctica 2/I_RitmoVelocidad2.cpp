/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_RitmoVelocidad.cpp: Escribe un programa, que transforme km por hora
//a minutos y segundos por km
//Entrada: minutos y segundos por km
//Salida: km/h.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	double kmhora;  //Declaración de variables de entrada
	
	int minutos, segundos;   //Resultado
	
	//Entrada de variables
	
	cout <<"Introduce la velocidad en km/h: ";
	cin >> kmhora;
	cout <<endl;
	
	//Cálculos
	
	segundos = (1 / kmhora)  * 3600;
	minutos = (segundos - (segundos % 60) ) / 60;
	segundos = segundos % 60;
	
	//Presentación de resultados
	
	cout <<"Lleva un ritmo de " <<minutos <<" minutos y " <<segundos;
	cout <<" segundos por km";
	
	return 0;
}
