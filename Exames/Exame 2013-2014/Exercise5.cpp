#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

/*
alinea de baixo:
Basicamente no fim tens os 4 pontos, e sabes que se f(x3) for menor que f(x4) podes descartar o intervalo [x4,x2], 
ou se f(x4) for menor que f(x3) podes descartar o intervalo [x1,x3]...
Como neste caso o f(x4) é menor, ao descartares aquele intervalo sabes que o minimo se encontra no intervalo [x3,x2],
que tem amplitude 0.47213

*/

double f(double x) {
	return 5 * cos(x) - sin(x);
}

void seccao_aurea(double x1, double x2, int n) {
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x3, x4;

	for (int i = 0; i < n; i++) {
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
		cout << "Iteracao " << i << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		cout << "f(x1) = " << f(x1) << endl;
		cout << "f(x2) = " << f(x2) << endl;
		cout << "f(x3) = " << f(x3) << endl;
		cout << "f(x4) = " << f(x4) << endl;

		if (f(x3) < f(x4)) {
			x1 = x1;
			x2 = x4;
		}
		else {
			x1 = x3;
			x2 = x2;
		}

	}

}







int main() {
	cout << fixed;
	cout.precision(6);



	seccao_aurea(2, 4, 4);


	return 0;
}