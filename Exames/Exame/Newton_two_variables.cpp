#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
//confirmed  with exam 2016/2017


double f1(double x, double y) {
	return (x*x - y - 1.2);
}
double df1x(double x, double y) {
	return 2 * x ;
}
double df1y(double x, double y) {
	return -1;
}
double f2(double x, double y) {
	return (-x + y * y - 1);
}
double df2x(double x, double y) {
	return -1;
}
double df2y(double x,double y) {
	return 2*y;
}


double jacobian(double x, double y) {
	return df1x(x, y)*df2y(x, y) - df2x(x, y)*df1y(x, y);
}
/* x0 - initial guess
   n_iter - numero de iteraçoes
*/
void newton(double x0, double y0,double n_iter) {
	double x = x0, y=y0,xn=0,yn=0;
	double m = 0;
	for (int i = 0; i < n_iter; i++) {
		cout << "i: " << i << "\t" << x << "\t" << y << endl;
		xn = x - (f1(x, y)*df2y(x, y) - f2(x, y)*df1y(x, y)) / jacobian(x, y);
		yn = y - (f2(x, y)*df1x(x, y) - f1(x, y)*df2x(x, y)) / jacobian(x, y);

		x = xn; 
		y = yn; 
	}
}



int main() {
	cout << fixed;
	cout.precision(6);


	// Guesses
	const double x0 = 1.0000;
	const double y0 = 1.0000;

	// Call the method
	newton(x0, y0, 4);


	return 0;
}