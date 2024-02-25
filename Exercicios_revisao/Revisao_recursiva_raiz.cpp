#include <iostream>
#include <iomanip> // biblioteca precis�o de casas decimais
#include <cmath> // biblioteca calculo complexo

using namespace std;

float raiz(double x, double x0, double e) // sintaxe da fun��o raiz - recursiva
{
	if(abs(pow(x0,2)-x) <= e) // condi��o de parada
		return x0;
	else // chamada recursiva
		return raiz(x,((pow(x0,2)+x)/(2*x0)),e); // chamar a fun��o de acordo com o retorno
}
int main()
{
	double x; // variavel n�mero do qual se quer calcular a raiz
	double x0; // variavel estimativa inicial para a raiz de x
	double e; // variavel limitante superior para o erro
	double total; // variavel para receber o retorno da fun��o

	cin >> x >> x0 >> e; // Ler as variaveis

	total = raiz(x,x0,e); // Chamar a fun��o

	cout << fixed << setprecision(4);
	cout << total << endl; // Mostrar o resultado com duas casas decimais

	return 0;
}