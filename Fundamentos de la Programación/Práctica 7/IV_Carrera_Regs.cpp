/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 4. Nº6.
//IV_Carrera_Regs.cpp: escribe un programa que calcule distintos datos 
//de interés tras una carrera como la velocidad y ritmo de los corredores
//y el tiempo empleado en la carrera.
//
//Entrada: instante de inicio de la carrera, instante de llegada y
//longitud del recorrido.
//Salida: duracion de la carrera, ritmo y velocidad.
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

//Declaración de tipo struct

struct Instante {
	double horas;
	double minutos;
	double segundos;
};

//Funciones

int LeeHoras () 
{
	int tiempo;

	do {
		
		cout << "Introduce la hora (formato 24 horas): ";
		cin >> tiempo;
		
	} while (tiempo < 0 || tiempo >= 24);

	return tiempo;
}

int LeeMinutos () 
{
	int tiempo;

	do {
		
		cout << "Introduce los minutos: ";
		cin >> tiempo;
		
	} while (tiempo < 0 || tiempo >= 60);

	return tiempo;
}

int LeeSegundos () 
{
	int tiempo;

	do {
		
		cout << "Introduce los segundos: ";
		cin >> tiempo;
		
	} while (tiempo < 0 || tiempo >= 60);

	return tiempo;
}

int main ()                      //Programa Principal
{                       
	//Declaración de constantes
	
	const int CONV_SEXAGESIMAL = 60;
	const int HORAS_DIA = 24;

	//Declaración de variables
	
	Instante inicio, final, total;
	
	double distancia, dorsal, km_h, min_km;
	
	double total_mins, total_horas;

	//Entrada de datos iniciales
	
	cout << "Introduce el momento de inicio de la carrera: " << endl;
	
	inicio.horas = LeeHoras(); 
	
	inicio.minutos = LeeMinutos();
	
	inicio.segundos = LeeSegundos();

	do {
		
		cout << "Introduce la distancia de la carrera en km: ";
		cin >> distancia;
		
	} while (distancia <= 0);


	do {
		
		cout << "\nIntroduce el número de dorsal (>0): ";
		cin >> dorsal;

		if (dorsal > 0) {

			cout << "Introduce los datos de llegada: " << endl;
			
			final.horas = LeeHoras(); 
			final.minutos = LeeMinutos();
			final.segundos = LeeSegundos();

			if ( inicio.segundos > final.segundos ) {
				
				total.segundos = final.segundos + CONV_SEXAGESIMAL 
								- inicio.segundos;
				final.minutos -= 1;
				
			}
			
			else total.segundos = final.segundos - inicio.segundos;
			
			if ( inicio.minutos > final.minutos ) {
				
				total.minutos = final.minutos + CONV_SEXAGESIMAL 
								- inicio.minutos;
				final.horas -= 1;
				
			}
			
			else total.minutos = final.minutos - inicio.minutos;
			
			
			if ( inicio.horas > final.horas )
				
				total.horas = final.horas + HORAS_DIA - inicio.horas;
				
			
			else total.horas = final.horas - inicio.horas;

			
			total_mins = total.minutos + (total.horas * CONV_SEXAGESIMAL) +
						(total.segundos / CONV_SEXAGESIMAL);
						
			total_horas = total_mins / CONV_SEXAGESIMAL;
						
			km_h = distancia / total_horas;
			
			min_km = total_mins / distancia;

			cout << "El dorsal número " << dorsal << " ha completado la carrera"
				 << " en " << total.horas << ":" << total.minutos << ":" 
				 << total.segundos << "." << endl;
			cout << "Su ritmo ha sido " << km_h << " km/h || " << min_km 
				 << " min/km." << endl;
		}	 
	} while (dorsal > 0);

	cout << "No has introducido un dorsal positivo." << "\nFin del programa.";

	return 0;
}
