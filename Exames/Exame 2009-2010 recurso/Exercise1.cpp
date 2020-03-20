#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dy(double t, double y) {
	return (y) / (t - 1);// dy/dt = y/(t-a), sendo que a=1
}


void euler(double t0, double y0, double h, int n) {
	double delta_y, t = t0, y = y0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;

		delta_y = h * dy(t, y);
		t += h;
		y += delta_y;

	}
}

void runge_kutta4(double t0, double y0, double h, int n) {
	double dy1, dy2, dy3, dy4;
	double t = t0, y = y0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;


		dy1 = h * dy(t, y);
		dy2 = h * dy(t + h / 2.0, y + dy1 / 2.0);
		dy3 = h * dy(t + h / 2.0, y + dy2 / 2.0);
		dy4 = h * dy(t + h, y + dy3);

		t += h;
		y += dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;
	}



}


int main() {
	cout << fixed;
	cout.precision(6);

	double t0 = 2, y0 = 2, h = 0.25;
	int n = 3;


	cout << "Euler " << endl;
	euler(t0, y0, h, n);
	cout << endl << "Runge Kutta 4" << endl;
	runge_kutta4(t0, y0, h, n);




	return 0;
}