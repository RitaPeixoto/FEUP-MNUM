#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;
/*
double dy(double z) {
	return z;
}

double dz(double x, double z) {
	return 2 + x * x + x * z;
}


void RK4(double h, double n,double x0,double y0, double z0) {

	double x = x0, y = y0, z = z0; 
	double dy1, dy2, dy3, dy4,dz1,dz2,dz3,dz4;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl; 
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
		dy1 = h * dy(z);
		dz1 = h * dz(x, z);

		dy2 = h * dy(z + dz1/2.0);
		dz2 = h *dz(x + h / 2.0, z + dz1 / 2.0);

		dy3 = h * dy(z + dz2 / 2.0);
		dz3 = h * dz(x + h / 2.0, z + dz2 / 2.0);

		dy4 = h * dy(z + dz3);
		dz4 = h * dz(x + h, z + dz3);

		y = y + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4/6.0;
		z = z + dz1 / 6.0 + dz2 / 3.0 + dz3 / 3.0 + dz4 / 6.0;
		x += h; 

		
	}

 

}




int main() {


	RK4(0.25, 5, 1, 1, 0); 
	return 0;
}

*/

double dx(double t, double x) {
	return sin(2 * x) + sin(2 * t);
}

void rk4(double t0, double x0, double h, double n) {
	double t = t0, x = x0;
	double dx1, dx2, dx3, dx4,deltax;
	cout << "Iteracao 0 " << endl;
	cout << "t = " << t << endl;
	cout << "x = " << x << endl;
	for (int i = 0; i < n; i++) {
		dx1 = h * dx(t, x);
		dx2 = h * dx(t + h / 2, x + dx1 / 2);
		dx3 = h * dx(t + h / 2, x + dx2 / 2);
		dx4 = h * dx(t + h, x + dx3);
		
		deltax = dx1 / 6.0 + dx2 / 3.0 + dx3 / 3.0 + dx4 / 6.0;


		x += deltax;
		t += h;
		cout << "Iteracao  "<<i+1 << endl;
		cout << "t = " << t << endl;
		cout << "x = " << x << endl;
	}

}

int main() {
	cout << fixed;
	cout.precision(6);
	double x0 = 1.000;
	double t0 = 1.0000;
	double h = 0.125;
	int n = 6;
	rk4(t0, x0, h, n);



	return 0;
}







/*void ex1_rk4(){
    double t = 0.0, T = 15.0, C = 1.0, h = 0.25, dT1, dT2, dT3, dT4, dC1, dC2, dC3, dC4;
 
    cout << "0. t = " << t << "\t C = " << C << "\t T = " << T << endl;
 
    for(int i = 0; i < 5; i++){
 
        dT1 = h*fT(C, T);
        dC1 = h*fC(C, T);
 
        dT2 = h*fT(C + (dC1/2.0), T + (dT1/2.0));
        dC2 = h*fC(C + (dC1/2.0), T + (dT1/2.0));
 
        dT3 = h*fT(C + (dC2/2.0), T + (dT2/2.0));
        dC3 = h*fC(C + (dC2/2.0), T + (dT2/2.0));
 
        dT4 = h*fT(C + dC3, T + dT3);
        dC4 = h*fC(C + dC3, T + dT3);
 
        T += (dT1/6.0) + (dT2/3.0) + (dT3/3.0) + (dT4/6.0);
        C += (dC1/6.0) + (dC2/3.0) + (dC3/3.0) + (dC4/6.0);
        t += h;
 
        cout << i+1 << ". t = " << t << "\t C = " << C << "\t T = " << T << endl;
    }
 
}*/



