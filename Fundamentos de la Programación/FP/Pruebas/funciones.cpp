// FUNCIONES

#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"
#include <cmath>        // Inclusión de los recursos matemáticos

using namespace std;

/************************************************************************/

string EliminaPrimerosSeparadores (string cadena)
{
	int posicion = 0;
	int tamanio = cadena.length();
	
	while (isspace(cadena.at(posicion) && posicion < tamanio)) {
		posicion++;
	}
	
	string local;
	while (posicion < tamanio) {
		local.push_back(cadena.at(posicion));
		posicion++;
	}
		
	return local;
}

/************************************************************************/

string EliminaUltimosSeparadores (string cadena)
{
	int longitud = cadena.length();
	
   	while (longitud > 0 && isspace(cadena.back())) {
		cadena.pop_back();
		longitud = cadena.length();
	}
        
	return cadena;
}

/************************************************************************/

string EliminaSeparadoresTotales (string cadena)
{	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

/************************************************************************/

bool EsEntero (string entrada)
{
	entrada = EliminaSeparadoresTotales(entrada);
	
	int pos;
	bool es_entero = true;
	int tamanio = entrada.length();
	bool tiene_signo = (entrada.at(0) == '-' || entrada.at(0) == '+');
	
	if (tiene_signo) {
		
		pos = 1;
		
		if (pos == tamanio) {
			
			es_entero = false;
		}
	}
	else {
		
		pos = 0;
	}
		
	while (pos < tamanio&& es_entero) {
		char char_actual = entrada.at(pos);
		es_entero = isdigit(char_actual);
		pos++;
	}
	
	if (entrada.length() == 0) {
		
		es_entero = false;
	}
	
	return es_entero;
}

/************************************************************************/

int LeeEntero (string titulo)
{
	string entrada;
	
	do {
		cout << titulo;
		getline(cin, entrada);
	} while (!EsEntero(entrada));

	int entero = stoi(entrada);
	
	return entero;
}

/************************************************************************/

int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int entero;
	bool en_rango = false;
	
	do {
		entero = LeeEntero(titulo);
		en_rango = (entero >= menor && entero <= mayor);
	} while (!en_rango);
	
	return entero;
}

/************************************************************************/

int LeeEnteroMayor (string titulo, int referencia)
{
	int entero;
	bool es_mayor;
	
	do {
		entero = LeeEntero (titulo);
		es_mayor = (entero > referencia);
	} while (!es_mayor);
	
	return entero;
}

/************************************************************************/

bool EstaEnRectangulo (Rectangulo rec, Punto2D punto)
{
	bool x = (punto.x>=rec.sup_izq.x && punto.x<=rec.inf_der.x);
	bool y = (punto.y<=rec.sup_izq.y && punto.y>=rec.inf_der.y);
	
	return (x && y);
}

/************************************************************************/

bool EstaEnCirculo (Circunferencia circulo, Punto2D punto)
{
	int dist_centro_punto_x = pow(punto.x - circulo.centro.x, 2);
	int dist_centro_punto_y = pow(punto.y - circulo.centro.y, 2);
	int dist_centro_punto = dist_centro_punto_x + dist_centro_punto_y;
	
	return (pow(circulo.radio, 2) >= dist_centro_punto);
}

