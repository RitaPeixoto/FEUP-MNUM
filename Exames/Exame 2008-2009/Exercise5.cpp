#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double t, double x) {
	return sin(x) + sin(2 * t);
}

double runge_kutta4(double t0, double x0, double h, int n) {
	double dx1, dx2, dx3, dx4;
	double t = t0, x = x0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "x = " << x << endl;
		dx1 = h * f(t, x);
		dx2 = h * f(t + h / 2.0, x + dx1 / 2.0);
		dx3 = h * f(t + h / 2.0, x + dx2 / 2.0);
		dx4 = h * f(t + h, x + dx3);

		t += h;
		x += dx1 / 6.0 + dx2 / 3.0 + dx3 / 3.0 + dx4 / 6.0;
		if (t == 1.5) {
			return x;
		}
	}
}




int main() {
	cout << fixed;
	cout.precision(6);
	double r, r_1, r_2;
	cout << "h = 0.5" << endl;
	r=runge_kutta4(1.0000, 1.0000, 0.5, 2);
	cout << endl << "h =0.25" << endl;
	r_1=runge_kutta4(1.0000, 1.0000, 0.25, 3);
	cout << "h = 0.125 " << endl;
	r_2=runge_kutta4(1.0000, 1.0000, 0.125, 4);

	double qc = (r_1 - r) / (r_2 - r_1);
	cout << "Qc = " << qc << endl;

	return 0;
}

