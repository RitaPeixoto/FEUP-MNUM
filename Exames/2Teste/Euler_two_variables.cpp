#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

/*double dz(double x, double y) {
	return  2 + pow(x, 2) + x * y;
}
void euler(double x, double y, double z, double h,int n ) {
	double delta_z;
	for (int i = 0; i <= n; i++) {
		cout << "Iteration " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;

		delta_z = dz(x, z);
		x += h;
		y += z	 * h;
		z += h * delta_z;

	}
}

int main() {
	cout << fixed;
	cout.precision(6);
	double h = 0.25, x = 1, y = 1, z = 0, delta_z;
	euler(1, 1, 0,0.25,14);

	return 0; 
}*/

/*double dT(double T) {
	return  -0.25*(T-45);
}*/
double dx(double x, double y) {
	return x * x + y * y;
}
void euler(double x, double y,double h,int n ) {

	for (int i = 0; i <= n; i++) {
		cout << "Iteration " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "h = " << h << endl; 

		y += dx(x, y) * h;
		x += h;
		
	}
}

int main() {
	cout << fixed;
	cout.precision(6);
	double h = 0.1, x = 0, y = 0;
	euler(x,y,h,14);
	cout << "-----------------" << endl;
	euler(x, y, 0.05, 28);
	cout << "-----------------" << endl;
	euler(x, y, 0.025, 56);
	cout << "-----------------" << endl;

	return 0;
}