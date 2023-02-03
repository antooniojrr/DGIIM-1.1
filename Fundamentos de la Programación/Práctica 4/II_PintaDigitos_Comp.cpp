/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//II_PintaDigitos_Comp.cpp: Escribe un programa que lea un numero entero
//cuyas cifras est�n separadas por dos espacios en blanco en un string
//
//Entrada: letra en min�scula
//Salida: letra en may�scula
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <string>       //Inclusi�n de la clase string
#include <iomanip>      //Formato

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	string entrada_num;  //Declaraci�n de variables de entrada
	
	int numero;          //Declaraci�n de variables de salida
	
	//Entrada de valores
	
	cout <<"Introduzca un numero de 3 cifras separando cada una con dos"
		 <<" espacios: " <<endl;
	getline (cin, entrada_num);
	
	char cifra1, cifra2, cifra3;
	
	cifra1 = entrada_num.at(0);
	cifra2 = entrada_num.at(3);
	cifra3 = entrada_num.at(6);
		
	//Comprobaci�n de errores
	
	bool ok1 = (cifra1 >= '1' && cifra1 <= '9');
	bool ok2 = (cifra2 >= '1' && cifra2 <= '9');
	bool ok3 = (cifra3 >= '1' && cifra3 <= '9');
	
	if ( !ok1 || !ok2 || !ok3 ) {
		cout <<"----------------ERROR----------------" <<endl;
		
		cout <<"Introduzca una cadena valida (Formato: |1  2  3|): " <<endl;
		
		getline (cin, entrada_num);
	}
	
	//C�lculos
	
	string cifras_juntas;    //Declaraci�n de variable intermedia
	
	cifras_juntas.push_back(cifra1);
	cifras_juntas.push_back(cifra2);
	cifras_juntas.push_back(cifra3);
	numero = stoi (cifras_juntas);
	
	//Presentaci�n de resultados
	
	cout <<endl;
	cout <<"El numero introducido ser�: " <<numero;
	
	return 0;
}
	
	
	
	
	
	
	
	
