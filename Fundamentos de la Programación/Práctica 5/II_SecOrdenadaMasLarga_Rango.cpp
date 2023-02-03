/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�43.
//II_SecOrdenadaMasLarga_Rango.cpp: escribe un programa que lea temperaturas
//y guarde la posici�n y la longitud de una subsecuencia de valores ordenados
//crecientemente. El programa leer� valores hasta que se introduzca uno fuera
//de un rango preestablecido.
//
//Entrada: valores de temperatura
//Salida: posici�n y longitud de la subsecuencia
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato 

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Constantes
	
	const double MIN_TEMP_VALIDA = -5 ;	
	const double MAX_TEMP_VALIDA = 40;	
	
	//Declaraci�n de variables de entradas
	
	double temp, temp_anterior;
	int dia_inicial = 1, dia_final = 1;
	int inicio_max = 1, final_max = 1;
	
	
	//Entrada y c�lculos (No es posible separar ambos m�dulos debido al
	//algoritmo usado para recoger los valores)
	
	cout <<"Introduzca la temperatura del primer dia: ";
	cin >> temp;
	
	int dia = 1;
	temp_anterior = temp;
	
	
	if ( temp > MIN_TEMP_VALIDA && temp < MAX_TEMP_VALIDA ) {
	
		cout <<"Introduzca una temperatura: ";
		cin >> temp;
		dia ++;
		
	}
	
	while (temp > MIN_TEMP_VALIDA && temp < MAX_TEMP_VALIDA) {
		
		if (temp_anterior <= temp) dia_final = dia;
		
		else {
			
			if ((final_max - inicio_max) < (dia_final - dia_inicial) ) {
				
				inicio_max = dia_inicial;
				final_max = dia_final;
				
				dia_inicial = dia;
		
			}
		
			else dia_inicial = dia;	
		}
		
					
		temp_anterior = temp;
		
		cout <<"Introduzca una temperatura: ";
		cin >> temp;
		dia ++;
		
	}
	
	
	//Salida de resultados
	
	int longitud = final_max - inicio_max;
	
	cout <<"La mayor subsecuencia de temperaturas crecientes tendra: " <<endl;
	cout <<"\tPosicion: " << inicio_max <<endl;
	cout <<"\tLongitud: " << longitud <<endl;
	
	return 0;
	
}
	
	
		
				
			
		
		
	
	
	
	
	
