#include <iostream>
#include <cmath>

using namespace std;

double f1(double x, double y) { return (x*x -y - 1.2); }	// f1(x,y) = x^2 - y - a , sendo que a=1.2

double df1x(double x, double y) { return (2*x); }			// df1/dx(x,y) = 2*x

double df1y(double x, double y) { return (-1); }			// df1/dy(x,y) = -1

double f2(double x, double y) { return (-x +y*y-0.5); }			// f2(x,y) = y^2 - x-b, sendo b=0.5

 
double df2x(double x, double y) { return (-1); }			// df2/dx(x,y) = -1

double df2y(double x, double y) { return (2*y); }			// df2/dy(x,y) = 1


double j(double x, double y) {
    return df1x(x, y)*df2y(x, y) - df2x(x, y)*df1y(x, y);
}
 
double h(double x, double y) {
    return -(f1(x, y)*df2y(x, y) - f2(x, y)*df1y(x, y)) / j(x, y);
}
 
double k(double x, double y) {
    return -(f2(x, y)*df1x(x, y) - f1(x, y)*df2x(x, y)) / j(x, y);;
   
}
 
/***
  Newton's Method (two variables)
  x0 - Initial X guess
  y0 - Initial Y guess
  num_iter - Number of iterations
 ***/
void newton(double x0, double y0, unsigned int num_iter) {

	double xAnt;

	for (int i = 0; i <= num_iter||abs(x0-y0)<pow(10,-4); i++) {
		xAnt = x0;

		cout << "Iteracao " << i << endl;
		cout << "x = " << x0 << endl;
		cout << "y = " << y0 << endl << endl;


		x0 += h(x0, y0);
		y0+= k(xAnt, y0);
	}
	/*// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;
	double jacobian;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for (unsigned int i = 1; i <= num_iter; i++) {
		// Update the variables
		x = xn;
		y = yn;

		jacobian = df1x(x, y)*df2y(x, y) - df2x(x, y)*df1y(x, y);
		xn = x - (f1(x, y)*df2y(x, y) - f2(x, y)*df1y(x, y)) / jacobian;
		yn = y - (f2(x, y)*df1x(x, y) - f1(x, y)*df2x(x, y)) / jacobian;

	
		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}
	*/
}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Guesses
	const double x0 = 1.10000;
	const double y0 = 1.10000;

	// Call the method
	newton(x0, y0, 30);

	return 0;
}