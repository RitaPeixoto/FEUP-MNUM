#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Z(double x, double y) {
	return 6 * pow(x, 2) - x * y + 12 * y + pow(y, 2) - 8 * x;
}

double derx(double x, double y) {
	return 12 * x - y - 8;
}
double dery(double x, double y) {
	return -x + 12 + 2 * y;
}

void gradient(double xn, double yn, double h, int n) {
	double x = xn, y = yn;


	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "Zderx(xn,yn): " << derx(xn, yn) << endl;
		cout << "Zdery(xn, yn): " << dery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "Z(xn, yn): " << Z(x, y) << endl;
		xn = x - h * derx(x, y);
		yn = y - h * dery(x, y);

		if (!(Z(xn, yn) < Z(x, y))) {
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

	gradient(0, 0, 0.25,2);



	return 0;
}