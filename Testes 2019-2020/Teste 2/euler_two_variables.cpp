#include <iostream>

using namespace std;


double dy(double x, double z) {
	return 2+pow(x,2)+x*z;
}

int main() {
	cout << fixed;
	cout.precision(6);
	double t = 1, y = 1, z = 0, s1, s2, s3,delta;
	double h1 = 0.25, h2 = 0.125, h3 = 0.0625;
	cout << "EULER: " << endl;
	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 14; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t: " << t << endl;
		cout << "y: " << y << endl;
		delta = dy(t, z);
		t += h1;
		y += h1 * z;
		z = h1 * delta;
	}
	//s1 = y0;

	/*xn = 0; yn = 0;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 28; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h2;
		yn = y0 + h2 * dy(x0 + (h2 / 2), y0 + (h2 / 2)*dy(x0, y0));
	}
	s2 = y0;

	xn = 0; yn = 0;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 56; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h3;
		yn = y0 + h3 * dy(x0 + (h3 / 2), y0 + (h3 / 2)*dy(x0, y0));
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
  Euler's method
  x0 - initial x value
  y0 - initial y value
  h - step
  num_iter - number of iterations
 ***/
/*void euler(double x0, double y0, double h, unsigned int num_iter) {

	// Variables
	double x = x0;
	double y = y0;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	for (unsigned int i = 1; i <= num_iter; i++) {
		// Perform the method
		y += h * f(x, y);
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
	euler(x0, y0, h, num_iter);





	return 0;
}



*/