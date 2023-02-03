
#include <iostream>
using namespace std;

int main () {
	double radio, area, longitud;
	const double PI = 3.1416;
	
	cout <<"Introduce el radio de la circunferencia: ";
	
	cin >> radio;
	
	area = PI * radio * radio;
	longitud = PI * radio * 2;
	cout <<endl;
	cout <<"El area del circulo es" << area << endl;
	cout <<"La longitud es " <<longitud <<endl <<endl;
	
	return 0;
}
