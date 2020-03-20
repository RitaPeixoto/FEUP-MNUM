#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;



double f(double x) {
	return pow(x, 4) + 2 * pow(x, 3) - x - 1;
}

double df(double x) {
	return 4 *pow(x,3) - 6 *pow(x,2) - 1;
}
/* x0 - initial guess
   n_iter - numero de iteraçoes
*/
double newton(double x0, double n_iter) {
	double x = x0;
	double m = 0;
	for (int i = 0; i < n_iter; i++) {
		cout << "i: " << i <<"\t"<< x <<"\t"<< f(x)<<"\t"<<df(x) <<"\t"<< m<< endl;
		m= x - (f(x) / df(x));
		x = m;
	}
	return x;
}



int main() {
	cout << fixed;
	cout.precision(6);

	int n_iter = 7;
	double x0 = 0;
	cout << newton(x0, n_iter)<<endl;

	return 0;
}