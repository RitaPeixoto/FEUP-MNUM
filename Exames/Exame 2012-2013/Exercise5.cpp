#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
	return (x - 3.7) + pow(cos(x + 1.2), 3);
}

double df(double x) {
	return 1 - 3 * pow(cos(x + 1.20), 2)*sin(x + 1.20);
}

void newton(double guess, int n) {
	double x = guess;
	for(int i = 0; i <= n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;

		x = x - f(x) / df(x);
	}
}


int main() {
	cout << fixed;
	cout.precision(6);

	newton(3.8, 2);



	return 0;
}