#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double f1(double x, double y) {
	return pow(x, 2) -y- 2; // a =2;
}
double df1dx(double x, double y) {
	return 2 * x;
}
double df1dy(double x, double y) {
	return -1;
}

double f2(double x, double y) {
	return -x+pow(y, 2) - 2;//b=2;
}
double df2dx(double x, double y) {
	return -1;
}
double df2dy(double x, double y) {
	return 2 * y;
}

double jacobian(double x, double y) {
	return (df1dx(x, y)*df2dy(x, y)) - (df1dy(x, y)*df2dx(x, y));
}

double hn(double x, double y) {
	return -((f1(x, y)*df2dy(x, y)) - (f2(x, y)*df1dy(x, y)))/jacobian(x,y);
}

double kn(double x, double y) {
	return-((df1dx(x, y)*f2(x, y)) - df2dx(x, y)*f1(x, y)) / jacobian(x, y);
}


void newton(double x_guess, double y_guess, int n) {
	double x = x_guess, y = y_guess,xn, yn;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;

		xn = x + hn(x, y);
		yn = y + kn(x, y);

		x = xn;
		y = yn;
	}
}



int main() {
	cout << fixed;
	cout.precision(6);

	newton(1.5000, 0.8000, 4);

	return 0;

}