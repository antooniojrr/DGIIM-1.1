/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº18.
//II_ConversionUnidadesMedida.cpp: escribe un pograma al cual se le introduzca
//una medida de distancia en una unidad y otra a la cual convertirla.
//
//Entrada: magnitud, unidad inicial y unidad final
//Salida: magnitud en unidad final
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <cmath>        //Inclusión de recursos matemáticos
#include <string>       //Inclusión de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//CONSTANTES
	const int PASO_UNIDADES = 10; //Para pasar entre unidades tendremos que
	                              //multiplicar o dividir entre 10.
	const int POSICION_MM = 1;
	const int POSICION_CM = 2;
	const int POSICION_DM = 3;
	const int POSICION_M = 4;
	const int POSICION_KM = 7;
	
	//Entrada de valores
	
	double magnitud;
	string unidad_inicial, unidad_final;
	char a;
	
	cout <<"Introduzca la conversion a realizar:" <<endl;
	cout <<"\t>";
	cin >>magnitud >>unidad_inicial >>a >>unidad_final;
	
	//Comprobación de errores
	
	bool unidad_inicial_ok, unidad_final_ok, a_ok, todo_ok;
	
	unidad_inicial_ok = (unidad_inicial == "mm" || unidad_inicial == "cm"
						|| unidad_inicial == "dm" || unidad_inicial == "m"
						|| unidad_inicial == "km");
						
	unidad_final_ok = (unidad_final == "mm" || unidad_final == "cm"
						|| unidad_final == "dm" || unidad_final == "m"
						|| unidad_final == "km");
	
	a_ok = ( a == 'a');
	
	todo_ok = unidad_inicial_ok && unidad_final_ok && a_ok;
	
	if (!todo_ok) {
		
		cout <<endl;
		cout <<"-----------------------ERROR-----------------------" <<endl;
		cout <<"Introduzca la conversion de forma correcta. Ejemplo:" <<endl;
		cout <<"\t>1 m a cm" <<endl <<endl;
		cout <<"Introduzca la conversion a realizar:" <<endl;
		cout <<"\t>";
		cin >>magnitud >>unidad_inicial >>a >>unidad_final;
	}
	
	//Cálculos
	
	int posiciones;    //Variable intermedia
	
	if (unidad_inicial == "mm") posiciones = POSICION_MM;
	if (unidad_inicial == "cm") posiciones = POSICION_CM;
	if (unidad_inicial == "dm") posiciones = POSICION_DM;
	if (unidad_inicial == "m") posiciones = POSICION_M;
	if (unidad_inicial == "km") posiciones = POSICION_KM;
	
	if (unidad_final == "mm") posiciones = posiciones - POSICION_MM;
	if (unidad_final == "cm") posiciones = posiciones - POSICION_CM;
	if (unidad_final == "dm") posiciones = posiciones - POSICION_DM;
	if (unidad_final == "m") posiciones = posiciones - POSICION_M;
	if (unidad_final == "km") posiciones = posiciones - POSICION_KM;
	
	double magnitud_final = magnitud * pow(PASO_UNIDADES,posiciones);
	
	//Resultados
	
	cout <<setprecision(3) <<magnitud <<" " <<unidad_inicial <<" = " 
		 <<setprecision(3) <<magnitud_final <<" " <<unidad_final;
		 
	return 0;
	
}
	
	
		
		
						
	
	
	
	
	
	
	
