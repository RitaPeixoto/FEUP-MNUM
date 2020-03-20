#include <iostream>

using namespace std;


/*
MÉTODO DE RK4


double dy(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

int main() {
	double x0 = 0, y0 = 0, xn = 0, yn = 0, s1, s2, s3,deltay1, deltay2, deltay3, deltay4;
	double h1 = 0.1, h2 = 0.05, h3 = 0.025;

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
		yn = y0 + deltay1/6.0+deltay2/3.0+deltay3/3.0 + deltay4/6.0;
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
		deltay4 = h3 * dy(x0 + h3, y0+ deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0+ deltay3 / 3.0 + deltay4 / 6.0;
	}
	s3 = y0;

	double QC = (s2 - s1) / (s3 - s2);
	cout << endl << "S1: " << s1 << endl << "s2: " << s2 << endl << "S3: " << s3 << endl;
	cout << endl << "Quociente de convergencia: " << QC << endl;

	double E = (s3 - s2) / 3;

	cout << endl << "Erro: " << E << endl;

}*/


/*SISTEMAS DE EQUAÇÕES DIFRERENCIAIS DE 1ª ORDEM */
/*
double f(double x, double y, double z) {
	return z * y + x;
}

double g(double x, double y, double z) {
	return z * x + y;
}

int main()
{
	double x0 = 0, y0 = 1, z0 = 1, xn = 0, yn = 1, zn = 1, sy1, sy2, sy3, sz1, sz2, sz3;
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

}*/



/*MÉTODO DE RK4 EQUAÇÕES DIFERENCIAIS DE ORDEM SUPERIOR*/

double f(double x, double y, double z) {
	return z;
}
double g(double x, double y, double z) {
	return x - 3 * z - 2 * y;
}

int main() {

	double x0 = 0, y0 =0 , z0 =0, xn = 0, yn = 0, zn = 0, sy1, sy2, sy3, sz1, sz2, sz3;
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






