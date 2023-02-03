/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 7. N�27.
// VII_ColeccionPuntos.cpp: escribe un programa que cuente con la clase
// "ColeccionPunto2D" que recoja una serie de objetos de la clase "Punto2D"
// que introduzca el usuario. M�s tarde, este introducir� los datos de
// una circunferencia y comprobar� que puntos pertenecen a la circunferencia
//
//Entrada: puntos2D y valores de la circunferencia
//Salida: puntos que pertenecen a la circunferencia
//
/************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Declaraci�n de la clase "Punto2D", la cual recoger� la ordenada y la abcisa
// de uno adem�s de recoger algunos m�todos b�sicos para operar con el mismo
// punto y con otros.

class Punto2D
{

	private:
	
		double x;
		double y;
	
	public:
		
		//////////////////////////////////////////////////////
		// Constructor que iniciar� los campos x e y con valores que se
		// le introduzcan.
		
		Punto2D (double la_x, double la_y):
			
			x(la_x),
			y(la_y)
			
		{}
		
		//////////////////////////////////////////////////////
		// Constructor sin argumentos. Inicializar� los campos x e y en 0
		
		Punto2D ():
			
			x(0),
			y(0)
			
		{}
		
		//////////////////////////////////////////////////////
		// M�todo para establecer las coordenadas de un punto despu�s de
		// haber inicializado este. Permitir� cambiar los valores de los
		// campos x e y por los introducidos
		//
		// Entrada: valor de "x" y de "y"
		// Salida: ------------
		
		void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
		{
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo "x".
		//
		// Entrada: -------------
		// Salida: "x"
		
		double GetX() {
			
			return x;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo "y".
		//
		// Entrada: -------------
		// Salida: "y"
		
		double GetY() {
			
			return y;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para calcular la distancia entre dos objetos "Punto2D".
		//
		// Entrada: el otro punto
		// Salida: distancia entre los puntos 
	
		double DistanciaCon (Punto2D otro) {
			
			double dif_x = pow (x - otro.GetX() , 2);
			double dif_y = pow (y - otro.GetY() , 2);
	
			return (sqrt(dif_x + dif_y));
			
		}
		
};

// Declaraci�n de la clase circunferencia, que contar� con un campo
// "Punto2D centro" y otro "double radio".

class Circunferencia {
	
	private:
		
		static const double PI; 
		Punto2D centro;
		double radio; //PRE: 0 < radio
		
	public:
		
		//Constructor que inicializar� los campos de radio y de centro con
		// valores que se le introduzca
		
		Circunferencia (Punto2D el_centro, double el_radio):
			
			centro(el_centro),
			radio(el_radio)
			
		{}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el objeto " centro ".
		//
		// Entrada: -------------
		// Salida: "Punto2D centro"
		
		Punto2D GetCentro (void) {
			
			return centro;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del campo " radio ".
		//
		// Entrada: -------------
		// Salida: "double radio"
		
		double GetRadio(void)
		{
			return radio;
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del di�metro de la circunferencia,
		// es decir, radio * 2
		//
		// Entrada: -------------
		// Salida: radio * 2
		
		double GetDiametro () {
			
			return (radio*2);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor de la longitud de la circunferencia
		//
		// Entrada: -------------
		// Salida: longitud
		
		double Longitud (void) {
			
			return (2 * PI * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el valor del �rea de la circunferencia
		//
		// Entrada: -------------
		// Salida: �rea
		
		double Area (void) {
			
			return (PI * radio * radio);
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo booleano para comprobar si un punto pertenece a la
		// circunferencia o no.
		//
		// Entrada: objeto " Punto2D "
		// Salida: "true" o "false"
		
		bool Contiene (Punto2D un_punto) {
			
			Punto2D el_centro = centro;
			double distancia = el_centro.DistanciaCon(un_punto);
			
			return (distancia <= radio);
			
		}
		
}; 
	
const double Circunferencia::PI = 3.1415926;

// Declaraci�n de la clase "Colecci�nPuntos2D", la cual recoger� un conjunto
// de puntos y algunos m�todos para operar con ellos, a�adir nuevos o
// devolverlos

class ColeccionPuntos2D
{
	
	private:
		
		static const int TAMANIO = 50; 	//Tama�o m�ximo del vector
		Punto2D vector_puntos[TAMANIO];
		int total_puntos;   		// PRE: 0 <= total_puntos <= TAMANIO
		
	public:
		
		//////////////////////////////////////////////////////
		// Constructor sin argumentos. Inicializar� "total_puntos" a 0.
		
		ColeccionPuntos2D ()
		{
			
			total_puntos = 0;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el total de puntos almacenados en el vector.
		//
		// Entrada: ---------------
		// Salida: total_puntos
		
		int TotalPuntos () {
			
			return total_puntos;
			
		}
		
		//////////////////////////////////////////////////////
		// M�todo para devolver el m�ximo de puntos que podr�a almacenar
		//
		// Entrada: ---------------
		// Salida: TAMANIO
		
		int Capacidad () {
			
			return TAMANIO;
			
		}
		
		/////////////////////////////////////////////////////
		// M�todo para vaciar el vector de puntos y reiniciar el objeto a 0
		//
		// Entrada: ---------------
		// Salida: -------------
		
		void EliminaTotal () {
			
			Punto2D punto_00( 0, 0);
			
			for ( int i = 0; i < total_puntos ; i ++ )
				
				vector_puntos[i] = punto_00;
			
			
			total_puntos = 0;
			
		}
		
		/////////////////////////////////////////////////////
		// M�todo para a�adir un punto nuevo a la colecci�n
		//
		// Entrada: punto nuevo a introducir
		// Salida: -------------
		
		void Aniade (Punto2D el_punto) {
			
			if (total_puntos < TAMANIO) {
				
				vector_puntos[total_puntos] = el_punto;
				total_puntos++;
				
			}
			
		}
		
		/////////////////////////////////////////////////////
		// M�todo para devolver uno de los puntos del vector a partir
		// de su �ndice
		//
		// Entrada: "i"
		// Salida: " Punto2D vector_puntos[i] "
		// PRE: 0 <= i <= total_puntos
		
		Punto2D Elemento (int indice) {
			
			if (indice >= 0 && indice < total_puntos) {
				
				return vector_puntos[indice];
				
			}
			
		}
		
};

int main()    //Funcion principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	ColeccionPuntos2D coleccion;
	const string TERMINADOR = "FIN";
	
	cout << "---------------| PUNTOS 2D |---------------" << endl;
	cout << "Introduzca un m�ximo de " << coleccion.Capacidad(); 
	cout << " puntos" << endl;
	cout << "Para terminar escriba " << TERMINADOR << " cuando se le";
	cout << " pregunte por la abscisa de un punto" << endl;
	

	bool seguir = true;
	
	while (coleccion.TotalPuntos() < coleccion.Capacidad() && seguir)
	{
		string cad_abs;
		int abs = 0, ordenada;
		
		cout << "\t x: ";
		cin >> cad_abs;
			
		if(cad_abs != TERMINADOR)
		{
			abs = stoi(cad_abs);
		}
		else
		{
			seguir = false;
		}
		
		if(seguir)
		{
			cout << "\t y: ";
			cin >> ordenada;
			cout << endl;
		
		
			Punto2D punto(abs, ordenada);
			
			coleccion.Aniade(punto);
		}
	}
	
	cout << "-----------------------------------------" << endl;
	
	cout << "Se han registrado " << coleccion.TotalPuntos() << " puntos";
	cout << endl << endl;
	
	//Ahora definamos una circunferencia
	double centro_x, centro_y, radio;
	
	cout << "Ahora introduzca los datos que definen una circunferencia";
	cout << endl << "Centro: " << endl << endl << "------------> x:";
	cin >> centro_x;
	cout << "------------> y:";
	cin >> centro_y;
	cout << endl << "Radio: ";
	cin >> radio;
	
	Punto2D centro (centro_x, centro_y);
	Circunferencia circunferencia (centro, radio);
	
	cout << endl << "-----------------------------------------" << endl;

	//Y ahora comprobamos cada punto si esta en la circunferencia
	
	for (int i = 0; i < coleccion.TotalPuntos(); i++)
	{
		if(circunferencia.Contiene(coleccion.Elemento(i)))
		{
			cout << "----->(" << coleccion.Elemento(i).GetX() << ",";
			cout << coleccion.Elemento(i).GetY() << ") est� en la circunferencia";
			cout << endl;
		}
		else
		{
			cout << "----->(" << coleccion.Elemento(i).GetX() << ",";
			cout << coleccion.Elemento(i).GetY() << ") no est� en la circunferencia";
			cout << endl;
		}
	}
	
	return 0;
	
}



