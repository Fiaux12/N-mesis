/*Trabalho de  Algoritmos e Estruturas de Dados
Professora: Virgínia Mota

Participantes: 
Marcela Donata
Amanda Fiaux
Glaucus Miranda de Almeida
Luiz Eduardo Cordeiro Ribeiro

Trabalho de Grafo - Tema:Nêmesis

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //necessário para usar o INT_MAX, maior valor de um inteiro
#include <time.h>//necessário p/ função time()
#include "grafo.h"

//----------------------------------------------------------------------------------------------------------------------
//Funcoes de lista encadeada
Lista* lst_cria(){
    return NULL;
}

//----------------------------------------------------------------------------------------------------------------------
//Imprime o Labirinto para o jogador
void labirinto(){

	system("tput reset");

	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\033[38;2;52;235;189mSaida------1----------2----------3----------4----------5  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |                     |                     |  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |                     |                     |  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |                     |                     |  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |                     |                     |  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |                     |                     |  \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m6----------7----------8          9----------10---------11 \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |          |          |          |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |          |          |          |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |          |          |          |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |          |          |          |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|          |          |          |          |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m12---------13         14---------15         16----------17\033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|                     |                     |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|                     |                     |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|                     |                     |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|                     |                     |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m|                     |                     |             \033[m");
    printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189m18---------19---------20---------21         22----------Chegada\033[m");
}
	
//----------------------------------------------------------------------------------------------------------------------

//verifica se o vértice está incluido no caminho mínimo.
int minDistance(int dist[], int incluido[]){
    int min = INT_MAX, min_ver;
    //INT_MAX = valor máximo

    for (int v = 0; v < 24; v++){
        if (incluido[v] == 0 && dist[v] <= min){
            min = dist[v];
            min_ver = v;
        }
    }

   return min_ver;
}

//----------------------------------------------------------------------------------------------------------------------
//calcula o caminho minimo e retorna em um vetor com todos os vertices do caminho minimo do vértice 23 e o custos
int* dijkstra(int matriz[24][24], int *soma, int *tam){
    //Vértice inicial: 0
    //Vértice final: 23
    
    int dist[24]; // Guarda as todas as menores distâncias de 0 aos outros vertices
    int anterior[24]; // Guarda o vértice anterior de menor distância
    int incluido[24]; // Olha se o vértice está incluido no caminho mais curto, 0=não e 1=sim
    int aux=23;
    int *caminho; //Vetor que salva o caminho mínimo
    
    // Inicializa todas as distâncias como infinitas e incluido como 0

    for (int i=0; i<24; i++){
        dist[i]=INT_MAX;
        incluido[i]=0;
        anterior[i]=0;
    }

     // primeiro caminho tem distância 0 pois é o caminho de 0 até 0
    dist[0]=0;

    for(int count=0; count<24; count++){ //Calcula as distâncias mínimas para todos os vértices
        int u = minDistance(dist, incluido);
        incluido[u] = 1;

        for (int v=0; v<24; v++){
            if (!incluido[v] && matriz[u][v] && dist[u] != INT_MAX && dist[u]+matriz[u][v] < dist[v]){
                //ordem de menor para maior valor de dist, que vai acumulando valores
                dist[v] = dist[u] + matriz[u][v];
                anterior[v]=u; //Salva o vértice anterior de menor caminho até o atual
            }
        }
    }

    caminho=(int *) malloc((*tam) * sizeof(int));
    caminho[0]=23;

    //Coloca o caminho do vértice 23 ao 0 no vetor caminho
    while(anterior[aux]!=0){
        caminho[(*tam)-1]=anterior[aux];
            if(aux!=7 && aux!=12 && aux!=2){
                (*tam)++;
                caminho=(int *) realloc (caminho, (*tam) * sizeof(int));
            }
        aux=anterior[aux];
    }

    (*tam)++;
    caminho=(int *) realloc (caminho, (*tam) * sizeof(int));
    caminho[(*tam)-1]=0;

    *soma=dist[23]; //passa a distância mínima de 0 até 23 para soma
    
    return caminho;
}
//----------------------------------------------------------------------------------------------------------------------

//Grafo usando matriz de adjacencias orientado que conta o numero de vertices! :D
Lista* mons_aleato(Lista *monstros, int matriz[24][24]){

    /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
      com o valor da função time(NULL). Este por sua vez, é calculado
      como sendo o total de segundos passados desde 1 de janeiro de 1970
      até a data atual.
      Desta forma, a cada execução o valor da "semente" será diferente.
      */

    int a=0,b=0,y=0; // variaveis auxiliares
    Lista *p; // Lista auxiliar usada para nao perdermos o valor de monstros

    srand(time(NULL));//inicializar o gerador de números aleatórios

    //coloca dentro da matriz um numero de energia aleatoria de um monstro
    //que esta dentro da lista 'monstros' passando por cada elemento da matriz
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            if (matriz [i][j] != 0){

                b = rand() % 27; // gera o numero aleatorio
                a=0;
                p = monstros;
                y=0;

                //procura pelo endereço do monstro que vai para dentro da matriz
                // e coloca o valor da energia dele dentro da matriz
                for (; p != NULL; p = p->prox ){
                    if (y == b){
                        matriz[i][j] = p->energia;
                        matriz[j][i] = p->energia;
                    }
                    y++;
                }
            }
        }
    }

    return monstros;
}
//----------------------------------------------------------------------------------------------------------------------

