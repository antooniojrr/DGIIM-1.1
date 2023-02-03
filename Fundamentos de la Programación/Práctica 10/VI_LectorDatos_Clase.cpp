/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 13. Nº6.
// VI_LectorDatos_Clase.cpp: escribe un programa que cuente con la clase
// "Lector" y lea con ella de manera ordenada y etiquetada datos de tipo
// "int" y "double".
//
//Entrada: diferentes datos de tipo "int" y "double"
//Salida: datos introducidos
//
/************************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       // Inclusión del tipo "string"

using namespace std; 

class Lector

{
	
	private:
		
		string titulo;
		
	public:
		
		Lector( string titulo_inic = "")
		
			: titulo ( titulo_inic )
			
		{}
		
		void SetTitulo(string titulo_nuevo){
			titulo = titulo_nuevo;
		}
		
		/******************************************************************/
		//	Lee una cadena y comprueba que es un número entero. 
		//
		//	Entrada: -----------
		//	Devuelve: número entero.
		//	
		//	POST: El número introducido es un número entero				 	  
		/******************************************************************/
		
		int LeeEntero (){
			
			int entero, j;
			char digito;
			string numero_introducido;
			bool todo_correcto = false;
			bool primer_digito_ok = false;
			unsigned int i = 1;
			
			while (!todo_correcto){
				todo_correcto = true;
				cout << titulo;
				cin >> numero_introducido;
			
				j = numero_introducido.length();
				digito = numero_introducido.at(0);
				
				if ((digito == '-') && (j == 1))
					todo_correcto = false;
					
				if ((digito == '-') || isdigit(digito))
					primer_digito_ok = true;
				else 
					todo_correcto = false;
				
				if ((primer_digito_ok) && (j > 1)){
					
					while (todo_correcto && (i < numero_introducido.length())){
						digito = numero_introducido.at(i);
						if (!isdigit(digito))
							todo_correcto = false;		
						i++;
					}
				}
				
				if (todo_correcto)
				
					entero = stoi(numero_introducido);
					
			} // while (!todo_correcto)
			
			return (entero);	
		} // LeeEntero
		
		/**********************************************************************/
		/*	Lee un número entero y comprueba que está dentro de un intervalo 
			dado por el número mínimo y el número máximo de ese intervalo a 
			través de un filtro.
		
			Recibe: El máximo y mínimo.
			Devuelve: El número entero.
			
			PRE: El máximo y mínimo que delimitan el intervalo son enteros.
			POST: El número introducido es un número entero	y está en el
				  intervalo establecido.								  	  */
		
		int LeeEnteroEnRango (int menor, int mayor)	{
			int entero;
			bool seguir = true;
		
			do{
				entero = LeeEntero();
			
				if ((entero < menor) || (entero > mayor))
					seguir = true;
				else
					seguir = false;
			} while (seguir);
			
			return (entero);
		}
		
		/**********************************************************************/
		/*	Lee un número entero y comprueba que es mayor o igual que un numero
			entero que actua como referencia.
		
			Recibe: El texto que le queremos mostrar al usuario para que 
				 	introduzca su numero entero y la referencia.
			Devuelve: El número entero.
			
			PRE: La referencia es un número entero. 
			POST: El número introducido es un número entero	y es mayor o igual 
				  que la referencia.									  	  */
			
		int LeeEnteroMayorOIgual (int referencia) {
			int entero;
			bool seguir = true;
			
			while (seguir){
				entero = LeeEntero();
				
				if (entero >= referencia)
					seguir = false;
			}
			
			return (entero);
		}
		
		/**********************************************************************/
		/*	Lee una cadena y comprueba que es un número real. 
		
			Recibe: Nada
			Devuelve: El número real.
			
			POST: El número introducido es un número real			  	  */
		
		double LeeReal () {
			double real, j;
			char digito;
			unsigned int i = 1;
			string numero_introducido;
			bool todo_correcto = false;
			bool primer_digito_ok = false;
			
			while (!todo_correcto){
				todo_correcto = true;
				cout << titulo;
				cin >> numero_introducido;
			
				j = numero_introducido.length();
				digito = numero_introducido.at(0);
				
				if (((digito == '-') || (digito == '.') || (digito == '+')) 
					&& (j == 1))
					todo_correcto = false;
					
				if ((digito == '-') || (digito == '+') || isdigit(digito) 
					|| digito == '.')
					primer_digito_ok = true;
				else 
					todo_correcto = false;
				
				if ((primer_digito_ok) && (j > 1)){
					
					while (todo_correcto && (i < numero_introducido.length())){
						digito = numero_introducido.at(i);
						if (!isdigit(digito) && (digito != '.'))
							todo_correcto = false;		
						i++;
					}
				}
				
				if (todo_correcto)
					real = stod(numero_introducido);
					
			} // while (!todo_correcto)
			
			return (real);
		} // LeeReal
		
		/**********************************************************************/
		/*	Lee un número real y comprueba que está dentro de un intervalo 
			dado por el número mínimo y el número máximo de ese intervalo a 
			través de un filtro.
		
			Recibe: El máximo y mínimo.
			Devuelve: El número real.
			
			PRE: El máximo y mínimo que delimitan el intervalo son reales.
			POST: El número introducido es un número real y está en el
				  intervalo establecido.								  	  */
		
		double LeeRealEnRango (double menor, double mayor) {
			double real;
			bool seguir = true;
		
			do{
				real = LeeReal();
			
				if ((real < menor) || (real > mayor))
					seguir = true;
				else
					seguir = false;
			} while (seguir);
			
			return (real);
		}
		
		/**********************************************************************/
		/*	Lee un número real y comprueba que es mayor o igual que un numero
			real que actua como referencia.
		
			Recibe: La referencia.
			Devuelve: El número real.
			
			PRE: La referencia es un número real. 
			POST: El número introducido es un número real y es mayor o igual 
				  que la referencia.									  	  */
			
		double LeeRealMayorOIgual (double referencia) {
			double real;
			bool seguir = true;
			
			while (seguir){
				real = LeeReal();
				
				if (real >= referencia)
					seguir = false;
			}
			
			return (real);
		}
		
}; // class Lector

