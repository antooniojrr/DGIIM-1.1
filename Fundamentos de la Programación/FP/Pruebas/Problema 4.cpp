/******************************************************************************/
//
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//Problema 4: Escribe un programa que muestre en pantalla los valores aproxima_
//dos de PI según las expresiones dadas.
//
//Entrada: -------
//Salida: valores de PI aproximados.
//
/******************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

using namespace std;

int main ()             //Programa Principal
{
	double pi1, pi2, pi3;  //Declaración de variables (Resultados)
	
	//Cálculos
	
	pi1 = 256.0 / 81;
	
	pi2 = 3.0 + (1.0 / 8);
	
	pi3 = 377.0 / 120;
	
	//Declaración de resultados
	
	cout << endl;
	
	cout << "Primera aproximacion de PI: " << pi1 <<endl;
	
	cout << "Segunda aproximacion de PI: " << pi2 <<endl;
	
	cout << "Tercera aproximacion de PI: " << pi3 <<endl;
	
	
}
	
