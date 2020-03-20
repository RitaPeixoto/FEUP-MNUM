#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
/*
d^2y/dx^2 = A*dy/dx - B*y;

dy/dx= z;
dz/dx = A*z -B*y;

A = -7;
B = 4;
*/

double dy(double x, double y, double z) {
	return z;
}

double dz(double x, double y, double z) {
	return -7 * z - 4 * y;
}

void euler(double x0, double y0, double z0, double h, int n) {
	double x = x0, y = y0, z = z0;
	double delta_y, delta_z;
	for (int i = 0; i < n; i++) {
		delta_y = h * dy(x, y, z);
		delta_z = h * dz(x, y, z);

		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;

		x += h;
		y += delta_y;
		z += delta_z;
	}
}


int main() {
	cout << fixed;
	cout.precision(6);

	euler(0.4000, 2.000, 1.000, 0.2, 5);

	return 0;
}