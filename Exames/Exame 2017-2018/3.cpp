#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;
double rec(double x) {
	return exp(x) - 5;
}

double rec_2(double x) {
	return log(5 + x);
}

double rec_newton(double x) {
	return x - (exp(x) - x - 5) / (exp(x) - 1);
}

void picard_peano(double x, int n_iter) {
	double x_next1, x_prev1=x,x_prev2 = x, x_next2;
	cout << "0: " << x << endl;
	for (int i = 1; i <= n_iter; i++) {
		x_next1 = rec(x_prev1);
		x_next2 = rec_2(x_prev2);
		x_prev1 = x_next1;
		x_prev2 = x_next2;
		cout << i << ": " << x_next1 << "\t" << x_next2 << endl;
	}
}

void newton(double x, int n_iter) {
	double x_next, x_prev =x;
	cout << "0: " << x << endl;
	for (int i = 1; i <= n_iter; i++) {
		x_next = rec_newton(x_prev);
		x_prev = x_next;
		cout << i << ": " << x_next<< endl;
	}
}







int main() {
	cout << fixed;
	cout.precision(6);

	picard_peano(3.0, 10);
	newton(3.0, 10);




	return 0;
}