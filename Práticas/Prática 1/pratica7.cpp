#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;
double pi = 3.14159265359;
//Gauss-Jacobi
/*float rec_1(float x2, float x3) {
	return (7.0 - x2 - x3) / 3.0;
}
float rec_2(float x1, float x3) {
	return (4-x1-2*x3) / 4.0;
}
float rec_3(float x2) {
	return (5 - 2 * x2) / 5.0;
}

int main() {
	float x1_guess = 0.0, x2_guess = 0.0, x3_guess = 0.0;
	float x1 = rec_1(x2_guess, x3_guess);
	float x2 = rec_2(x1_guess, x3_guess);
	float x3 = rec_3(x2_guess);
	int it = 0;
	//-3 ou -5
	while ((abs(x1 - x1_guess) >= pow(10, -3)) && (abs(x2 - x2_guess) >= pow(10, -3)) && (abs(x3 - x3_guess) >= pow(10, -3))) {
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;

		x1 = rec_1(x2_guess, x3_guess);
		x2 = rec_2(x1_guess, x3_guess);
		x3 = rec_3(x2_guess);
		it++;
	}


	cout << "x1= " << x1 << "\nx2= " << x2 << "\nx3= " << x3 << endl<<"iterations: "<<it<<endl;
	return 0;
}
*/


//Gauss-Seidel
/*
float rec_1(float x2, float x3) {
	return (7.0 - x2 - x3) / 3.0;
}
float rec_2(float x1, float x3) {
	return (4 - x1 - 2 * x3) / 4.0;
}
float rec_3(float x2) {
	return (5 - 2 * x2) / 5.0;
}

int main() {
	float x1_guess = 0.0, x2_guess = 0.0, x3_guess = 0.0;
	float x1 = rec_1(x2_guess, x3_guess);
	float x2 = rec_2(x1_guess, x3_guess);
	float x3 = rec_3(x2_guess);
	int it = 0;
	//-3 ou -5
	while ((abs(x1 - x1_guess) >= pow(10, -5)) && (abs(x2 - x2_guess) >= pow(10, -5)) && (abs(x3 - x3_guess) >= pow(10, -5))) {
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;

		x1 = rec_1(x2_guess, x3_guess);
		x2 = rec_2(x1, x3_guess);
		x3 = rec_3(x2);
		it++;
	}


	cout << "x1= " << x1 << "\nx2= " << x2 << "\nx3= " << x3 << endl << "iterations: " << it << endl;
	return 0;
}*/


double f(double x) {
	return sin(x) / pow(x, 2);
}

double Trapezies_method(double h, double a, double b, double n) {
	double result=0;

	for (int i = 1; i < n; i++) {
		result += 2 * f(a + i * h);
	}
	result = (h / 2)*(f(a) + result);
	return result;
}
double Simpson_method(double h, double a, double b, double n) {
	double result = 0;

	for (int i = 1; i < n; i++) {
		if (i % 2 != 0) {
			result += 4 * f(a + i * h);
		}
		else {
			result += 2 * f(a + i * h);
		}
		
	}
	result = (h / 3)*(f(a) + result);
	return result;
}

int main() {
	double a = pi / 2, b=pi;
	double n1 = 4, n2= 8, n3= 16, n4= 32;
	double h1 = pi / 8, h2= pi/16, h3= pi/32,h4=pi/64;

	cout <<"1.\n"<<fixed<<setprecision(6)<< "T= "<<Trapezies_method(h1, a, b, n1)<<endl;

	cout << fixed << setprecision(6) << "S= " << Simpson_method(h1, a, b, n1)<<endl;

	cout << "2.\n" << fixed << setprecision(6) << "T= " << Trapezies_method(h2, a, b, n2) << endl;

	cout << fixed << setprecision(6) << "S= " << Simpson_method(h2, a, b, n2)<<endl;

	cout << "3.\n" << fixed << setprecision(6) << "T= " << Trapezies_method(h3, a, b, n3) << endl;

	cout << fixed << setprecision(6) << "S= " << Simpson_method(h3, a, b, n3)<<endl<<endl;

	cout << "Qt= " << (Trapezies_method(h2, a, b, n2) - Trapezies_method(h1, a, b, n1)) / (Trapezies_method(h3, a, b, n3) - Trapezies_method(h2, a, b, n2))<<endl;
	cout << "Qs= " << (Simpson_method(h2, a, b, n2) - Simpson_method(h1, a, b, n1)) / (Simpson_method(h3, a, b, n3) - Simpson_method(h2, a, b, n2)) << endl;

	cout << "S'''= " << Simpson_method(h4, a, b, n4)<<endl;
	cout << "Qs= " << (Simpson_method(h3, a, b, n3) - Simpson_method(h2, a, b, n2)) / (Simpson_method(h4, a, b, n4) - Simpson_method(h3, a, b, n3)) << endl;

	cout << "Et= " << (Trapezies_method(h3, a, b, n3) - Trapezies_method(h2, a, b, n2)) / 3.0 << endl;

	cout << "Es= " << (Simpson_method(h4, a, b, n4) - Simpson_method(h3, a, b, n3)) / 15.0 << endl;

	return 0;

}










