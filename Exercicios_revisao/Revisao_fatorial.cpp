#include<iostream>
using namespace std; //C�digo O(n)

int fatorial (int n)
{
	if(n == 0) //condi��o de parada
		return 1;
	else
		return n * fatorial(n - 1); // Chamando a fun��o novamente
}
int main()
{
	int n;

	cin >> n;

	cout <<	fatorial (n) << " "; // chamando a fun��o e apresentando o fatorial

	return 0;
}
