#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { return (x*x - 4); }	// f(x) = x^2 - 4

/***
  Rope's Method
  a0 - Interval's left extreme
  b0 - Interval's right extreme
  num_iter - Number of iterations
 ***/
void corda(double a0, double b0, unsigned int num_iter) {
	// Initial values
	double a = a0;
	double b = b0;
	double guess;
	int i = 0;

	//cout << 0 << ":\t" << a << "\t" << b << "\t" << abs(b - a) << endl;

	// Loop until final interval is reached
	while (i < 50 & abs(a-b) > 5 * pow(10, -3)) {
		guess = (a*f(b) - b * f(a)) / (f(b) - f(a));

		// Print current values
		cout << "Iteracao numero " << i << endl;
		cout << "a = " << a << " --- f(a) = " << f(a) << endl;
		cout << "b = " << b << " --- f(b) = " << f(b) << endl;
		cout << "guess = " << guess << " --- f(guess) = " << f(guess) << endl << endl;
		// Decide which extreme changes
		if (f(guess) * f(a) > 0)
			a = guess;
		else
			b = guess;
		i++;
	}

}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Values
	const double a0 = -2;
	const double b0 = -1;

	// Call the method
	corda(a0, b0, 45);

	return 0;
}