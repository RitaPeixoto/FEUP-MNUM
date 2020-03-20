#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f1(double x, double y) {
	return sin(x + y) - exp(x - y);
}

double f2(double x, double y) {
	return cos(x + y) - pow(x, 2)*pow(y, 2);
}
double df1dx(double x, double y) {
	return cos(y + x) - exp(x - y);
}
double df1dy(double x, double y) {
	return cos(y + x) + exp(x - y);
}
double df2dx(double x, double y) {
	return (-sin(y + x)) - 2 * x*pow(y, 2);
}
double df2dy(double x, double y) {
	return (-sin(y + x)) - 2 * y*pow(x, 2);
}

double jacobian(double x, double y) {
	return (df1dx(x, y)*df2dy(x, y) - df1dy(x, y)*df2dx(x, y));
}
double hn(double x, double y) {
	return -(f1(x, y)*df2dy(x, y) - df1dy(x, y)*f2(x, y)) / jacobian(x, y);
}
double kn(double x, double y) {
	return -(df1dx(x,y)*f2(x,y)-df2dx(x,y)* f1(x,y))/ jacobian(x, y);
}

void newton(double x_guess, double y_guess, int n) {
	double x = x_guess, y = y_guess, xn, yn;
	for (int i = 0; i < n; i++) {

		x = x_guess + hn(x_guess, y_guess);
		y = y_guess + kn(x_guess, y_guess);
		cout << "Iteracao " << i << endl;
		cout << "x = " << x_guess<< endl;
		cout << "y = " << y_guess << endl;

		x_guess = x;

		y_guess = y;
	}
}

int main() {
	cout << fixed;
	cout.precision(6);

	newton(0.5000, 0.25000, 4);

	return 0;
}