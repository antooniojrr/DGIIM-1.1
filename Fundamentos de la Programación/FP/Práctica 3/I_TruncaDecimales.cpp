/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_TruncaDecimales.cpp: Escribe un programa que trunque un numero real
//a tantas cifras decimales como indique un numero entero introducido
//
//Entrada: número de cifras, número a truncar
//Salida: número truncado
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos
#include <iomanip>    // Formato 

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	int numero_cifras;
	double numero_real; //Declaración de variables de entrada
	
	double numero_trunc;   //Resultado
	
	//Entrada de valores
	
	cout <<"Introduzca el numero real a truncar: ";
	cin >> numero_real;
	
	cout <<"Introduzca el numero de decimales a mostrar: ";
	cin >> numero_cifras;
	
	//Cálculos
	
	numero_trunc = trunc (numero_real * pow(10 , numero_cifras));
	numero_trunc = numero_trunc / pow(10 , numero_cifras);
	
	//Presentación de resultados
	
	cout <<endl;
	cout <<"El numero truncado sera "<<setprecision(numero_cifras)
		 <<numero_trunc;
		 
	return 0;
	
}
	
