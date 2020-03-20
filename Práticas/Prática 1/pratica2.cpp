#include<iostream>
#include<math.h>


using namespace std;

/*int main() {
	for ( double i = 1; i <= 20; i++) {
		cout<<"y("<<i<<")= " << exp(i) << endl<<endl;
	}



	return 0;
}*/


/*int main() {
	for (double i = 1; i <20.1; i += 0.1) {
		cout << "y(" << i << ")= " << exp(i) << endl << endl;
	}



	return 0;
}*/


/*int main() {
	double x1 = 1, x2= 1, step=1, y1,y2;

	while (x1 <= 20) {
		x1 = x1 + step;
		y1 = exp(x1);
	}
	step = 0.1;
	while (x2 <= 20) {
		x2 = x2 + step;
		y2 = exp(x2);
	}
	cout<< "y(" << x1 << ") = " << y1 << endl << endl;
	cout << "y(" << x2 << ") = " << y2 << endl << endl;
	if (y1 == y2) {
		cout << "Awesome" << endl;
	}
	else {
		cout << "Fail" << endl;
	}

	if (x1 == x2) {
		cout << "x1==x2? True" << endl;
	}
	else {
		cout << "x1==x2? False" << endl;
	}
	cout << x1 << endl;
	cout << x2 << endl;

	return 0;
}*/


/*int main() {


	float estimation = 1, a;

	cout << " Number :";
	cin >> a;

	for (int i = 0; i < 20; i++) {
		estimation = (estimation + (a / estimation)) / 2;
	}

	cout << "Square root of " << a << " is " << estimation << endl;

	return 0;
}*/

int main() {
	double x = 453;
	double xhi = x;
	double xlo = 0;
	double guess = x / 2;

	while (guess*guess != x) {
		if (guess*guess > x) {
			xhi = guess;
		}
		else xlo = guess;
		double new_guess = (xhi + xlo) /2;
		if (new_guess == guess)
			break;// not getting closer
		guess = new_guess;
	}
	cout << "Square root of " << x << " is " << guess;
	return 0;

}
