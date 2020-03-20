#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double dy(double x) {
	return 1.5*(exp(1.5*x));//k =1.5
}
double f(double x) {
	return sqrt(1 + pow(dy(x), 2));
}



double trapezees(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += 2 * f(a + i * h);
	}
	sum += f(a) + f(b);
	sum *= (1 / 2.0)*h;

	return sum; 
}


double simpson(double a, double b, double h, int n) {
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
	sum *= (1 / 3.0)*h;

	return sum;



}





int main() {
	cout << fixed;
	cout.precision(6);

	double h = 0.5, h_1= 0.25, h_2=0.125;
	double n = 4, n_1 = 8, n_2 = 16;
	double st,ss, st_1,ss_1, st_2,ss_2;
	double a = 0, b = 2;
	double qc_t, qc_s, e_t, e_s;

	st= trapezees(a, b, h, n);
	ss = simpson(a, b, h, n);
	cout << "ST: " << st<<endl;
	cout << "SS: " << ss<<endl;

	st_1 = trapezees(a, b, h_1, n_1);
	ss_1 = simpson(a, b, h_1, n_1);
	cout << "ST': " << st_1<<endl;
	cout << "SS': " << ss_1<<endl;

	st_2 = trapezees(a, b, h_2, n_2);
	ss_2 = simpson(a, b, h_2, n_2);
	cout << "ST': " << st_2<<endl;
	cout << "SS': " << ss_2<<endl;

	qc_t = (st_1 - st) / (st_2 - st_1);
	qc_s = (ss_1 - ss) / (ss_2 - ss_1);
	cout << "QcT: " << qc_t << endl;
	cout << "QcS: " << qc_s << endl;

	e_t = (st_2 - st_1) / 3.0;
	e_s = (ss_2 - ss_1) / 15.0;
	cout << "Et: " << e_t << endl;
	cout << "Es: " << e_s << endl;

	return 0;
}