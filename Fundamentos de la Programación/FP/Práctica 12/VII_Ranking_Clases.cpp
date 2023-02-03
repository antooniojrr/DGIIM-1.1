/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 7. Nº6.
// VII_Ranking_Clases.cpp: escribe un programa que clasifique los tiempos
// de diferentes atletas en diferentes pruebas dependiendo de los tiempos de
// cada uno, creando clases para cada uno de los datos introducidos, tanto
// de la marca como de la fecha y el ritmo de cada uno
//
//Entrada: datos de cada uno de los atletas, los cuales se extraerán del
// fichero provisto ( Utilizando el formato en el que vienen escritos en este)
//Salida: clasificación de cada prueba, de mejores a peores marca
//
/************************************************************************/

#include <iostream>						// Inclusión de los recursos de E/S
#include <iomanip>						// Inclusión de los recursos de formato
#include <string>						// Inclusión del tipo "string"

using namespace std;

// Declaración de las constantes

const int MAX_ATLETAS = 100;
const int MILISEG_SEG = 1000;
const int MILISEG_MIN = MILISEG_SEG * 60;
const int MILISEG_HORA = MILISEG_MIN * 60;
const int MESES_ANIO = 12;
const string MESES[MESES_ANIO] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", 
								  "Junio", "Julio", "Agosto", "Septiembre", 
								  "Octubre", "Noviembre", "Diciembre"};

const int MAX_PRUEBAS = 20;
const int MAX_MARCAS_POR_PRUEBA = 100;

////////////////////////////////////////////////////////////////////////////////

class Fecha{
	
	private:
		
		int dia;		// PRE: 0 < dia <= 31
		int mes;		// PRE: 0 < mes <= 12
		int anio;		// PRE: 0 < mes <= 2021
		
	public: 
		
		// Declaración de un constructor sin argumentos. Asignará la fecha
		// de 1 / 1 / 2021 por defecto
		
		Fecha()
		
			: dia(1),
			  mes(1),
			  anio(2021)
			  
		{}
		
		// Declaración de un constructor con argumentos. Asignará a cada campo
		// los valores que se le introduzcan a este.
		
		Fecha(int dia_inic, int mes_inic, int anio_inic)
		
			: dia(dia_inic),
			  mes(mes_inic),
			  anio(anio_inic)
			  
		{}
		
		// Declaración de un consructor que asigne a cada campo un valor a
		// partir de una cadena de caracteres en formato "dd/mm/aaaa".
		// PRE: la cadena debe estar en el formato especificado
		