Lista* insere(Lista *monstros, char i[], int ener){

    //Insere os monstros e suas energias dentro da lista de struct
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    strcpy(novo->monstro,i);
	novo->energia = ener;
    novo->prox = monstros;

    return novo;
}
//----------------------------------------------------------------------------------------------------------------------

Lista* monst(Lista *monstros){

    // coloca os monstros dentro da lista 'monstros'

    Lista *p;
    char v[50];

    strcpy(v, "Hidra");// copia o a palavra 'Hidra' para dentro da string 'v'
    monstros = insere(monstros, v, 200);// passa pra funcao o valor da energia e o nome do
                                        //monstro que sera inserido
    strcpy(v, "Esfinge");
    monstros = insere(monstros, v, 80);

    strcpy(v, "Cerbero");
    monstros = insere(monstros, v, 140);

    strcpy(v, "Quimera");
    monstros = insere(monstros, v, 70);

    strcpy(v, "Furias");
    monstros = insere(monstros, v, 20);

    strcpy(v, "Ciclope");
    monstros = insere(monstros, v, 30);

    strcpy(v, "Medusa");
    monstros = insere(monstros, v, 550);

    strcpy(v, "Gargola");
    monstros = insere(monstros, v, 45);

    strcpy(v, "Iete");
    monstros = insere(monstros, v, 25);

    strcpy(v, "Palhaço Assasino");
    monstros = insere(monstros, v, 9);

    strcpy(v, "Troll");
    monstros = insere(monstros, v, 15);

    strcpy(v, "Cthulhu");
    monstros = insere(monstros, v, 800);

    strcpy(v, "Dragao");
    monstros = insere(monstros, v, 1000);

    strcpy(v, "Lich");
    monstros = insere(monstros, v, 350);

    strcpy(v, "Porco Aranha");
    monstros = insere(monstros, v, 10);

    strcpy(v, "Pedra no Caminho");
    monstros = insere(monstros, v, 1);

    strcpy(v, "Nazgol");
    monstros = insere(monstros, v, 250);

    strcpy(v, "Vampiro");
    monstros = insere(monstros, v, 57);

    strcpy(v, "Fenrir");
    monstros = insere(monstros, v, 657);

    strcpy(v, "Fantasma");
    monstros = insere(monstros, v, 60);

    strcpy(v, "Teia de Aranha");
    monstros = insere(monstros, v, 5);

    strcpy(v, "Esqueleto");
    monstros = insere(monstros, v, 89);

    strcpy(v, "Godzilla");
    monstros = insere(monstros, v, 600);

    strcpy(v, "Minotauro");
    monstros = insere(monstros, v, 900);

    strcpy(v, "Leao da Nemeia");
    monstros = insere(monstros, v, 65);

    strcpy(v, "Surt");
    monstros = insere(monstros, v, 256);

    strcpy(v, "Vaca");
    monstros = insere(monstros, v, 12);

    strcpy(v, "Equidna");
    monstros = insere(monstros, v, 1500);

    strcpy(v, "Tifão");
    monstros = insere(monstros, v, 2000);

    strcpy(v, "Cão Ortro");
    monstros = insere(monstros, v, 100);

    strcpy(v, "Caríbdis");
    monstros = insere(monstros, v, 400);

	strcpy(v, "Ethon");
    monstros = insere(monstros, v, 22);

    strcpy(v, "Hecatônquiro");
    monstros = insere(monstros, v, 1300);

    strcpy(v, "Sátiro");
    monstros = insere(monstros, v, 62);

    strcpy(v, "Basilísco");
    monstros = insere(monstros, v, 32);

    strcpy(v, "Goblin");
    monstros = insere(monstros, v, 40);

    strcpy(v, "Mantícora");
    monstros = insere(monstros, v, 37);

    strcpy(v, "Súcubo");
    monstros = insere(monstros, v, 75);

    strcpy(v, "Harpias");
    monstros = insere(monstros, v, 26);

    strcpy(v, "Unicórnio");
    monstros = insere(monstros, v, 42);

    strcpy(v, "Estalagmite");
    monstros = insere(monstros, v, 9);

    strcpy(v, "Estalagtite");
    monstros = insere(monstros, v, 11);

    strcpy(v, "Goteira");
    monstros = insere(monstros, v, 2);

    strcpy(v, "Bolsominion");
    monstros = insere(monstros, v, 17);

    strcpy(v, "Grendel");
    monstros = insere(monstros, v, 53);

    strcpy(v, "Kappa");
    monstros = insere(monstros, v, 21);

     strcpy(v, "Serpente");
    monstros = insere(monstros, v, 8);

    strcpy(v, "Scylla");
    monstros = insere(monstros, v, 35);

    strcpy(v, "Empusa");
    monstros = insere(monstros, v, 130);

    strcpy(v, "Demônio");
    monstros = insere(monstros, v, 460);

    return monstros;
}
//----------------------------------------------------------------------------------------------------------------------
int jogar(int matriz[24][24], Lista *monstros){
    Lista *p;
    int op[4]; //Salva os vértices alcançaveis a partir do que está 
    int cont=0; //cont guarda número de caminhos possíveis a partir do vértice em que está
    int resp; //Guarda o número que o usuário digitar 
    int y=0; //Tamanho do caminho
    int *caminho=NULL; //Guarda o caminho percorrido pelo usuário
    int custoj=0; //Soma das arestas percorridas pelo usuário

    labirinto(); //Imprime o grafo

    for(int i=0; i<24; i++){

        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\033[38;2;52;235;189mVocê está no vértice %i\n\033[m", i);

        caminho=(int *) realloc (caminho, (y+1) * sizeof(int));
		caminho[y]=i;
        y++;

        for(int i=0; i<4; i++){
            op[i]=0;
        }

        //Guarda os vértices acessíveis do vértice em que está
        for(int j=0; j<24; j++){
                if(matriz[i][j]!=0){
                    op[cont]=j;
                    cont++;
                }
        }
            printf("\n\t\t\t\t\t\t\t\033[38;2;52;235;189mEscolha um caminho, ou digite '-1' para desistir:\n\n\033[m");
            
            for(int i=0; i<cont ; i++){
                printf("\t\t\t\t\t\t\t\033[38;2;52;235;189m%i\n\033[m", op[i]);
            }

            printf("\n\t\t\t\t\t\t\t\t\t\033[38;2;52;235;189m-----Resposta-----\t\n\033[m");
            printf("\t\t\t\t\t\t\t\t\t\033[38;2;200;45;36m->\033[m");
            scanf("%i", &resp);

            if(resp == -1){ //Se o usuário desistir
                custoj=0;
                return custoj;
            }else if(op[0]!=resp && op[1]!=resp && op[2]!=resp && op[3]!=resp){ //Se o usuário digitar um caminho indisponível
                while(op[0]!=resp && op[1]!=resp && op[2]!=resp && op[3]!=resp){ //Loop até que o usuário escolha um caminho
                    printf("\t\t\t\t\t\t\t\t\033[38;2;200;45;36mDigite um numero dentre os acima!!!\n\033[m");
                    printf("\n\t\t\t\t\t\t\t\t\t\033[38;2;200;45;36m->\033[m");
                    scanf("%i", &resp);
                        if(resp == -1){ //Se o usuário desistir
                            custoj=0;
                            system("tput reset");
                            return custoj;
                        }
                }
                cont=0;
                for(p = monstros; p != NULL ; p=p->prox){
                    if(p->energia==matriz[i][resp]){ //Acha o monstro de onde ele está indo
                    	custoj=custoj + matriz[i][resp]; //Soma ao custo do caminho
                		i=resp-1;
                    	labirinto();
                        printf("\n\n\t\t\t\t\t\t\t\t\033[38;2;255;255;0mVocê se depara com %s no seu caminho!\033[m",p->monstro);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\033[38;2;255;255;0mQue gasta %i da sua energia!\n\n\033[m", p->energia);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\033[38;2;156;15;216mEnergia -> %i \n\n\033[m", custoj);
						break;
					}
                }
            }else{ //Se o usuário escolher um dos caminhos disponíveis
                cont=0;
                for(p = monstros; p != NULL ; p=p->prox){
                    if(p->energia==matriz[i][resp]){ //Acha o monstro de onde ele está indo
                    	custoj=custoj + matriz[i][resp]; //Soma ao custo do caminho
                        labirinto();
                        printf("\n\n\t\t\t\t\t\t\t\t\033[38;2;255;255;0mVocê se depara com %s no seu caminho!\033[m",p->monstro);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\033[38;2;255;255;0mQue gasta %i da sua energia!\n\n\033[m", p->energia);
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\033[38;2;156;15;216mEnergia -> %i \n\n\033[m", custoj);
                        if(resp!=23){
                		    i=resp-1;
                        }else{ //Se chegar no último vértice
                            caminho=(int *) realloc (caminho, (y+1) * sizeof(int));
                            caminho[y]=23;
                            y++;
                            i=24;
                        }
						break;
					}
                }  
            }
                 
    }

    //Imprime o caminho percorrido
	if(custoj!=0){
		printf("\n\n\t\t\t\t\t\t\t\033[38;2;255;255;0mVocê percorreu o caminho:\n\033[m");
		printf("\n\t\t\t\t\t\t\t\033[38;2;15;216;21m-> \033[m");
		for(int i=0; i<y; i++){
			printf("\033[38;2;242;139;48m%i-\033[m", caminho[i]);
		}
		printf("\n\n");
	}

return custoj;
}
