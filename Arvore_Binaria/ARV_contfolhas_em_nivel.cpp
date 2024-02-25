#include<iostream>
#include<list> // Biblioteca para listas

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
void emNivel(treenodeptr t)
{
	treenodeptr n = t; // ponteiro para varrer a arvore
	list<treenodeptr> q; // fila auxilar

	if (t != NULL) // se o n� da arvore n�o estiver vazio
	{
		q.push_front (n); // listando a arvore
		while (!q.empty())
		{
			n = q.front(); 
			q.pop_front(); // retira o primeiro n� da fila
			if (n->esq != NULL) // se o n� esquerdo for diferente de NULL
				q.push_back(n->esq); // colocando o n� como ultimo da fila
			if (n->dir != NULL) // se o n� direito for diferente de NULL
				q.push_back(n->dir); // colocando o n� como ultimo da fila
		}
	}
}
void contaFolha (treenodeptr arvore, float &folha_return, int &aux) // Fun��o para contar folhas
{
    if (arvore != NULL)
	{
		aux = 0; 
		contaFolha(arvore->esq, folha_return, aux); 
		contaFolha(arvore->dir, folha_return, aux);
		if(aux == 2) // se aux for igual a 2, ou seja, quando o elemento n�o tiver filhos (2 NULL)
		{
			folha_return++; // conta quantidade de folhas
			aux = 0; 
		}
	}
	else
		aux++; // contando a quantidade de vazios (NULL) na arvore
}
float contaFolhas (treenodeptr arvore) // Fun��o para realizar contagem das folhas da arvore
{
    int aux;  // var pra auxiliar na contagem de folhas da arvore
    float folha_return = 0; // var para armazenar a quantidade de folhas presentes na arvore
    
    emNivel(arvore); // chamando a fun��o que ir� realizar o percurso em n�vel
    contaFolha (arvore, folha_return, aux); // chamando fun��o para contar folhas
	
	return folha_return;
}
int main()
{
	treenodeptr arvore = NULL; // ponteiro para a ra�z da arvore
	int n; // quantidade de elementos
	float folha; // var para armazenar a quantidade de folhas presentes na arvore

	// Realizando a leitura da quantidade de elementos a serem inseridos na arvore
	cin >> n;

	while(n != -1) // Inserindo elementos diferentes de -1 na arvore
	{
		tInsere(arvore, n);
		cin >> n;
	}

	folha = contaFolhas(arvore); // chamando a fun��o que ir� contar a quantidade de folhas
	
	// Apresentando a quantidade de folhas
	cout << folha << endl;

	tDestruir(arvore); // chamando a fun��o que ir� destruir a arvore
	
	return 0;
}
