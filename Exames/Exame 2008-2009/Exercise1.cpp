#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x) {
	return (x - 2.6) + pow(cos(x + 1.1), 3);
}

double df(double x) {
	return 1 - 3 * pow(cos(x + 1.1), 2)*sin(x + 1.1);
}

void newton(double guess, int n) {
	double x = guess, xn = 0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "xn = " << xn << endl;
		xn = x - f(x) / df(x);
	}
}


int main() {
	cout << fixed;
	cout.precision(6);

	newton(1.8, 3);

	return 0;
}
