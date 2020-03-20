#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

//Método do Gradiente 
double f(double x, double y)
{
	return y * y - 2 * x * y - 6 * y + 2 * x * x + 12;
}

double fderx(double x, double y)
{
	return -2 * y + 4 * x;
}

double fdery(double x, double y)
{
	return 2 * y - 2 * x - 6;
}

void gradient(double f(double, double), double x, double y, double h)
{
	double xn = 1, yn = 1;
	int iterations = 0;

	cout << "f(x0, y0): " << f(x, y) << endl;

	do {
		x = xn;
		y = yn;

	GRAD:
		xn = x - h * fderx(x, y);
		yn = y - h * fdery(x, y);

		if ((f(xn, yn) > f(x, y))) {
			h /= 2;
			goto GRAD;
		}
		else
		{
			h *= 2;
		}

		cout << "fderx(xn,yn): " << fderx(xn, yn) << endl;
		cout << "fdery(xn, yn): " << fdery(xn, yn) << endl;
		cout << "xn: " << xn << endl;
		cout << "yn: " << yn << endl;
		cout << "f(xn, yn): " << f(xn, yn) << endl;

		cout << "-------------------" << endl;
		iterations ++;

	} while ((abs(xn - x) > 0.01) && (abs(yn - y) > 0.01));
	cout << "iterations: " << iterations<<endl ;

}

int main()
{
	const int OUT_PREC = 5;
	cout << fixed << setprecision(OUT_PREC);

	gradient(f, 1.0, 1.0, 1.0);

	return 0;
}