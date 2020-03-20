#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

double function(double num) {
	return 2*pow(num, 2) - 5 * num - 2;
}
double function_derivative(double num) {
	return 4 * num - 5;
}
double picard_peano(double num) {
	//return sqrt((5 * num + 2) / 2.0); ---> cuidado que é +/- por isso dá merda
	return 0.4*pow(num, 2) - 0.4;
}

double iterator_x(double x, double y) {
	return (-2 * pow(x, 2) + 5 * y - 1) / -y;
}
double iterator_y(double x, double y) {
	return (x + 3 * log(x)) / y;
}






int main() {
	//Encontrar os zeros da função 2x^2-5x-2=0
	/*Passos: -1-> Encontrar os zeros pela formula resolvente
				0-> fazer previsoes
				1-> aplicar método numérico para descobrir as soluçoes 
				2-> comparar as soluçoes em termos de erros absolutos
	*/
	//método de newton
	/*double prevX = 0;
	double x = 0;
	cout << "Insert a value\n";
	cin >> x;
	for (int i = 0; i < 20; i++) {
		cout << fixed << setprecision(20) << "x: " << x << " f(x): " << function(x) << endl;
		x = prevX - (function(prevX) / function_derivative(prevX));
		prevX = x;

	}*/

	//Método de Picard-Piano(nem todas as raizes vao funcionar pelo mesmo metodo 
	/*float x1=2, x2;
	x2 = picard_peano(x1);
	int n = 0;
	while ((abs(x1 - x2) > 0) | (n < 20)) {
		x1 = x2;
		x2 = picard_peano(x1);
		n++;
	}
	cout << "Aproximated root - " << x1 << "\twith " << n << " iteration(s)\n";
	cout << "Absolute error - " << (abs(x1 - ((5 + sqrt(41)) / 4)));*/

	double future_x = 0, x = 1.46,y=1.41;
	for(int i=0; i<20;i++) {
		future_x = iterator_x(x,y);
		y = iterator_y(x,y);
		x = future_x;
	}
	cout << x << endl;
	return 0;

}

/*RESOLUÇAO DA TRUTA
float function(float x) {
	return 2*pow(x, 2)-5*x-2;
}

float derivative(float x) {
	return 4.0 * x - 5;
}

float picard_peano(float x) {
	//return sqrt((5 * x + 2) / 2.0); ---> cuidado que é +/- por isso dá merda
	return 0.4*pow(x, 2) - 0.4;
}

float picard_peano1(float x, float y) {
	return sqrt((x*(y + 5) - 1) / 2);
}

float picard_peano2(float x, float y) {
	return sqrt(x+log10(x));
}

int main()
{
	/*float precision = pow(10, -5);
	float x1 = 98, x2 = 100;
	float aproximate_root = (x1+x2)/2;
	int n = 0;

	while (abs(x1 - x2) > precision) {
		if (function(x1) * function(aproximate_root) < 0) {
			x2 = aproximate_root;
			aproximate_root = (x1 + x2) / 2.0;
		}
		else {
			x1 = aproximate_root;
			aproximate_root = (x1 + x2) / 2.0;
		}
		n++;
	}

	if (function(x1) - function(x2) > 0) {
		aproximate_root = x2;
	}
	else
		aproximate_root = x1;

	cout << "x1 - " << x1 << "\tx2 - " << x2 << "\tn - " << n << "\troot - " << aproximate_root;
*/
/*float precision = pow(10, -5);
float x1 = -2, x2 = 0;
float aproximate_root = (x1 * function(x2) -x2*function(x1))/(function(x2)-function(x1));
int n = 0;
float aux;

do {
	if (function(x1) * function(aproximate_root) < 0) {
		x2 = aproximate_root;
		aux = aproximate_root;
		aproximate_root = (x1 * function(x2) - x2 * function(x1)) / (function(x2) - function(x1));
	}
	else {
		x1 = aproximate_root;
		aux = aproximate_root;
		aproximate_root = (x1 * function(x2) - x2 * function(x1)) / (function(x2) - function(x1));
	}
	n++;

} while (abs(aproximate_root - aux) > precision);


while (abs(x1 - x2) <= precision) {
	if (function(x1) * function(aproximate_root) < 0) {
		x2 = aproximate_root;
		aux =
		aproximate_root = (x1 + x2) / 2.0;
	}
	else {
		x1 = aproximate_root;
		aproximate_root = (x1 + x2) / 2.0;
	}
	n++;

}

if (function(x1) - function(x2) > 0) {
	aproximate_root = x2;
}
else
	aproximate_root = x1;

cout << "x1: " << x1 << "\nx2: " << x2 << "\nn: " << n << "\nroot: " << aproximate_root;*/



//Newton Method
/*float aproximate_root = -1;
float aprox_root_prev = aproximate_root;


for (int i = 0; i < 40; i++) {
	aproximate_root = aprox_root_prev - (function(aprox_root_prev)/derivative(aprox_root_prev));
	aprox_root_prev = aproximate_root;
}

cout << "aproximate root:   " << aproximate_root << endl;*/

//Picard-Peano

/*float aproximate_root = 2;
float aprox_root_prev = aproximate_root;

for (int i = 0; i < 40; i++) {
	aproximate_root = picard_peano(aproximate_root);
	aprox_root_prev = aproximate_root;
}

cout << "aproximate root:   " << aproximate_root << endl;*/

//Picard-Peano sistema (pag.80)

/*float x = 3.5, y = 2.3, x1 = 1.46, y1 = -1.41;

for (int i = 0; i < 40; i++) {
	x = x1;
	y = y1;
	x1 = picard_peano1(x, y);
	y1 = picard_peano2(x, y);

}

cout << "x:   " << x1 << endl << "y:   " << y1 << endl;


return 0;

}*/