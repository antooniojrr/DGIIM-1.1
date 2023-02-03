/************************************************************************/
//Fundamentos de Programación
//Antonio Javier Rodríguez Romero. DGIIM A1.
//
//RELACIÓN DE PROBLEMAS 2. Nº20.
//
//II_Subida_SalarioPrecario_enum.cpp: escribe un pograma que lea la edad
//y el salario de una persona y aplique si es pertinente una subida en este.
//
//Entrada: edad y salario
//Salida: aumento aplicado, salario final
//
/************************************************************************/

#include <iostream>     //Inclusión de los recursos de E/S
#include <iomanip>      // Formato
#include <string>       //Inclusión de la clase string

using namespace std;

int main ()             //Programa Principal
{
	
	cout.setf(ios::fixed);      // Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	
	//Constantes
	
	const double AUMENTO_EDAD = 0.04;
	const double AUMENTO_INF_300 = 0.03;
	const double AUMENTO_INF_900 = 0.015;
	const int EDAD_MIN = 35;
	const int EDAD_MAX = 65;
	const int SALARIO_PRECARIO = 300;
	const int SALARIO_MIN = 900;
	
	//Entrada de datos
	
	int edad;
	double salario;
	
	cout <<"Introduzca su edad: ";
	cin >> edad;
	cout <<"Introduzca su salario: ";
	cin >> salario;
		
	enum class TipoDescuento {ninguno, por_edad, por_menor_900, maximo};
	
	TipoDescuento descuento;
	
	//Cálculos.
	
	bool edad_aprop = (edad > EDAD_MAX || edad < EDAD_MIN);
	bool inf_300 = (salario < SALARIO_PRECARIO);
	bool inf_900 = (salario < SALARIO_MIN && salario > SALARIO_PRECARIO);
	
	if (edad_aprop) {
		
		if (inf_300) descuento = TipoDescuento::maximo;
		
		if (inf_900) descuento = TipoDescuento::por_menor_900;
		
		if (!inf_300 && !inf_900) descuento = TipoDescuento::por_edad;
		
	}
	else descuento = TipoDescuento::ninguno;
	
	//Resultados
	cout <<endl;
	
	switch (descuento) {
		
		case (TipoDescuento::ninguno) :
			
			cout <<"Descuento aplicado:     0%" <<endl;
			
			cout <<"Salario final:     " <<setw(8) <<setprecision(2)
				 <<salario;
			break;
		
		case (TipoDescuento::por_edad) :
			
			cout <<"Descuento aplicado:" <<setw(8) <<setprecision(2)
				 <<AUMENTO_EDAD * 100 <<"%" <<endl;
				 
			cout <<"Salario final:" <<setw(13) <<setprecision(2)
				 <<salario * (1 + AUMENTO_EDAD) <<"E";
		break;
		
		case (TipoDescuento::por_menor_900) :
			cout <<"Descuento aplicado:" <<setw(8) <<setprecision(2)
				 <<(AUMENTO_EDAD + AUMENTO_INF_900) * 100 <<"%" <<endl;
				 
			cout <<"Salario final:" <<setw(13) <<setprecision(2)
				 <<salario * (1 + AUMENTO_EDAD + AUMENTO_INF_900) <<"E";
		break;
		
		case (TipoDescuento::maximo) :
			
			cout <<"Descuento aplicado:" <<setw(8) <<setprecision(2)
				 <<(AUMENTO_EDAD + AUMENTO_INF_300) * 100 <<"%" <<endl;
				 
			cout <<"Salario final:" <<setw(13) <<setprecision(2)
				 <<salario * (1 + AUMENTO_EDAD + AUMENTO_INF_300) <<"E";
		break;
	}
	
	return 0;
	
}
	
	
	
	
