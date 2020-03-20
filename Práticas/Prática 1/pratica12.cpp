#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double f1(double x, double y) {
	return sin(y) + y * y / 4.0 + cos(x) + x * x / 4.0 - 1;
}


double hx(double xn) {
	return (xn / 2.0 - sin(xn)) / (1 / 2.0 - cos(xn));
}
double hy(double yn) {
	return (cos(yn) + yn / 2.0) / (1 / 2.0 - sin(yn));
}
void quadrica(double x0, double y0, int n) {
	double x_next, y_next, xn=0, yn=0;

	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << xn << endl;
		cout << "y = " << yn << endl;
		cout << " f(x,y) = " << f1(xn, yn) << endl<<endl;
		x_next = xn - hx(xn);
		y_next = yn - hy(yn);

		xn = x_next; 
		yn = y_next; 
	}
	cout << "Iteracao 4" << endl;
	cout << "x = " << xn << endl;
	cout << "y = " << yn<< endl;
	cout << " f(x,y) = " << f1(xn, yn) << endl;
}

double f2(double xn, double yn) {
	return yn * yn - 2 * xn*yn - 6 * yn + 2 * xn*xn + 12;
}

double lambda_grad_x(double lambda, double xn, double yn) {
	return lambda*(4 * xn - 2 * yn);
}


double lambda_grad_y(double lambda, double xn, double yn) {
	return lambda * (2 * yn-2*xn-6);
}
double ih_grad_x(double xn, double yn) {
	return xn-3;
}

double ih_grad_y(double xn, double yn) {
	return yn-6;
}

void levenberg_marquardt(double x0, double y0, double lambda, double n) {
	int i = 0;
	double xn = x0, yn = y0, x_next, y_next;

	do { 
		x_next = xn - (ih_grad_x(xn, yn) + lambda_grad_x(lambda, xn, yn));
		y_next = yn - (ih_grad_y(xn, yn) + lambda_grad_y(lambda, xn, yn));
	} while (i < n && abs(x_next - xn) <= 0.01);

	cout << "Iteracao " << endl;
	cout << "x = " << xn << endl;
	cout << "y = " << yn << endl;
	cout << "f(x,y) = " << f2(xn, yn) << endl;
}
int main() {
	cout << fixed;
	cout.precision(6);
	//quadrica(0, 0, 4);

	levenberg_marquardt(1, 1, 1, 20);

	return 0; 
}