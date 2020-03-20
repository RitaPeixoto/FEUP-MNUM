#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;
/*1.
convergir <=> |g'(x)|<=1

1-- g'(x) = exp(x/2.0)/4, em [-1,0]: g'(-1) = 0.15 g'(0)=0.25, em [0,1]: g'(0)=0.25 g'(1)=0.41, em [4,5]: g'(4)=1.84 g'(5)=3.04
A formula de recorrencia 1 converge para as raizes nos intervalos 1 e 2

2-- g'(x) = exp(x)/(4*x)-exp(x)/(4*x^2), em [-1,0]: g'(-1) = -0.18  g'(0)=infinito , em [0,1]: g'(0)= infinito g'(1)= 0, em [4,5]: g'(4)=2.55 g'(5)=5.93
A formula de recorrencia 2 nao converge para nenhum intervalo de raizes

3--	g'(x) = -exp(x/2)/4, em [-1,0]: g'(-1)=-0.15 g'(0)= -0.25   , em [0,1]: g'(0)=  -0.25 g'(1)=-0.41, em [4,5]: g'(4) = -1.84  g'(5)=-3.04
A formula de recorrencia 3 converge para as raizes nos intervalos 1 e 2
*/



/*2.*/
double f(double x) {
	return 2 * log(2 * x);
}

void Picard_Peano(double guess, int n) {
	double x = guess;
	for (int i = 0; i < n; i++) {
		cout << i << ": " << x << endl;
		x = f(x);
	}
}



int main() {
	cout << fixed;
	cout.precision(6);

	Picard_Peano(1.1, 2);



	return 0;
}

/*3.

erro = 1.57691 - 1.1000 = 0.47691

*/