#include <iostream>
#include <iomanip>
#include <cmath>
#include<vector>
using namespace std;


double Simpson(vector<double> v, int n, double h) {
	double sum = 0;
	for (int i = 1; i < n - 1; i++) {
		if (i % 2 == 0) {
			sum += 2 * v[i];
		}
		else {
			sum += 4 * v[i];
		}
	}
	sum = v[0] + sum + v[n - 1];
	sum *= (h / 3.0);
	return sum; 
}


int main() {
	cout << fixed;
	cout.precision(6);

	//vector<double> v = { 1.04, 0.37, 0.38,1.49,1.08,0.13,0.64,0.84,0.12 };
	vector<double> v = { 0.18, 0.91,0.83,1.23,0.88,1.37,0.80,1.34,0.43};
	double h1 = 0.20;
	int n1 = 9;
	double res1= Simpson(v, n1, h1);
	cout <<"S'' = "<< res1 << endl; 
	double h2 = 0.4;
	int n2 = 5;
	//vector<double> v1 = { 1.04,0.38,1.08,0.64,0.12};
	vector<double> v1 = { 0.18,0.83,0.88,0.80,0.43 };
	double res2 = Simpson(v1, n2, h2);
	cout << "S' = " << res2 << endl;
	//vector<double> v2 = { 1.04,1.08,0.12 };
	vector<double> v2 = { 0.18,0.88,0.43 };
	double h3 = 0.8;
	int n3 = 3;
	double res3 = Simpson(v2, n3, h3);
	cout << "S = " << res3 << endl;
	double erro = (res1 - res2) / 15.0;
	cout << "Erro = " << erro << endl;
	return 0;
}