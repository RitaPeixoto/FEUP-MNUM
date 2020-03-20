#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double dy(double t, double y, double z) {
	return z;
}

double dz(double t, double y, double z) {
	return 0.5 + pow(t, 2) + t * z;//A= 0.5
}

void euler(double t0, double y0, double z0, double h, int n) {
	double delta_z, delta_y;
	double t = t0, y = y0, z = z0;
	for (int i = 0; i < n; i++) {
		delta_y = dy(t, y, z) * h;
		delta_z = dz(t, y, z) *h;
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;

		t += h;
		y += delta_y;
		z += delta_z;
	}
}

void runge_kutta_4(double t0, double y0, double z0, double h, int n) {
	double d_y1, d_z1, d_y2, d_z2, d_y3, d_z3, d_y4, d_z4;
	double t = t0, y = y0, z = z0;

	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;

		d_y1 = h * dy(t, y, z);
		d_z1 = h * dz(t, y, z);

		d_y2 = h * dy(t + h / 2.0, y + d_y1 / 2.0,z + d_z1 / 2.0);
		d_z2 = h * dz(t + h / 2.0, y + d_y1 / 2.0, z + d_z1 / 2.0);


		d_y3 = h * dy(t + h / 2.0, y + d_y2 / 2.0, z + d_z2 / 2.0);
		d_z3 = h * dz(t + h / 2.0, y + d_y2 / 2.0, z + d_z2 / 2.0);

		
		d_y4 = h * dy(t+h, y+d_y3, z+d_z3);
		d_z4= h * dz(t + h, y + d_y3, z + d_z3);


		t += h;
		y += d_y1 / 6.0 + d_y2 / 3.0 + d_y3 / 3.0 + d_y4 / 6.0;
		z += d_z1 / 6.0 + d_z2 / 3.0 + d_z3 / 3.0 + d_z4 / 6.0;

	}
}



int main() {
	cout << fixed;
	cout.precision(6);
	double t0 = 0, y0 = 0, z0 = 1, h = 0.25;
	int n = 4;
	euler(t0, y0, z0, h, n);
	runge_kutta_4(t0, y0, z0, h, n);


	return 0;
}