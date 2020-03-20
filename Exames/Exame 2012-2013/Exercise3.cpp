#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Z(double x, double y) {
	return 3 * pow(x, 2) - x * y + 11 * y + pow(y, 2) - 8 * x;
}
double Zderx(double x, double y) {
	return 6 * x - y - 8;
}
double Zdery(double x, double y) {
	return -x + 11 + 2 * y;
}

void gradient(double x, double y, double h, int n) {
	double xn=x, yn=y ;
	cout << "Z(x0, y0): " << Z(x, y) << endl;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "Zderx(xn,yn): " << Zderx(xn, yn) << endl;
		cout << "Zdery(xn, yn): " << Zdery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "Z(xn, yn): " << Z(x, y) << endl;
		xn = x - h * Zderx(x, y);
		yn = y - h * Zdery(x, y);

		if (!(Z(xn,yn) < Z(x, y))) {
			h /= 2;
		}
		else {
			x = xn;
			y = yn;
			h *= 2;
		}



	}
}





int main() {
	cout << fixed;
	cout.precision(6);

	gradient(2.0, 2.0, 0.5, 3);

	return 0;
}