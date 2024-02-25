/// ALOCA��O DIN�MICA - ANOTA��ES


// ALOCA��O EM STRUCT:

*** Tem uma struct com os dados. 

EX: struct dado

*** Na int main(): (NOME DA struct) *(NOME DO PONTEIRO) = NULL;

EX: dado *total = NULL; // ponteiro para a struct

*** Alocando a memoria: ponteiro = new (nome da struct);

EX: total = new dado; // alocando mem�ria

*** NO cin: ponteiro -> (dado da struct);

EX: cin >> total->nota1;

*** No final da int main(): delete ponteiro;

EX: delete total;



// ALOCA��O EM VETOR DE STRUCT:

*** Tem uma struct com os dados. 

EX: struct dado

*** Na int main(): (NOME DA struct) *(NOME DO PONTEIRO);

EX: dado *total; // ponteiro para a struct

*** Entrar com o tamanho do vetor: cin >> n;

*** Alocando a memoria: ponteiro = new (nome da struct)[tamanho do vetor];

EX: total = new dado [n]; // alocando mem�ria

*** NO cin: ponteiro[i].(dado da struct);

EX: cin >> total[i].nota1;

*** No final da int main(): delete [] ponteiro;

EX: delete [] total;



// ALOCA��O EM VETOR:

*** "N�O TEM STRUCT!!!!!!!"

*** Na int main(): (tipo do vetor) *(NOME DO vetor) = NULL;

EX: int *vetor = NULL; // ponteiro para a struct

*** Entrar com o tamanho do vetor: cin >> n;

*** Alocando a memoria: (nome do vetor) = new (tipo do vetor )[tamanho do vetor];

EX: total = new int [n]; // alocando mem�ria

*** NO cin: vetor[i]   EX: cin >> vetor[i];

*** No final da int main(): delete [] vetor;
