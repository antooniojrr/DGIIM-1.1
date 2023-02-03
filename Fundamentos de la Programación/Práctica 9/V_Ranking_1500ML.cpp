/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 29. N�5.
// V_Ranking_1500ML.cpp: escribe un programa que organice todas las marcas
// que han conseguido atletas en una carrera de menor a mayor tiempo.
//
//Entrada: marcas de cada corredor
//Salida: marcas ordenadas
//
/************************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusi�n del tipo "string"
#include <cctype>
#include <cmath>        // Inclusi�n de los recursos matem�ticos

using namespace std;


// Declaraci�n de constantes
	
const int NUMERO_MESES = 12;
const string MESES[NUMERO_MESES] = { "Enero", "Febrero", "Marzo", "Abril",
									"Mayo", "Junio", "Julio", "Agosto",
									"Septiembre", "Octubre", "Noviembre",
									"Diciembre" };

const int SEG_MIN = 60;
const int MIN_HORA = 60;
const int SEG_HORA = SEG_MIN * MIN_HORA;
const int MILI_SEG = 1000;
const int MAX_ATLETAS = 100;
const string TERMINADOR = "FIN";
const int LONGITUD_TIEMPO = 12;
const int LONGITUD_FECHA = 10;

	
// Declaraci�n del tipo "struct Fecha" para guardar las fechas de las marcas
// de cada corredor.

struct Fecha {
	
	int dia;   // PRE: 0 < Dia <= 31
	int mes;   // PRE: 0 < Mes <= 12
	int anio;   // PRE: 0 < A�o
	
};

/************************************************************************/

// Declaraci�n del tipo "struct Tiempo" para guardar los tiempos de cada
// atleta en la carrera.

struct Tiempo {
	
	int horas;        // PRE: 0 <= Horas < 24
	int minutos;      // PRE: 0 <= Minutos < 60
	int segundos;     // PRE: 0 <= Segundos < 60
	int milisegundos; // PRE: 0 <= Milisegundos < 1000
	
};

/************************************************************************/

/************************************************************************/

// Declaraci�n del tipo "struct Marca" para guardar cada dato que se expresa
// en el string de marca.

struct Marca {
	
	Fecha fecha;
	string nombre;
	Tiempo tiempo;
	
};

/************************************************************************/


/************************************************************************/
// Funci�n para quitar los espacios del principio de un string. Esta asignar�
// a una nueva cadena un substr de la original, que comenzar� en el momento
// en el que se detecte un caracter diferente a un espacio
//
// Entrada: cadena.
// Salida: cadena sin espacios al principio.
//
/************************************************************************/

string EliminaPrimerosEspacios ( string cad ) {
	
	int pos = 0;
	int longitud = cad.length();
	
	while ( pos < longitud && isspace(cad.at(pos)) )
		
		pos ++;
		
	cad = cad.substr(pos);
	
	return cad;
	
}

/************************************************************************/

/************************************************************************/
// Funci�n para quitar los espacios del final de un string. Esta ir�
// eliminandolos desde el �ltimo car�cter hacia el principio hasta que detecte
// que no hay un espacio en la �ltima casilla
//
// Entrada: cadena.
// Salida: cadena sin espacios al final.
//
/************************************************************************/

string EliminaUltimosEspacios ( string cad ) {
	
	
	while ( cad.length() > 1 && isspace(cad.back()) )
		
		cad.pop_back();

	
	return cad;
	
}
	
/************************************************************************/
// Funci�n que combina las dos anteriores para eliminar todos los espacios
// de un string, tanto de delante como intermedios y �ltimos.
//
// Entrada: cadena
// Salida: cadena sin espacios
//
/************************************************************************/

string EliminaEspacios ( string cad ) {
	
	cad = EliminaUltimosEspacios(EliminaPrimerosEspacios(cad));
	
	string cad_final = "";
	
	for (  int i = 0 ; i < cad.length() ; i ++ ) 
		
		if ( !isspace(cad.at(i)) ) cad_final.push_back(cad.at(i));
	
	return cad_final;
	
}

/************************************************************************/

/************************************************************************/
// Funci�n que leer� la fecha de un string y la pasar� a un dato tipo 
// "struct Fecha".
//
// Entrada: string de la fecha
// Salida: dato tipo struct Fecha
//
// PRE: adapatado al formato del ejercicio ( dd/mm/aaaa )
/************************************************************************/

Fecha LeeFecha ( string cad ) {
	
	string dia = cad.substr(0, 2);
	string mes = cad.substr(3, 2);
	string anio = cad.substr(6, 4);
	
	Fecha fecha;
	
	fecha.dia = stoi(dia);
	fecha.mes = stoi(mes);
	fecha.anio = stoi(anio);
	
	return fecha;
	
}

/************************************************************************/

/************************************************************************/
// Funci�n que leer� el tiempo de un string y la pasar� a un dato tipo 
// "struct Tiempo".
//
// Entrada: string del tiempo
// Salida: dato tipo struct tiempo
//
// PRE: adapatado al formato del ejercicio ( hh:mm:ss:mmm )
/************************************************************************/

