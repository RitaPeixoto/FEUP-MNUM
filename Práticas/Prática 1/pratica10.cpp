#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
double pi = 3.141593;
double B = (sqrt(5)- 1)/2.0;
double f(double x) {
	return pow((2*x+1),2)-5*cos(10*x);
}


double pesquisa(double step, double guess) {
	double x0, x1, x2;

	x0 = guess;
	x1 = guess + step;
	x2 = guess + 2 * step;

	while (f(x1) > f(x2)) {
		x0 = x1;
		x1 = x2;
		x2 = x2 + step;
	}
	cout << x0 << "\t" << x1 << "\t" << x2 << "\t";
	
	return x0; 
}

vector<double> tercos(double a, double b, double prec) {
	double prop,c,d;
	while (abs(b - a) > prec) {
		prop = (b - a) / 3;
		c = a + prop;
		d = b - prop;
		if (f(c) < f(d)) {
			a = c;
		}
		else
			b = d; 
	}
	cout << "Intervalo: " << a << " a "<< b<<endl;
	cout << "Sin(x1): " << sin(a) << endl;
	cout << "Sin(x2): " << sin(b) << endl;
	vector<double> res = { a,b };
	return res;
}

double quadratica(double x1, double x2, double x3) {
	cout << "AJUSTE DA QUADRATICA:\n";
	 
	double h = (x3 - x1) / 2.0;

	return x2 + h * (f(x1) - f(x3)) / (2 * (f(x3) - 2 * f(x2) + f(x1)));
}

double seccaoAurea(double x1, double x2) {//se quisermos o máximo é só trocar os menores para maiores
	double x3 = x1 + pow(B, 2)*(x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	while (abs(x2 - x1) > pow(10, -3)) {
		if (f(x3)< f(x4)) {
			x1 = x1;
			x2 = x4;
		}
		else {
			x2 = x2;
			x1 = x3;
		}
		x3 = x1 + pow(B, 2)*(x2 - x1);
		x4 = x1 + B * (x2 - x1);
	}
	double min;
	if (f(x1) > f(x2)) {
		min = x1;
	}
	else min = x2;
	if (f(x3) < f(min)) min = x3;
	if (f(x4)<  f(min))min = x4;
	cout << "x1: " << x1 << endl << "x2: " << x2 << endl << "x3: " << x3 << endl << "x4: " << x4 << endl;
	return min;
}



int main() {
	//PESQUISA
	/*double guess = 2;
	double step = 0.1;

	if (f(guess) < f(guess + step))
		step = -step;
		*/
	//double x0 = pesquisa(guess, step);
	//double x2 = x0 + 2 * step;

	//PESQUISA
	/*
	//METODO DOS TERÇOS
	vector<double> tercos = terços(x0, x2);
	x0 = tercos[0];
	x2 = tercos[1];
	*/

	//METODO DA SECÇAO AUREA
	//METODO DOS TERÇOS
	cout.precision(20);
	//vector<double> tercos = seccaoAurea(-1, 0);
	//double x0 = tercos[0];
	//double x2 = tercos[1];
	//double min = x0;
	//AJUSTE DA QUADRATICA
	//double h = (x2 - x0) / 2.0;
	//double x1 = x0 + h;

	//double min = quadratica(x0, x1, x2);

	//RESULTADO
	double min = seccaoAurea(-1, 0);
	cout << "Minimo: " << min << endl;
	cout << "f(min) =" << f(min) << endl;	
}
