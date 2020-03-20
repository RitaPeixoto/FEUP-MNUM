#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
alineas a e b resolvidas no codigo
c) Como o QC está longe de 16, voltar a dividir h'', sendo o proximo passo h = 0.0625

*/
double f(double t, double x) {
	return sin(x) + sin(2 * t); // sin(ax) +sin(bt), com a=1 e b=2
}
	
double runge_kutta4(double t0, double x0, double h, int n) {
	double dy1, dy2, dy3, dy4;
	double t = t0, x = x0;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "x = " << x << endl;
		if (t == 1.5) {
			return x;
		}

		dy1 = h * f(t, x);
		dy2 = h * f(t + h / 2.0, x + dy1 / 2.0);
		dy3 = h * f(t + h / 2.0, x + dy2 / 2.0);
		dy4 = h * f(t + h, x + dy3);

		t += h;
		x += (1 / 6.0)*dy1 + (1 / 3.0)*dy2 + (1 / 3.0)*dy3 + (1 / 6.0)*dy4;

	}
}







int main() {
	cout << fixed;
	cout.precision(6);
	double s, s_1, s_2;

	s=runge_kutta4(1.000, 0.000, 0.5, 2);
	s_1=runge_kutta4(1.000, 0.000, 0.25, 4);
	s_2=runge_kutta4(1.000, 0.000, 0.125, 8);


	double qc = (s_1 - s) / (s_2 - s_1);
	cout << "QC = " << qc << endl;



	return 0;
}


