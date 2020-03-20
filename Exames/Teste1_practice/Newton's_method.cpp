#include <iostream>
#include<algorithm>
#include <cmath>


using namespace std;

double f(double x) { return ((x-2.6)+pow(cos(x+1.1),3)); }	// f(x) = ....
double df(double x) { return 1-3*pow(cos(x+1.1),2)*sin(x+1.1); }		// f'(x) = ....

/***
  Newton's Method
  x0 - Initial guess
  num_iter - Number of iterations
 ***/
void newton(double x0, unsigned int num_iter) {
	/*// Initial values
	int i = 1;
	double xseg = x - (f(x) / df(x)), aux;

	cout << "Iteracao numero " << 0 << endl;
	cout << "x = " << x << "  xn+1 = " << xseg << endl << endl;

	while (i < 30 & (abs(xseg - x) > 5 * pow(10, -6))) {

		aux = xseg;
		xseg = x - (f(x) / df(x));
		x = aux;

		cout << "Iteracao numero " << i << endl;
		cout << "x = " << x << "  xn+1 = " << xseg << endl << endl;

		i++;
	}*/



	double x = x0;

	cout << 0 << ":\t" << x << endl;

	// Loop until final interval is reached
	for (unsigned int i = 1; i <= num_iter; i++) {
		x = x - f(x) / df(x);

		// Print current value
		cout << i << ":\t" << x << endl;
	}

}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(5);

	// Guess
	const double x0 = 1.8;

	// Call the method
	newton(x0, 3);

	return 0;
}