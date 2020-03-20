#include <iostream>
#include<vector>
#include <iomanip>
#include<cmath>

using namespace std;

double Trapezees(vector<vector<double>> v, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {//vertices
				sum += v[i][j];
			}
			else if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {//pontos intermedios
				sum += 2 * v[i][j];
			}
			else {//ponto central
				sum += 4 * v[i][j];
			}
		}
	}
	sum /= 4.0;
	return sum; 

}

int main() {
	cout << fixed;
	cout.precision(6);
	vector<vector<double>> v = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2} };
	int n = 3;
	double res=Trapezees(v, n);


	cout << res << endl;
	return 0; 

}