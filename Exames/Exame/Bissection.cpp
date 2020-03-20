#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) {
	return pow(x, 4) + 2 * pow(x, 3) - x - 1;
	//return exp(0.7*x) - pow(x, 2) - 0.5;
}


double bissection_iter(double a, double b, int n_iter) {
	
	for (int i = 0; i < n_iter; i++) {
		double m = (a + b) / 2.0;
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}


double bissection_error(double a, double b, double prec) {
	int i = 0;
	while(abs(a-b)>pow(10,prec)){
		double m = (a + b) / 2.0;
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
		i++;
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}

double bissection_both(double a, double b, int n_iter, double prec) {
	int i = 0;
	while ((abs(a - b) > pow(10, prec)) && i<n_iter) {
		double m = (a + b) / 2.0;
		cout << "i: " << i << " a: " << a << " b: " << b << " m: " << m << " f(a): " << f(a) << " f(b): " << f(b) << " f(m): " << f(m) << endl;
		if (f(m)*f(a) < 0) {
			b = m;
		}
		else if (f(m)*f(a) > 0) {
			a = m;
		}
		i++;
	}
	if (f(a) < f(b))
		return a;
	else
		return b;
}



int main() {
	cout << fixed;
	cout.precision(6);

	double prec = -5;
	int n_iter = 20;
	double a = 0, b = 1;
	//double a=-1, b =1 
	
	cout << bissection_iter(a,b,n_iter)<<endl;

	cout << bissection_error(a,b,prec)<<endl;
	
	cout << bissection_both(a,b,n_iter,prec)<< endl;

	return 0;
}