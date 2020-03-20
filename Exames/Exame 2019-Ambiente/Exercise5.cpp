#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/*
Podemos usar os diferentes métodos de pesquisa unidimensional abordados na cadeira: método dos terços, regra áurea, interpolaçao quadratica
Como o metodo da seccao aurea é o mais eficiente, entres estes , por isso é portanto a minha escolha 
*/

double y(double x, double a) {
	return pow(x - a, 2) + pow(x, 4);
}

void  seccao_aurea(double x1, double x2,double a, int n) {
	double B = (sqrt(5) - 1) / 2.0;
	double A = pow(B, 2);
	double x3, x4;
	int i = 0;
	while(abs(x2-x1)>= pow(10,-5) && i<n) {
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
		cout << "Iteracao " << i << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		if (y(x3,a) < y(x4,a)) {
			x1 = x1;
			x2 = x4;
		}
		else {
			x2 = x2;
			x1 = x3; 
		}
		i++;
	}
}


int main() {
	cout << fixed;
	cout.precision(6);
	double a = 7;

	seccao_aurea(0, 3, 7, 20);
	/*o x1 e x2 foram escolhidos desenhando o grafico da funçao no maximo e escolhendo um intervalo que contenha o minimo, neste 
	caso foi [0,3]*/

	return 0;
}