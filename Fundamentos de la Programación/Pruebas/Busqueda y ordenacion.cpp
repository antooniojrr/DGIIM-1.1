

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int BusquedaSecuencia ( int vector[], int utilizados, int valor_buscado ) {
	
	int pos_encontrado = -1;
	bool encontrado = false;
	int i = 0;
	
	while ( i < utilizados && !encontrado ) {
		
		if ( vector[i] == valor_buscado ) {
			
			encontrado = true;
			pos_encontrado = i;
			
		}
		
		else i ++;
		
	}
	
	return pos_encontrado;
	
}

int BusquedaBinaria ( int vector[], int utilizados, int valor_buscado ) {
	
	int pos_encontrado = -1;
	int izda = 0, dcha = utilizados - 1;
	bool encontrado = false;
	int centro;
	
	while ( dcha >= izda && !encontrado ) {
		
		centro = (dcha + izda) * 0.5;
		
		if ( valor_buscado == vector[centro] ) {
			
			encontrado = true;
			pos_encontrado = centro;
			
		}
		
		else if ( valor_buscado < vector[centro] ) dcha = centro;
		
		else izda = centro;
		
	}
	
	return pos_encontrado;
	
}


int main () {
	
	int vector_desordenado[50] = {0};
	
	vector_desordenado[0] = 19;
	vector_desordenado[1] = 12;
	vector_desordenado[2] = 14;
	vector_desordenado[3] = 11;
	vector_desordenado[4] = 21;
	vector_desordenado[5] = 37;
	vector_desordenado[6] = 1;
	vector_desordenado[7] = 15;
	
	
	int usados = 8;
	int aux;
	
	// Ordenacion por seleccion
	
	for ( int i = 0; i < usados ; i ++ ) {
		
		for ( int j = i + 1; j < usados ; i ++ ) {
			
			if ( vector_desordenado[j] < vector_desordenado[i] ) {
				
				aux = vector_desordenado[i];
				vector_desordenado[i] = vector_desordenado[j];
				vector_desordenado[j] = aux;
				
			}
			
		}
		
	}
	
	for ( int i = 0; i < usados; i++ ) {
		
		cout << vector_desordenado[i] << "   ";
		
	}
	
	
	return 0;
	
}
	