/***************************************************************************/
/***************************************************************************/

int main()						// Programa principal
{	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales	
	
	
	// Lectura de un entero arbitrario

	Lector lector_temp ("Temperatura (sin decimales): "); 
	
	int temp = lector_temp.LeeEntero();
	
	cout << endl;
	cout << "Temperatura leida = " << temp << endl;
	cout << endl;


	// Lectura de enteros acotados superior e inferiormente 
	
	int horas, minutos, segundos;
	
	const int MAX_HORAS = 23;
	const int MAX_MIN_SEG = 59;
	
	Lector lector_hora; 
	
	lector_hora.SetTitulo ("Introduzca hora: "); 	
	horas = lector_hora.LeeEnteroEnRango( 0, MAX_HORAS );
	
	lector_hora.SetTitulo ("Introduzca minuto: "); 		
	minutos = lector_hora.LeeEnteroEnRango(0, MAX_MIN_SEG);
	
	lector_hora.SetTitulo ("Introduzca segundo: "); 		
	segundos = lector_hora.LeeEnteroEnRango(0, MAX_MIN_SEG);

	cout << endl;
	cout << "Hora ---> ";
	cout << setw(2) << horas << ":";
	cout << setw(2) << minutos << ":" << setw(2) << segundos << endl;
	cout << endl << endl;
		
		
	// Lectura de un entero mayor que una referencia (0)
	
	int ingreso;
	
	const double MIN_INGRESO = 0;
	
	Lector lector_ingreso("Cantidad a ingresar: "); 

	ingreso = lector_ingreso.LeeEnteroMayorOIgual (MIN_INGRESO);
	
	cout << endl;
	cout << "Valor del ingreso = " << ingreso << endl;
	cout << endl << endl;
	
	
	// Lectura de un valor real arbitrario 
	
	double temperatura;
	
	Lector lector_temperatura("Temperatura (con decimales): "); 

	temperatura = lector_temperatura.LeeReal ();
	
	cout << endl;
	cout << "Valor de la temperatura = " 
	     << setw(6) << setprecision(2) << temperatura << endl;
	cout << endl << endl;
	
	
	// Lectura de enteros acotados superior e inferiormente
	
	const double MIN_IVA = 4.0;
	const double MAX_IVA = 21.0;
	
	Lector lector_iva("Introduzca el IVA [entre 4.0 y 21.0]: "); 	 
	
	double iva = lector_iva.LeeRealEnRango ( MIN_IVA, MAX_IVA );
	
	cout << endl;
	cout << "Valor del IVA = " << setw(5) << setprecision(2) << iva << endl;
	cout << endl << endl;
	
	
	// Lectura de un real mayor o igual que una referencia (4.0)
	
	lector_iva.SetTitulo("Introduzca el IVA [>=4.0]: "); 	 

	iva = lector_iva.LeeRealMayorOIgual ( MIN_IVA );
	
	cout << endl;
	cout << "Valor del IVA = " << setw(5) << setprecision(2) << iva << endl;
	cout << endl << endl;
	
	
	
	return 0;
}

