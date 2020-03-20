#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
1
a) g'(x) = exp(x/2)/4,em [-1,0]: g'(-1) = 0.1516 g'(0)=0.25, em [0,1]: g'(0)= 0.25 g'(1)=0.41, em [4,5]: g'(4) = 1.847 g'(5)=3.045, converge para x1 e x2
b) g'(x) = -exp(x/2)/4,em [-1,0]: g'(-1) = -0.1516 g'(0)=-0.25, em [0,1]: g'(0)= -0.25 g'(1)=-0.41, em [4,5]: g'(4) = -1.847 g'(5)=-3.045, converge para x1 e x2
c) g'(x) = exp(x)/(4*x) - exp(x)/(4*x^2,em [-1,0]: g'(-1) = -0.1839 g'(0)=-00, em [0,1]: g'(0)= -00 g'(1)=-00, em [4,5]: g'(4) = 2.559 g'(5)=5.9365, converge para x1
*/

/*
2
*/
double recf(double x) {
	return 2 * log(2 * x);
}

void picard_peano(double guess, int n) {
	double x = guess;
	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;
		x = recf(x);
	}
}



int main() {
	cout << fixed;
	cout.precision(6);

	picard_peano(0.9, 3);
	cout << recf(0.9);

	return 0;
}



