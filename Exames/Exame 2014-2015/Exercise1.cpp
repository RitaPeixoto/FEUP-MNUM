#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

double dT(double t, double T){
	return -0.25*(T - 37);
}
double euler(double t,double T, double h, int n) {
	double delta_y;	
	for (int i = 0; i < n; i++) {
		delta_y = dT(t, T)*h;
		t += h;
		T += delta_y;
	}
	return T;

}



int main() {
	cout << fixed;
	cout.precision(6);


	cout << euler(5, 3, 0.4, 2) << endl;


	return 0;
}