//****** Modo de corregir el error ******
// Suponiendo que el segundo dato puede ser indistintamente
// un entero o una cadena. Por ejemplo:
// 2346 645 763
// 6534 ABC 837

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a = 23, b = 7653, c = 9;
	double p = 3547.73621, q = 1.735, r = 0.005241;
	char car, nombre[50], apellido[50];
	int dd,mm,aa;
	cin >> a >> b;
 	if (cin.fail()){ // Se verifica si hay error
 		cin.clear(); // Se levanta una bandera
 		cin >> nombre >> c;
 		cout << nombre << endl;
 	}
 	else cin >> c;
 	cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cin >> p;
 	cout<<setw(10)<<p<<endl;
	return 0;
	//1 ABC 2
	//1 abc asc 3
	//1 aacs ass asa 3
}

