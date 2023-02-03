
#include <stdio.h>

int main () {
	
	float radio, circunferencia, circulo;
	
	printf ("Introduce el radio de la circunferencia: ");
	scanf ("%f" ,&radio);
	
	circunferencia = radio*2*3.1416;
	circulo = radio*radio*3.1416;
	
	printf ("La longitud de la circunferencia es %f y el área del círculo es %f" ,circunferencia ,circulo);
}
