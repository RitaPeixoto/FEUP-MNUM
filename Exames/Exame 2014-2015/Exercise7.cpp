#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

double f(double x) {
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

void bissection(double a, double b, int n) {
	double m;
	cout << "Iteracao: 0"<< endl;
	cout << "a: " << a << "\t f(a): " << f(a) << endl;
	cout << "b: " << b << "\t f(b): " << f(b) << endl;
	for (int i = 0; i < n; i++) {
		m = (a + b) / 2.0;
		if (f(a)*f(m) < 0) {
			a = a;
			b = m;
		}
		else {
			a = m;
			b = b;
		}
		cout << "Iteracao: " << i+1 << endl;
		cout << "a: " << a << "\t f(a): " << f(a) << endl;
		cout << "b: " << b << "\t f(b): " << f(b) << endl;
		cout << "m: " << m << "\t f(m): " << f(m) << endl << endl;
	}
	
}




int main() {
	cout << fixed;
	cout.precision(6);
	double a = 1.5, b = 4.2;
	int n = 4;


	bissection(a, b, n);

	return 0;
}