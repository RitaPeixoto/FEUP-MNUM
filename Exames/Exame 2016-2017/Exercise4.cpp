#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

double f(double x) {
	return	pow(x, 7) + 0.5*x - 0.5;
}


void rope(double a, double b, int n) {
	double next=0;
	for (int i = 0; i < n; i++) {
		cout << i << endl;
		cout << "a: " << a << endl << "b: " << b << endl;
		cout << "f(a): " << f(a) << endl << "f(b): " << f(b) << endl;
		next = (a*f(b) - b * f(a)) / (f(b) - f(a));
		cout << "next: " << next << endl;
		cout << "f(next): " << f(next) << endl;
		if (f(next)*f(a) < 0) {
			a = a;
			b = next;
		}
		else {
			a = next;
			b = b;
		}
	}
}




int main() {
	cout << fixed;
	cout.precision(6);

	rope(0.00000, 0.80000, 4);


	return 0;
}