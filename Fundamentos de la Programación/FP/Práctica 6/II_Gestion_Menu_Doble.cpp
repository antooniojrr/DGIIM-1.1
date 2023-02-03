/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 2. N�81.
//II_Gestion_Menu_Doble.cpp: escribe un programa que presente un men�
//que permita al usuario elegir entre distintas operaciones
//
//Entrada: selecciones de men�
//Salida: c�lculos dependiendo de cada operacion
//
/************************************************************************/

#include <iostream>     //Inclusi�n de los recursos de E/S
#include <iomanip>    // Formato

using namespace std;


//Funci�n booleana para comprobar que el caracter introducido corresponde con
//alguna de las opciones.

bool opcion_valida ( char elec, char op_1, char op_2, char op_3) {
	
	bool valido = ( elec == op_1 || elec == op_2 || elec == op_3 );
	
	return (valido);
	
}


int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	// En este programa la modularizaci�n E/C/S ser�a m�s complicada de hacer
	// ya que esta se realiza dentro de cada una de las opciones del submenu
	// en las cuales se piden primero los dos t�rminos (Entrada), se calcula
	// el resultado (C�lculos) y se expresa este (Salida).
	
	char submenu;
	char submenu_sec;
	const char PRODUCTO = 'P', ADICION = 'A', SALIR = 'X';
	const char SUMA = 'S', RESTA = 'R';
	const char MULTIPLICACION = 'M', DIVISION = 'D';
	
	double term_1, term_2;
	double resultado;
	bool salir;
	bool acabar = false;
	

	do{
		
		cout << "-------------------|MENU PRINCIPAL|-------------------";
		cout << endl << endl;
		
		cout << "\tA -> Calcular ADICION." << endl << endl;
		cout << "\tP -> Calcular PRODUCTO." << endl << endl;
		cout << "\tX -> Salir." << endl << endl;
		
		
		do {
			
			cout << "Elija un submenu: ";
			cin >> submenu;
			
			salir = false;
			
		}while ( !opcion_valida (submenu, ADICION, PRODUCTO, SALIR) );
		
		
		if ( submenu == ADICION ) {
			
			do {
				
				cout << "-------------------|ADICION|-------------------";
				cout << endl << endl;
				
				cout << "\tS -> Calcular SUMA." << endl << endl;
				cout << "\tR -> Calcular RESTA." << endl << endl;
				cout << "\tX -> Salir." << endl << endl;
				
				
				do {
				
					cout << "Elija un submenu: ";
					cin >> submenu_sec;
				
				}while (!opcion_valida (submenu_sec, SUMA, RESTA, SALIR));
			
				
				if ( submenu_sec == 'S' ) {
					
					cout << "--------------|(ADICION) SUMA|--------------";
					cout << endl <<endl;
					
					// Entrada de datos
					
					cout << "\tIntroduzca el primer termino: ";
					cin >> term_1;
					
					cout << "\tIntroduzca el segundo termino: ";
					cin >> term_2;
					
					// C�lculos
					
					resultado = term_1 + term_2;
					
					// Salida
					
					cout << endl;
					cout <<setprecision(3)<< term_1 <<" + " << term_2 <<" = ";
					cout <<setw(8) << resultado;
					cout << endl << endl << endl;
					
				}
				
				else if ( submenu_sec == 'R' ) {
					
					cout << "--------------|(ADICION) RESTA|--------------";
					cout << endl <<endl;
					
					// Entrada de datos
					
					cout << "\tIntroduzca el primer termino: ";
					cin >> term_1;
					
					cout << "\tIntroduzca el segundo termino: ";
					cin >> term_2;
					
					// C�lculos
					
					resultado = term_1 - term_2;
					
					// Salida
					
					cout << endl;
					cout <<setprecision(3) << term_1 <<" - " << term_2 <<" = ";
					cout <<setw(8) << resultado;
					cout << endl << endl << endl;
					
				}
				
				else {
					
					salir = true;
					cout << endl << endl;
					
				}
			
			} while (!salir);
			
		} 
		
		if ( submenu == PRODUCTO ) {
			
			do {
				
				cout << "-------------------|PRODUCTO|-------------------";
				cout << endl <<endl;
				
				cout << "\tM -> Calcular MULTIPLICACION." << endl << endl;
				cout << "\tD -> Calcular DIVISION." << endl << endl;
				cout << "\tX -> Salir." << endl << endl;
				
				
				do {
				
					cout << "Elija un submenu: ";
					cin >> submenu_sec;
				
				}while(!opcion_valida
								(submenu_sec,MULTIPLICACION,DIVISION,SALIR));
			
				
				if ( submenu_sec == MULTIPLICACION ) {
					
					cout << "--------|(PRODUCTO) MULTIPLICACION|--------";
					cout << endl <<endl;
					
					// Entrada de datos
					
					cout << "\tIntroduzca el primer factor: ";
					cin >> term_1;
					
					cout << "\tIntroduzca el segundo factor: ";
					cin >> term_2;
					
					// C�lculos
					
					resultado = term_1 * term_2;
					
					// Salida
					
					cout << endl;
					cout <<setprecision(3) << term_1 <<" * " << term_2 <<" = ";
					cout <<setw(8) << resultado;
					cout << endl << endl << endl;
					
				}
				
				else if ( submenu_sec == DIVISION ) {
					
					cout << "----------|(PRODUCTO) DIVISION|----------" <<endl;
					cout << endl;
					
					// Entrada de datos
					
					cout << "\tIntroduzca el DIVIDENDO: ";
					cin >> term_1;
					
					cout << "\tIntroduzca el DIVISOR: ";
					cin >> term_2;
					
					// C�lculos
					
					resultado = term_1 / term_2;
					
					// Salida
					
					cout << endl;
					cout <<setprecision(3) << term_1 <<" / ";
					cout << term_2 <<" = " <<setw(8) << resultado;
					cout << endl << endl << endl;
					
				}
				
				else {
					
					salir = true;
					cout << endl << endl;
					
				}
				
			} while (!salir);
			
		} 
		
		if ( submenu == SALIR ) acabar = true;
					
	} while (!acabar);
	
	return 0;
		
}
				
			
	
		
		
		
		
	
	
	
