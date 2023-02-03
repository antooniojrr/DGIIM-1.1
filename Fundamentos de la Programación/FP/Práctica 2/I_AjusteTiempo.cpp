/******************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_AjusteTiempo.cpp: Escribe un programa que exprese de manera correcta la
//cantidad de tiempo (horas, minutos y segundos) introducidos por teclado.
//Entrada: número de horas, minutos y segundos
//Salida: precio del vuelo.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	int horas, minutos, segundos;  //Declaración de variables de entrada
	
	int horasf, minutosf, segundosf, diasf;   //Resultado
	
	//Entrada de variables
	
	cout <<"Indique un numero de horas: ";
	cin >> horas;
	
	cout << endl;
	cout <<"Indique un numero de minutos: ";
	cin >> minutos;
	
	cout << endl;
	cout <<"Indique un numero de segundos: ";
	cin >> segundos;
	
	//Cálculos
	
	segundosf = segundos % 60;
	if (segundos >= 60) {
		minutos = minutos + ((segundos - segundosf) / 60);
	}
	
	minutosf = minutos % 60;
	if (minutos >= 60) {
		horas = horas + ((minutos - minutosf) / 60);
	}
	
	horasf = horas % 24;
	if (horas >= 24) {
		diasf = (horas - horasf) /24;
	}
	
	//Presentación de resultados
	
	cout <<endl;
	cout << "Tiempo introducido: " <<diasf << " dias, ";
	cout <<horasf <<" horas, " <<minutosf <<" minutos y " <<segundosf;
	cout <<" segundos.";
	
	return 0;
}
