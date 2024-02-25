#include<iostream>
#include<cstring>
using namespace std;

struct dados //struct para armazenar nome e pontu��o de cada atleta
{
	char nome[100];
	int n1;
	int n2;
	int n3;
	int n4;
};
int strongest(dados atletas[], int nAtletas) // fun��o para calcular a pontua��o de cada atleta
{
	int i; // contador
	int soma = 0; // var para calcular a potua��o

	for(i = 0; i < nAtletas; i++)
		soma = atletas[i].n1 + atletas[i].n2 + atletas[i].n3 + atletas[i].n4;

	return soma;
}
int main()
{
	dados atletas [1000]; //struct para armazenar nome e pontu��o de cada atleta
	int n; // quant de atletas
	int i; // contador
	int pont; // var aux apara armazenar retorno da fun��o
	int maior = 0; // var aux para verirficar qual atleta tem maior pontua��o
	char vencedor [100]; // var aux para armazenar o nome do atleta vencedor

	cin >> n; // lendo a quant de atletas

	for(i = 0; i < n; i++) // lendo o nome de cada atleta e sua pontua��o
	{
		cin.ignore();
		cin.getline(atletas[i].nome, 100);
		cin >> atletas[i].n1 >> atletas[i].n2 >> atletas[i].n3 >> atletas[i].n4;

		pont = strongest(atletas, n); // chamando a fun��o


		if (pont > maior) // verificando quem � o vencedor
			strcpy(vencedor, atletas[i].nome);
	}

	cout << "Vencedor: " << vencedor << endl; // apresentando o nome do vencedor

	return 0;
}


4
Eddie Hall
70 85 92 67
Brian Shaw
72 87 99 85
Zydrunas Savickas
77 85 45 94
Hafbor Julius Bjornsson
98 77 99 95