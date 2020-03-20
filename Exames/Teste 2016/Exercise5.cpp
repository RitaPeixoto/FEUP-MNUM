#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double recx1(double x2, double x3, double x4) {
	return (2.5 - 0.5*x2 - 3 * x3 - 0.25*x4) / 6.0;
}
double recx2(double x1, double x3, double x4) {
	return (3.8 - 1.2*x1 - 0.25*x3 - 0.20*x4) / 3.0;
}
double recx3(double x1, double x2, double x4) {
	return (10.0 + 1 * x1 - 0.25*x2 - 2 * x4) / 4.0;
}
double recx4(double x1, double x2, double x3) {
	return (7 - 2 * x1 - 4 * x2 - x3) / 8.0;
}

int main() {
	float x1_guess = 0.0000, x2_guess = 0.0000, x3_guess = 0.0000, x4_guess = 0.0000;
	float x1 = recx1(x2_guess, x3_guess, x4_guess);
	float x2 = recx2(x1, x3_guess, x4_guess);
	float x3 = recx3(x1, x2, x4_guess);
	float x4 = recx4(x1, x2, x3);

	int it = 1;
	while ((abs(x1 - x1_guess) >= pow(10, -5)) && (abs(x2 - x2_guess) >= pow(10, -5)) && (abs(x3 - x3_guess) >= pow(10, -5)) && (abs(x1 - x1_guess) >= pow(10, -5))) {
		cout << "Iteracao " << it << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;

		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;
		it++;
		if (it == 2) {
			break;
		}
	}
	return 0;
}