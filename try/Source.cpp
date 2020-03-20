#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;
/*
double Simpson(vector<vector<double>>v, int n,double h ) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {
				sum += v[i][j];
			}
			else if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
				sum += 4*v[i][j];
			}
			else {
				sum += 16 * v[i][j];
			}
		}
	}

	sum *= (h/9.0);

	return sum; 

}
*/
/*
double rec_1(double x2, double x3, double x4) {
	return (1.000 + x2 + x3 - x4) / 4.80;
}
double rec_2(double x1, double x3, double x4) {
	return (-1.000 + x1 -x3 + x4) / 4.80;
}
double rec_3(double x1, double x2, double x4) {
	return (-1.000+x1 -2*x2 +x4) / 4.80;
}
double rec_4(double x1, double x2, double x3) {
	return (-2*x1+ x2 + x3) / 4.80;
}


void gauss_seidel(double x1_guess, double x2_guess, double x3_guess, double x4_guess) {
	double x1 = rec_1(x2_guess, x3_guess, x4_guess);
	double x2 = rec_2(x1, x3_guess, x4_guess);
	double x3 = rec_3(x1, x2, x4_guess);
	double x4 = rec_4(x1, x2, x3);
	int iterations = 1;
	while (abs(x1 - x1_guess >= pow(10, -5)) || abs(x2 - x2_guess) >= pow(10, -5) || abs(x3 - x3_guess >= pow(10, -5)) || abs(x4 - x4_guess) >= pow(10, -5)) {
		cout << "Iteracao " << iterations << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;

		x1 = rec_1(x2_guess, x3_guess, x4_guess);
		x2 = rec_2(x1, x3_guess, x4_guess);
		x3 = rec_3(x1, x2, x4_guess);
		x4 = rec_4(x1, x2, x3);
		iterations++;
		if (iterations == 7) {
			break;
		}
	}


}*/
/*
double dv(double u, double v) {
	return u * (u / 2 + 1)*v*v*v + (u + 5 / 2)*v*v;
}

double Euler(double u0, double v0, double h, double n) {
	double u = u0, v = v0;
	cout << "-----------------" << endl;
	cout << "h = " << h << endl;
	cout << "Iteracao 0" << endl;
	cout << "u = " << u << endl;
	cout << "v= " << v << endl;
	for (int i = 0; i < n; i++) {
		v += dv(u, v)*h;
		u += h;

		cout << "Iteracao "<<i+1 << endl;
		cout << "u = " << u << endl;
		cout << "v= " << v << endl;
	}
	return v; 


}


int main() {
	
	cout << fixed;
	cout.precision(6);
	/*
	vector<vector<double>> v = { {1.1,1.4,2.6},{2.1,4.9,2.2},{6.3,1.5,1.2} };
	double h = 0.9*0.9; // hx*hy
	double res = Simpson(v, 3,h);
	cout << "res = " << res << endl;
	*/
	/*double x1_guess = 0.0, x2_guess = 0.0, x3_guess = 0.0, x4_guess = 0.0;
	gauss_seidel(x1_guess, x2_guess, x3_guess, x4_guess);*/
	/*double u0 = 1, v0 = 0.1;
	double s = Euler(u0, v0, 0.08, 10);
	double s1 = Euler(u0, v0, 0.04, 20);
	double s2 = Euler(u0, v0, 0.02, 40);
	double QC = (s1 - s) / (s2 - s1);
	double erro = s2 - s1;
	cout << "S = " << s << endl;
	cout << "S' = " << s1 << endl;
	cout << "S'' = " << s2 << endl;
	cout << "QC = " << QC << endl;
	cout << "Erro = " << erro << endl;
	return 0;
}
*/

double Simpson(vector<double> v, int n, double h) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		cout << i << endl;
		if (i % 2 == 0) {
			sum += 2 * v[i];
		}
		else {
			sum += 4 * v[i];
		}
	}
	sum += v[0] + v[n] ;
	sum *=(h/ 3.0);
	return sum; 
}

double rec_1(double x2, double x3, double x4) {
	return (1.00+x2+x3-x4) / 4.50;
}

double rec_2(double x1, double x3, double x4) {
	return (-1.0+x1-x3+x4) / 4.50;
}

double rec_3(double x1, double x2, double x4) {
	return (-1.0+x1-2*x2+x4) / 4.50;
}

double rec_4(double x1, double x2, double x3) {
	return (-2*x1 +x2+ x3) / 4.50;
}


void gauss_jacobi(double x1_guess, double x2_guess, double x3_guess, double x4_guess) {
	double x1 = rec_1(x2_guess, x3_guess, x4_guess);
	double x2 = rec_2(x1_guess, x3_guess, x4_guess);
	double x3 = rec_3(x1_guess, x2_guess, x4_guess);
	double x4 = rec_4(x1_guess, x2_guess, x3_guess);
	int it = 1;
	cout << "Iteracao " <<it<< endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	cout << "x4 = " << x4 << endl;
	while (abs(x1 - x1_guess) >= pow(10, -5) || abs(x2 - x2_guess) >= pow(10, -5) || abs(x3 - x3_guess) >= pow(10, -5) || abs(x4 - x4_guess) >= pow(10, -5)) {
		x1_guess = x1;
		x2_guess = x2;
		x3_guess = x3;
		x4_guess = x4;

		x1 = rec_1(x2_guess, x3_guess, x4_guess);
		x2 = rec_2(x1_guess, x3_guess, x4_guess);
		x3 = rec_3(x1_guess, x2_guess, x4_guess);
		x4 = rec_4(x1_guess, x2_guess, x3_guess);
		it++;
		cout << "Iteracao " << it << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
	}
}

