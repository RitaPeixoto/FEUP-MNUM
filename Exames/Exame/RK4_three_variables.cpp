#include <iostream>
using namespace std;

/*MÉTODO DE RK4 EQUAÇÕES DIFERENCIAIS DE ORDEM SUPERIOR*/

double f(double x, double y, double z) {
	return z;
}
double g(double x, double y, double z) {
	return x - 3 * z - 2 * y;
}

int main() {

	double x0 = 0, y0 = 0, z0 = 0, xn = 0, yn = 0, zn = 0, sy1, sy2, sy3, sz1, sz2, sz3;
	double h1 = 0.05, h2 = 0.025, h3 = 0.0125;
	double deltay1, deltay2, deltay3, deltay4;
	double deltaz1, deltaz2, deltaz3, deltaz4;

	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 10; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h1;
		deltay1 = h1 * f(x0, y0, z0);
		deltaz1 = h1 * g(x0, y0, z0);
		deltay2 = h1 * f(x0 + h1 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h1 * g(x0 + h1 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h1 * f(x0 + h1 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h1 * g(x0 + h1 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h1 * f(x0 + h1, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h1 * g(x0 + h1, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy1 = y0;
	sz1 = z0;

	xn = 0; yn = 1; zn = 1;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 20; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h2;
		deltay1 = h2 * f(x0, y0, z0);
		deltaz1 = h2 * g(x0, y0, z0);
		deltay2 = h2 * f(x0 + h2 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h2 * g(x0 + h2 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h2 * f(x0 + h2 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h2 * g(x0 + h2 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h2 * f(x0 + h2, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h2 * g(x0 + h2, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy2 = y0;
	sz2 = z0;

	xn = 0; yn = 1; zn = 1;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 40; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h3;
		deltay1 = h3 * f(x0, y0, z0);
		deltaz1 = h3 * g(x0, y0, z0);
		deltay2 = h3 * f(x0 + h3 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h3 * g(x0 + h3 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h3 * f(x0 + h3 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h3 * g(x0 + h3 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h3 * f(x0 + h3, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h3 * g(x0 + h3, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy3 = y0;
	sz3 = z0;

	double QCy = (sy2 - sy1) / (sy3 - sy2);
	double QCz = (sz2 - sz1) / (sz3 - sz2);

	cout << endl << "Quociente de convergencia Y: " << QCy << endl;
	cout << endl << "Quociente de convergencia Z: " << QCz << endl;

	double Ey = sy3 - sy2;
	double Ez = sz3 - sz2;

	cout << endl << "Erro Y: " << Ey << endl;
	cout << endl << "Erro Z: " << Ez << endl;





	return 0;

}


/*
//RUI ALVES
double f1 (double x , double y , double z){ return (z); }

double f2 (double x , double y , double z){ return (1.5 + x*x + x*z); }


/***
  RK4's method
  x0 - initial x value
  y0 - initial y value
  z0 - initial z value
  h - step
  num_iter - number of iterations
 ***/
/*void rk4(double x0 , double y0 , double z0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;
	double z = z0;
	double d1 , d2 , d3 , d4;
	double l1 , l2 , l3 , l4;

	cout << 0 << ":\t" << x << "\t" << y << "\t" << z << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the increments
		d1 = h*f1(x,y,z);
		l1 = h*f2(x,y,z);

		d2 = h*f1(x+h/2,y+d1/2,z+l1/2);
		l2 = h*f2(x+h/2,y+d1/2,z+l1/2);

		d3 = h*f1(x+h/2,y+d2/2,z+l2/2);
		l3 = h*f2(x+h/2,y+d2/2,z+l2/2);

		d4 = h*f1(x+h,y+d3,z+l3);
		l4 = h*f2(x+h,y+d3,z+l3);

		// Perform the method
		z += (l1/6 + l2/3 + l3/3 + l4/6);
		y += (d1/6 + d2/3 + d3/3 + d4/6);
		x += h;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << "\t" << z << endl;
	}
}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Integral Conditions
	const double x0 = 1;
	const double y0 = 0;
	const double z0 = 1;
	const double h = 0.2;
	const unsigned int num_iter = 2;

	// Perform the method
	rk4(x0 , y0 , z0 , h , num_iter);





	return 0;
}*/


