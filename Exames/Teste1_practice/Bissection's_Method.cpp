#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double e = 2.718281828;

double f(double x) { return (pow(e,0.7*x)-x*x-0.5); }	// f(x) = x^3-10*sin(x)+2.8

/***
  Bissection Method
  a0 - Interval's left extreme
  b0 - Interval's right extreme
  final_interval - Interval b-a to reach : termination condition
 ***/
void bissecao(double a, double b,int num_iter, double final_interval) {
	double guess;
	for (int i = 0; i < num_iter; i++) {
		guess = (a + b) / 2.0;

		cout << "Iteracao numero " << i << endl;
		cout << "a = " << a << " --- f(a) = " << f(a) << endl;
		cout << "b = " << b << " --- f(b) = " << f(b) << endl;
		cout << "m = " << guess << " --- f(m) = " << f(guess)<<  endl << endl;

		if (f(a)*f(guess) < 0) {
			a = a;
			b = guess;
		}
		else {
			a = guess;
			b = b;
		}
	}
	/*// Initial values
	double a = a0;
	double b = b0;
	double m;
	unsigned int iterations_counter = 0;

	
	// Loop until final interval is reached
	while (abs(b - a) > final_interval) {
		m = (b + a) / 2;

		// Decide which extreme changes
		if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;

		// Print current values
		iterations_counter++;
		cout << iterations_counter << ":\t" << "a: " << a << "\t" << " b " << b << " f(a): " << f(a) << " f(b): " << f(b) << " m: " << m << " f(m): " << f(m) << "\t" << abs(b - a) << endl;
	}
	/*
	// Initial values
	double a = a0;
	double b = b0;
	double guess;
	unsigned int iterations_counter = 0;

	//cout << iterations_counter << ":\t" << a << "\t" << b << "\t" << abs(b - a) << endl;

	// Loop until final interval is reached
	while (abs(b - a) > final_interval && iterations_counter < num_iter) {
		guess = (b + a) / 2;

		// Decide which extreme changes
		if (f(guess) * f(a) > 0){
			a = guess;
			b = b;
		}
		else {
			a = a;
			b = guess;
		}

		// Print current values
		
		cout << "Iteracao numero " << iterations_counter << endl; 
			cout << "a = " << a << " --- f(a) = " << f(a) << endl;
		cout << "b = " << b << " --- f(b) = " << f(b) << endl;
		cout << "guess = " << guess << " f(guess): " << f(guess)<< endl << endl;
		iterations_counter++;
	}*/

}


int main(){
	// Set printing precision
	cout << fixed;
	cout.precision(10);

	// Values
	const double a0 = -1.000;
	const double b0 = 0.000;

	// Call the method
	bissecao(a0, b0,20,pow(10,-4));

	return 0;
}