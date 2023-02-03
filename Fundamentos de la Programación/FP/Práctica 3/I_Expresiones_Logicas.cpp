/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//I_Expresiones_Logicas.cpp: escriba expresiones lógicas para representar cada
//una de las situaciones descritas en el enunciado.
//Entrada: votos_presenciales, votos_correo (votos_emitidos),
//votos_validos_presenciales, votos_validos_correo (votos_validos, votos_nulos)
//
//Salida: Veracidad de las situaciones descritas
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S

#include <iomanip>    // Formato 

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	const int VOTANTES = 100;  //Constante con el censo que vota.
	
	int votos_presenciales, votos_correo, votos_emitidos; //Declaración de 
													 //variables de entrada 
	
	//Entrada de valores
	
	cout <<"Poblacion sobre la que se realiza la votación: " <<VOTANTES;
	
	cout <<endl;
	cout <<"Introduzca numero de votos realizados presencialmente: ";
	cin >>votos_presenciales;
	cout <<"Introduzca el numero de votos realizados por correo: ";
	cin >>votos_correo;
	
	//Los votos emitidos será la suma de las dos variables anteriores.
	
	votos_emitidos = votos_presenciales + votos_correo;
	
	//Ahora registrará los votos válidos y nulos.
	
	int votos_validos_presenciales, votos_validos_correo;
	int votos_validos, votos_nulos;
	
	cout <<endl;
	cout <<"Votos validos presenciales: ";
	cin >>votos_validos_presenciales;
	cout <<"Votos validos por correo: ";
	cin >>votos_validos_correo;
	cout <<"Votos nulos: ";
	cin >>votos_nulos;
	
	//Obtendremos los validos de la suma de los presenciales y correo
	
	votos_validos = votos_validos_presenciales + votos_validos_correo;
	
	
	
	
	//El programa preguntará entonces los votos a cada opción
	
	int votos_A, votos_B, votos_C;
	
	cout <<endl;
	cout <<"Numero total de votos validos: " <<votos_validos <<endl;
	
	cout <<"Numero de votos validos opción A: ";
	cin >>votos_A;
	
	cout <<"Numero de votos validos opción B: ";
	cin >>votos_B;
	
	cout <<"Numero de votos validos opción C: ";
	cin >>votos_C;
	
	//Declaración de datos recogidos
	
	cout <<endl;
	cout <<"DATOS RECOGIDOS: " <<endl;
	cout <<"Votos emitidos: " <<setw(4) <<votos_emitidos <<endl;
	cout <<"Votos validos:  " <<setw(4) <<votos_validos <<endl;
	cout <<"Votos nulos:    " <<setw(4) <<votos_nulos <<endl;
	cout <<"Votos A:        " <<setw(4) <<votos_A <<endl;
	cout <<"Votos B:        " <<setw(4) <<votos_B <<endl;
	cout <<"Votos C:        " <<setw(4) <<votos_C <<endl;
	
	//Declaración de variables de salida y operaciones lógicas
	
	bool emitidos_votantes, suma_opciones_no_valida, nulos_validos;
	
	bool ganaA, ganaB, ganaC, empate2, empate_tecnico, mayoria_abs_A;
	
	bool coalicion, coalicion_A_C, minoriaB, participacion75, gob_A;
	
	bool nulos_abst_mayoria, nulos_y_abst, votos_correo_mayor;
	
	bool nulos_correo_mayor, nulos_correo_validos;
	
	
	emitidos_votantes = votos_emitidos > VOTANTES;
	
	suma_opciones_no_valida = votos_validos =! votos_A + votos_B + votos_C;
	
	nulos_validos = votos_emitidos == votos_validos + votos_nulos;
	
	ganaA = (votos_A > votos_B && votos_A > votos_C);
	
	ganaB = (votos_B > votos_A && votos_B > votos_C);
	
	ganaC = (votos_C > votos_B && votos_C > votos_A);
	
	empate2 = (votos_A == votos_B || votos_A == votos_C || votos_B == votos_C);
	
	//Para el siguiente crearé variables intermedias para aclarar el código
	
	double porciento_suma;
	int diferenciaAC;
	
	if (votos_A > votos_C) {
		diferenciaAC = votos_A - votos_C;
	}
	else {
		diferenciaAC = votos_C - votos_A;
	}
	porciento_suma = (votos_A + votos_C) * 0.05;
	
	
	empate_tecnico = (diferenciaAC <= porciento_suma);
	
	int mayoria = VOTANTES * 0.5; //50 votantes
	
	mayoria_abs_A = votos_A < mayoria;
	
	coalicion = (votos_A + votos_B > mayoria || votos_A + votos_C > mayoria ||
		votos_B + votos_C > mayoria );
		
	coalicion_A_C = votos_A + votos_C > mayoria;
	
	minoriaB = votos_B < votos_validos * 0.03;
	
	participacion75 = votos_emitidos > VOTANTES * 0.75;
	
	gob_A = ganaA;
	
	int abstenciones = votos_validos - votos_A - votos_B - votos_C;
	
	nulos_abst_mayoria = (votos_nulos > votos_validos || 
		abstenciones > votos_validos);
	
	nulos_y_abst = (abstenciones > votos_validos && votos_nulos > votos_validos
		&& votos_nulos >= abstenciones);
	
	votos_correo_mayor = (votos_correo > votos_presenciales * 0.2 ||
		votos_correo > abstenciones);
	
	//Añadiré variables para guardar los nulos por correo y presenciales
	
	int nulos_correo = votos_correo - votos_validos_correo;
	int nulos_presenciales = votos_presenciales - votos_validos_presenciales;
	
	nulos_correo_mayor = nulos_correo > nulos_presenciales;
	
	nulos_correo_validos = nulos_correo > votos_validos_correo;
	
	//Declaración de resultados
	
	cout <<endl;
	cout <<"**************************************************************";
	cout <<endl;
	cout <<"Apartado A: " <<emitidos_votantes <<endl;
	cout <<"Apartado B: " <<suma_opciones_no_valida <<endl;
	cout <<"Apartado C: " <<nulos_validos <<endl;
	cout <<"Apartado D: " <<ganaA <<endl;
	cout <<"Apartado E: " <<ganaB <<endl;
	cout <<"Apartado F: " <<ganaC <<endl;
	cout <<"Apartado G: " <<empate2 <<endl; 
	cout <<"Apartado H: " <<empate_tecnico <<endl;
	cout <<"Apartado I: " <<mayoria_abs_A <<endl;
	cout <<"Apartado J: " <<coalicion <<endl;
	cout <<"Apartado K: " <<coalicion_A_C <<endl; 
	cout <<"Apartado L: " <<minoriaB <<endl;
	cout <<"Apartado M: " <<participacion75 <<endl;
	if (gob_A = 1) {
		cout <<"Apartado N: A puede gobernar solo." <<endl;
	}
	else {
		cout <<"Apartado N: A puede en compania de otros." <<endl;
	}
	cout <<"Apartado N': " <<nulos_abst_mayoria <<endl;
	cout <<"Apartado O: " <<nulos_y_abst <<endl;
	cout <<"Apartado P: " <<votos_correo_mayor <<endl;
	cout <<"Apartado Q: " <<nulos_correo_mayor <<endl; 
	cout <<"Apartado R: " <<nulos_correo_validos <<endl;
	cout <<"**************************************************************";
	
	return 0;
	
}
