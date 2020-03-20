#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;


double trapezees(vector<vector<double>> v, double h) {
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if ((i == 0 || i == v.size() - 1) && (j == 0 || j == v.size() - 1)) {
				sum += v[i][j];
			}
			else if (i == 0 || j == 0 || i == v.size() - 1 || j == v.size() - 1) {
				sum += 2 * v[i][j];
			}
			else {
				sum += 4 * v[i][j];
			}
		}
	}
	sum *= (h / 4.0);
	return sum;
}


int main() {
	cout << fixed;
	cout.precision(6);

	vector<vector<double>> v = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2} };
	double hx=2/2, hy=2/2;
	double h = hx * hy;

	cout << "Sum = " << trapezees(v, h);
	return 0;
}



