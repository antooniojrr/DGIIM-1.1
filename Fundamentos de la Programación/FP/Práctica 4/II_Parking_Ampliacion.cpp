/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº17.
//II_Parking_Ampliacion.cpp: actualiza el programa de cálculo de precio
//de estancia en un parking agregando un nuevo tramo horario y cambiando
//el precio de la tarifa plana.
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
	const double CANT_MAX_DIA   = 35.0000; 
	const int MINS_CORTA     =  30;
	const int MINS_MEDIA     =  90;
	const int MINS_LARGA     = 120;	
	const int MINS_MUY_LARGA = 660;
	const int MINS_MAS_LARGA = 900;

	
	
	// Datos de entrada
	int hora_inic, minuto_inic;
	int hora_fin, minuto_fin;
	
	
	bool hora_inic_ok = false; 
	bool hora_fin_ok  = false; 
	bool minuto_inic_ok = false; 
	bool minuto_fin_ok  = false; 
	bool datos_ok = false; 
	
	// Valores calculados
	
	int num_mins;	// Número de minutos en el parking
	double precio;	// Precio final -total- a pagar 
	
	
			
	// Entrada de datos
	
	cout << "Introduzca hora inicial:" << endl;
	cout << "\tHora:    ";
	cin >> hora_inic;

	cout << "\tMinuto:  ";
	cin >> minuto_inic;

    cout << "Introduzca hora final:" << endl;
	cout << "\tHora:    ";
	cin >> hora_fin;		

	cout << "\tMinuto:  ";
	cin >> minuto_fin;
	
	// Comprobar la validez de los datos 
	
 	hora_inic_ok = (hora_inic >= 0 && hora_inic < HORAS_DIA);
	minuto_inic_ok = (minuto_inic >= 0 && minuto_inic < MINS_HORA);
	hora_fin_ok = (hora_fin >= 0 && hora_fin < HORAS_DIA);
 	minuto_fin_ok = (minuto_fin >= 0 && minuto_fin < MINS_HORA);	
		 		
	datos_ok = hora_inic_ok && hora_fin_ok && minuto_inic_ok && minuto_fin_ok; 
	   
		
	// Cálculos
	
	if (datos_ok) {
			
		// 1. Calcular número de minutos entre la entrada y la salida
		
		int mins_hora_inic = (hora_inic*MINS_HORA) + minuto_inic;
		int mins_hora_fin  = (hora_fin*MINS_HORA)  + minuto_fin;
	
		num_mins = mins_hora_fin - mins_hora_inic;
	
		//Calculamos si son de dias diferentes
		bool dia_diferente = (num_mins < 0);
		
		// Si el número de minutos es negativo significa que la hora de entrada
		// corresponde al día anterior
	
		if (dia_diferente) {
	
			// (MINS_DIA - mins_hora_inic) + mins_hora_fin
			// MINS_DIA - mins_hora_inic + mins_hora_fin
			// MINS_DIA + (mins_hora_fin - mins_hora_inic)
			// MINS_DIA + num_mins
	
			num_mins = MINS_DIA + num_mins;
		}

		// El caso más simple es una larguísima permanencia --> precio único
		if (num_mins > MINS_MAS_LARGA) {
		
			precio = CANT_MAX_DIA;
		}
		else { // Calcular precio por tramo, desendentemente
	
			precio = 0; 
		
			int num_mins_quedan = num_mins;
	
			if (num_mins_quedan > MINS_MUY_LARGA){
				precio=precio+(num_mins_quedan-MINS_MUY_LARGA)*CANT_MAS_LARGA;
				num_mins_quedan =  MINS_MUY_LARGA;
			}
			if (num_mins_quedan > MINS_LARGA){
				precio = precio + (num_mins_quedan-MINS_LARGA)*CANT_MUY_LARGA;
				num_mins_quedan = MINS_LARGA;
			}
			if (num_mins_quedan > MINS_MEDIA){
				precio = precio + (num_mins_quedan-MINS_MEDIA)*CANT_LARGA;
				num_mins_quedan =  MINS_MEDIA;	
			}
			if (num_mins_quedan > MINS_CORTA){
				precio = precio + (num_mins_quedan-MINS_CORTA)*CANT_MEDIA;
				num_mins_quedan =  MINS_CORTA;
			}
			if (num_mins_quedan > 0)
				precio = precio + num_mins_quedan*CANT_CORTA;			
		}
		
	}
	

	//Salida de resultados

	if (datos_ok) {
			
		cout << endl;
		cout << "Tarifa final =  "<< setw(6)<< setprecision(2)<< precio <<endl;
		cout << endl;
		cout << "Minutos de estancia = " << num_mins << endl;
		cout << endl;		
	}
	else { // !datos_ok
	
		if (!hora_inic_ok) {
			cout << endl; 
			cout << "ERROR: Hora inicial incorrecta."<< endl; 
			cout << endl; 
		}
		if (!minuto_inic_ok) {
			cout << endl; 
			cout << "ERROR: Minuto inicial incorrecto."<< endl; 
			cout << endl; 
		}
		if (!hora_fin_ok) {
			cout << endl; 
			cout << "ERROR: Hora final incorrecta."<< endl; 
			cout << endl; 
		} 
		if (!minuto_fin_ok) {
 			cout << endl; 
			cout << "ERROR: Minuto final incorrecto."<< endl; 
			cout << endl; 	
		}	 
	}
	
	return 0;	
}
