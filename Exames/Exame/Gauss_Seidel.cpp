#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


typedef vector<vector<double> > matrix;
/***
  Gauss-Seidel method
  m - matrix to solve
  x1_i - Initial x1 guess
  x2_i - Initial x2 guess
  x3_i - Initial x3 guess
  x4_i - Initial x4 guess
  num_iter - Number of iterations
 ***/
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

}


int main() {
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


//Gauss-Seidel

float rec_1(float x2, float x3, float x4) {
	return (25 -0.5* x2 - 3*x3-0.25*x4) / 6.0;
}
float rec_2(float x1, float x3,float x4) {
	return (10 - 1.2* x1 - 0.25 * x3 - 0.20*x4) / 3.0;
}
float rec_3(float x1,float x2, float x4) {
	return (7 +1* x1 - 0.25 * x2 - 2*x4) / 4.0;
}

float rec_4(float x1, float x2, float x3) {
	return (-12 - 2 * x1 - 4 * x2 - 1 * x3) / 8.0;
}



int main() {
	cout << fixed;
	cout.precision(6);
	float x1_guess = 2.12687, x2_guess = 2.39858, x3_guess = 3.99517,x4_guess=-3.73040;
	float x1 = rec_1(x2_guess, x3_guess,x4_guess);
	float x2 = rec_2(x1_guess, x3_guess,x4_guess);
	float x3 = rec_3(x1_guess,x2_guess,x4_guess);
	float x4 = rec_4(x1_guess, x2_guess, x3_guess);
	int it = 0;
	//-3 ou -5
	while ((abs(x1 - x1_guess) >= pow(10, -5)) && (abs(x2 - x2_guess) >= pow(10, -5)) && (abs(x3 - x3_guess) >= pow(10, -5))) {
		cout << x1 << "\t" << x2 << "\t" << x3 << "\t"<<x4<<endl;
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;

		x1 = rec_1(x2_guess, x3_guess,x4_guess);
		x2 = rec_2(x1, x3_guess,x4_guess);
		x3 = rec_3(x1,x2,x3_guess);
		x4 = rec_4(x1, x2, x3);
		it++;
		if (it == 3)
			break;
	}


	//cout << "x1= " << x1 << "\nx2= " << x2 << "\nx3= " << x3 << endl << "iterations: " << it << endl;
	return 0;
}