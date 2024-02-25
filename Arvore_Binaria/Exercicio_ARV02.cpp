#include<iostream>
#include<list> // Biblioteca para listas
#include<iomanip>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else             // insere na subarvore direita
		tInsere(p->dir, x);
}
void tDestruir (treenodeptr &arvore) // Fun��o para destruir a arvore
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}
//Realiza um percurso em n�vel na �rvore
void emNivel(treenodeptr arvore, int &soma)
{
	treenodeptr n; // ponteiro de arvore aux
	list<treenodeptr> q; // lista aux

	if (arvore != NULL) // se o n� da arvore n�o estiver vazio
	{
		q.push_back (arvore); // listando a arvore
		while (!q.empty())
		{
			n = *q.begin();
			q.pop_front(); // retira o primeiro n� da lista
			if (n->esq != NULL) // se o n� esquerdo for diferente de NULL
				q.push_back(n->esq); // colocando o n� como ultimo da fila
			if (n->dir != NULL) // se o n� direito for diferente de NULL
				q.push_back(n->dir); // colocando o n� como ultimo da fila
			soma = soma + n->info; // apresentando o percruso em n�vel
		}
	}
}
void Ordemprim (treenodeptr arvore, int &n) // Fun��o que verificar� se h� numeros primos na arvore
{
	if (arvore != NULL)
	{
	    // condi��o para numeros n�o primos
		if (arvore->info % 2 != 0 && arvore->info % 3 != 0 && arvore->info % 5 != 0 && arvore->info % 7 != 0 ) // condi��o para numeros n�o primos
			n++;
        // condi��o para numeros primos
		else if (arvore->info == 1 || arvore->info == 2 || arvore->info == 3 || arvore->info == 5 || arvore->info == 7) 
			n++; // contando numeros primos
		Ordemprim(arvore->esq, n);
		Ordemprim(arvore->dir, n);
	}
}
int contaPrimos(treenodeptr arvore) // Fun��o que contar� quantidade de n�meros primos na arvore
{
	int n = 0; // contador iniciado em zero
	Ordemprim(arvore, n); // chamando fun��o que ir� verificar se h� numeros primos na arvore

	return n; // retornar� a quantidade de numeros primos presentes na arvore
}
int main()
{
    //FAZER UM CODIGO QUE FA�A PERCURSO EM NIVEL
    // MEDIA DOS ELEMENTOS E VERIFICA A QUANTIDADE DE PRIMOS
	
	treenodeptr arvore = NULL;
	int n;
	int m = 0;
	int soma = 0;
	int primos;
	float media;

	cin >> n;
	
	while(n != -1)
	{
		tInsere(arvore,n);
		m++;
		cin >> n;
	}
	emNivel(arvore,soma);
	
	media = (1.0 * soma) / m;
	
	primos = contaPrimos(arvore);
	
	cout << fixed << setprecision(2);
	cout << "Media: " << media << endl;
	cout << "Quantidade de primos: " << primos << endl;

	tDestruir(arvore);

	return 0;
}
