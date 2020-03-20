#include<cmath>
#include<iostream>
#include<iomanip>


using namespace std;

double dC(double C, double T) {
	return -(exp((-0.5) / (T + 273))) * C;
}

double dT(double C, double T) {
	return 20 * exp(-0.5 / (T + 273))*C - 0.5*(T - 20);
}


void Euler(double t0,double c0, double T0, double h, double n ) {
	double C = c0, T=T0, t=t0,fT,fC;
	cout << "Iteracao 0 " << endl;
	cout << "t = " << t << endl;
	cout << "C = " << C << endl;
	cout << "T = " << T << endl;
	
	for (int i = 0; i < n; i++) {
		fT = h*dT(C, T);
		fC = h*dC(C, T);
		C += fC;
		T += fT;
		t += h;
		cout << "Iteracao "<<i+1 << endl;
		cout << "t = " << t << endl;
		cout << "C = " << C << endl;
		cout << "T = " << T << endl;
	}
}


int main() {
	cout << fixed;
	cout.precision(6);
	double c0 = 1.00000, T0 = 15.0000, t0=0;
	double h = 0.25;
	int n = 5; 
	Euler(t0, c0, T0, h, n);




	return 0;
}



