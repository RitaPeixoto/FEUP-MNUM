#include <iostream>
#include <iomanip>
#include<cmath>

using namespace std;
/*sqrt(1+(y')^2)*/
double f(double x) {
	return sqrt(1 + pow(2.5*exp(2.5*x), 2));
}

double trapezees(double a, double b,double h, int n ) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += 2*f(a+h*i);
	}
	sum += f(a) + f(b);
	sum *= (h / 2.0);
	return sum; 
}

double simpson(double a, double b, double h, double n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			sum += 2 * f(a + h * i);
		}
		else {
			sum += 4 * f(a + h * i);
		}
	}
	sum += f(a) + f(b);
	sum *= (h / 3.0);
	return sum;
}




int main() {
	cout << fixed; 
	cout.precision(6);
	double h = 0.125, h_1 = 0.0625, h_2 = 0.03125, n= 8, n_1=16, n_2=32;
	cout << "h:"<< h<< endl;
	cout << trapezees(0, 1, h, n) << endl;
	cout << simpson(0, 1, h, n) << endl<<endl;

	cout << "h':" << h_1 << endl;
	cout << trapezees(0, 1, h_1, n_1) << endl;
	cout << simpson(0, 1, h_1, n_1) << endl << endl;


	cout << "h'':" << h_2 << endl;
	cout << trapezees(0, 1, h_2, n_2) << endl;
	cout << simpson(0, 1, h_2, n_2) << endl << endl;



	cout << "Qc T: " << (trapezees(0, 1, h_1, n_1) - trapezees(0, 1, h, n)) / (trapezees(0, 1, h_2, n_2) - trapezees(0, 1, h_1, n_1)) << endl;
	cout << "Qc S: " << (simpson(0, 1, h_1, n_1)- simpson(0, 1, h, n)) / (simpson(0, 1, h_2, n_2)-simpson(0, 1, h_1, n_1))<<endl;

	cout << " E'' T: " << (trapezees(0, 1, h_2, n_2) - trapezees(0, 1, h_1, n_1)) / 3.0 << endl;

	cout << "E'' S: " << (simpson(0, 1, h_2, n_2) - simpson(0, 1, h_1, n_1)) / 15.0 << endl;

	return 0;
}