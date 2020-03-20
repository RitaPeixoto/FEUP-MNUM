#include<iostream>
#include<cmath>
using namespace std;



double d1y(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

double d2y(double x, double y, double z) {
	return z;
}

double d2z(double x, double y, double z) {
	return x - 3 * z - 2 * y;
}


/*double dx(double x, double t) {
	return sin(2 * x) + sin(2 * t);
}*/
double dx(double x, double y) {
	return x * x + y * y;
}

void rk4_2_variables() {

	double a = 0, b = 1.4, x = 0, y=0, result = 0, h = 0.1, n = (abs(b - a) / h);
	double d1, d2, d3, d4;
	cout << "0. x = " << x << "\t y = " << y << endl;
	for (int i = 0; i <n ; i++) {
		d1 = h * dx(x, y);
		d2 = h * dx(x + (h / 2), y + (d1 / 2.0));
		d3 = h * dx(x + (h / 2.0), y + (d2 / 2.0));
		d4 = h * dx(x + h, y + d3);
		y += (d1 / 6.0) + (d2 / 3.0) + (d3 / 3.0) + (d4 / 6.0);
		x += h;
		cout << i +1<< ". x = " << x << "\t y = " << y << endl;

	}

	result = y;
	cout << endl << "---------" << endl;

	x = 0, y = 0;
	double result1, h1 = h / 2.0, n1 = abs(b - a) / h1;
	cout << "0. x = " << x << "\t y = " << y << endl;
	for (int i = 0; i <= n1; i++) {

		d1 = h1 * dx(x, y);
		d2 = h1 * dx(x + (h1 / 2), y + (d1 / 2.0));
		d3 = h1 * dx(x + (h1 / 2.0), y + (d2 / 2.0));
		d4 = h1 * dx(x + h1, y + d3);
		y += (d1 / 6.0) + (d2 / 3.0) + (d3 / 3.0) + (d4 / 6.0);
		x += h1;
		cout << i << ". x = " << x << "\t y = " << y << endl;
	}

	result1 = y;
	cout << endl << "---------" << endl;

	x = 0, y = 0;
	double result2, h2 = h1 / 2.0, n2 = abs(b - a) / h2;
	cout  << "0. x = " << x << "\t y = " << y << endl;
	for (int i = 0; i <= n2; i++) {
		d1 = h2 * dx(x, y);
		d2 = h2 * dx(x + (h2 / 2), y + (d1 / 2.0));
		d3 = h2 * dx(x + (h2 / 2.0), y + (d2 / 2.0));
		d4 = h2 * dx(x + h2, y + d3);
		y += (d1 / 6.0) + (d2 / 3.0) + (d3 / 3.0) + (d4 / 6.0);
		x += h2;
		cout << i << ". x = " << x << "\t y = " << y << endl;
	}

	result2 = y;

	cout << endl << "---------" << endl;

	double qc = (result1 - result) / (result2 - result1);

	cout << "quociente de convergencia = " << qc << endl;

	double e = result2 - result1;

	cout << "erro = " << e << endl;
}

void rk4_3_variables() {
	double a = 0, b = 0.5, x = 0, y = 0, z = 0, result = 0, h = 0.05, n = (abs(b - a) / h);
	double dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;

	for (int i = 0; i < n; i++) {
		dy1 = h * d2y(x, y, z);
		dy2 = h * d2y(x + (h / 2), y + (dy1 / 2.0), z + (dy1 / 2.0));
		dy3 = h * d2y(x + (h / 2.0), y + (dy2 / 2.0), z + (dy2 / 2.0));
		dy4 = h * d2y(x + h, y + dy3, z + dy3);

		dz1 = h * d2z(x, y, z);
		dz2 = h * d2z(x + (h / 2), y + (dz1 / 2.0), z + (dz1 / 2.0));
		dz3 = h * d2z(x + (h / 2.0), y + (dz2 / 2.0), z + (dz2 / 2.0));
		dz4 = h * d2z(x + h, y + dz3, z + dz3);

		y += (dy1 / 6.0) + (dy2 / 3.0) + (dy3 / 3.0) + (dy4 / 6.0);
		z += (dz1 / 6.0) + (dz2 / 3.0) + (dz3 / 3.0) + (dz4 / 6.0);
		x += h;


		cout << i << ". x = " << x << "\t y = " << y << "\t z = " << z << endl;
	}
}
int main() {
	rk4_2_variables();
	return 0;
}


/*
double dz(double x, double z) {
	return 2 + pow(x, 2) + x * z;
}

int main() {
	double h = 0.25, t = 1, y = 1, z = 0, deltaz;

	cout << endl << endl << "RK4: " << endl;
	h = 0.25;
	t = 1;
	y = 1;
	z = 0;
	double z1, z2, z3, z4, dz1, dz2, dz3, dz4;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		z1 = (h * z);
		dz1 = h * dz(t, z);
		z2 = (h * (z + dz1 / 2));
		dz2 = (h * (dz(t, z + dz1 / 2)));
		z3 = (h * (z + dz2 / 2));
		dz3 = (h * (dz(t, z + dz2 / 2)));
		z4 = (h * (z + dz3));
		dz4 = (h * (dz(t, z + dz3)));
		y += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		t += h;
}
	*/