#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double rec_1(double x2, double x3, double x4) {
	return (25 - 0.5*x2 - 3.0*x3 - 0.25*x4) / 6.0;
}

double rec_2(double x1, double x3, double x4) {
	return (10 - 1.2*x1 - 0.25*x3 - 0.2*x4) / 3.0;
}

double rec_3(double x1, double x2, double x4) {
	return (7 + 1.0*x1 - 0.25*x2 - 2 * x4) / 4.0;
}

double rec_4(double x1, double x2, double x3) {
	return (-12 - 2 * x1 - 4 * x2 - 1 * x3) / 8.0;
}

int main() {
	double x1_guess=2.12687;
	double x2_guess=2.39858;
	double x3_guess=3.99517;
	double x4_guess=-3.73040;
	int it = 0;
	double x1 = rec_1(x2_guess, x3_guess, x4_guess);//x1 = rec_1(x2_guess, x3_guess, x4_guess);
	double x2 = rec_2(x1, x3_guess, x4_guess);//x2 = rec_2(x1_guess, x3_guess, x4_guess);
	double x3 = rec_3(x1, x2, x4_guess);//x3 = rec_3(x1_guess, x2_guess, x4_guess);
	double x4 = rec_4(x1, x2, x3);// x4 = rec_4(x1_guess, x2_guess, x3_guess);
	it++;
	while (abs(x1 - x1_guess) >= pow(10, -5) || abs(x2 - x2_guess) >= pow(10, -5) || abs(x3 - x3_guess) >= pow(10, -5)) {
		cout << "Iteration " << it << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;


		x1 = rec_1(x2_guess, x3_guess, x4_guess);//x1 = rec_1(x2_guess, x3_guess, x4_guess);
		x2 = rec_2(x1, x3_guess, x4_guess);//x2 = rec_2(x1_guess, x3_guess, x4_guess);
		x3 = rec_3(x1, x2, x4_guess);//x3 = rec_3(x1_guess, x2_guess, x4_guess);
		x4 = rec_4(x1, x2, x3);// x4 = rec_4(x1_guess, x2_guess, x3_guess);
		it++;
	}
	return 0; 
}





