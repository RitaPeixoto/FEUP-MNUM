#include<iostream>
#include<math.h>

using namespace std;
double metodo_bissecçao_1(double a, double b);
double metodo_bissecçao_2(double a, double b);
double metodo_bissecçao_3(double a, double b);

double metodo_corda_1(double a, double b);
int main() {
	metodo_bissecçao_1(-2,0 );
	cout << endl;
	metodo_bissecçao_1(1, 3);
	cout << endl;
	metodo_bissecçao_1(4, 7);
	cout << endl;
	metodo_corda_1(-2, 0);
	cout << endl;	
	metodo_corda_1(1, 3);
	cout << endl;
	metodo_corda_1(4, 7);

	cout << endl<<"Number 2"<<endl;

	/*metodo_bissecçao_2(0.001, 0.1);
	cout << endl;
	metodo_bissecçao_2(9, 10);
	cout << endl<<"Number 3"<<endl;
	metodo_bissecçao_3(0, 1);
	cout << endl;
	metodo_bissecçao_2(98, 100);
	cout << endl;*/

	
	return 0;
}

double f(double x) {
	return -2.75*pow(x, 3) + 18 * pow(x, 2) - 21 * x - 12;
}
double g(double x) {
	return x - 2 * log(x) - 5;
}
double h(double x) {
	return pow(2, sqrt(x)) - 10 * x + 1;
}
double metodo_bissecçao_1(double a,double b) {
	
	for (int i = 0; abs(a - b) > 0.00001; i++) {
		double xn = (a + b) / 2;
		cout << "i: "<<i<<" a: " << a << " b: " << b << " xn: "<<xn<< " f(a): " << f(a) << " f(b): " << f(b) << " f(xn): " << f(xn) << endl;
		if ((f(a)*f(xn) )< 0) {
			b = xn;
		}
		else {
			a = xn;
		}
	}
	if (f(a) < f(b))
		return a;
	else
		return b;

}
double metodo_bissecçao_2(double a, double b) {

	for (int i = 0; abs(a-b)>0.00001; i++) {
		double xn = (a + b) / 2;
		cout <<"i: "<<i<<" a: " << a << " b: " << b << " xn: " << xn << " g(a): " << g(a) << " g(b): " << g(b) << " g(xn): " << g(xn) << endl;
		if ((g(a)*g(xn)) < 0) {
			b = xn;
		}
		else {
			a = xn;
		}
	}
	
	if (g(a) < g(b))
		return a;
	else
		return b;

}

double metodo_bissecçao_3(double a, double b) {

	for (int i = 0; abs(a - b) > 0.00001; i++) {
		double xn = (a + b) / 2;
		cout << "i: " << i << " a: " << a << " b: " << b << " xn: " << xn << " h(a): " << h(a) << " h(b): " << h(b) << " h(xn): " << h(xn) << endl;
		if ((h(a)*h(xn)) < 0) {
			b = xn;
		}
		else {
			a = xn;
		}
	}

	if (h(a) < h(b))
		return a;
	else
		return b;

}


double metodo_corda_1(double a, double b) {
	double xn=0, aux;
	for (int i = 0; i == 0 || abs(xn - aux) > 0.00001; i++) {
		aux = xn;
		xn = (a * f(a) - b * f(b)) / (f(b) - f(a));
		cout << "i: " << i << " a: " << a << " b: " << b << " xn: " << xn << " f(a): " << f(a) << " f(b): " << f(b) << " f(xn): " << f(xn) << endl;
		if ((f(a)*f(xn)) < 0) {
			b = xn;
		}
		else {
			a = xn;
		}
	}

	if (f(a) < f(b))
		return a;
	else
		return b;

}