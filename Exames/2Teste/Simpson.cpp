#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;


double f(double x) {
	return sqrt(1 + pow((1.5*exp(1.5*x)), 2));
}


double Simpson_method(double h, double a, double b, double n) {
	double result = 0;

	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			result += 2 * f(a + i * h);
		}
		else {
			result += 4 * f(a + i * h);
		}

	}
	result = (h / 3.0)*(f(a) + result + f(b));
	return result;
}
double Simpson_function(vector<double> v, double h, double n) {
	double result = 0;
	for (int i = 1; i < n-1; i++) {
		if (i % 2 == 0) {
			result += 2 * v[i];
		}
		else {
			result += 4 * v[i];
		}
	}
	result = (h / 3.0)*(v[0] + result + v[n-1]);
	return result;
}

int main() {
	cout << fixed;
	cout.precision(6);
	double a=0, b=1, n1=4, n2=8, n3= 16, h1=0.25,h2=0.125,h3=0.0625;
	double s, s1, s2;
	s = Simpson_method(h1, a, b, n1);
	cout << "S = " << s << endl;
	s1 = Simpson_method(h2, a, b, n2);
	cout << "S' = " << s1 << endl;
	s2 = Simpson_method(h3, a, b, n3);
	cout << "S'' = " << s2 << endl;

	double QC = (s1 - s) / (s2 - s1); //tem que ser aproximadamente 16, senao duplicar o n e reduzir para metade o h;
	double erro = (s2 - s1) / 15.0;
	cout << "QC = " << QC << endl;
	cout << "Erro = " << erro << endl;

	/*vector<double> v = { 0.36,1.19,1.32,0.21,1.15,1.39,0.12,1.22,0.60};
	double h = 0.25;
	double n = 9; 
	double res = Simpson_function(v, h, n);
	cout << "S'' = " << res << endl;

	vector<double> v1 = { 0.36,1.32,1.15,0.12,0.60};
	double h1 = 0.50;
	double n1 = 5; 
	double res1 = Simpson_function(v1, h1, n1);
	cout << "S' = " << res1 << endl;
	double erro = (res - res1) / 15.0;
	cout << "Erro = " << erro << endl;
	*/
	
	return 0;
}

/*double Simpson_double(vector<vector<double>> v, double h) {
	double sum = 0;
	double n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {//vertices
				sum += v[i][j];
			}
			else if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {//pontos intermedios
				sum += 4 * v[i][j];
			}
			else {//ponto central
				sum += 16 * v[i][j];
			}
		}
	}
	sum *= (h / 9.0);
	return sum; 
}


int main() {
	double hx=0, hy =0;
	double h = (hx*hy);

	vector<vector<double>> v; 
	double res = Simpson_double(v, h);
	cout << "result = " << res << endl;

	return 0; 
}*/