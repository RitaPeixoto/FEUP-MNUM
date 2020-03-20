#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

double dy(double z) {
	return z;
}

double dz(double x, double z) {
	return 2 + x * x + x * z;
}


double dT(double t) {
	return -0.25*(t - 42);
}
void euler(double n, double h, double x0, double y0) {
	double t = x0, T = y0;
	cout << "Iteracao 0" << endl;
	cout << "x = " << t << endl;
	cout << "y= " << T<< endl;
	for (int i = 0; i < n; i++) {
		T += h * dT(T);
		t += h;
		cout << "Iteracao "<<i+1 << endl;
		cout << "x = " << t << endl;
		cout << "y= " << T << endl;
	}
}

void euler2(double n , double h, double x0, double y0, double z0) {
	double x=x0, y=y0, z=z0;
	
	cout << "Iteracao 0 " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	for (int i = 0; i < n; i++) {
		y += h * dy(z);
		z += h * dz(x, z);
		x += h; 
		cout << "Iteracao "<< i+1<< endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}

}

int main() {
	cout << fixed;
	cout.precision(6);
	/*int n = 3;
	double h = 0.25;
	double x0=1, y0=1, z0=0;
	euler2(n, h, x0, y0, z0);*/


	int n = 4;
	double h = 0.4;
	euler(n, h, 5, 10);
	return 0; 
}





