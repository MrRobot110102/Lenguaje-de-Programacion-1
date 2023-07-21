#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a = 2351,b=765,c=1234;
	char prev;
	
	cout<<right<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<left<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<right<<hex<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<uppercase<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<oct<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<dec<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<nouppercase<<endl;
	
	cout << setfill('X') << setw(10) << a << setw(10) << b << setw(10) << c << endl;
	cout << setfill('0') << setw(10) << a << setw(10) << b << setw(10) << c << endl;
	cout << setfill(' ') << setw(10) << a << setw(10) << b << setw(10) << c << endl<<endl;
	
	double f = 314.15926535;
	cout << fixed;
	cout << setw(14) << f << endl; 	// Que es equivalente a:
	cout.precision(10); 			// cout << setprecision(10) << setw(14) << f << endl;
	cout << setw(14) << f << endl; 	//
	cout.precision(3); 				// cout << setprecision(3) << setw(14) << f << endl;
	cout << setw(14) << f << endl; 	//
	cout.unsetf(ios::fixed);
	
	//cin >> a >> f;
	//cout << a << endl << f << endl;
	
	char a1, b1, c1,d1,d2,d3;
	cout << "Ingrese un texto: "<<endl;
	//cin >> ws;
	d1 = cin.peek();
	d3 = cin.peek();
	a1 = cin.get();
	d2 = cin.peek();
	b1 = cin.get();
	c1 = cin.get();
	cout << "A = " << a1 << endl;
	cout << "B = " << b1 << endl;
	cout << "C = " << c1 << endl;
	cout << "D1 = " << d1 << endl;
	cout << "D2 = " << d2 << endl;
	cout << "D3 = " << d3 << endl;
	cout <<left<<setw(25)<<"Juan Rodriguez"<<right<<setw(5)<<a<<endl;
	cout <<left<<setw(25)<<"Ana Li"<<right<<setw(5)<<b<<endl;
	cout <<left<<setw(25)<<"Pedro Quispe Salinas"<<right<<setw(5)<<c<<endl<<endl;
	//****** algún problema que se puede presentar ******
	cout <<right<<setw(5)<<a<<"  "<<left<<setw(25)<<"Juan Rodriguez"<<endl;
	cout <<right<<setw(5)<<b<<"  "<<left<<setw(25)<<"Ana Li"<<endl;
	cout <<right<<setw(5)<<c<<"  "<<left<<setw(25)<<"Pedro Quispe Salinas"<<endl<<endl;
	
	//****** función miembro fill y setfill(v) de iomanip ******
 	cout<<right<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
 	prev = cout.fill('T'); //setfill('T');
	cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
 	cout<<setw(10)<<b<<setw(10)<<c<<setw(10)<<a<<endl;
 	cout.fill(prev);
 	cout<<setw(10)<<c<<setw(10)<<a<<setw(10)<<b<<endl<<endl;
	
	return 0;
}
