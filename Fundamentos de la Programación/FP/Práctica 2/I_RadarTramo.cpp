/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_RadarTramo.cpp: Escribe un programa que calcule el tiempo umbral de sanción
//para cada uno de los sectores del radar de tramo.
//
//Entrada: --------
//Salida: tiempo del sector 1 (t1), del sector 2 (t2) y del sector 3 (t3) .
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	
	double t1, t2, t3;   //Resultados
	
	//Cálculos
	
	t1 = (5.3 / 80) * 60 ;
	
	t2 = (8.1 / 100) * 60;
	
	t3 = (6.4 / 80) * 60;
	
	//Salida
	
	cout <<"El tiempo umbral de cada sector será: " <<endl;
	cout <<"Sector 1: " <<t1 <<" minutos" <<endl;
	
	cout <<"Sector 2: " <<t2 <<" minutos" <<endl;
	
	cout <<"Sector 3: " <<t3 <<" minutos" <<endl;
	
	return 0;
	
}
	
