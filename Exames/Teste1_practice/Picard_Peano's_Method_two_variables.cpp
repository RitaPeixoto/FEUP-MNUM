#include <iostream>
#include <cmath>

using namespace std;
double pi = 3.14159265359;
//funçoes ja recursivas
double f1(double x, double y) { return ((10/x)-x); }		// f1(x,y) = 2x^2 - xy - 5x + 1 = 0    --->   x = sqrt( (x(y + 5) - 1)/2 )

double f2(double x, double y) { return ((57-y)/(3*y*y)); }			// f2(x,y) = x + 3log10(x) - y^2 = 0   --->   y = sqrt( x + log10(x) )

/***
  Picardo-Peano's Method (two variables)
  x0 - Initial X guess
  y0 - Initial Y guess
  num_iter - Number of iterations
 ***/
void picardo_peano(double x0, double y0, unsigned int num_iter) {
	/*int i = 0;
	double x = 1;
	double y = 1;
	double	xAnt = 2;
	double	yAnt = 2;
	while (((abs(xAnt - x) >= pow(10, -4)) || (abs(yAnt - y) >= pow(10, -4))) && i<num_iter) {
		xAnt = x;
		yAnt = y;
		x = f1(x, y);
		y = f2(xAnt, y);
		cout << "x: " << x<<" y: "<<y<< endl;
		i++;
		}*/
			



	/*// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for (unsigned int i = 1; i <= num_iter || abs(xn-x)<pow(10,-4) && abs(yn-y)<pow(10,-4); i++) {
		xn = f1(x, y);
		yn = f2(x, y);

		// Update the variables
		x = xn;
		y = yn;

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}*/

	int i = 0;
    double xf = x0, yf = y0, auxx, auxy;
    while (i < 10) {
 
        cout << i << " iteracao" << endl;
        cout << "x = " << x0 << endl;
        cout << "y = " << y0<< endl;
 
        xf = f1(x0, y0);
        yf = f2(x0, y0);
 
        x0 = xf;
        y0 = yf;
 
        cout << "g1 = " << xf << endl;
        cout << "g2 = " << yf << endl << endl;
        i++;
    }
}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guess
	const double x0 = 3.0;
	const double y0 = 3.0;

	// Call the method
	picardo_peano(x0, y0, 15);

	return 0;
}