Tiempo LeeTiempo ( string cad ) {
	
	string horas = cad.substr( 0, 2 );
	string minutos = cad.substr( 3, 2 );
	string segundos = cad.substr( 6, 2 );
	string miliseg = cad.substr( 9, 3 );
	
	
	Tiempo tiempo;
	tiempo.horas = stoi(horas);
	tiempo.minutos = stoi(minutos);
	tiempo.segundos = stoi(segundos);
	tiempo.milisegundos = stoi(miliseg);
	
	return tiempo;
	
}

/************************************************************************/
	
/************************************************************************/
// Funci�n que transformar� un dato tipo "struct Tiempo" en una variable 
// double segundos, convirtiendo horas, minutos y milisegundos en esta
// magnitud
//
// Entrada: dato tipo struct tiempo
// Salida: double segundos
//
/************************************************************************/

double PasaMiliseg ( Tiempo tiempo ) {
	
	int milisegundos = 0;
	
	milisegundos += tiempo.horas * SEG_HORA * MILI_SEG;
	milisegundos += tiempo.minutos * SEG_MIN * MILI_SEG;
	milisegundos += tiempo.segundos * MILI_SEG;
	
	return milisegundos;
	
}

/************************************************************************/

/************************************************************************/
// Funci�n que imprimir� en pantalla el tiempo de un dato "struct Tiempo" en
// formato hh:mm:ss:mmm
//
// Entrada: dato tipo struct tiempo
// Salida: en pantalla
//
/************************************************************************/

void ExpresaTiempo ( Tiempo tiempo) {
	
	cout << setw(2) << tiempo.minutos;
	cout << ":" << setw(2) << tiempo.segundos;
	cout << ":" << setw(3) << tiempo.milisegundos;
	
}
int main ()				// Funci�n principal
{	

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	Marca marcas[MAX_ATLETAS];
	
	int util = 0;
	string entrada;
	
	cout << "---------|INTRODUZCA LAS MARCAS DE TODOS LOS ATLETAS|---------";
	cout << endl << endl;
	
	// LECTURA ADELANTADA
	
	cout << "\tIntroduzca la marca " << (util + 1) <<": ";
	getline ( cin, entrada );
	
	entrada = EliminaEspacios(entrada);
	
	for ( int i = 0; i < entrada.length() ; i++ ) 
		
			if ( isalpha(entrada.at(i)) ) entrada.at(i)=toupper(entrada.at(i));

	// No existe filtro para las marcas porque se supone que estas marcas
	// vienen proporcionadas por otro programa que las expresa de manera
	// correcta.
	
	int pos_tiempo;
	int longitud_nombre;
	
	while ( entrada != TERMINADOR && util < MAX_ATLETAS ) {
		
		marcas[util].fecha = LeeFecha ( entrada.substr( 0, LONGITUD_FECHA ) );
		
		longitud_nombre = entrada.length() - LONGITUD_TIEMPO - LONGITUD_FECHA;
		
		pos_tiempo = entrada.length() - LONGITUD_TIEMPO;
		
		marcas[util].nombre = 
							entrada.substr((LONGITUD_FECHA-1),longitud_nombre);
			
		marcas[util].tiempo = LeeTiempo ( entrada.substr(pos_tiempo) );
					
		util ++;
		
		cout << "\tIntroduzca la marca " << (util + 1) <<": ";
		getline ( cin, entrada );
		
		entrada = EliminaEspacios(entrada);
		
		for ( int i = 0; i < entrada.length() ; i++ ) 
		
			if ( isalpha(entrada.at(i)) ) entrada.at(i)=toupper(entrada.at(i));
	
		
		
	}
	
	// C�lculos
	
	Marca resultados[MAX_ATLETAS];
	
	int pos_mejor;
	
	int resto = util;
	
	for ( int j = 0 ; j < util ; j ++ ) {
		
		pos_mejor = 0;
		
		resultados[j] = marcas[pos_mejor];
		
		for ( int i = 0; i < resto ; i ++ ) {
			
			if ( PasaMiliseg(resultados[j].tiempo) > 
											PasaMiliseg(marcas[i].tiempo) ) {
				
				resultados[j] = marcas[i];
				
				pos_mejor = i;
				
			}
					
		}
	
		for ( int k = pos_mejor ; k < resto ; k ++ )
			
			marcas[k] = marcas[k+1];
			
		resto -- ;
		
	}
	
	// Salida de resultados
	
	cout << endl << endl;
	cout << "Ranking de la prueba: 1500ML" << endl << endl;
	
	for ( int i = 0; i < util ; i ++ ) {
		
		cout << setw(3) << i+1 << setw(13) << resultados[i].nombre;
		
		cout << setw(5) << resultados[i].fecha.dia;
		cout << setw(12) << MESES[resultados[i].fecha.mes - 1] << setw(6);
		cout << resultados[i].fecha.anio << "  ";
		
		ExpresaTiempo ( resultados[i].tiempo) ;
		
		cout << endl;
	
	}
	
	return 0;
	
}
	
	
	
	
	
	
	
	
	

