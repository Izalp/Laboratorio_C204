#include<iostream>
using namespace std;

void troca(int &X, int &Y) // Fun��o para troca os valores de x e y
{
	int aux = 0; // var aux para realizar a troca
	
	aux = X; // armazenando valor de x em aux
	X = Y; // armazenando valor de y em x
	Y = aux; // armazenando valor de aux em y 
}
int main()
{
	int X,Y; // numeros a serem inseridos
	
	cin >> X >> Y; // fazendo leitura dos n�meros
	
	troca(X,Y); // chamando a fun��o
	
	cout << X << " " << Y << endl; // apresentando x e y

	return 0;
}
