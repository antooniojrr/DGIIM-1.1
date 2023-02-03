/************************************************************************/
//Fundamentos de Programaci�n
//Antonio Javier Rodr�guez Romero. DGIIM A1.
//
//RELACI�N DE PROBLEMAS 36. N�6.
// VI_RedSocial_Clase.cpp: escribe un programa que contenga la clase
// "RedSocial" para controlar los usuarios registrados en tal red social
// y las relacionnes de amistad que mantengan entre ellos. El programa
// sugerir� los amigos potenciales de cada usuario y sus amigos
// circunstanciales
//
//Entrada: usuarios y amistades
//Salida: amigos potenciales y circunstanciales
//
/************************************************************************/

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Declaraci�n de la clase "RedSocial", que procesar� todos los registros
// de usuarios, solicitudes de amistad entre ellos, las guardar� y recomendar�
// a cada usuario una serie de usuarios que llamar� "amistades potenciales",
// e identificar� los amigos circunstanciales de cada usuario

class RedSocial {
	
	private:
		
	static const int MAXIMO_USUARIOS = 100;
	string usuarios[MAXIMO_USUARIOS];
	bool relaciones_amistad[MAXIMO_USUARIOS][MAXIMO_USUARIOS];
	int usuarios_utiles;
	
	// PRE: 0 <= usuarios_utiles <= 100
	
	public:
		
		// Declaraci�n de un constructor sin argumentos para la clase.
		// inicializar� "usuarios_utiles" a 0 y todas las amistades en "false".
		// Tomaremos como que un usuario no es amigo de si mismo.
		
