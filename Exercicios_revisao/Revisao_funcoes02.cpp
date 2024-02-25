#include<iostream>
using namespace std;

int sinal(int n) // Fun��o para verificar se o n�mero � positivo, negativo ou zero:
{
	// Verifica��o se o numero � positivo, negativo ou zero
	if(n > 0) 
		return 1; // retorna 1 = positivo
	else if (n < 0)
		return -1; // retorna -1 = negativo
	else 
		return 0; // retorna 0 = zero
}
int main()
{
	int n; // numero a ser verificado
	int res; // variavel para armazenar o retorno da fun��o "sinal"

	//Fazer leitura do n�mero:
	cin >> n;

	res = sinal(n); // Chamar a fun��o "sinal"

	//Apresentar o resultado de acordo com o respectivo retorno da fun��o:
	if (res == 1)
		cout << "Positivo" << endl;
	else if (res == -1)
		cout << "Negativo" << endl;
	else
		cout << "Zero" << endl;
	
	return 0;
}