		Fecha ( string cad ) {
			
			dia = stoi(cad.substr(0,2));
			mes = stoi(cad.substr(3,2));
			anio = stoi(cad.substr(6,4));
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "dia".
		//
		// Entrada: -----------
		// Salida: "dia"
		
		int GetDia() {
			
			return dia;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "mes".
		//
		// Entrada: -----------
		// Salida: "mes"
		
		int GetMes() {
			
			return mes;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "anio".
		//
		// Entrada: -----------
		// Salida: "anio"
		
		int GetAnio() {
			
			return anio;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el nombre de un mes y no su número. Lo hará
		// restandole uno al número de este para igualarlo a su índice dentro
		// del array "MESES"
		//
		// Entrada: -----------
		// Salida: nombre del mes
		
		string NombreMes () {
			
			return MESES[mes - 1];
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del ritmo expresado en un string
		//
		// Entrada: -----------
		// Salida: string de ritmo
		
		string To_String () {
			
			string fecha = to_string(dia) + " / " + to_string(mes);
			fecha = fecha + " / " + to_string(anio);
			
			return fecha;
			
		}
			
};

/////////////////////////////////////////////////////////
// Declaración de la clase "Ritmo", la cual guardará las horas, minutos,
// segundos y milésimas por kilómetro de cada atleta.

class Ritmo {
	
	private: 
	
		int horas;		// PRE: 0 <= horas
		int min;		// PRE: 0 <= min < 60
		int segs;		// PRE: 0 <= segs < 60
		int milesimas;	// PRE: 0 <= milesimas < 1000
		
	public: 
		
		// Declaración de un constructor sin argumentos que inicializará
		// todos los campos a 0
		
		Ritmo(): 
			
			horas(0),
			min(0),
			segs(0),
			milesimas(0)
			
		{}
		
		// Declaración de un constructor con argumentos. Este asignará a cada
		// valor el que se le introduzca.
		
		Ritmo(int horas_inic, int min_inic, int segs_inic, int milesimas_inic)
		
			: horas(horas_inic),
			  min(min_inic),
			  segs(segs_inic),
			  milesimas(milesimas_inic)
			  
		{}
		
		// Declaración de constructor que extraerá de una cadena de caracteres
		// del formato "hh:mm:ss:mmm" el ritmo.
		// PRE: debe estar en el formato indicado
		
		Ritmo ( string cad ) {
			
			horas = stoi(cad.substr(0,2));
			min = stoi(cad.substr(3,2));
			segs = stoi(cad.substr(6,2));
			milesimas = stoi(cad.substr(9,3));
			
		}
			
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "hora".
		//
		// Entrada: -----------
		// Salida: "hora"
		
		int GetHora() {
			
			return horas;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "min".
		//
		// Entrada: -----------
		// Salida: "min"
		
		int GetMin() {
			
			return min;
		
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "segs".
		//
		// Entrada: -----------
		// Salida: "segs"
		
		int GetSegs() {
			
			return segs;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "milesimas".
		//
		// Entrada: -----------
		// Salida: "hora"
		
		int GetMilesimas(){
			
			return milesimas;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del ritmo expresado en su totalidad
		// en milisegundos
		//
		// Entrada: -----------
		// Salida: milisegundos totales							  
		
		int RitmoAMilesimas() {
			
			int milesimas_totales;
			
			milesimas_totales = milesimas + (segs * MILISEG_SEG)
							  + (min * MILISEG_MIN) + (horas
							  * MILISEG_HORA);
						      
			return milesimas_totales;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del ritmo expresado en un string
		//
		// Entrada: -----------
		// Salida: string de ritmo
		
		string To_String () {
			
			string ritmo = to_string(horas) + " : " + to_string(min);
			ritmo = ritmo + " : " + to_string(segs) + " : ";
			ritmo = ritmo + to_string(milesimas);
			
			return ritmo;
			
		}
		
		
};

/////////////////////////////////////////////////////////
// Declaración de la clase "RegistroDeMarca", la cual aglutinará objetos
// de las clases "Fecha" y "Ritmo", además de la identificacion del atleta
// y la prueba en la que competía

class RegistroDeMarca {
	
	private:
		
		string prueba;
		Fecha fecha;
		string dorsal;
		Ritmo ritmo;
		
		/////////////////////////////////////////////////////////
		// Método privado para eliminar todos los espacios de una cadena.
		// Esto unificará el formato de todas las marcas introducidas
		
		string EliminaEspacios ( string cad ) {
			
			for ( int i = 0; i < cad.length() ; i ++ ) {
				
				if ( isspace(cad.at(i)) ) {
					
					for ( int j = i ; j < cad.length() - 1 ; j ++ ) {
						
						cad.at(j) = cad.at(j+1);
						
					}
					
					cad.pop_back();
					
				}
					
			}
			
			return cad;
		
		}
		
		/////////////////////////////////////////////////////////
		// Método privado para eliminar todos los espacios del principio
		// de una cadena.
		
		string EliminaPrimerosEspacios ( string cad ) {
			
			int pos = 0;
			
			while ( isspace(cad.at(pos)) ) pos ++;
			
			return cad.substr(pos);
			
		}
		
	public:
	 	
	 	// Declaración del constructor sin argumentos.
	 	
		RegistroDeMarca()
		
			: prueba(""),
			  dorsal("")
			  
		{
			
			Fecha fecha_pred;
			
			fecha = fecha_pred;
			
			Ritmo ritmo_pred;
			
			ritmo = ritmo_pred;
		
		}
		
		// Declaración del constructor con argumentos que recibirá los valores
		// a asignar a cada campo por separado.
		
		RegistroDeMarca(string tipo_prueba, Fecha fecha_inic,  
						string un_dorsal, Ritmo ritmo_inic)
						
			: prueba (tipo_prueba),
			  fecha (fecha_inic),
			  dorsal (un_dorsal),
			  ritmo (ritmo_inic)
			  
		{}
		
		// Declaración del constructor con argumentos que recibirá una cadena
		// que contendrá todos los datos de todos los campos, asignando a cada
		// campo su valor extraido de la cadena.
		// PRE: debe ser del formato especificado.
		
		RegistroDeMarca ( string cad ) {
			
			const int LONG_FECHA = 10;
			const int LONG_RITMO = 12;
			int long_dorsal;
			
			cad = EliminaPrimerosEspacios(cad);
			int pos = 0;
			
			while ( !isspace(cad.at(pos)) && pos < cad.length() ) pos ++;
			prueba = cad.substr( 0, pos );
			
			cad = EliminaEspacios(cad);
			
			
			Fecha fecha_nueva( cad.substr( pos, LONG_FECHA ) );
			fecha = fecha_nueva;
			
			Ritmo ritmo_nuevo( cad.substr(cad.length() - LONG_RITMO) );
			ritmo = ritmo_nuevo;
			
			long_dorsal = cad.length() - LONG_RITMO - LONG_FECHA - pos;
			pos += LONG_FECHA;
			
			dorsal = cad.substr( pos, long_dorsal );
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "fecha".
		//
		// Entrada: -----------
		// Salida: "fecha"
		
		Fecha GetFecha(){
			
			return fecha;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "dorsal".
		//
		// Entrada: -----------
		// Salida: "dorsal"
		
		string GetDorsal(){
			
			return dorsal;
		
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "ritmo".
		//
		// Entrada: -----------
		// Salida: "ritmo"
		
		Ritmo GetRitmo(){
			
			return ritmo;
			
		}
		
		//////////////////////////////////////////////////////////
		// Método para devolver el valor del campo "tipo_prueba".
		//
		// Entrada: -----------
		// Salida: "tipo_prueba"
		
		string GetPrueba (){
			
			return prueba;
			
		}
		
		////////////////////////////////////////////////
		// Método para expresar en un dato string la marca en su formato
		// apropiado.
		//
		// Entrada: -----------
		// Salida: string marca
		
		string To_String () {
			
			const int LONG_MAX_DORSAL = 7;
			const int LONG_FECHA = 14;
			
			if ( dorsal.length() < LONG_MAX_DORSAL ) {
				
				while ( dorsal.length() < LONG_MAX_DORSAL )
					
					dorsal = " " + dorsal;
					
			}
			
			string fecha_cad = fecha.To_String();
			
			if ( fecha_cad.length() < LONG_FECHA ) {
				
				while ( fecha_cad.length() < LONG_FECHA )
					
					fecha_cad = " " + fecha_cad;
					
			}
			
			string marca = prueba + "        " + fecha_cad;
			marca = marca + "        " + dorsal + "        ";
			marca = marca + ritmo.To_String();
			
			return marca;
			
		}
		
		////////////////////////////////////////////////
		// Método para cambiar todos los valores de los campos del objeto
		// a partir de una cadena de caracteres en el formato apropiado
		//
		// Entrada: cadena
		// Salida: -----------
		
		void SetMarca ( string cad ) {
			
			const int LONG_FECHA = 10;
			const int LONG_RITMO = 12;
			int long_dorsal;
			
			cad = EliminaPrimerosEspacios(cad);
			
			int pos = 0;
			
			while ( !isspace(cad.at(pos)) && pos < cad.length() ) pos ++;
			prueba = cad.substr( 0, pos );
			
			cad = EliminaEspacios(cad);
			
			Fecha fecha_nueva( cad.substr( pos, LONG_FECHA ) );
			fecha = fecha_nueva;
			
			Ritmo ritmo_nuevo( cad.substr(cad.length() - LONG_RITMO) );
			ritmo = ritmo_nuevo;
			
			long_dorsal = cad.length() - LONG_RITMO - LONG_FECHA - pos;
			pos += LONG_FECHA;
			
			dorsal = cad.substr( pos, long_dorsal );
				
		}
			
		
};

////////////////////////////////////////////////////////////////////////////////

int main(){										// Programa principal
	
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Declaración de la matriz donde se guardarán todas las marcas
	
	const string TERMINADOR = "FIN";
	string entrada;
	RegistroDeMarca marca_entrada;
	
	RegistroDeMarca marcas[MAX_PRUEBAS] [MAX_MARCAS_POR_PRUEBA];
	int num_marcas[MAX_PRUEBAS] = {0};
	
	// Entrada de datos
	
	cout << "--------------|ENTRADA DE DATOS|--------------" << endl << endl;
	
	int num_marcas_total = 0;
	int j;
	int num_pruebas = 0;
	bool prueba_encontrada;
	string prueba_saved, prueba_nueva;
	
	cout << "\t Marca " << num_marcas_total + 1 << ": ";
	
	getline(cin, entrada);
	
	while ( entrada != TERMINADOR ) {
		
		prueba_encontrada = false;
		
		marca_entrada.SetMarca(entrada);
		
		j = 0;
		
		while ( !prueba_encontrada && j < num_pruebas ) {
			
			prueba_saved = (marcas[j][0].GetPrueba());
			prueba_nueva = (marca_entrada.GetPrueba());
			
			if ( prueba_saved == prueba_nueva )
				
				prueba_encontrada = true;
				
			else j ++;
			
		}
		
		if ( prueba_encontrada ) {
			
			marcas[j][num_marcas[j]] = marca_entrada;
			num_marcas[j] ++;
			
		}
		
		else {
			
			marcas[num_pruebas][0] = marca_entrada;
			num_marcas[num_pruebas] ++;
			num_pruebas ++;
			
		}
		
		num_marcas_total++;
		
		cout << "\t Marca " << num_marcas_total + 1 << ": ";
		getline(cin, entrada);
		
	}
	
	// Cálculos
	
		// Ordenaré de menor a mayor las marcas de cada fila según los
		// milisegundos totales
		
	RegistroDeMarca aux;
	
	for ( int k = 0; k < num_pruebas ; k ++ ) {
		
		for ( int l = 0; l < num_marcas[k] ; l ++ ) {
			
			for ( int n = l + 1 ; n < num_marcas[k] ; n ++ ) {
				
				if ( ((marcas[k][n].GetRitmo()).RitmoAMilesimas()) <
						((marcas[k][l].GetRitmo()).RitmoAMilesimas()) ) {
							
					aux = marcas[k][l];
					marcas[k][l] = marcas[k][n];
					marcas[k][n] = aux;
					
				}
				
			}
			
		}
			
	}
		
	// Salida de resultados
	
		// Como están ya ordenados, simplemente los expresaré en el orden
		// en el que están guardados
		
	cout << endl << endl;
	
	cout << "---------------------|RANKING|---------------------" << endl;
	cout << endl;
	
	for ( int k = 0; k < num_pruebas; k ++ ) {
		
		cout << "\tPrueba " << k + 1 << ": " << marcas[k][0].GetPrueba();
		cout << endl;
		
		for ( int l = 0 ; l < num_marcas[k]; l ++ )
			
			cout << l+1 << "  " << marcas[k][l].To_String() << endl;
			
		cout << endl << endl;
		
	}
	
	return 0;
	
}