		RedSocial (): usuarios_utiles(0)
		{
			
			for ( int i = 0; i < MAXIMO_USUARIOS ; i ++ ) {
				
				for ( int j = 0; j < MAXIMO_USUARIOS ; j ++ )
					
					relaciones_amistad[i][j] = false;
					
			}
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para devolver el n�mero de usuarios que actualmente est�n
		// registrados en la red (usuarios_utiles).
		//
		// Entrada: -----------
		// Salida: "usuarios_utiles"
		
		int GetNumUsuarios () {
			
			return usuarios_utiles;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para devolver el nombre de alg�n usuario a partir de su
		// �ndice de componente del array
		//
		// Entrada: "i"
		// Salida: "usuarios[i]"
		
		string GetUsuario ( int i ) {
			
			return usuarios[i];
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para devolver el n�mero de usuarios que se pueden registrar
		// como m�ximo en la red social
		//
		// Entrada: -----------
		// Salida: "MAXIMO_USUARIOS"
		
		int GetMaximo () {
			
			return MAXIMO_USUARIOS;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para a�adir a un nuevo usuario a la red, registrandolo
		// con su nombre.
		//
		// Entrada: nombre de usuario
		// Salida: ----------------
		
		void AniadeUsuario (string usr) {
			
			usuarios[usuarios_utiles] = usr;
			usuarios_utiles++;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para eliminar a un usuario de la red, comprobando primero
		// que existe.
		//
		// Entrada: nombre del usuario a eliminar
		// Salida: ----------------

		void EliminaUsuario (string usr) {
		
			if ( Existe(usr) ) {
				
				int pos = 0;
				
				while ( usuarios[pos] != usr ) pos ++;
				
				for ( int i = pos; i < usuarios_utiles ; i ++ )
					
					usuarios[i] = usuarios [i+1];
					
			}
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo "booleano" para comprobar si un usuario est� registrado 
		// en la red, buscandolo en "usuario[]"
		//
		// Entrada: nombre del usuario a buscar
		// Salida: true o false
		
		bool Existe (string usr) {
			
			int pos = 0;
			bool encontrado = false;
			
			while ( !encontrado && pos < usuarios_utiles ) {
				
				if ( usuarios[pos] == usr ) encontrado = true;
				pos ++;
				
			}
				
			return encontrado;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para hacer amigos a dos usuarios, comprobando antes que
		// existen. Cambiar� el componente apropiado de "relaciones_amistad"
		// a true
		//
		// Entrada: nombres de los usuarios amigos
		// Salida: -----------------
		
		void HacerAmigos(string usr1, string usr2) {
			
			if ( Existe ( usr1 ) && Existe ( usr2 ) ) {
				
				int pos1 = BuscarUsuario ( usr1 );
				int pos2 = BuscarUsuario ( usr2 );
				
				relaciones_amistad[pos1][pos2] = true;
				relaciones_amistad[pos2][pos1] = true;
				
			}
		
		}
		
		////////////////////////////////////////////////////////
		// M�todo para buscar el �ndice del componente del array "usuario[]"
		// que guarda el nombre del usuario buscado
		//
		// Entrada: nombre de usuario
		// Salida: �ndice
		// PRE: antes se ha de comprobar que el usuario a buscar existe
		
		int BuscarUsuario ( string usr ) {
			
				
			int pos = 0;
			bool encontrado = false;
			
			if ( usuarios[pos] == usr ) encontrado = true;
				
			while ( !encontrado && pos < usuarios_utiles ) {
				
				pos ++;
				if ( usuarios[pos] == usr ) encontrado = true;
					
			}
			
			return pos;
		
		}
		
		////////////////////////////////////////////////////////
		// M�todo para deshacer la amistad de dos usuarios, comprobando antes 
		// que existen. Cambiar� el componente apropiado de 
		// "relaciones_amistad" a false
		//
		// Entrada: nombres de los usuarios amigos
		// Salida: -----------------
		
		void DeshacerAmigos(string usr1, string usr2) {
			 
			if ( Existe ( usr1 ) && Existe ( usr2 ) && 
												SonAmigos(usr1,usr2) ) {
				
				int pos1 = BuscarUsuario ( usr1 );
				int pos2 = BuscarUsuario ( usr2 );
				
				relaciones_amistad[pos1][pos2] = false;
				relaciones_amistad[pos2][pos1] = false;
				
			}
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo "booleano" para comprobar si dos usuarios son amigos
		//
		// Entrada: nombre del usuario a buscar
		// Salida: true o false
		// PRE: se ha de comprobar que los dos usuarios existen antes de
		// introducirlos al m�todo "SonAmigos"
		
		bool SonAmigos(string usr1, string usr2) {
			
			int pos1 = BuscarUsuario ( usr1 );
			int pos2 = BuscarUsuario ( usr2 );
				
			bool amigos = relaciones_amistad[pos1][pos2];
			
			return amigos;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para conseguir las amistades potenciales de un usuario, es
		// decir, aquellos usuarios de los cuales no es amigo pero tiene muchas
		// amistades en com�n
		//
		// Entrada: usuario
		// Salida: string con todos los amigos potenciales
		// PRE: comprobar antes que "usr" existe
		
		string AmigosPotenciales ( string usr ) {
			
			string amistades = "";
			int pos = BuscarUsuario ( usr );
			int contador;
			const int LIM_AMISTADES = 3;   // A partir de este num de amistades
										   // en com�n, contar� al usuario
										   // como amistad potencial
			
			for ( int i = 0; i < usuarios_utiles; i ++ ) {
				
				if ( i != pos && !relaciones_amistad[i][pos] ) {
					
					contador = 0;
					
					for ( int j = 0 ; j < usuarios_utiles; j++ ) {
						
						if ( relaciones_amistad[i][j]
											&& relaciones_amistad[pos][j] ) 
							
							contador ++;
						
					}
					
					if ( contador >= LIM_AMISTADES ) 
						
						amistades = amistades + usuarios[i] + " , ";
					
				}
				
			}
			
			return amistades;
			
		}
		
		////////////////////////////////////////////////////////
		// M�todo para conseguir las amistades circunstanciales de un usuario, 
		// es decir, aquellos usuarios de los cuales es amigo pero no tiene
		// amistades en com�n.
		//
		// Entrada: usuario
		// Salida: string con todos los amigos circunstanciales
		// PRE: comprobar antes que "usr" existe
		
		string AmigosCircunstanciales ( string usr ) {
			
			string amistades = "";
			int pos = BuscarUsuario ( usr );
			int contador;
			
			for ( int i = 0; i < usuarios_utiles; i ++ ) {
				
				if ( i != pos && relaciones_amistad[i][pos] ) {
					
					contador = 0;
					
					for ( int j = 0 ; j < usuarios_utiles; j++ ) {
						
						if ( relaciones_amistad[i][j]
											&& relaciones_amistad[pos][j] ) 
							
							contador ++;
						
					}
					
					if ( contador == 0 ) 
						
						amistades = amistades + usuarios[i] + " , ";
					
				}
				
			}
			
			return amistades;
			
		}
		
		////////////////////////////////////////////////////////				
					
};

//////////////////////////////////////////////////////////////////////


int main ()			// Funci�n principal
{
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
	// Entrada de datos
	
	cout << "------------------|REGISTRO DE USUARIOS|------------------";
	cout << endl;
	cout << "Introduzca \" FIN \" cuando quiera finalizar el registro."; 
	cout << endl << endl;
	
	const string TERMINADOR = "FIN";
	string nombre;
	RedSocial red;
	
	int i = 0;
	
	cout << "\tUsuario 1 ----> ";
	getline ( cin , nombre );
	
	while ( nombre != TERMINADOR && i < red.GetMaximo() ) {
		
		red.AniadeUsuario ( nombre );
		i++;
		
		cout << endl;
		cout << "\tUsuario " << i + 1 << " ----> ";
		getline ( cin , nombre );
		
	}
	
	cout << endl << endl;
	cout << "------------------|REGISTRO DE AMISTADES|------------------";
	cout << endl << endl;
	
	string usr1, usr2;
	
	cout << "----> Usuario 1: ";
	getline ( cin, usr1 );
	
	cout << endl;
	
	cout << "----> Usuario 2: ";
	getline ( cin, usr2 );
	
	while ( usr1 != TERMINADOR && usr2 != TERMINADOR ) {
		
		if ( red.Existe(usr1) && red.Existe(usr2) )
			
			red.HacerAmigos( usr1, usr2);
		
		cout << endl << endl;
		
		cout << "----> Usuario 1: ";
		getline ( cin, usr1 );
		cout << endl;
		
		cout << "----> Usuario 2: ";
		getline ( cin, usr2 );
		
	}
	
	cout << endl << endl;
	
	// Salida de resultados
	
	cout << "------------|AMISTADES POTENCIALES|------------" << endl << endl;
	
	for ( int i = 0; i < red.GetNumUsuarios(); i ++ ) {
		
		if (red.AmigosPotenciales(red.GetUsuario(i)) != "") {
			
			cout << "----> " << red.GetUsuario(i) << ":" << endl;
			cout << "\t" << red.AmigosPotenciales(red.GetUsuario(i));
			cout << endl << endl;
		}
		
	}
	
	cout << endl << endl;
	
	cout << "------------|AMISTADES CIRCUNSTANCIALES|------------" << endl;
	cout << endl;
	
	for ( int i = 0; i < red.GetNumUsuarios(); i ++ ) {
		
		if (red.AmigosCircunstanciales(red.GetUsuario(i)) != "") {
			cout << "----> " << red.GetUsuario(i) << ":" << endl;
			cout << "\t" << red.AmigosCircunstanciales(red.GetUsuario(i));
			cout << endl << endl;
		}
		
	}
	
	return 0;
	
}
		
	
		

			
			


