#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double rec_x1(double x2, double x3, double x4) {
	return (1 + x2 + x3 - x4) / 4.5;
}
double rec_x2(double x1, double x3, double x4) {
	return (-1 + x1 - x3 + x4) / 4.5;
}
double rec_x3(double x1, double x2, double x4) {
	return (-1 + x1 - 2 * x2 + x4) / 4.5;
}
double rec_x4(double x1, double x2, double x3) {
	return (-2 * x1 + x2 + x3) / 45;
}


int main() {
	cout << fixed;
	cout.precision(6);


	double x1_guess=0.2500, x2_guess=0.2500, x3_guess=0.2500, x4_guess=0.2500;
	double x1 = rec_x1(x2_guess,x3_guess,x4_guess);
	double x2 = rec_x2(x1_guess, x3_guess, x4_guess); 
	double x3=rec_x3(x1_guess, x2_guess, x4_guess); 
	double x4=rec_x4(x1_guess, x2_guess, x3_guess);
	int i = 1;
	while ((abs(x1-x1_guess)>=pow(10,-5))&& (abs(x2 - x2_guess) >= pow(10, -5))&& (abs(x3 - x3_guess) >= pow(10, -5))&& (abs(x4 - x4_guess) >= pow(10, -5))) {
		cout << "Iteracao " << i << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;

		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;

		x1 = rec_x1(x2_guess, x3_guess, x4_guess);
		x2 = rec_x2(x1_guess, x3_guess, x4_guess);
		x3 = rec_x3(x1_guess, x2_guess, x4_guess);
		x4 = rec_x4(x1_guess, x2_guess, x3_guess);
		i++;
		if (i == 3) {
			break;
		}


	}


	return 0;

}