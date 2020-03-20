#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double dy(double x) {
	return 1.5*exp(1.5*x);//k =1.5
}
double L(double x) {
	return sqrt(1 + pow(dy(x), 2));	
}

double Trapezees(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += 2 * L(a + i * h);
	}

	sum += L(a) + L(b);
	sum *= (h / 2.0);
	return sum;
}


double Simpson(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			sum += 2 * L(a + i * h);
		}
		else {
			sum += 4 * L(a + i * h);
		}
	
	}

	sum += L(a) + L(b);
	sum *= (h / 3.0);
	return sum;
}

int main() {
	cout << fixed;
	cout.precision(6);
	double a=0, b=1;
	double h=0.25, h_1=0.125, h_2=0.0625;
	int n=4, n_1=8, n_2=16;
	double s, s_1, s_2, t, t_1, t_2;

	cout << "h = " << h << endl;
	t = Trapezees(a, b, h, n);
	cout << "T = " << t << endl;
	s = Simpson(a, b, h, n);
	cout << "S = " << s << endl;



	cout << "h' = " << h_1 << endl;
	t_1 = Trapezees(a, b, h_1, n_1);
	cout << "T' = " << t_1 << endl;
	s_1 = Simpson(a, b, h_1, n_1);
	cout << "S' = " << s_1 << endl;


	cout << "h'' = " << h_2 << endl;
	t_2 = Trapezees(a, b, h_2, n_2);
	cout << "T'' = " << t_2 << endl;
	s_2 = Simpson(a, b, h_2, n_2);
	cout << "S'' = " << s_2 << endl;

	double qct = (t_1 - t) / (t_2 - t_1), error_t = (t_2-t_1)/3.0;
	cout << "Qct = " << qct << endl << "errorT = " << error_t << endl;

	double qcs = (s_1 - s) / (s_2 - s_1), error_s = (s_2 - s_1) / 3.0;
	cout << "Qcs = " << qcs << endl << "errorS = " << error_s << endl;

	return 0;
}
