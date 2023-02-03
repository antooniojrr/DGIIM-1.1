/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 44. Nº5.
// V_Ranking.cpp: escribe un programa que muestre el ranking de atletas
// en diferentes pruebas introducidas previamente ordenado según los 
// tiempos de los atletas
//
//Entrada: pruebas y marcas.
//Salida: ranking de cada prueba
//
/************************************************************************/

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cctype>
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;


// Declaración de constantes
	
const int NUMERO_MESES = 12;
const string MESES[NUMERO_MESES] = { "Enero", "Febrero", "Marzo", "Abril",
									"Mayo", "Junio", "Julio", "Agosto",
									"Septiembre", "Octubre", "Noviembre",
									"Diciembre" };

const int SEG_MIN = 60;
const int MIN_HORA = 60;
const int SEG_HORA = SEG_MIN * MIN_HORA;
const int MILI_SEG = 1000;
const string TERMINADOR = "FIN";
const int LONGITUD_TIEMPO = 12;
const int LONGITUD_FECHA = 10;

	
// Declaración del tipo "struct Fecha" para guardar las fechas de las marcas
// de cada corredor.

struct Fecha {
	
	int dia;   // PRE: 0 < Dia <= 31
	int mes;   // PRE: 0 < Mes <= 12
	int anio;   // PRE: 0 < Año
	
};

/************************************************************************/

// Declaración del tipo "struct Tiempo" para guardar los tiempos de cada
// atleta en la carrera.

struct Tiempo {
	
	int horas;        // PRE: 0 <= Horas < 24
	int minutos;      // PRE: 0 <= Minutos < 60
	int segundos;     // PRE: 0 <= Segundos < 60
	int milisegundos; // PRE: 0 <= Milisegundos < 1000
	
};

/************************************************************************/

/************************************************************************/

// Declaración del tipo "struct Marca" para guardar cada dato que se expresa
// en el string de marca.

struct Marca {
	
	Fecha fecha;
	string nombre;
	Tiempo tiempo;
	
};

/************************************************************************/


/************************************************************************/
// Función para quitar los espacios del principio de un string. Esta asignará
// a una nueva cadena un substr de la original, que comenzará en el momento
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
// Función para quitar los espacios del final de un string. Esta irá
// eliminandolos desde el último carácter hacia el principio hasta que detecte
// que no hay un espacio en la última casilla
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
// Función que combina las dos anteriores para eliminar todos los espacios
// de un string, tanto de delante como intermedios y últimos.
//
// Entrada: cadena
// Salida: cadena sin espacios
//
/************************************************************************/

string EliminaEspacios ( string cad ) {
	
	cad = EliminaUltimosEspacios(EliminaPrimerosEspacios(cad));
	
	string cad_final;
	
	for ( int i = 0; i < cad.length() ; i ++ ) 
		
		if ( !isspace(cad.at(i)) ) cad_final.push_back(cad.at(i));
	
	return cad_final;
	
}

/************************************************************************/

/************************************************************************/
// Función que leerá la fecha de un string y la pasará a un dato tipo 
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
// Función que leerá el tiempo de un string y la pasará a un dato tipo 
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
// Función que transformará un dato tipo "struct Tiempo" en una variable 
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
// Función que imprimirá en pantalla el tiempo de un dato "struct Tiempo" en
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

/************************************************************************/


