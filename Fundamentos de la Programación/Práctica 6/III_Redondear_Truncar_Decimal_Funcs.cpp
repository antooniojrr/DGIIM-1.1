/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 3. Nº13.
//III_Redondear_Truncar_Decimal_Funcs.cpp: escribe un programa que,
//a través de funciones, redondee o trunque un número a cierta cifra decimal
//indicada antes
//
//Entrada: selecciones de menú
//Salida: cálculos dependiendo de cada operacion
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        //Inclusión de los recursos matemáticos

using namespace std;


// Función para calcular potencias enteras.

double Potencia ( double numero, int exponente ) {
	
	double resultado = 1;
	
	if ( exponente >= 0) {
		
		for ( int i = 0; i < exponente ; i ++ ) 
			
			resultado = resultado * numero;
			
	}
	
	else {
		
		for ( int i = 0; i > exponente ; i -- ) 
			
			resultado = resultado / numero;
			
	}
		
		
	return (resultado);
	
}
		

// Función truncar a cierta cifra decimal

double Trunca ( double numero, int cifras ) {
	
	double numero_trunc;
	
	numero_trunc = trunc (numero * Potencia(10 , cifras));
	numero_trunc = numero_trunc / Potencia(10 , cifras);
	
	return numero_trunc;
	
}

// Función redondear a cierta cifra decimal

double Redondea ( double numero, int cifras ) {
	
	double numero_redond;
	
	numero_redond = round (numero * Potencia(10 , cifras));
	numero_redond = numero_redond / Potencia(10 , cifras);
	
	return numero_redond;
	
}

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//Constantes
	
	const char REDOND = 'R';
	const char TRUNC = 'T';
	
	// Entrada de datos
	
	double numero_real;
	
	int numero_cifras;
	
	cout << "Introduzca un numero real: ";
	cin >> numero_real;

	do {
		
		cout <<"Introduzca a la cifra decimal ";
		cout <<"a la que desea truncar o redondear: ";
		cin >> numero_cifras;
		
	} while ( numero_cifras < 0 );
	
	cout << endl;
	cout << "¿Redondear o truncar?" << endl <<endl;
	cout << "\tR -> Redondear" << endl << endl;
	cout << "\tT -> Truncar" << endl << endl;
	
	char eleccion;
	
	do {
		
		cout << "Introduzca una de las opciones: ";
		cin >> eleccion;
		
	}while ( eleccion != REDOND && eleccion != TRUNC);
	
	//Cálculos
	
	double resultado;
	
	if ( eleccion ==  REDOND) 

		resultado = Redondea (numero_real,numero_cifras);
	
	else 
		
		resultado = Trunca (numero_real,numero_cifras);
		
	//Salida de resultados
	
	cout << endl << endl;
	
	cout << "Opcion escogida: ";
	
	if ( eleccion == REDOND ) cout << "REDONDEAR" << endl;
	
	else cout << "TRUNCAR" << endl;
	
	cout << "\t" << numero_real << " ---> " <<setprecision(numero_cifras);
	cout << resultado;
	
	return 0;
	
}
		
		
	
	
	
	
	
	
	


