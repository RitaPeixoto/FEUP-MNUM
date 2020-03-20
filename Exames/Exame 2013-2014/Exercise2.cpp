#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;
/*
1-- resposta no maxima plot2d(f, 0,50)
Tem 3 zeros nos intervalos : [0,4], [27,32] e [38,44]
2-- resolvida com o codigo abaixo 
3-- ????? 

*/
double f(double x) {
	return -x + 40 * cos(sqrt(x)) + 3;
}

double df(double x) {
	return -1 - ((20 * sin(sqrt(x))) / sqrt(x));
}
void newton(double x, double n) {

	for (int i = 0; i < n; i++) {
		cout << "Iteracao: " << i << endl;
		cout << "x: " << x << endl;
		cout << "g(x): " << f(x) << endl;
		x = x - f(x) / df(x);
	}
}

int main() {
	cout << fixed;
	cout.precision(6);


	newton(1.7000, 3);


	return 0;
}