#include <iostream>
#include<iomanip>
#include <cmath>
#include <vector>

using namespace std;
double f(double x) {
	return sqrt(1+pow((1.5*exp(1.5*x)),2));
}

double Trapezees_simple(double a, double b, double h, int n) {
	double sum=0;
	for (int i = 1; i < n; i++) {
		sum += 2 * f(a + h * i);
	}	
	sum = (h / 2.0)*(f(a) + sum + f(b));
	return sum;
}

int main() {
	double a=0, b=1, n1=4,n2=8,n3=16;
	double h1=0.25, h2=0.125, h3=0.0625;
	double s, s1, s2;
	cout << fixed;
	cout.precision(6);

	s = Trapezees_simple(a, b, h1, n1);
	cout << "S = " << s << endl;
	s1 = Trapezees_simple(a, b, h2, n2);
	cout << "S' = " << s1 << endl;
	s2 = Trapezees_simple(a, b, h3, n3);
	cout << "S'' =  " << s2 << endl;
	double QC = (s1 - s) / (s2 - s1);//tem que ser aproximadamente 4 para ser valido, caso contrario volta-se a dividir por 2 o passo e a multiplicar por 2 as iteraçoes
	cout << "Quociente de Convergencia = " << QC << endl;
	double erro = abs((s2 - s1) / 3.0);
	cout << "Erro = " << erro << endl;

	return 0; 
}
/*
double Trapezees(vector<vector<double>> v, double h) {
	double sum = 0;
	double n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i==0 || i==n-1)&&(j==0 || j==n-1)){//vertices
				sum += v[i][j];
			}
			else if (i == 0 || i == n - 1 || j == 0 || j == n - 1){//pontos intermedios 
				sum += 2*v[i][j];
			}
			else {//ponto central 
				sum += 4*v[i][j];
			}
		}
	}
	sum *=(h/4.0);
	return sum; 
}

int main() {
	cout << fixed;
	cout.precision(6);
	vector<vector<double>> v;
	v = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2}};
	double hx = 2 - 0;
	double hy = 2 - 0;
	double h = (hx*hy) /4.0 ;
	double res;
	res=Trapezees(v,h);
	cout << " result = " << res << endl;
	return 0;
}
*/