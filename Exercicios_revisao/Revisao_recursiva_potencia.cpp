#include<iostream>
using namespace std; 

int pot (int a, int n) // fun��o potencia
{
	if(n == 0) //condi��o de parada
		return 1;
	else 
		return a * pot(a,n-1); // Chamando a fun��o novamente
}
int main()
{
	int n; // expoente
	int a; // base
	int res; // var para armazenar o retorno da fun��o

	cin >> a >> n;

	res = pot(a, n);
	
	cout <<	res << endl; // apresentando o resultado

	return 0;
}