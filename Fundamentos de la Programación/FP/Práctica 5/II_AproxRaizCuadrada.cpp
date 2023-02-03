/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº82.
//II_AproxRaizCuadrada.cpp: escribe un programa que calcule una aproximación 
//de la raiz cuadrada de un número.
//
//Entrada: número
//Salida: valor aproximado de la raiz
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>    // Formato 
#include <cmath>       //Inclusión de los recursos matemáticos

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Entrada de valores
	
	double numero;
	
	do {
		
		cout <<"Introduzca un numero para realizarle la raiz cuadrada (n>0): ";
		cin >> numero;
		
	} while (numero < 0);
	
	// Cálculos
	
	double i = 0;
	const double SALTO = 0.5;
	
	while ( i <= 16 ) {
	
		int raiz_cercana = 1, raiz_anterior = 0;    //Variables intermedias
		
		while ( raiz_cercana * raiz_cercana <  numero ) {
			
			raiz_anterior = raiz_cercana;
			raiz_cercana = raiz_cercana + 1;
			
		}
		
		int cuadrado_cercano = raiz_cercana * raiz_cercana;
		int cuadrado_anterior = raiz_anterior * raiz_anterior;
		
		//Método del vídeo
		
		bool es_la_mayor = (cuadrado_cercano - numero < numero 
						  - cuadrado_anterior);
		
		double raiz_aprox;
		
		if ( es_la_mayor )
			
			raiz_aprox = raiz_cercana + ((numero - cuadrado_cercano) / 
					   (raiz_cercana * 2));
			
		else {
		
			raiz_aprox = raiz_anterior + ( ( numero - cuadrado_anterior )
					   / ( raiz_anterior * 2 ) );
					  
		}
		
		//Método de triángulos equivalentes
		
		double raiz_aprox2;
		
		int altura_tr = raiz_cercana - raiz_anterior;
		
		int base_tr = cuadrado_cercano - cuadrado_anterior;
		
		double seg_base_tr = numero - cuadrado_anterior;
		
		raiz_aprox2 = raiz_anterior + ( altura_tr * seg_base_tr / base_tr ) ;
		
		double raiz_exacta = sqrt (numero);
		
		//Salida de datos
		
		
		cout << endl;
		cout << "El valor de la raiz cuadrada de " << setprecision(3) <<numero;
		cout << " será:" <<endl <<"\tValor aproximado (M.1)      = ";
		cout << setprecision(3) << setw(8) << raiz_aprox << endl;
		cout <<"\tValor aproximado (M.2)      = ";
		cout << setprecision(3) << setw(8) << raiz_aprox2 << endl;
		cout <<"\tValor exacto (sqrt)         = ";
		cout << setprecision(3) << setw(8) << raiz_exacta << endl;
		
		if (numero == i) i = i + SALTO;
		
		numero = i;
		
	}
	
	
	return 0;
	
}

		
		
	
	
	
	
	
