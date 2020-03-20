#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/*
dy/dt= z
dz/dt= 0.5+t^2+t*z;
*/

double dy(double t, double y, double z) {
	return z;
}
double dz(double t, double y, double z) {
	return 0.5 + pow(t, 2) + t * z;
}

void euler(double t, double y, double z, double h, int n) {
	double t_next=t, y_next=y;

	for (int i = 0; i < n; i++) {
		cout << "Iteration: " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		cout << "z: " << z << endl;

		t_next += h;
		y_next += dy(t, y, z)*h;
		z += dz(t, y, z)*h;
		 
		t = t_next;
		y = y_next;
	}



}


void runge_kunta_4(double t, double y, double z, double h, int n) {
	double dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao: " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		cout << "z: " << z << endl;


		dy1 = h * dy(t,y,z);
		dz1 = h * dz(t, y, z);

		dy2 = h * dy(t+h/2.0,y+dy1/2.0,z+dz1/2.0);
		dz2 = h * dz(t + h / 2.0, y + dy1 / 2.0, z + dz1 / 2.0);

		dy3 = h * dy(t + h / 2.0, y + dy2 / 2.0, z + dz2 / 2.0);
		dz3 = h * dz(t + h/2.0, y + dy2 / 2.0, z + dz2 / 2.0);

		dy4 = h * dy(t+h,y+dy3,z+dz3);
		dz4 = h * dz(t + h, y + dy3, z + dz3);

		t += h;
		y += (1 / 6.0)*dy1 + (1 / 3.0)*dy2 + (1 / 3.0)*dy3 + (1 / 6.0)*dy4;
		z += (1 / 6.0)*dz1 + (1 / 3.0)*dz2 + (1 / 3.0)*dz3 + (1 / 6.0)*dz4;

	}
}




int main() {
	cout << fixed;
	cout.precision(6);

	euler(0, 0, 1, 0.25, 4);
	cout << endl << endl;
	runge_kunta_4(0, 0, 1, 0.25, 4);





	return 0;
}