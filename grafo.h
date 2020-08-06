/*Trabalho de  Algoritmos e Estruturas de Dados
Professora: Virgínia Mota

Participantes: 
Marcela Donata
Amanda Fiaux
Glaucus Miranda de Almeida
Luiz Eduardo Cordeiro Ribeiro

Trabalho de Grafo - Tema:Nêmesis

*/

/*definindo lista encadeada*/

struct lista{
    int info;
    char monstro[50];
    int energia;
    struct lista *prox;
};

typedef struct lista Lista;

/*definindo lista duplamente encadeada*/
struct lista2{
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
};

typedef struct lista2 Lista2;

Lista* lst_cria();
int minDistance(int dist[], int incluido[]);
int* dijkstra(int matriz[24][24], int *soma, int *tam);
Lista* mons_aleato(Lista *monstros, int matriz[24][24]);
Lista* insere(Lista *monstros, char i[], int ener);
Lista* monst(Lista *monstros);
int jogar(int matriz[24][24], Lista *monstros);