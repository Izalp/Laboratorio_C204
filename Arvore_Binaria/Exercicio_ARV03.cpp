#include <iostream>
#include <list> // Biblioteca para lista

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
void prelist(treenodeptr arvore, list<int> &m) // Inserindo na lista os elementos de acordo com a respectiva ordem
{
	if (arvore != NULL)
	{
		m.push_back(arvore->info);
		prelist(arvore->esq, m);
		prelist(arvore->dir, m);
	}
}
void emlist(treenodeptr arvore, list<int> &m)  // Inserindo na lista os elementos de acordo com a respectiva ordem
{
	if (arvore != NULL)
	{
		emlist(arvore->esq, m);
		m.push_back(arvore->info);
		emlist(arvore->dir, m);
	}
}
void poslist(treenodeptr arvore, list<int> &m)  // Inserindo na lista os elementos de acordo com a respectiva ordem
{
	if (arvore != NULL)
	{
		poslist(arvore->esq, m);
		poslist(arvore->dir, m);
		m.push_back(arvore->info);
	}
}
int main()
{
	treenodeptr arvore = NULL; // Ponteiro para a raiz da �rvore
	int n = 0;                 // Valor a ser inserido
	int c;                     // Cidade a ser buscada
	int dpre = 0;      // Dist�ncia entre os n�s da preOrdem
	int dem = 0;       // Dist�ncia entre os n�s da emOrdem
	int dpos = 0;      // Dist�ncia entre os n�s da posOrdem

	// Realizar preOrdem, emOrdem e posOrdem e verificar qual � a cidade mais pr�xima
	list<int> lista_pre;
	list<int> lista_em;
	list<int> lista_pos;
	list<int>::iterator p;

	cin >> n;

	while (n != -1) // Inserindo elementos diferentes de -1 na arvore
	{
		tInsere(arvore, n);
		cin >> n;
	}

	cin >> c; // Inserindo cidade desejada

	prelist(arvore, lista_pre); // Fun��o que armazena na lista em pr� ordem
	emlist(arvore, lista_em); // Fun��o que armazena na lista em ordem
	poslist(arvore, lista_pos); // Fun��o que armazena na lista em p�s ordem

	// Define distancia ate a cidade partindo de:
	for (p = lista_pre.begin(); p != lista_pre.end(); p++) // Pre ordem
	{
		dpre++;
		if (*p == c)
			break;
	}
	for (p = lista_em.begin(); p != lista_em.end(); p++) // Em ordem
	{
		dem++;
		if (*p == c)
			break;
	}
	for (p = lista_pos.begin(); p != lista_pos.end(); p++) // P�s ordem
	{
		dpos++;
		if (*p == c)
			break;
	}

	// imprimir qual m�todo de busca foi mais r�pido
	if (dpre < dem && dpre < dpos)
		cout << "Pre" << endl;
	else if (dem < dpre && dem < dpos)
		cout << "Em" << endl;
	else
		cout << "Pos" << endl;

	tDestruir(arvore); // chamando a fun��o que ir� destruir a arvore

	return 0;
}
