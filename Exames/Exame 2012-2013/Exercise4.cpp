#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
b) 3.33736
c) 0.00000
*/

double f(double x) {
	return exp(1.5*x);//exp(ox) , sendo que o= 1.5
}
double Simpson(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			sum += 2 * f(a + i * h);
		}
		else {
			sum += 4 * f(a + i * h);
		}
	}
	sum += f(a) + f(b);
	sum *= (h / 3.0);
	return sum; 
}



int main() {
	cout << fixed;
	cout.precision(6);
	double h=0.125, h_1=0.0625, h_2=0.03125;
	int n=4, n_1=8, n_2=16;
	double s, s_1, s_2;
	double a = 1.0, b = 1.5;
	
	s = Simpson(a, b, h, n);
	cout << "h = " << h << endl;
	cout << "S = " << s << endl;

	s_1 = Simpson(a, b, h_1, n_1);
	cout << "h' = " << h_1 << endl;
	cout << "S' = " << s_1 << endl;

	s_2 = Simpson(a, b, h_2, n_2);
	cout << "h'' = " << h_2 << endl;
	cout << "S'' = " << s_2 << endl;
 
	double qc = (s_1 - s) / (s_2 - s_1);
	cout << "Qc = " << qc << endl;

	double err = (s_2 - s_1) / 15.0;
	cout << "erro = " << err << endl;

	return 0;
}