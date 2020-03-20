#include <iostream>
#include <iomanip>
#include<cmath>

using namespace std;

double f1(double x, double y) {
	return pow(x, 2) - y - 1.2;
}

double f2(double x, double y) {
	return -x + pow(y, 2) - 1.0;
}

double df1dx(double x, double y) {
	return 2 * x;
}
double df1dy(double x, double y) {
	return -1;
}

double df2dx(double x, double y) {
	return -1;
}

double df2dy(double x, double y) {
	return 2 * y;
}

double jacobian(double x, double y) {
	return df1dx(x, y)*df2dy(x, y) - df1dy(x, y)*df2dx(x, y);
}

double hn(double x, double y) {
	return -(f1(x, y)*df2dy(x, y) - df1dy(x, y)*f2(x, y)) / jacobian(x, y);
}

double kn(double x, double y) {
	return -(df1dx(x, y)*f2(x, y) - f1(x, y)*df2dx(x, y)) / jacobian(x, y);
}

void newton(double x, double y, int n) {
	double x_prev = x, y_prev = y;
	for (int i = 0; i < n; i++) {
		cout << i<<": " << "\t" << x << "\t" << y << endl;
		x = x_prev + hn(x_prev,y_prev);
		y = y_prev + kn(x_prev,y_prev);
		x_prev = x;
		y_prev = y;
	}
}


int main() {
	cout << fixed;
	cout.precision(6);


	newton(1.0000, 1.0000, 4);




	return 0;
}