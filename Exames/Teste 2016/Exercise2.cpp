#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

/*menor passo de integraçao, h = 0.2*/

double simpson(vector<double> f, double h, int n) {
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
	vector <double> f_2 = { 0.18,0.91,0.83,1.23,0.88,1.37,0.80,1.34,0.43 };
	vector<double> f_1 = { 0.18,0.83,0.88,0.80,0.43 };
	vector<double> f = { 0.18,0.88,0.43 };
	double h =0.8 , h_1 = 0.4,h_2 = 0.20;
	int n=3 , n_1=5, n_2=9;
	double s, s_1, s_2;
	s = simpson(f, h, n);
	s_1 = simpson(f_1, h_1, n_1);
	s_2 = simpson(f_2, h_2, n_2);
	cout <<"S =" <<s<<endl;
	cout << "S' =" << s_1 << endl;
	cout << "S'' =" << s_2 << endl;
	double error = (s_2 - s_1) / 15.0;
	cout << "error = " << error << endl;

	return 0; 
}