double dT(double t, double T) {
	return -0.25*(T - 45);
}

void Euler(double t0, double T0, double h, double n) {
	double T = T0;
	double t = t0;

	for (int i = 0; i < n; i++) {
		cout << "Iteration " << i << endl;
		cout << "t = " << t<<endl;
		cout << "T = " << T<<endl;

		T += dT(t, T)*h;
		t += h;

	}

}

double dx(double t, double x) {
	return sin(2 * x) + sin(2 * t);
}


void rk4(double t0, double x0, double h, double n) {
	double d1, d2, d3, d4, deltax;
	double x = x0, t = t0;
	for (int i = 0; i < n; i++) {

		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "x = " << x << endl;


		d1 = h * dx(t, x);
		d2 = h * dx(t + h / 2.0, x + d1 / 2.0);
		d3 = h * dx(t + h / 2.0, x + d2 / 2.0);
		d4 = h * dx(t + h, x + d3);

		deltax = d1 / 6.0 + d2 / 3.0 + d3 / 3.0 + d4 / 6.0;
		x += deltax;
		t += h; 
	}
}


double L(double x) {
	return sqrt(1 + pow(1.5*exp(1.5*x), 2));
}

double Trapezios(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		sum += 2 * L(a + i * h);
	}
	sum += L(a) + L(b);
	sum *= (h / 2.0);
	return sum;
}

double Simpson(double a, double b, double h, int n) {
	double sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			sum += 2 * L(a + i * h);
		}
		else
			sum += 4 * L(a + i * h);
	}
	sum += L(a) + L(b);
	sum *= (h / 3.0);
	return sum; 
}

double dC(double T, double C) {
	return -exp(-0.10 / (T + 273))*C;
}

double DT(double T, double C) {
	return 15.0*exp(-0.10 / (T + 273))*C - 0.10*(T - 20.0);
}

double euler(double t0,double c0, double T0, double h,double n) {
	double t = t0, C = c0, T = T0, fC, fT;
	cout << "-------------------" << endl;
	cout << h << endl;
	cout << "Iteracao 0" << endl;
	cout << "C = " << C << endl;
	cout << "T = " << T << endl;
	for (int i = 0; i < n; i++) {
		fC = dC(T, C);
		fT = DT(T, C);

		C += h * fC;
		T += h * fT;
		t += h;
		cout << "Iteracao " << i+1 << endl;
		cout << "C = " << C << endl;	
		cout << "T = " << T << endl;
	}
	return C;
}
double rk4(double t0, double T0, double C0, double h, double n) {
	double t = t0, T = T0, C = C0;
	double c1,c2,c3,c4,t1,t2,t3,t4,deltaC, deltaT;
	cout << "Iteracao 0 " << endl;
	cout << "t = " << t << endl;
	cout << "T = " << T << endl;
	cout << "C = " << C << endl;

	for (int i = 0; i < n; i++) {

		c1 = h * dC(T, C);
		t1 = h * DT(T, C);

		c2 = h * dC(T + t1/2.0, C + c1 / 2.0);
		t2 = h * DT(T + t1/2.0, C + c1 / 2.0);

		c3 = h * dC(T + t2/2.0, C + c2/ 2.0);
		t3 = h * DT(T + t2/2.0, C + c2 / 2.0);

		c4 = h * dC(T + t3, C + c3);
		t4 = h * DT(T + t3, C + c3);

		deltaC = c1 / 6.0 + c2 / 3.0 + c3 / 3.0 + c4 / 6.0;
		deltaT = t1 / 6.0 + t2 / 3.0 + t3 / 3.0 + t4 / 6.0;
		 
		C += deltaC;
		T += deltaT;
		t += h;

		cout << "Iteracao "<<i+1 << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;
		cout << "C = " << C << endl;
	}
	return C;
}


int main() {
	cout << fixed;
	cout.precision(6);

	/*vector<double> v = { 0.36,1.19,1.32,0.21,1.15,1.39,0.12,1.22,0.6 };
	double h = 0.25;
	int n = (2-0)/h;
	double s = Simpson(v, n, h);
	cout << "S'' = " << s << endl;
	vector<double> v1 = { 0.36,1.32,1.15,0.12,0.6 };
	double h1 = 0.5;
	int n1 = (2-0)/h1;
	double s1 = Simpson(v1, n1, h1);
	cout << "S' = " << s1 << endl;
	vector<double> v2 = { 0.36,1.15,0.6 };
	double h2 = 1.0;
	int n2 = (2-0)/h2;
	double s2 = Simpson(v2, n2, h2);
	cout << "S = " << s2 << endl;
	double erro = (s - s1)/15.0;
	cout << "Erro = " << erro << endl;*/


	//gauss_jacobi(0.25, 0.25, 0.25, 0.25);
	//Euler(1,23,0.4,4);
	
	//rk4(1.0, 1.0, 0.125, 8);
	/*double res = Trapezios(0, 1, 0.25, 1 / 0.25);
	cout << "res = " << res << endl;
	double res2 = Simpson(0, 1, 0.25, 1 / 0.25);
	cout << "res 2 = " << res2 << endl; */

	double s0=euler(0.5, 2.0, 20.0, 0.25,2);
	double s1= euler(0.5, 2.0, 20.0, 0.125,4);
	double s2= euler(0.5, 2.0, 20.0, 0.0625,8);

	double QC = (s1 - s0) / (s2 - s1);
	double erro = s2 - s1;
	cout << "QC = " << QC << endl;
	cout << "erro = " << erro << endl;

	
	double res = rk4(0.5, 20.0, 2.0, 0.25, 2);


	return 0;

}









