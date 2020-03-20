#include <iomanip>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<vector<double> > matrix;

/***
(4x4)
  Gauss-Jacobi method
  m - matrix to solve
  x1_i - Initial x1 guess
  x2_i - Initial x2 guess
  x3_i - Initial x3 guess
  x4_i - Initial x4 guess
  num_iter - Number of iterations
 ***/
/*void gauss_jacobi(matrix & m, double x1_i, double x2_i, double x3_i, double x4_i, unsigned int num_iter) {
	// Initial Values
	double x1 = x1_i;
	double x2 = x2_i;
	double x3 = x3_i;
	double x4 = x4_i;

	// Useful variables
	double x1n, x2n, x3n, x4n;

	cout << 0 << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;

	for (unsigned int i = 1; i <= num_iter; i++) {
		// Compute the values
		x1n = (m[0][4] - (m[0][1] * x2 + m[0][2] * x3 + m[0][3] * x4)) / m[0][0];
		x2n = (m[1][4] - (m[1][0] * x1 + m[1][2] * x3 + m[1][3] * x4)) / m[1][1];
		x3n = (m[2][4] - (m[2][0] * x1 + m[2][1] * x2 + m[2][3] * x4)) / m[2][2];
		x4n = (m[3][4] - (m[3][0] * x1 + m[3][1] * x2 + m[3][2] * x3)) / m[3][3];

		// Update the Variables
		x1 = x1n;
		x2 = x2n;
		x3 = x3n;
		x4 = x4n;

		// Print the current values
		cout << i << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;
	}

}


int main() {
	// Set printing precision
	cout << fixed;
	cout.precision(6);


	// Make the matrix
	matrix m = { { 2 , -6   , -1  ,-38},
			{ -3 , -1 , 7 , -34},
			{ -8  , 1   , -2 , -20 } };


	// Initial values
	const double x1_i = 14.02;
	const double x2_i = 13.123;
	const double x3_i = 94.423;
	const double x4_i = 54.2341;
	const unsigned int num_iter = 13;


	// Perform the method
	gauss_jacobi(m, x1_i, x2_i, x3_i, x4_i, num_iter);


	return 0;
}*/		


//Gauss-Jacobi (3x3)
float rec_1(float x2, float x3) {
	return (6*x2+x3-38) / 2.0;
}
float rec_2(float x1, float x3) {
	return (34-3*x1+7*x3);
}
float rec_3(float x2,float x1) {
	return (-8*x1+x2+20) / 2.0;
}

int main() {
	float x1_guess =0.0, x2_guess = 0.0, x3_guess = 0.0;
	float x1 = rec_1(x2_guess, x3_guess);
	float x2 = rec_2(x1_guess, x3_guess);
	float x3 = rec_3(x2_guess,x1_guess);
	int it = 0;
	//-3 ou -5
	while ((abs(x1 - x1_guess) >= pow(10, -3)) && (abs(x2 - x2_guess) >= pow(10, -3)) && (abs(x3 - x3_guess) >= pow(10, -3))) {
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;

		x1 = rec_1(x2_guess, x3_guess);
		x2 = rec_2(x1_guess, x3_guess);
		x3 = rec_3(x2_guess,x1_guess);
		it++;
	}


	cout << "x1= " << x1 << "\nx2= " << x2 << "\nx3= " << x3 << endl<<"iterations: "<<it<<endl;
	return 0;
}
