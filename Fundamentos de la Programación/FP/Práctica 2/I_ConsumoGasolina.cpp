/******************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_ConsumoGasolina.cpp: Escribe un programa que calcule el consumo de gasolina
//y haga una previsi�n de la autonom�a del coche en funci�n de los litros
//restantes
//
//Entrada: km recorridos, litros gastados, litros restantes
//Salida: km/litro, litros cada 100 km, autonom�a restante del coche
/******************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double kmrecorr,litrosgast,litrosrest; //Declaraci�n de variables de entrada
	
	double kmlitro, litros100km, kmrest;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca los km recorridos: ";
	cin >> kmrecorr;
	cout <<endl;
	
	cout <<"Introduzca los litros de gasolina gastados: ";
	cin >> litrosgast;
	cout <<endl;
	
	cout <<"Introduzca los litros restantes en el dep�sito: ";
	cin >> litrosrest;
	
	//C�lculos
	
	kmlitro = kmrecorr / litrosgast;
	
	litros100km = (1 / kmlitro) * 100;
	
	kmrest = kmlitro * litrosrest;
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"El coche tiene un autonom�a de " <<kmlitro <<" Km/litro" <<endl;
	cout <<"Consume " <<litros100km <<" litros cada 100 Km" <<endl;
	cout <<"Con la gasolina restante, podr� recorrer " <<kmrest <<" Km m�s";
	
	return 0;
}
	
