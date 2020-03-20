#include<iostream>
#include <cmath>
#include<algorithm>

using namespace std;
double rec_f(double x) { return (2*log(2*x)); }	// f(x) = x + 1 - tan(x) = 0   --->   x = tan(x) - 1   --->   tan(x) = x + 1   --->   x = atan(x+1)

/***
  Picardo-Peano's Method
  x0 - Initial guess
  num_iter - Number of iterations
 ***/
void picardo_peano(double x, unsigned int num_iter) {
	/*// Initial values
	double x = x0;
	int i = 0;
	double xseg = rec_f(x);

	cout << "Iteracao numero " << 0 << endl;
	cout << "x = " << x << "  xn+1 = " << xseg << endl << endl;


	while (i < 30 & (abs(x - xseg) > 5 * pow(10, -5))) {
		cout << "Iteracao numero " << i << endl;
		cout << "x = " << x << "  xn+1 = " << xseg << endl << endl;

		x = xseg;
		xseg = rec_f(x);

		i++;
	}*/
	cout << 0 << ":\t" << x << endl;

	// Loop until final interval is reached
	for (unsigned int i = 1; i <= num_iter; i++) {
		x = rec_f(x);

		// Print current value
		cout << i << ":\t" << x << endl;
	}
}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guess
	const double x0 = 0.9;

	// Call the method
	picardo_peano(x0, 30);

	return 0;
}
