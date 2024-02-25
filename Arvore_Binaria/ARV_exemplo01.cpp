#include<iostream>
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
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL;
	else	if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub �arvore esquerda
		return tPesq(p->esq, x);
	else             // procura na sub �arvore direita
		return tPesq(p->dir, x);
}
int main()
{
	int n; // quantidade de elementos
	int x; // elementos a serem inseridos na arvore
	int procurado; // elemento a ser procurado
	int i; // contador

	treenodeptr arvore = NULL; // ponteiro para a ra�z da arvore
	treenodeptr p = NULL;

	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> x;
		tInsere(arvore, x);
	}
	
	cin >> procurado;
	
	p = tPesq(arvore, procurado);

	if(p == NULL)
		cout << "Nao encontrado" << endl;
	else
		cout << "Encontrado" << endl;

	return 0;
}
