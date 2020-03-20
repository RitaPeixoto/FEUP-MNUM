#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double dT(double t, double T) {
	return -0.25*(T - 45);//Ta = 45
}

void euler(double t0, double T0, double h, int n) {
	double delta_t;
	double t=t0, T = T0;
	for (int i = 0; i < n; i++) {
		delta_t = dT(t, T)*h;
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;

		t += h;
		T += delta_t;
	}
}


int main() {
	cout << fixed;
	cout.precision(6);

	euler(1, 23, 0.4, 3);

	return 0;
}

