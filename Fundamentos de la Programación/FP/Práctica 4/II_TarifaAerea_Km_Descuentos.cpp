/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//II_TarifaAerea_Km_Descuentos.cpp: Escribe un programa que calcule el precio
//de un vuelo teniendo en cuenta el precio base del vuelo, su aumento por km
//y los descuentos aplicables si se dan las condiciones apropiadas
//
//Entrada: kil�metros de vuelo, n�mero de puntos del cliente
//Salida: descuento aplicado, precio final del billete.
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato 

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	const int PRECIO_BASE = 150;    //Declaraci�n de constantes
	const double EUR_KM = 0.1;
	double km;  
	int puntos;         //Declaraci�n de variables de entrada
	
	double precio;   //Resultado
	
	//Entrada de valores
	cout <<"Introduzca el numero de km hasta su destino: ";
	cin >> km;
	
	cout <<"Introduzca los puntos que posee en su tarjeta de fidelizaci�n: ";
	cin >> puntos;
	
	//C�lculos
	
	bool si_700km = (km > 700);                      //Declaraci�n y calculo de 
	bool si_100pts = (puntos > 100 && puntos < 200); //variables bool para 
	bool si_200pts = (puntos > 200);           //aplicar los descuentos m�s tarde
	
	double descuento = (0.02 * si_700km)+(0.03 * si_100pts)+(0.04 * si_200pts);
	precio = (PRECIO_BASE + (EUR_KM * km)) * ( 1 - descuento);
	
	//Salida
	
	cout <<endl;
	cout <<"Descuento aplicado: " <<setw(12) <<setprecision(2) <<descuento * 100 
		 <<"%" <<endl;
	cout <<"El precio del viaje es: " <<setw(8) <<setprecision(2) <<precio;
	cout <<"E";
	
	return 0;
	
}
