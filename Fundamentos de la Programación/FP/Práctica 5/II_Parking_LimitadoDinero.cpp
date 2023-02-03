/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº31.
//II_Parking_LimitadoDinero.cpp: actualiza el programa de cálculo de precio
//de estancia en un parking haciendo que este calcule cuanto tiempo podrá
//dejar el coche con una cantidad de dinero
//
//Entrada: hora de entrada y hora de salida
//Salida: precio de la estancia.
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>    // Formato 

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const int HORAS_DIA = 24;	
	const int MINS_HORA = 60;	
	const int MINS_DIA  = HORAS_DIA*MINS_HORA;
		
	const double CANT_CORTA     =  0.0412;
	const double CANT_MEDIA     =  0.0370;
	const double CANT_LARGA     =  0.0311;
	const double CANT_MUY_LARGA =  0.0305;
	const double CANT_MAS_LARGA =  0.0270;
	const int MINS_CORTA     =  30;
	const int MINS_MEDIA     =  90;
	const int MINS_LARGA     = 120;	
	const int MINS_MUY_LARGA = 660;
	const int MINS_MAS_LARGA = 900;
	const int INTER_CORTA = MINS_CORTA;
	const int INTER_MEDIA = MINS_MEDIA - MINS_CORTA;
	const int INTER_LARGA = MINS_LARGA - MINS_MEDIA;
	const int INTER_MUY_LARGA = MINS_MUY_LARGA - MINS_LARGA;
	const int INTER_MAS_LARGA = MINS_MAS_LARGA - MINS_MUY_LARGA;
	const double UMBRAL_CORTA = CANT_CORTA * INTER_CORTA;
	const double UMBRAL_MEDIA = UMBRAL_CORTA + (CANT_MEDIA * INTER_MEDIA);
	const double UMBRAL_LARGA = UMBRAL_MEDIA + (CANT_LARGA * INTER_LARGA);
	const double UMBRAL_MUY_LARGA = UMBRAL_LARGA + 
								 (CANT_MUY_LARGA * INTER_MUY_LARGA);
	const double UMBRAL_MAS_LARGA = UMBRAL_MUY_LARGA + 
								 (CANT_MAS_LARGA * INTER_MAS_LARGA);
	
	// Datos de entrada
	int hora_inic, minuto_inic;
	double dinero;
	
	// Valores calculados
	
	int num_mins;	// Número de minutos en el parking
	int min_hora_final;
	int hora_final, minuto_final;	// Hora final del parking 
	
	// Entrada de datos (Con filtros para cada uno de ellos)
	
	cout << "Introduzca hora inicial:" << endl;
		
	do {
		
		cout << "\tHora:    ";
		cin >> hora_inic;
		
	} while ( hora_inic < 0 || hora_inic > HORAS_DIA );
	
	do {
		
		cout << "\tMinuto:  ";
		cin >> minuto_inic;
		
	} while ( minuto_inic < 0 || minuto_inic > MINS_HORA );
		
	cout << endl;
	
	do {
		
    	cout << "Introduzca una cantidad de dinero: ";
		cin >> dinero;
		
	} while ( dinero < 0);
		   
		
	// Cálculos

	
	// 1. Calcular número de minutos de la entrada
	
	int min_hora_inic = (hora_inic*MINS_HORA) + minuto_inic;

	// 2. Calcular el tiempo correspondiente al dinero introducido
	
	double dinero_rest;
	
	if (dinero >= UMBRAL_MAS_LARGA) 
	
		num_mins = MINS_DIA;
	
	else if (dinero >= UMBRAL_MUY_LARGA) {
		
		dinero_rest = dinero - UMBRAL_MUY_LARGA;
		num_mins = MINS_MUY_LARGA + (dinero_rest / CANT_MAS_LARGA);
	}
	
	else if (dinero >= UMBRAL_LARGA) {
		
		dinero_rest = dinero - UMBRAL_LARGA;
		num_mins = MINS_LARGA + (dinero_rest / CANT_MUY_LARGA);
	}
	
	else if (dinero >= UMBRAL_MEDIA) {
		
		dinero_rest = dinero - UMBRAL_MEDIA;
		num_mins = MINS_MEDIA + (dinero_rest / CANT_LARGA);
	}
	
	else if (dinero >= UMBRAL_CORTA) {
		
		dinero_rest = dinero - UMBRAL_CORTA;
		num_mins = MINS_CORTA + (dinero_rest / CANT_MEDIA);
	}
	
	else
	
		num_mins = dinero / CANT_CORTA;


	//Calculamos si son de dias diferentes
	
	min_hora_final = min_hora_inic + num_mins;
	
	bool dia_diferente = (min_hora_final >= MINS_DIA);
	
	// Si el número de minutos de la hora final es mayor que el número de
	// minutos de un día, nos situaremos en un día diferente al de la
	//hora inicial

	if (dia_diferente) {

		min_hora_final = min_hora_final - MINS_DIA;
		
	}
	
	//Calculamos las horas y minutos finales
	
	hora_final = min_hora_final / MINS_HORA;
	minuto_final = min_hora_final % MINS_HORA;

	//Salida de resultados

	cout << endl;
	cout << "Minutos de estancia = " << num_mins << endl;
	cout << endl;		
	cout << "Hora de salida = " << hora_final << " : " << minuto_final;
	cout << endl;
	
	return 0;	
}
