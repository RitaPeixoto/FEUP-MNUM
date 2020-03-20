#include <iostream>
#include <iomanip>
#include <cmath>
#include<vector>
using namespace std;

double Simpson(vector<double>f, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n-1; i++) {
		if (i % 2 == 0) {
			sum += 2 * f[i];
		}
		else {
			sum += 4 * f[i];
		}
	}

	sum += f[0] + f[n - 1];
	sum *= (h / 3.0);
	return sum;
}

int main() {
	cout << fixed;
	cout.precision(6);
	double s, s_1, s_2, h=1, h_1=0.5, h_2 = 0.25;
	int n=3, n_1=5, n_2=9; 
	vector<double> f = {0.36,1.15,0.60};
	vector<double> f_1 = {0.36,1.32,1.15,0.12,0.60};
	vector<double> f_2 = {0.36,1.19,1.32,0.21,1.15,1.39,0.12,1.22,0.60};
	
	s = Simpson(f, h, n);
	cout << "S = " << s << endl;
	s_1 = Simpson(f_1, h_1, n_1);
	cout << "S' = " << s_1 << endl;
	s_2 = Simpson(f_2, h_2, n_2);
	cout << "S'' = " << s_2 << endl;

	double error = (s_2 - s_1) / 15.0;
	cout << "error = " << error << endl;

	return 0;
}