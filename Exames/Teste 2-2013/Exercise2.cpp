#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*Neste teste vou fazer apenas o exercicios 2 e 3, porque o 1 encontra-se idêntico ao 1 de 2015 e o 4 identico 1 de 2016*/

double dx(double t, double x) {
	return sin(2 * x) + sin(2 * t);// a=2 e b=2
}


double runge_kutta4(double t0, double x0, double h, int n) {
	double t = t0, x=x0;
	double dx1, dx2, dx3, dx4;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "x = " << x << endl;

		dx1 = h * dx(t, x);
		dx2 = h * dx(t + h / 2.0, x + dx1 / 2.0);
		dx3 = h * dx(t + h / 2.0, x + dx2 / 2.0);
		dx4 = h * dx(t + h, x + dx3);

		if (t == 1.5) {
			return x;
		}
		t += h;
		x += dx1 / 6.0 + dx2 / 3.0 + dx3 / 3.0 + dx4 / 6.0;
	}
}

int main() {
	cout << fixed;
	cout.precision(6);
	double r, r_1, r_2;
	cout << "1ª Integracao" << endl;
	r=runge_kutta4(1.000, 1.0000,0.5, 3);

	cout << "2ª Integracao" << endl;
	r_1=runge_kutta4(1.000, 1.0000, 0.25, 4);

	cout << "3ª Integracao" << endl;
	r_2=runge_kutta4(1.000, 1.0000, 0.125, 6);

	double qc = (r_1 - r) / (r_2-r_1);
	cout << "QC = " << qc << endl;

	return 0;
}

