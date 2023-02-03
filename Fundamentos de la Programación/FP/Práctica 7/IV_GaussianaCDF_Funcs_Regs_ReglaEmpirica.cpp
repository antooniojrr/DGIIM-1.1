/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 3. N�13.
//IV_GaussianaCDF_Funcs_Regs_ReglaEmpirica.cpp: escribe un programa que,
//a trav�s de funciones, realice la evaluaci�n de la gaussiana en un x
//determinado y CDF de la funci�n de dos formas diferentes.
//
//Entrada: par�metros de la funci�n y x donde y hasta donde evaluar.
//Salida: g(x), CDF de ambos m�todos.
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        //Inclusi�n de los recursos matem�ticos
#include <string>       // Inclusi�n de la clase "string"

using namespace std;

//Declaraci�n del tipo "struct Gaussiana", que contendr� sus par�metros sigma
// y mu, adem�s de la x en la que calcularla

struct Gaussiana
{
	double sigma;
	double mu;
	double x;
	
};

// Funci�n para calcular la gaussiana en un x determinado

double gaussiana ( struct Gaussiana gauss ) {
	
	const double PI = 3.1415;
	double g;
	
	g = ( 1 / ( gauss.sigma * sqrt ( 2 * PI ) ) ) *
		exp( -0.5 *( pow ( (gauss.x - gauss.mu ) / gauss.sigma , 2 ) ) );
									
	return g;
	
}

/************************************************************************/
// M�todo 1 para calcular el CDF de la gaussiana. Este m�todo consiste en
// simular una integral con la suma de diferenciales de 0.25.
//
// Entrada: dato de tipo "struct Gaussiana"
// Salida: CDF
/************************************************************************/

double CDF_met1 ( struct Gaussiana gauss ) {
	
	const double DELTA = 0.25;
	
	double x_inicial = gauss.mu - (3 * gauss.sigma);
	double x_inter, suma = 0, g, x_final;
	
	if ( x_inicial < gauss.x) {
		
		x_inter = x_inicial;
		x_final = gauss.x;
		
		while (x_inter <= x_final ) {
			
			gauss.x = x_inter;
			
			g = gaussiana ( gauss );
			
			suma = suma + g;
			
			x_inter = x_inter + DELTA;
			
		}
		
	}
	
	else {
		
		x_inter = gauss.x;
		
		while (x_inter <= x_inicial ) {
			
			g = gaussiana ( gauss );
			
			suma = suma + g ;
			
			x_inter = x_inter + DELTA;
			
			gauss.x = x_inter;
			
		}
		
	}
	
	return ( suma * DELTA );
	
}

/************************************************************************/
// M�todo 2 para calcular el CDF de la gaussiana. Este se basa en una
// expresi�n predefinida.
//
// Entrada: dato de tipo "struct Gaussiana"
// Salida: CDF
/************************************************************************/

double CDF_met2 ( struct Gaussiana gauss ) {
	
	const double B0 = 0.2316419, B1 = 0.319381530, B2 = -0.356563782;
	const double B3 = 1.781477937, B4 = -1.821255978, B5 = 1.330274429;
	
	double x_estand = ( gauss.x - gauss.mu ) / gauss.sigma;
		
	double t = 1 / 1 + ( B0 * abs ( x_estand ) );
	
	double term;
	
	term = (B1 * t) + (B2 * pow(t,2)) + (B3 * pow(t,3)) + (B4 * pow(t,4))
			+ (B5 * pow(t,5));
	
	gauss.x = x_estand;
	gauss.mu = 0;
	gauss.sigma = 1;
	
	double cdf = 1 - ( gaussiana (gauss) * term );
	
	if ( x_estand < 0 ) cdf = 1 - cdf ;
	
	return cdf;
	
}

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//Entrada de variables
	
	struct Gaussiana gauss;
	bool continuar;
	string respuesta;
	
	do {
		
		do {
			
			cout <<"Introduzca el valor del par�metro SIGMA de la expresi�n: ";
			cin >> gauss.sigma;
		
		}while ( gauss.sigma <= 0 );
		
		cout <<endl;
		cout <<"Introduzca el valor del par�metro MU de la expresi�n: ";
		cin >> gauss.mu;
		
		cout <<endl;
		
		int min = gauss.mu - ( 3 * gauss.sigma );
		int max = gauss.mu + ( 3 * gauss.sigma );
		
		do {
			
			cout <<"Escribe X hasta la que calcular el CDF de la Gaussiana: ";
			cin >> gauss.x;
			
		} while ( gauss.x < min || gauss.x > max );
		
		
		// C�lculos
		
		double g = gaussiana ( gauss );
		
		double cdf_1 = CDF_met1 ( gauss);
		
		double cdf_2 = CDF_met2 ( gauss);
		
		//Resultados
		
		cout << "--------------------|RESULTADOS|--------------------";
		cout << endl << endl;
		
		cout << "\tGaussiana (" << gauss.x << ") = " << g << endl;
		cout << "\tCDF (Metodo 1) = " << cdf_1 << endl;
		cout << "\tCDF (Metodo 2) = " << cdf_2 << endl << endl;
		
		do {
			
			cout << "�Quiere continuar? SI/NO" << endl << "\t";
			cin >> respuesta;
		
			respuesta.at(0) = toupper(respuesta.at(0));
			respuesta.at(1) = toupper(respuesta.at(1));
			
		} while ( respuesta != "SI" && respuesta != "NO" );
		
		cout << endl << endl;
		
		if (respuesta == "SI" ) continuar = true;
		
		else continuar == false;
		
	} while (continuar);

	return 0;
		
}
	
	


	
									
	
