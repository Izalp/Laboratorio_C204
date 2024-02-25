#include<iostream>
#include<list>
using namespace std;

struct treenode // struct para armazenar a arvore
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr;

void tInsere(treenodeptr &p, int x) // fun��o para inserir os elementos na arvore
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode; // ponteiro para arvore
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda, se o valor for menor que a raiz
		tInsere(p->esq, x);
	else             // insere na subarvore direita, se o valor for maior que a raiz
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
void emNivel(treenodeptr t)
{
	treenodeptr n; // ponteiro de arvore aux
	list<treenodeptr> q; // lista aux

	if (t != NULL) // se o n� da arvore n�o estiver vazio
	{
		q.push_back (t); // listando a arvore
		while (!q.empty())
		{
			n = *q.begin(); 
			q.pop_front(); // retira o primeiro n� da lista
			if (n->esq != NULL) // se o n� esquerdo for diferente de NULL
				q.push_back(n->esq); // colocando o n� como ultimo da fila
			if (n->dir != NULL) // se o n� direito for diferente de NULL
				q.push_back(n->dir); // colocando o n� como ultimo da fila
			cout << n->info << " "; // apresentando o percruso em n�vel
		}
	}
}
int main()
{
	treenodeptr arvore = NULL;
	int n, m, x;
	int i = 0;
	int j = 0;

	cin >> n;

	while(n != i)
	{
		cin >> m;

		while (m != j)
		{
			cin >> x;
			tInsere(arvore, x);
			j++;
		}
		j = 0;
		
		i++;
		
		cout << "Case " << i << " :" << endl;
		emNivel(arvore);
		
		tDestruir(arvore);
	}
	
	return 0;
}

