#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double rec_x1(double x2, double x3,double x4) {
	return (2.5 - 0.5* x2 - 3 * x3 - 0.25*x4) / 6.0;
}
double rec_x2(double x1, double x3, double x4) {
	return (3.8 - 1.2* x1 - 0.25 * x3 - 0.20*x4) / 3.0;
}

double rec_x3(double x1, double x2,double x4) {
	return (10 + 1 * x1 - 0.25 * x2 - 2 * x4) / 4.0;
}
double rec_x4(double x1, double x2, double x3) {
	return (7 - 2 * x1 - 4 * x2 - 1 * x3) / 8.0;x
}



int main() {
	cout << fixed;
	cout.precision(6);
	double x1_guess = 0.0000 ;
	double x2_guess = 0.0000;
	double x3_guess = 0.0000;
	double x4_guess = 0.0000;
	double x1 = rec_x1(x2_guess, x3_guess, x4_guess);
	double x2 = rec_x2(x1, x3_guess, x4_guess);
	double x3 = rec_x3(x1, x2, x4_guess);
	double x4 = rec_x4(x1, x2, x3);
	int iterations=1; 

	while (abs(x1 - x1_guess) >= pow(10, -5) || abs(x2 - x2_guess) >= pow(10, -5) || abs(x3- x3_guess) >= pow(10, -5)|| abs(x4 - x4_guess) >= pow(10, -5)){
		
		cout << "Iteration " << iterations << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		iterations++;
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;

		x1 = rec_x1(x2_guess, x3_guess, x4_guess);
		x2 = rec_x2(x1, x3_guess, x4_guess);
		x3 = rec_x3(x1, x2,x4_guess);
		x4 = rec_x4(x1, x2, x3);

	}
	return 0; 

}