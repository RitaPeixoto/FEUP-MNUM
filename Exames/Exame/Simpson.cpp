#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;
double pi = 3.14159265359; 
double e = 2.718281828459045;


double f(double x) {
	return (1 - pow(e, -x));
}


double Simpson_method(double h, double a, double b, double n) {
	double result = 0;

	for (int i = 1; i < n; i++) {
		if (i % 2 != 0) {
			result += 2 * f(a + i * h);
		}
		else {
			result += 4 * f(a + i * h);
		}

	}
	result = (h / 3)*(f(a) + result+f(b));
	return result;
}	


/*
int main() {
	double a = 0, b = 4;
	double n1 = 4, n2 = 8, n3 = 16, n4 = 32;
	double h1 = 1, h2 = 1/2, h3 = 1/4, h4 = 1 / 8;

	cout << "1.\n" << fixed << setprecision(6)<< "S= " << Simpson_method(h1, a, b, n1) << endl;
	cout << "2.\n" << fixed << setprecision(6)<< "S= " << Simpson_method(h2, a, b, n2) << endl;
	cout << "3.\n" << fixed << setprecision(6)<< "S= " << Simpson_method(h3, a, b, n3) << endl << endl;
	cout << "Qs= " << (Simpson_method(h2, a, b, n2) - Simpson_method(h1, a, b, n1)) / (Simpson_method(h3, a, b, n3) - Simpson_method(h2, a, b, n2)) << endl;

	cout << "S'''= " << Simpson_method(h4, a, b, n4) << endl;
	cout << "Qs= " << (Simpson_method(h3, a, b, n3) - Simpson_method(h2, a, b, n2)) / (Simpson_method(h4, a, b, n4) - Simpson_method(h3, a, b, n3)) << endl;
	cout << "Es= " << (Simpson_method(h4, a, b, n4) - Simpson_method(h3, a, b, n3)) / 15.0 << endl;

	return 0;
}
*/




int main()
{
	vector<double> results = { 0,0,0 };
	double result, h = 1, err, dx = 0.25;
	int counter;
	vector<double> list = { 1.04,0.37,0.38,1.49,1.08,0.13,0.64,0.84,0.12 };
	for (int j = 0; j < 3; j++)
	{
		result = list[0];
		counter = 1;
		for (int i = h / dx; i < list.size() - h / dx; i += h / dx)
		{
			if (counter % 2 == 0)
				result += list[i] * 2;
			else
				result += list[i] * 4;
			counter++;
		}
		result += list[list.size() - 1];
		result *= h / 3;
		cout << "Step: " << h << "; Result: " << result << endl;
		results[j] = result;
		h /= 2;
	}
	err = (results[2] - results[1]) / 15;
	cout << "Error: " << err;
	return 0;
}




/*
//RUI ALVES

double f(double x) { return (5*x*x*x*x + 8.5*x*x*x + 3.14); }	// f(x) = 5x^4 + 8.5x^3 + 3.14


/***
  Simpson's method
  a - integral initial value
  b - integral final value
  h - step
 ***/
/*double simpson(const double a, const double b, const double h) {

	const unsigned int n = abs(b - a) / h;
	double integral = 0;
	double integral_odd_terms = 0;
	double integral_even_terms = 0;

	// Make the values list
	vector<double> values;
	for (unsigned int i = 0; i <= n; i++) {
		values.push_back(f(a + i * h));
	}

	// Compute the odd values
	for (unsigned int i = 1; i < n; i += 2)	integral_odd_terms += values.at(i);


	// Compute the even values
	for (unsigned int i = 2; i < n; i += 2)	integral_even_terms += values.at(i);

	integral_odd_terms *= 4;	// The odd values have coeficient 4

	integral_even_terms *= 2;	// The even values have coeficient 2

	integral += values.at(0);	// y0
	integral += values.at(n);	// yn
	integral += integral_odd_terms;
	integral += integral_even_terms;

	// Multiply by step/3

	integral *= h / 3;	// I = h/3 * (y0 + 4y1 + 2y2 + 4y3 + ... + 4y(n-3) + 2y(n-2) + 4y(n-1) + y(n) )


	// Return the computed value
	return integral;
}*/

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
	double integral1 = simpson(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral1 << endl << endl;

	h /= 2;	// Dimish the step

	double integral2 = simpson(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral2 << endl << endl;

	h /= 2;	// Dimish the step

	double integral3 = simpson(a, b, h);
	cout << "Using h = " << h << endl;
	cout << "Integral: " << integral3 << endl << endl;

	// Print the convergence quotient
	double convergence_quotient = quotient(integral1, integral2, integral3);
	cout << "Convergence quotient: " << convergence_quotient << endl;


	return 0;
}
*/