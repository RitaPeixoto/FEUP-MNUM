#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


/*
a) Através do comando do maxima plot2d(f,[x,-2,5]) podemos observar que esta função tem apenas 2 zeros
b) A menor raiz positiva encontra-se muito proxima de 4
--[0,+00], enquadra-se
--[-0.2,4], enquadra-se
--[1,3.5], não se enquadra
--[3.5,4.5], enquadra-se

c) Para convergir |g'(x)| <1, escolhi o intervalo [3.5,4.5] para testar isto 
-- g1'(x) = ...    g1'(3.5)= 0.697 g1'(4.5)=0.641, logo converge 
-- g2'(x) = 2/x^3  - 9/x^4       g2'(3.5)=0.0133 g2'(4.5)=3.469*10^-18 , logo  converge
-- g3'(x) = 12*x^2-4*x^3    g3'(3.5) = -24.5 g3'(4.5)= -121.5 , logo nao converge 
*/

double g(double x) {
	return pow(4 * pow(x, 3) - x + 3, (1 / 4.0));
}

void picard_peano(double guess, int n) {
	double xn = guess;

	for (int i = 0; i < n; i++) {
		cout << "Iteracao " << i << endl;
		cout << "xn = " << xn << endl; 
		xn = g(xn);
	}
}




int main() {
	cout << fixed;
	cout.precision(6);

	picard_peano(3.50000, 3);



	return 0;
}
