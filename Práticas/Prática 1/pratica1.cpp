#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double j = exp(1)-1;
	cout << "Ano 1: "<< j<<endl;
	for (int i = 1; i < 26; i++) {
		j = j * i - 1;
		cout <<"Ano "<<i<<": " <<j<<endl;
	}
	return 0;
}
