/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 5. Nº3.
//V_CambioMonedas_con_caja.cpp: escribe un programa que indique el número
//de monedas de cada tipo que se tendrán que dar a un cliente a modo de vuelta
//teniendo en cuenta las que están en la caja
//
//Entrada: precio de la compra, dinero pagado
//Salida: número de monedas de cada tipo a devolver
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;


const int CENTS_EUR = 100;     // Constante global

/************************************************************************/
// Función para leer un real, sirviendo esta de filtro. Pedirá un número
// hasta que se le introduzca uno correcto.
//
// Entrada: título a mostrar en pantalla a la hora de pedir el número.
// Salida: número real.
/************************************************************************/

double LeeRealPos ( string titulo)
{
	
	string num;
	double real;
	bool Es_Real;
	int longitud;
	bool ya_punto = false;
	
	do {
		
		// Entrada de datos en filtro
		
		cout << titulo;
		getline ( cin, num );
		
		Es_Real = true;
		
		longitud = num.length();
		
		for ( int pos = 0 ; pos <= longitud - 1 && Es_Real ; pos ++ ) {
			
			if ( num.at(pos) > '9' || num.at(pos) < '0') {
				
				if ( (num.at(pos) == '.' || num.at(pos) == ',') && !ya_punto )
				
				ya_punto = true;
				
				else Es_Real = false;
				
				if ( (num.at(pos) == '+' || num.at(pos) == '-') && pos == 0 )
		
				Es_Real = true;
			
			}
			
		}


	} while ( !Es_Real && stod(num) < 0 );
	
	real = stod(num);
	
	return real;
	
}

/************************************************************************/
// Función para expresar el número de monedas a entregar de vuelta.
//
// Entrada: número de monedas, su valor y su nombre.
// Salida: imprimir en pantalla los resultados.
/************************************************************************/

void PonMonedas ( string nombre, double valor, int numero )
{
	
	cout << "\t" << setw(5) << nombre << " ---------> " << numero << " * ";
	cout << valor / CENTS_EUR << " = ";
	cout << numero * valor / CENTS_EUR << endl;
	
}


int main ()                          // Función principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	// Declaración de constantes
	
	const int TIPOS_MONEDA = 8;
	
		// Valor de las monedas en céntimos
		
	const double CENT1 = 1;
	const double CENT2 = 2;
	const double CENT5 = 5;
	const double CENT10 = 10;
	const double CENT20 = 20;
	const double CENT50 = 50;
	const double EUR = 100;
	const double DOSEUR = 200;
	
	const int POS_1CENT = 0;
	const int POS_2CENT = 1;
	const int POS_5CENT = 2;
	const int POS_10CENT = 3;
	const int POS_20CENT = 4;
	const int POS_50CENT = 5;
	const int POS_EUR = 6;
	const int POS_DOSEUR = 7;
	
	// Declaración de los arrays
	
	int caja [TIPOS_MONEDA] = { 10, 0, 10, 10, 3, 0, 10, 25 }; //Arbitrario
	double valor [TIPOS_MONEDA] = { CENT1, CENT2, CENT5, CENT10, CENT20,
								 CENT50, EUR, DOSEUR };
								 
	int vuelta [TIPOS_MONEDA] = {0};
	
	// Entrada de datos
	
	double a_pagar = LeeRealPos ( "Introduzca el importe a pagar: ");
	double pagado =	LeeRealPos ( "Introduzca el importe pagado: ");
	
	
		// Filtro por si el importe a pagar es mayor que el pagado
	
	while ( a_pagar > pagado ) {
		
		cout << "FALTA DINERO POR PAGAR" << endl;
		a_pagar = LeeRealPos ( "Introduzca el importe a pagar: ");
		pagado = LeeRealPos ( "Introduzca el importe pagado: ");
		
	}
	
	
	// Cálculos
	
	double vuelta_total = pagado - a_pagar;
	double vuelta_parcial = vuelta_total * CENTS_EUR;
	
		// La vuelta parcial estará expresada en cents
	
	for ( int i = TIPOS_MONEDA - 1 ; i >= 0 && vuelta_parcial > 0 ; i -- ) {
		
		if ( (int) ( vuelta_parcial / valor[i] ) <= caja[i] ) 
			
			vuelta [i] = (int) ( vuelta_parcial / valor[i] );
		
		else
			
			vuelta [i] = caja [i];
			
		vuelta_parcial -= (vuelta[i] * valor[i]);
		
	}
	
	// Salida de datos
	
	cout << endl << endl;
	
	if ( vuelta_parcial > 0 )
		
		cout << "Lo sentimos, la caja no tiene cambio suficiente." << endl;
		cout <<  "Entregaremos la vuelta lo más aproximada posible " << endl;
	
	
		
	cout << "------------------|CAMBIO A ENTREGAR|------------------";
	cout << endl << endl;
	cout << setw(8) << setprecision(2);
	
	cout << "Precio de la compra = " << a_pagar << "E" << endl;
	cout << "Dinero pagado       = " << pagado << "E" << endl << endl;
	
	cout << setw(5);
	cout << "Vuelta a entregar   = " << pagado <<" - " << a_pagar << " = ";
	cout << vuelta_total << "E" << endl << endl;
	
	cout << "MONEDAS A ENTREGAR: " << endl;
	
	PonMonedas ( "2E      " , valor[POS_DOSEUR], vuelta[POS_DOSEUR] );
	PonMonedas ( "1E      " , valor[POS_EUR], vuelta[POS_EUR] );
	PonMonedas ( "50cnts" , valor[POS_50CENT], vuelta[POS_50CENT] );
	PonMonedas ( "20cnts" , valor[POS_20CENT], vuelta[POS_20CENT] );
	PonMonedas ( "10cnts" , valor[POS_10CENT], vuelta[POS_10CENT] );
	PonMonedas ( "5cnts " , valor[POS_5CENT], vuelta[POS_5CENT] );
	PonMonedas ( "2cnts " , valor[POS_2CENT], vuelta[POS_2CENT] );
	PonMonedas ( "1cnts " , valor[POS_1CENT], vuelta[POS_1CENT] );

	cout << "___________________________________________________________";
	cout << endl;
	
	cout << setw(16) << vuelta_total - vuelta_parcial << "E";
	


	
	return 0;
	
}
	
	
	
	
	
	
	
	
	
	
	
