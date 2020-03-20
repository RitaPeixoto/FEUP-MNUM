#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double dT(double t, double T) {
	return -0.25*(T - 42);
}


void euler(double t0, double T0, double h, int n) {
	double delta_t, t=t0, T=T0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;
		delta_t = dT(t, T)*h;

		t += h;
		T += delta_t;

	}
}


int main() {
	cout << fixed;
	cout.precision(6);

	euler(5, 10, 0.4, 3);


	return 0;
}



