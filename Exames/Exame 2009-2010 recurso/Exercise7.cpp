#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
a) h = 0.125000
S = 31.664249
h' = 0.062500
S' = 31.664046
h'' = 0.031250
S'' = 31.664034
Qc = 15.947453
error = -0.000001 = -1*10^6

b)  31.66403286697275, através do comando no maxima integrate(exp(1.5*x),x,2.5,3);

c) erro relativo = (s_analitico - s_numerico) /s_analitico= - 3.57827840644395E-8, como o qc é muito proximo de 16, o melhor valor numérico é o calculado com h''

d) o erro relativo estimado é de 6ª ordem de grandeza, enquanto o erro relativo calculado a partir do valor exato é de 8ª ordem de grandeza, logo diferem 2 ordens de grandeza

*/




double f(double x) {
	return exp(1.5*x);// exp(c*x), sendo que c=1.5
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
	sum *= (h / 3.0);
	return sum;
}



int main() {
	cout << fixed;
	cout.precision(6);
	double h=0.125, h_1=0.0625, h_2=0.03125;
	double a=2.5, b=3;
	double s_1, s_2, s;
	int n = 4, n_1 = 8, n_2 = 16;

	s = simpson(a, b, h, n);
	cout << "h = " << h << endl;
	cout << "S = " << s << endl;

	s_1 = simpson(a, b, h_1, n_1);
	cout << "h' = " << h_1 << endl;
	cout << "S' = " << s_1 << endl;

	s_2 = simpson(a, b, h_2, n_2);
	cout << "h'' = " << h_2 << endl;
	cout << "S'' = " << s_2 << endl;

	double qc = (s_1 - s) / (s_2 - s_1);
	cout << "Qc = " << qc << endl;

	double error = (s_2 - s_1) / 15.0;
	cout << "error = " << error << endl;

	return 0;
}