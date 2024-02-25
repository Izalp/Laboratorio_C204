#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float calc_raizes(float a, float b, float c, float &x1, float &x2) // fun��o para calcular raizes
{
	float delta;

	delta = (pow(b, 2) - (4 * a * c)); // calculando delta

	if(delta >= 0) // se delta for positivo ou igual a zero, existe raizes reais
	{
		x1 = ((- b - sqrt(delta)) / (2 * a));
		x2 = ((- b + sqrt(delta)) / (2 * a));

		return 0; // retorna zero se houver raizes reais
	}
	else
		return 1; // retorna um se n�o houver raizes reais
}
int main()
{
	float a, b, c;
	float x1, x2;
	float total;

	cin >> a >> b >> c; // fazendo a leitura dos dados

	if (a != 0)  // garantindo que a n�o seja zero
	{
		total = calc_raizes(a, b, c, x1, x2); // chamando a fun��o

		if (total == 0) // verificando se existe raizes reais
		{
			if (x1 == x2) // se delta for zero, as raizes x1 e x2 ter�o o valor de zero tambem
				cout << "x = " << x2 << endl;

			else if (x1 > x2 || x1 < x2) // se delta for maior que zero, as raizes reais ter�o valores distintos
			{
				cout << fixed << setprecision (2); // apresentando o resusltado com duas casas decimais
				cout << "x1 = " << x1 << endl;
				cout << "x2 = " << x2 << endl;
			}
		}
		else // se delta for negativo, logo n�o haver� raizes reais
			cout << "Nao ha raizes reais" << endl;

		return 0;
	}
}
