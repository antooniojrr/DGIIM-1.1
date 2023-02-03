/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_ConsumoGasolina.cpp: Escribe un programa que calcule el consumo de gasolina
//y haga una previsión de la autonomía del coche en función de los litros
//restantes
//
//Entrada: km recorridos, litros gastados, litros restantes
//Salida: km/litro, litros cada 100 km, autonomía restante del coche
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double kmrecorr,litrosgast,litrosrest; //Declaración de variables de entrada
	
	double kmlitro, litros100km, kmrest;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca los km recorridos: ";
	cin >> kmrecorr;
	cout <<endl;
	
	cout <<"Introduzca los litros de gasolina gastados: ";
	cin >> litrosgast;
	cout <<endl;
	
	cout <<"Introduzca los litros restantes en el depósito: ";
	cin >> litrosrest;
	
	//Cálculos
	
	kmlitro = kmrecorr / litrosgast;
	
	litros100km = (1 / kmlitro) * 100;
	
	kmrest = kmlitro * litrosrest;
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"El coche tiene un autonomía de " <<kmlitro <<" Km/litro" <<endl;
	cout <<"Consume " <<litros100km <<" litros cada 100 Km" <<endl;
	cout <<"Con la gasolina restante, podrá recorrer " <<kmrest <<" Km más";
	
	return 0;
}
	
