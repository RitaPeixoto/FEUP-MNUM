#include<iostream>
using namespace std;

//MÉTODO DE RK4


double dz(double x, double z) {
	return 2 + pow(x, 2) + x * z;
}

int main() {
	double h = 0.25, t = 1, y = 1, z = 0, deltaz;

	cout << endl << endl << "RK4: " << endl;
	h = 0.25;
	t = 1;
	y = 1;
	z = 0;
	double z1, z2, z3, z4, dz1, dz2, dz3, dz4;
	for (int i = 0; i < 3; i++)
	{
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		z1 = (h * z);
		dz1 = h * dz(t, z);
		z2 = (h * (z + dz1 / 2));
		dz2 = (h * (dz(t, z + dz1 / 2)));
		z3 = (h * (z + dz2 / 2));
		dz3 = (h * (dz(t, z + dz2 / 2)));
		z4 = (h * (z + dz3));
		dz4 = (h * (dz(t, z + dz3)));
		y += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		t += h;
	}
	/*double x0 = 0, y0 = 1, xn = 1, yn = 0, s1, s2, s3, deltay1, deltay2, deltay3, deltay4;
	double y1, y2, y3,y4;
	double h1 = 0.25, h2 = 0.125, h3 = 0.0625;

	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 14; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h1;
		deltay1 = h1 * dy(x0, y0);
		deltay2 = h1 * dy(x0 + h1 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h1 * dy(x0 + h1 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h1 * dy(x0 + h1, y0 + deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
	}
	s1 = y0;

	xn = 0; yn = 0;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 28; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h2;
		deltay1 = h2 * dy(x0, y0);
		deltay2 = h2 * dy(x0 + h2 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h2 * dy(x0 + h2 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h2 * dy(x0 + h2, y0 + deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;

	}
	s2 = y0;

	xn = 0; yn = 0;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 56; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h3;
		deltay1 = h3 * dy(x0, y0);
		deltay2 = h3 * dy(x0 + h3 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h3 * dy(x0 + h3 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h3 * dy(x0 + h3, y0 + deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
	}
	s3 = y0;

	double QC = (s2 - s1) / (s3 - s2);
	cout << endl << "S1: " << s1 << endl << "s2: " << s2 << endl << "S3: " << s3 << endl;
	cout << endl << "Quociente de convergencia: " << QC << endl;

	double E = (s3 - s2) / 3;

	cout << endl << "Erro: " << E << endl;*/
}


	/*
	//RUI ALVES
double f(double x , double y) { return (y); }		// dy/dx = y   ---->   y = e^x


/***
  RK4's method
  x0 - initial x value
  y0 - initial y value
  h - step
  num_iter - number of iterations
 ***/
/*	void rk4(double x0, double y0, double h, unsigned int num_iter) {

		// Variables
		double x = x0;
		double y = y0;
		double d1, d2, d3, d4;

		cout << 0 << ":\t" << x << "\t" << y << endl;

		for (unsigned int i = 1; i <= num_iter; i++) {
			// Compute the increments
			d1 = h * f(x, y);
			d2 = h * f(x + h / 2, y + d1 / 2);
			d3 = h * f(x + h / 2, y + d2 / 2);
			d4 = h * f(x + h, y + d3);

			// Perform the method
			y += (d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6);
			x += h;

			// Print the current values
			cout << i << ":\t" << x << "\t" << y << endl;
		}
	}


	int main() {
		// Set printing precision
		cout << fixed;
		cout.precision(6);

		// Integral Conditions
		const double x0 = 0;
		const double y0 = 1;
		const double h = 0.1;
		const unsigned int num_iter = 100;

		// Perform the method
		rk4(x0, y0, h, num_iter);





		return 0;
	}
	*/