#include<iostream>
using namespace std; //C�digo O(2^N)

int fib (int n)
{
	if(n == 0 || n == 1) //condi��o de parada
		return 1;
	else if (n > 1)
		return fib(n - 1) + fib (n - 2); // Chamando a fun��o novamente
}
int main()
{
	int n;

	cin >> n;

	cout <<	fib (n) << " "; // chamando a fun��o e apresentando o fibonacci

	return 0;
}
