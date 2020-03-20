#include<iostream>
#include <iomanip>
#include<vector>
#include<cmath>

using namespace std;

double rec_x1(double x2, double x3, double x4) {	
	return (1 +1* x2 +1* x3 - 1*x4) / 4.5;
}
double rec_x2(double x1, double x3, double x4) {
	return (-1 + 1.0* x1 -1* x3 + 1*x4) / 4.5;
}

double rec_x3(double x1, double x2, double x4) {
	return (-1 + 1 * x1 - 2 * x2 +1 * x4) / 4.5;
}
double rec_x4(double x1, double x2, double x3) {
	return (0.0 - 2 * x1 +1 * x2 + 1 * x3) / 4.5; 
}



int main() {
	cout << fixed;
	cout.precision(6);
	double x1_guess = 0.2500;
	double x2_guess = 0.2500;
	double x3_guess = 0.2500;
	double x4_guess = 0.2500;
	double x1 = rec_x1(x2_guess, x3_guess, x4_guess);
	double x2 = rec_x2(x1_guess, x3_guess, x4_guess);
	double x3 = rec_x3(x1_guess, x2_guess, x4_guess);
	double x4 = rec_x4(x1_guess, x2_guess, x3_guess);
	int iterations = 1;

	while (abs(x1 - x1_guess) >= pow(10, -5) || abs(x2 - x2_guess) >= pow(10, -5) || abs(x3 - x3_guess) >= pow(10, -5) || abs(x4 - x4_guess) >= pow(10, -5)) {

		cout << "Iteration " << iterations << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		iterations++;
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;

		x1 = rec_x1(x2_guess, x3_guess, x4_guess);
		x2 = rec_x2(x1_guess, x3_guess, x4_guess);
		x3 = rec_x3(x1_guess, x2_guess, x4_guess);
		x4 = rec_x4(x1_guess, x2_guess, x3_guess);

	}
	return 0;

}


/*void gauss_seidel(matrix & m, double x1_i, double x2_i, double x3_i, double x4_i, unsigned int num_iter) {
	// Initial Values
	double x1 = x1_i;
	double x2 = x2_i;
	double x3 = x3_i;
	double x4 = x4_i;

	cout << 0 << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;

	for (unsigned int i = 1; i <= num_iter; i++) {
		// Compute the values
		x1 = (m[0][4] - (m[0][1] * x2 + m[0][2] * x3 + m[0][3] * x4)) / m[0][0];
		x2 = (m[1][4] - (m[1][0] * x1 + m[1][2] * x3 + m[1][3] * x4)) / m[1][1];
		x3 = (m[2][4] - (m[2][0] * x1 + m[2][1] * x2 + m[2][3] * x4)) / m[2][2];
		x4 = (m[3][4] - (m[3][0] * x1 + m[3][1] * x2 + m[3][2] * x3)) / m[3][3];

		// Print the current values
		cout << i << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;
	}

}*/
//typedef<vector<vector<double>> matrix
/*int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);


	// Make the matrix
	matrix m = { { 6 , 0.5   , 3  ,  0.25 , 25},
				{ 1.2  , 3 , 0.25 , 0.20  , 10},
				{ -1  , 0.25   , 4 , 2  , 7 },
				{ 2 , 4   , 1  , 8 , -12 } };

	// Initial values
	const double x1_i = 2.12687;
	const double x2_i = 2.39858;
	const double x3_i = 3.99517;
	const double x4_i = -3.73040;
	const unsigned int num_iter = 1;


	// Perform the method
	gauss_seidel(m, x1_i, x2_i, x3_i, x4_i, num_iter);


	return 0;
}*/




