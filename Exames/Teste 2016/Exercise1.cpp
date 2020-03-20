#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double dC(double t,double T, double c) {
	return -exp(-0.5 / (T + 273))*c;// b = 0.5		
}


double dT(double t, double T,double c) {
	return 20.0*exp(-0.5 / (T + 273))*c - 0.5*(T - 20);// a = 20.0, b = 0.5
}

double euler(double t0, double T0, double c0, double h, int n) {
	double t = t0, T = T0, c = c0;
	double delta_t, delta_c;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;
		cout << "C = " << c << endl;
		delta_t = h * dT(t, T, c);
		delta_c = h * dC(t, T, c);

		if (i == n - 1) {
			return c;
		}
		t += h;
		T += delta_t;
		c += delta_c;

	}
}

void runge_kutta4(double t0, double T0, double c0, double h, int n) {
	double t = t0, T = T0, c = c0;
	double dt1, dt2, dt3, dt4, dc1, dc2, dc3, dc4;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;
		cout << "C = " << c << endl;

		dt1 = h * dT(t, T, c);
		dc1 = h * dC(t, T, c);

		dt2 = h * dT(t + h / 2.0, T + dt1 / 2.0, c + dc1 / 2.0);
		dc2 = h * dC(t + h / 2.0, T + dt1 / 2.0, c + dc1 / 2.0);

		dt3 = h * dT(t + h / 2.0, T + dt2 / 2.0, c + dc2 / 2.0);
		dc3 = h * dC(t + h / 2.0, T + dt2 / 2.0, c + dc2 / 2.0);

		dt4 = h * dT(t + h, T + dt3, c + dc3);
		dc4 = h * dC(t + h, T + dt3, c + dc3);

		t += h;
		T += dt1 / 6.0 + dt2 / 3.0 + dt3 / 3.0 + dt4 / 6.0;
		c += dc1 / 6.0 + dc2 / 3.0 + dc3 / 3.0 + dc4 / 6.0;


	}
}





int main() {
	cout << fixed;
	cout.precision(6);
	double s, s_1, s_2;
	cout << "Euler " << endl;
	s = euler(0, 15.0, 1.0, 0.25, 3);
	s_1 = euler(0, 15.0, 1.0, 0.125, 5);
	s_2 = euler(0, 15.0, 1.0, 0.0625, 9);
	cout << endl << "Runge Kutta 4" << endl;
	runge_kutta4(0, 15.0, 1.0, 0.25, 3);
	double error = s_2 - s_1;
	cout << "Error = " << error << endl;
	return 0;
}



