#include<iostream>
#include<cmath>
using namespace std;

int calc_a(int x) // Fun��o para calcular a
{
	int a;
	
	a = ((2 * pow(x, 2)) + (3 * x) - 1);

	return a; // retornando valor de a
}
int calc_b(int x) // Fun��o para calcular b
{
	int b;
	
	b = pow(x, 3);

	return b; // retornando valor de b
}
int calc_c(int y) // Fun��o para calcular c
{
	int c;
	
	c = pow(y, 3);

	return c; // retornando valor de c
}
int main()
{
	int a, b, c, x, y;

	cin >> x >> y; // fazendo a leitura de 2 numeros

	a = calc_a (x); // chamando a fun��o a
	cout << "a = " << a << endl;

	b = calc_b(x); // chamando a fun��o b
	cout << "b = " << b << endl;

	c = calc_c (y); // chamando a fun��o c
	cout << "c = " << c << endl;

	return 0;
}
