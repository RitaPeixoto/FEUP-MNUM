#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
/*Nao vou resolver o exercicio 2 porque é identico a outros testes e o 4 que é identico ao nosso teste 2
o n de x e y é 2 porque se divide o quadrado em dois no x e dois no y

*/

int main() {
	double sum = 0;
	vector<vector<double>> v = {{1.1,1.4,2.6},{2.1,4.9,2.2},{6.3,1.5,1.2}};
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if ((i == 0 || i == v.size() - 1) && (j == 0 || j == v.size() - 1)) {//vertices
				sum += v[i][j];
			}
			else if(i == 0 || i == v.size() - 1||j == 0 || j == v.size() - 1){//pontos intermedios
				sum += 4 * v[i][j];

			}
			else {//ponto central
				sum += 16 * v[i][j];
			}
		}
	}


	double hx = (1.8 - 0) / 2.0;
	double hy = (1.8 - 0) / 2.0;
	double h = hx * hy;

	sum *= (h/ 9.0);
	cout << "Sum: " << sum;
	return 0;
}