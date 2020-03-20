#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
//Not working with the error 

double f(double x) {
	return pow(x, 4) + 2 * pow(x, 3) - x - 1;
}

double rope_iter(double a, double b, int n_iter) {

	for (int i = 0; i < n_iter; i++) {
		double m = (a*f(b) -b*f(a)) / (f(b)-f(a));
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}

double rope_error(double a, double b, double prec) {
	int i = 0;
	while(abs(a-b)>pow(10,prec)) {
		double m = (a*f(b) - b * f(a)) / (f(b) - f(a));
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
		i++;
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}

double rope_both(double a, double b, int n_iter, double prec) {
	int i = 0;
	while ((abs(a - b) > pow(10, prec)) && i<n_iter) {
		double m = (a*f(b) - b * f(a)) / (f(b) - f(a));
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
		i++;
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}

int main() {
	cout << fixed;
	cout.precision(6);

	double prec = -3;
	int n_iter = 15;
	double a = 0, b = 1;

	cout << rope_iter(a, b, n_iter) << endl;

	//cout << rope_error(a, b, prec) << endl;

	cout << rope_both(a, b, n_iter, prec) << endl;

	return 0;
}