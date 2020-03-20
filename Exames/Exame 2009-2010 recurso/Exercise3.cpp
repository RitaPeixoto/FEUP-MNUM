#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dw(double x, double y) {
	return -1.7*x*y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double derx(double x, double y) {
	return -1.7*y + 14 * x - 8;
}

double dery(double x, double y) {
	return -1.7*x + 12;
}

void gradient(double x0, double y0, double h, int n) {
	double x = x0, y=y0, xn=x, yn=y;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "wderx(xn,yn): " << derx(xn, yn) << endl;
		cout << "wdery(xn, yn): " << dery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "w(xn, yn): " << dw(xn, yn) << endl;
		xn = x - h * derx(x, y);
		yn = y - h * dery(x, y);



		if (!(dw(xn, yn) < dw(x, y))) {
			h /= 2;
		}
		else {
			h *= 2;
			x = xn;
			y = yn;
		}
	}


}



int main() {
	cout << fixed;
	cout.precision(6);



	gradient(2.4, 4.3, 0.1, 2);
	return 0;
}
