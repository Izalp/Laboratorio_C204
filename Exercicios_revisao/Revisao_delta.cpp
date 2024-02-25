#include<iostream>
#include<cmath>
using namespace std;

float calc_delta(float a, float b, float c) // fun��o para calcular delta
{
	float res;

	res = (pow(b, 2) - (4 * a * c)); // calculando delta

	return res; // retornando o valor de delta
}
int main()
{
	float x, y, z;
	float delta;

	cin >> x >> y >> z; // fazendo a leitura dos dados

	if (x != 0) // garantindo que a n�o seja zero
		delta = calc_delta(x, y, z); // chamando a fun��o

	cout << "delta = " << delta << endl; // apresentando o resultado

	return 0;
}
