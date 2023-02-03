/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 7. Nº10.
// VII_CountingSort.cpp: amplia la clase "SecuenciaCaracteres" con un método
// que ordene un vector a través de un previo estudio de frecuencias de cada
// carácter.
//
//Entrada: valores de la secuencia de caracteres
//Salida: vector ordenado
//
/************************************************************************/

#include <iostream>  //Inclusión de los recursos de entrada y salida
#include <string>    //Inclusión de los recursos string

using namespace std;

/************************************************************************/
// Declaración de la clase "SecuenciaCaracteres", que contara con un vector
// privado que recogerá todos los caracteres introducidos.
//
/////////////////////////////////////////////////////////////////
class SecuenciaCaracteres
{

private:
	
	static const int TAMANIO = 50; //Num casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;  //Num casillas ocupadas
	
public:
	
	/////////////////////////////////////////////////////////////////
	//Constructor sin argumentos
	SecuenciaCaracteres (void) : total_utilizados (0) {}
	
	/////////////////////////////////////////////////////////////////
	//Devuelve el número de casillas ocupadas
	
	int TotaUtilizados (void)
	{
		return total_utilizados;
	}
	
	/////////////////////////////////////////////////////////////////
	//Devuelve el número de casillas disponibles
	
	int Capacidad (void)
	{
		return TAMANIO;
	}
	
	/////////////////////////////////////////////////////////////////
	//"Vacía" completamente la secuencia
	
	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}
	
	/////////////////////////////////////////////////////////////////
	//Añade un elemento "nuevo" al vector
	//PRE: total_utilizados < TAMANIO
	//	La adición se realiza si hay alguna casilla disponible
	//	El nuevo elemento se coloca al final del vector
	//	Si no hay espacio, no se hace nada
	
	void Aniade (char nuevo)
	{
		if (total_utilizados < TAMANIO)
		{
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	/////////////////////////////////////////////////////////////////
	//Devuelve el elemento de la casilla "indice"
	//PRE: 0 <= indice < total_utilizados
	
	char Elemento (int indice)
	{
		return (vector_privado[indice]);
	}
	
	/////////////////////////////////////////////////////////////////
	//Cambia el contenido de la casilla "indice" por el valor
	//dado en "nuevo". El tamanio de la secuencia no cambia.
	//PRE: 0 <= indice < total_utilizados
	
	void Modifica (int indice, char nuevo)
	{
		if ((indice >= 0) && (indice < total_utilizados))
		{
			vector_privado[indice] = nuevo;
		}
	}
	
	/////////////////////////////////////////////////////////////////
	//Eliminar el caracter de la posicion dada por "indice".
	//Realiza un borrado físico (desplazamiento y sustitución).
	//PRE: 0 <= indice < total_utilizados
	
	void Elimina (int indice)
	{
		if ((indice >= 0) && (indice < total_utilizados))
		{
			int tope = total_utilizados - 1; //pos del ultimo
			
			for (int i = indice; i < tope; i++)
			{
				vector_privado[i] = vector_privado[i+1];
			}
			
			total_utilizados--;
		}
	}
	
	/////////////////////////////////////////////////////////////////
	//Inserta el carácter "nuevo" en la posición dada por "indice".
	//Desplaza todos los caracteres una posición a la derecha
	//antes de copiar en "indice" el valor "nuevo"
	
	void Inserta (int indice, char valor_nuevo)
	{
		if ((total_utilizados < TAMANIO) && (indice >= 0))
		{
			for (int i = total_utilizados; i > indice; i--)
			{
				vector_privado[i] = vector_privado[i-1];
			}
			
			vector_privado[indice] = valor_nuevo;
			total_utilizados++;
		}
	}
	
	/////////////////////////////////////////////////////////////////
	//Método para elinar todas las apariciones que hubiese
	//de un determinado caracter "a_borrar" en la secuencia.
	
	void EliminaOcurrencias (char a_borrar)
	{
		int posicion_lectura = 0;
		int posicion_escritura = 0;
		bool borrar;
		
		while (posicion_lectura < total_utilizados)
		{
			borrar = false;
			
				if (vector_privado[posicion_lectura] == a_borrar)
				{
					borrar = true;
				}
			
			
			if(borrar)
			{
				Elimina(posicion_escritura);
			}
			else
			{
				posicion_lectura++;
				posicion_escritura++;
			}
		}
		
		total_utilizados = posicion_escritura;
	}
	
	/////////////////////////////////////////////////////////////////
	//Método para eliminar todas los excesos de espacios de la cadena
	// dejando solo uno por cada serie de espacios encontrados
	
	void EliminaExcesoBlanco()
	{	
		for (int i = 0; i < total_utilizados; i++)
		{
			if (vector_privado[i] == ' ')
			{	
				
				while ( isspace(vector_privado[i + 1]) ) Elimina(i+1);
			
			}
		}
	}
			
			
	
	/////////////////////////////////////////////////////////////////
	//Compone un string con todos los caracteres que están 
	//almacenados en la secuenica y lo devuelve
	
	string ToString()
	{
		string cadena;
		
		for (int i=0; i<total_utilizados; i++)
		{
			cadena = cadena + vector_privado[i];
		}
		
		return cadena;
	}
	
	/////////////////////////////////////////////////////////////////
	// Método para ordenar la secuencia de caracteres, identificando el valor
	// mínimo y máximo del vector_privado para llamar más tarde a otro método
	// de ordenación con esos valores
	//
	// Entrada: -----------
	// Salida: objeto "SecuenciaCaracteres"	
	
	SecuenciaCaracteres CountingSort()
	{
		char min = vector_privado[0];
		char max = vector_privado[0];
		SecuenciaCaracteres nueva;
		
		//Identificamos el valor min y max
		for (int i = 0; i < total_utilizados; i++)
		{
			if(vector_privado[i] < min)
			{
				min = vector_privado[i];
			}
			else if(vector_privado[i] > max)
			{
				max = vector_privado[i];
			}
		}
		
		return (CountingSortEntre(min,max));
	
	}
		
	/********************************/
	//Ordenara los valores desde un minimo hasta un máximo
	
	SecuenciaCaracteres CountingSortEntre (char min, char max)
	{
		int frecuencias[max-min+1] = {0};
		int pos_letra = 0;
		SecuenciaCaracteres nueva;
		
		for(char c = min; c<=max; c++)
		{
			for (int k = 0; k < total_utilizados; k++)
			{
				if(vector_privado[k] == c)
				{
					frecuencias[pos_letra]++;
				}
			}
			pos_letra++;
		}
		
		int veces = 1;
		pos_letra = 0;
		//Modificamos la nueva secuencia con el orden
		for(char letra = min; letra <= max; letra++)
		{
			while(frecuencias[pos_letra] != 0 && veces <= frecuencias[pos_letra])
			{
				nueva.Aniade(letra);
				veces++;
			}
			veces = 1;
			pos_letra++;
		}
		
		return nueva;
	}
	
};

int main()
{
	SecuenciaCaracteres secuencia, nueva;
	char c;
	const char TERMINADOR = '.';
	
	cout << "Introduzca una serie de caracteres. EL programa leerá";
	cout << " hasta que introduzca '" << TERMINADOR << "'" << endl;
	
	//Lectura de datos
	do 
	{
		cin.get(c);
		
		if(c != TERMINADOR)
		{
			secuencia.Aniade(c);
		}
	}while(c != TERMINADOR);
	
	nueva = secuencia.CountingSort();
	cout << nueva.ToString();
	
	return 0;
}
