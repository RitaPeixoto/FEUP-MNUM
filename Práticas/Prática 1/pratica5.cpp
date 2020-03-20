#include<iostream>
#include<cmath>

using namespace std;




double f1(double x, double y) { return sqrt((x*(y + 5) - 1) / 2); }		// f1(x,y) = 2x^2 - xy - 5x + 1 = 0    --->   x = sqrt( (x(y + 5) - 1)/2 )

double f2(double x, double y) { return sqrt(x +3*log(x)); }			// f2(x,y) = x + 3log10(x) - y^2 = 0   --->   y = sqrt( x +3* log(x) )

/***
  Picardo-Peano's Method (two variables)
  x0 - Initial X guess
  y0 - Initial Y guess
  num_iter - Number of iterations
 ***/
void picardo_peano(double x0, double y0, unsigned int num_iter) {
	// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	xn = f1(x, y);
	yn = f2(x, y);
	cout << "a";
	for (unsigned int i = 0;(i<num_iter ||(abs(x-xn)<= pow(10,-5) &&  abs(y-yn)<=pow(10,-5))); i++) {
		cout << "b";
		// Update the variables
		x = xn;
		y = yn;

		xn = f1(x, y);
		yn = f2(xn, y);

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}

}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guess
	const double x0 = 1.46;
	const double y0 = -1.41;

	// Call the method
	picardo_peano(x0, y0, 15);

	return 0;
}
