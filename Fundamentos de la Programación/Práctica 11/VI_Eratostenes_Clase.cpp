/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 22. Nº6.
// VI_Eratostenes_Clase.cpp: escribe un programa que cuente con la clase
// "Eratostenes", la cual será capaz de calcular los primos menores que un
// número introducido.
//
//Entrada: número hasta el cual calcular los primos
//Salida: primos hasta ese número en orden, número total de ellos y
// primo máximo
//
/************************************************************************/

#include <iostream>  //Inclusión de los recursos de entrada y salida

using namespace std;

class Erastostenes
{

	private:
		
		static const int TAMANIO = 500;
		int primos[TAMANIO];
		bool es_primo [TAMANIO];
		int total_utilizados;  //Número de casillas ocupadas
								//PRE: 0 <= total_utlizados <= TAMANIO
	
	public:
		
		/////////////////////////////////////////////////////////////////
		
		Erastostenes ()
		{
			total_utilizados = 0;
			
			for (int i = 0; i < TAMANIO; i++)
			{
				primos[i] = 0;
				es_primo[i] = true;
			}
		}
		
		/////////////////////////////////////////////////////////////////
		
		void CalculaHasta (int n)  //Método de la criba
		{
			for(int num = 2; num*num < n; num++) //Empezamos en 2 y terminamos
			{                                  //si num^2 es < n
				if (es_primo[num]) 
				{
					for (int k = 2; k*num <= n; k++)  //Tachamos los multiplos
					{                                 //del primo
						es_primo[k*num] = false;
					}
				}
			}
			
			for (int i = 1; i <= n; i++)
			{
				if(es_primo[i])
				{
					primos[total_utilizados] = i;
					total_utilizados++;
				}
			}
		}
		
		/////////////////////////////////////////////////////////////////
		
		int TotalCalculados()
		{	
			return total_utilizados;
		}
		
		/////////////////////////////////////////////////////////////////
		
		int Elemento (int k)
		{
			return primos[k];
		}
		
		/////////////////////////////////////////////////////////////////
		
		int GetMaximo()
		{
			return primos[total_utilizados - 1];
		}
		
		/////////////////////////////////////////////////////////////////
		
};

//Funciones

int LeeEnteroEnRango (string mensaje, int min, int max)
{
	string num;
	int numero = 0;
	bool ok;
	
	do {
		
		ok = true;
		
		cout << mensaje;
		getline( cin, num);
		
		for ( unsigned int i = 0 ; i < num.length() ; i++ )
			
			if ( num.at(i) > '9' || num.at(i) < '0' ) ok = false;
		
		if ( ok ) numero = stoi(num);
		
	} while ( !ok || (numero<min) || (numero> max));
	
	return (numero);
}

int main()     //Función principal
{
	
	// Declaración de constantes
	
	const int MIN = 1;
	const int MAX = 500;
	
	// Entrada de datos
	
		// Declaramos el objeto
	
	Erastostenes criba;
	
	cout << "Se consideraran los primos menores que el valor límite" << endl;
	
	string msg = "Valor límite (entre 1 y 500): ";
	int limite_max = LeeEnteroEnRango(msg, MIN, MAX); //Pedimos el valor máximo 
	
	cout << endl;
	cout << "Generando primos entre 1 y " << limite_max << endl;
	cout << endl;
	
	criba.CalculaHasta(limite_max);  //Calculamos los primos con la criba
	
	cout << "Se han encontrado un total de " << criba.TotalCalculados();
	cout << " numeros primos" << endl;
	
	cout << endl;
	cout << "El máximo primo es : " << criba.GetMaximo() << endl;
	cout << endl;
	
	cout << "-------------------------------------" << endl;
	
	//Mostramos los elementos primos
	
	for (int i  = 0; i < criba.TotalCalculados(); i++)
	
		cout << i + 1 << "." << "\t" << criba.Elemento(i) << endl;
	
	
	return 0;
	
}