int main ()				// Función principal
{	

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	const int MAX_PRUEBAS = 20;
	const int MAX_MARCAS_POR_PRUEBA = 100;
	const int MAX_MARCAS = MAX_PRUEBAS * MAX_MARCAS_POR_PRUEBA;
	Marca RegistroMarcas[MAX_PRUEBAS][MAX_MARCAS_POR_PRUEBA];
	
	int num_pruebas;
	int num_marcas_prueba[MAX_PRUEBAS] = {0};
	string pruebas[MAX_PRUEBAS];
	
	string entrada = "";
	string entrada_pruebas;
	
	
	cout << "---------|INTRODUZCA EL NUMERO DE PRUEBAS Y CUALES SON|---------";
	cout << endl;
	
	cin >> num_pruebas;
	
	for ( int i = 0; i < num_pruebas ; i ++ ) {
		
		cin >> pruebas[i];
		
	}
	
	cout << "---------|INTRODUZCA LAS MARCAS DE TODOS LOS ATLETAS|---------";
	cout << endl << endl;
	
	// LECTURA ADELANTADA
	
	int contador = 0;
	
	cout << "\tIntroduzca la marca " << (contador + 1) <<": ";
	getline ( cin, entrada );
	
	entrada = EliminaEspacios(entrada);
	
	for ( int i = 0; i < entrada.length() ; i++ ) 
		
			if ( isalpha(entrada.at(i)) ) entrada.at(i)=toupper(entrada.at(i));

	// No existe filtro para las marcas porque se supone que estas marcas
	// vienen proporcionadas por otro programa que las expresa de manera
	// correcta.
	
	int longitud;
	string prueba;
	bool prueba_recon;
	int lon_prueba;
	int pos_prueba;
	int util;
	string fecha;
	string tiempo;
	int pos_tiempo, lon_nombre, pos_nombre;
	
	while ( entrada != TERMINADOR && contador < MAX_MARCAS ) {
		
		longitud = entrada.length();
		prueba_recon = false;
		lon_prueba = 1;
		
		while ( !prueba_recon && lon_prueba < longitud ) {
			
			prueba = entrada.substr(0,lon_prueba);
			pos_prueba = 0;
			
			while ( pos_prueba < num_pruebas && !prueba_recon ) {
				
				if ( pruebas[pos_prueba] == prueba )
					
					prueba_recon = true;
				
			}
			
		}
		
		fecha =	entrada.substr( lon_prueba - 1 , LONGITUD_FECHA);		
		RegistroMarcas[pos_prueba][num_marcas_prueba[pos_prueba]].fecha = 
															   LeeFecha(fecha);
		
		pos_tiempo = longitud - LONGITUD_TIEMPO;
		tiempo = entrada.substr(pos_tiempo);
		RegistroMarcas[pos_prueba][num_marcas_prueba[pos_prueba]].tiempo = 
															LeeTiempo(tiempo);
		
		pos_nombre = lon_prueba - 1 + LONGITUD_FECHA;
		lon_nombre = pos_tiempo - pos_nombre + 1;
		
		num_marcas_prueba[pos_prueba] ++;
		
		cout << "\tIntroduzca la marca " << (contador + 1) <<": ";
		getline ( cin, entrada );
	
		entrada = EliminaEspacios(entrada);
	
		for ( int i = 0; i < entrada.length() ; i++ ) { 
			
				if ( isalpha(entrada.at(i)) ) 
					entrada.at(i)=toupper(entrada.at(i));
		
		}
		
		contador ++;
	}
	
	// Cálculos
	
	Marca ranking[MAX_PRUEBAS][MAX_MARCAS_POR_PRUEBA];
	
	int pos_mejor;
	
	int resto;
	
	for ( int x = 0 ; x < num_pruebas ; x ++ ) {
		
		resto = num_marcas_prueba[x];
		
		for ( int j = 0 ; j < num_marcas_prueba[x] ; j ++ ) {
		
			pos_mejor = 0;
			
			ranking[x][j] = RegistroMarcas[x][pos_mejor];
			
			for ( int i = 0; i < resto ; i ++ ) {
				
				if ( PasaMiliseg(ranking[x][j].tiempo) > 
								PasaMiliseg(RegistroMarcas[x][i].tiempo) ) {
					
					ranking[x][j] = RegistroMarcas[x][i];
					
					pos_mejor = i;
					
				}
						
			}
		
			for ( int k = pos_mejor ; k < resto ; k ++ )
				
				RegistroMarcas[x][k] = RegistroMarcas[x][k+1];
				
			resto -- ;
			
		}
	
	}
		
	// Salida de resultados
	
	cout << endl << endl;
	cout << "Ranking general." << endl << endl;
	
	for ( int j = 0 ; j < num_pruebas ; j++ ) {
		
		cout << pruebas[j] << endl;
		
		for ( int i = 0; i < util ; i ++ ) {
			
			cout <<"\t" << setw(3) << i+1 << setw(13) << ranking[j][i].nombre;
			
			cout << setw(5) << ranking[j][i].fecha.dia;
			cout << setw(12) << MESES[ranking[j][i].fecha.mes - 1] << setw(6);
			cout << ranking[j][i].fecha.anio << "  ";
			
			ExpresaTiempo ( ranking[j][i].tiempo) ;
			
			cout << endl;
		
		}
		
		cout << endl;
	}
		
	return 0;
	
}
	
	

