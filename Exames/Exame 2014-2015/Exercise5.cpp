#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;
double f(double x) {
	return exp(2.5*x);//k = 2.5
}
double df(double x) {
	return 2.5*exp(2.5*x);
}

double l(double x) {
	return sqrt(1 + pow(df(x), 2));
}

double trapezees(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += 2 * l(a + i * h);
	}
	sum += l(a) + l(b);
	sum *= (h / 2.0);
	return sum;
}

double simpson(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			sum += 2 * l(a + i * h);
		}
		else {
			sum += 4 * l(a + i * h);
		}
	}
	sum += l(a) + l(b);
	sum *= (h / 3.0);
	return sum;
}



int main() {
	cout << fixed;
	cout.precision(6);
	double a = 0, b = 1;
	double h=0.125, h_1=0.0625, h_2=0.03125;
	int n=8, n_1=16, n_2=32;
	double st, ss, st_1, ss_1, st_2, ss_2;
	double qc_t, qc_s;
	double e_t, e_s;

	st = trapezees(a, b, h, n);
	ss = simpson(a, b, h, n);
	cout << "St: " << st << endl;
	cout << "Ss: " << ss << endl;


	st_1 = trapezees(a, b, h_1, n_1);
	ss_1 = simpson(a, b, h_1, n_1);
	cout << "St': " << st_1 << endl;
	cout << "Ss': " << ss_1 << endl;

	st_2 = trapezees(a, b, h_2, n_2);
	ss_2 = simpson(a, b, h_2, n_2);
	cout << "St'': " << st_2 << endl;
	cout << "Ss'': " << ss_2 << endl;

	qc_t = (st_1 - st) / (st_2 - st_1);
	qc_s = (ss_1 - ss) / (ss_2 - ss_1);
	cout << "Qc-t: " << qc_t << endl;
	cout << "Qc_s: " << qc_s << endl;


	e_t = (st_2 - st_1) / 3.0;
	e_s = (ss_2 - ss_1) / 15.0;
	cout << "Et: " << e_t << endl;
	cout << "Es: " << e_s << endl;

	return 0;
}