/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº83.
//II_BinToDec.cpp: escribe un programa que pase cualquier número binario
//a decimal. 
//
//Entrada: número binario 
//Salida: número decimal
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      //Formato 
#include <cmath>        //Inclusión de los recursos matemáticos
#include <string>       //Inclusión de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// Entrada de valores
	
	string num_bin;
	bool todo_ok = true;
	
	do {
		
		cout <<"Introduzca un número en forma binaria:" << endl;
		cin >> num_bin;
		
		int i = num_bin.length() - 1;
		
		while (i >= 0 && todo_ok) {
			
			if (num_bin.at(i) != '1' && num_bin.at(i) != '0' ) todo_ok = false;
			
			i --;
			
		}
		
	} while ( !todo_ok);
	
	//Cálculos
	
	int num_dec = 0;
	int exponente = num_bin.length() - 1;
	int posicion = 0;
	
	while ( posicion <= (num_bin.length() - 1) ) {
		
		if (num_bin.at(posicion) == '1')
		 
			num_dec = num_dec + pow(2,exponente);
			
		exponente --;
		posicion ++;
		
	}
	
	//Salida de resultados
	
	cout << endl;
	cout << "Numero BINARIO = | " << num_bin << " |" << endl;
	cout << "Numero DECIMAL = " << num_dec << endl;
	
	
		
	return 0;
	
}
			
			
	
	
	
	
	
	
