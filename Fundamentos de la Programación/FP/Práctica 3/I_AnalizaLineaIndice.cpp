/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//I_AnalizaLineaIndice.cpp: escriba un programa que reciba una cadena de
//caracteres y analice sus datos.
//Entrada: t�tulo de �ndice (variable clase string)
//
//Salida: seccion, subseccion, subsubseccion, titulo, pagina
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S

#include <iomanip>      // Formato 

#include <string>       //Inclusi�n de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	
	string indice;                //Declaraci�n de variable de entrada
	
	//Declaraci�n de variables de salida
	string seccion, subseccion, subsubseccion, titulo, pagina;
	
	//Entrada de valores
	
	cout <<"Introduzca el indice del documento." <<endl;
	getline (cin, indice);
	
	//Asignaci�n de variables de salida
	
	seccion = seccion + indice.at(0) + indice.at(1) + indice.at(2);
	subseccion = subseccion + indice.at(3) + indice.at(4) + indice.at(5);
	subsubseccion = subsubseccion + indice.at(6) + indice.at(7) + indice.at(8);
	
	//En vez de a�adir caracter a caracter, crear� un bucle que a�ada los 40
	//del t�tulo.
	
	int i = 9;
	while (i <=49){
		titulo = titulo + indice.at(i);
		i++;
	}
	
	pagina = pagina + indice.at(50) + indice.at(51) + indice.at(52);
	
	//Presentaci�n de resultados

	cout <<endl;
	cout <<"**************************************************************";
	cout <<endl;
	cout <<"Indice analizado: " <<endl;
	cout <<"|" <<indice <<"|" <<endl;
	cout <<"Componentes:" <<endl;
	cout <<"Seccion:       " <<setw (8) <<seccion <<endl;
	cout <<"Subseccion:    " <<setw (8) <<subseccion <<endl;
	cout <<"Subsubseccion: " <<setw (8) <<subsubseccion <<endl;
	cout <<"Titulo:        " <<setw (48) <<titulo <<endl;
	cout <<"Pagina:        " <<setw (8) <<pagina <<endl;
	cout <<"**************************************************************";
	
	
	return 0;
	
}
	
	
