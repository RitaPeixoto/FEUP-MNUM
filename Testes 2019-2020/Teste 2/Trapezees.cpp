
#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;
double pi = 3.14159265359;
double e = 2.718281828459045;


double f(double x) {
	return (1 - exp(-x));
}

double Trapezies_method(double h, double a, double b, double n) {
	double result = 0;

	for (int i = 1; i < n; i++) {
		result += 2 * f(a + i * h);
	}
	result = (h / 2)*(f(a) + result+f(b));
	return result;
}

/*
int main() {
	double a = 0, b = 4;
	double n1 = 4, n2 = 8, n3 = 16, n4 = 32;
	double h1 = 1, h2 = 1/2, h3 = 1/4, h4 = 1/8;

	cout << "1.\n" << fixed << setprecision(6) << "T= " << Trapezies_method(h1, a, b, n1) << endl;
	cout << "2.\n" << fixed << setprecision(6) << "T= " << Trapezies_method(h2, a, b, n2) << endl;
	cout << "3.\n" << fixed << setprecision(6) << "T= " << Trapezies_method(h3, a, b, n3) << endl;
	cout << "Qt= " << (Trapezies_method(h2, a, b, n2) - Trapezies_method(h1, a, b, n1)) / (Trapezies_method(h3, a, b, n3) - Trapezies_method(h2, a, b, n2)) << endl;
	cout << "Et= " << (Trapezies_method(h3, a, b, n3) - Trapezies_method(h2, a, b, n2)) / 3.0 << endl;
	return 0;
}*/

int main()
{
	double sum = 0;
	vector<vector<double>> xy = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2} };
	{
		for (int i = 0; i < xy.size(); i++)
		{
			for (int j = 0; j < xy.size(); j++)
			{
				if ((i == 0 || i == xy.size() - 1) && (j == 0 || j == xy.size() - 1))
				{
					sum += xy[i][j];
				}
				else if (i == 0 || j == 0 || i == xy.size() - 1 || j == xy.size() - 1)
				{
					sum += 2 * xy[i][j];
				}
				else
				{
					sum += 4 * xy[i][j];
				}
			}
		}
	}
	sum /= 4;
	cout << "Sum: " << sum;
	return 0;
}

//RUI ALVES
/*
double f(double x) { return (x*x - 4*x + 3.5); }	// f(x) = x^2 - 4*x + 3.5
*/

/***
  Trapezio's method
  a - integral initial value
  b - integral final value
  h - step
 ***/
/*double trapezio(const double a, const double b, const double h) {

	const unsigned int n = abs(b - a) / h;
	double integral = 0;

	// Make the values list
	vector<double> values;
	for (unsigned int i = 0; i <= n; i++) {
		values.push_back(f(a + i * h));
	}

	// Compute the middle values ( all except y0 and yn )
	for (unsigned int i = 1; i < n; i++)	integral += values.at(i);

	// The middle terms have coeficient 2
	integral *= 2;

	integral += values.at(0);	// y0
	integral += values.at(n);	// yn

	// Multiply by step/2

	integral *= h / 2;	// I = h/2 * (y0 + 2y1 + 2y2 + ... + 2y(n-1) + y(n) )


	// Return the computed value
	return integral;
}

/* Function no compute the Convergence Quotient */
/*double quotient(double s, double s_l, double s_ll) { return (s_l - s) / (s_ll - s_l); }



int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Integral Values
	const double a = 2;
	const double b = 6;
	double h = 0.25;

	// Compute and print the answers
	double integral1 = trapezio(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral1 << endl << endl;

	h /= 2;	// Dimish the step

	double integral2 = trapezio(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral2 << endl << endl;

	h /= 2;	// Dimish the step

	double integral3 = trapezio(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral3 << endl << endl;

	// Print the convergence quotient
	double convergence_quotient = quotient(integral1, integral2, integral3);
	cout << "Convergence quotient: " << convergence_quotient << endl;


	return 0;
}*/





