
#include <stdio.h>

int main () {
	
	float intensidad, resistencia, voltaje;
	
	printf ("Introduce la intensidad: ");
	scanf ("%f" ,&intensidad);
	printf ("\nIntroduce la resistencia: ");
	scanf ("%f" ,&resistencia);
	
	voltaje = intensidad * resistencia;
	
	printf ("\nVoltaje: %f" ,voltaje);
	
}
	
