#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


double dy(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

void rk2_1_order() {

	double a = 0, b = 1.4, x = 0, y = 0, result = 0, h = 0.1, n = (abs(b - a) / h);

	for (int i = 0; i < n; i++) {
		y += h * dy(x + (h / 2.0), y + (h / 2.0) * dy(x, y));
		x += h;
		cout << i << ". x = " << x << "\t y = " << y << endl;
	}

	result = y;

	cout << endl << "---------" << endl;

	x = 0, y = 0;
	double h1 = h / 2.0, n1 = (abs(b - a)) / h1, result1;

	for (int i = 0; i < n1; i++) {
		y += h1 * dy(x + (h1 / 2.0), y + (h1 / 2.0)*dy(x, y));
		x += h1;
		cout << i << ". x = " << x << "\t y = " << y << endl;
	}
	result1 = y;

	cout << endl << "---------" << endl;

	x = 0, y = 0;
	double h2 = h1 / 2.0, n2 = (abs(b - a)) / h2, result2;

	for (int i = 0; i < n2; i++) {
		y += h2 * dy(x + (h2 / 2.0), y + (h2 / 2.0)*dy(x, y));
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