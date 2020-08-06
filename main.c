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
#include <limits.h>
#include <time.h>//necessário p/ função time()
#include "grafo.h"

int main(){ 
    system("tput reset");

    Lista *monstros = lst_cria();  //Salva os monstros
    Lista *p;
    int matriz[24][24], i ,j; //Matriz do nosso grafo
    int soma=0, *caminho2, tam=2; //Variaveis modificadas no Dijkstra
    int l = 0, op, custoj;

    //Iguala todas as arestas igual a 0
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            matriz[j][i]=0;
        }
    }

    //Define os vertices existentes
    matriz [0][1]=1;
    matriz [0][6]=1;

    matriz [1][0]=1;
    matriz [1][2]=1;
    matriz [1][7]=1;

    matriz [2][1]=1;
    matriz [2][3]=1;

    matriz [3][2]=1;
    matriz [3][4]=1;
    matriz [3][9]=1;

    matriz [4][3]=1;
    matriz [4][5]=1;

    matriz [5][4]=1;
    matriz [5][11]=1;

    matriz [6][0]=1;
    matriz [6][7]=1;
    matriz [6][12]=1;

    matriz [7][1]=1;
    matriz [7][8]=1;
    matriz [7][6]=1;
    matriz [7][13]=1;

    matriz [8][7]=1;
    matriz [8][14]=1;

    matriz [9][3]=1;
    matriz [9][10]=1;
    matriz [9][15]=1;

    matriz [10][9]=1;
    matriz [10][11]=1;
    matriz [10][16]=1;

    matriz [11][5]=1;
    matriz [11][10]=1;

    matriz [12][6]=1;
    matriz [12][18]=1;
    matriz [12][13]=1;

    matriz [13][7]=1;

    matriz [14][8]=1;
    matriz [14][15]=1;
    matriz [14][20]=1;

    matriz [15][9]=1;
    matriz [15][14]=1;

    matriz [16][10]=1;
    matriz [16][17]=1;
    matriz [16][22]=1;

    matriz [17][16]=1;

    matriz [18][12]=1;
    matriz [18][19]=1;

    matriz [19][18]=1;
    matriz [19][20]=1;

    matriz [20][14]=1;
    matriz [20][19]=1;
    matriz [20][21]=1;

    matriz [21][20]=1;

    matriz [22][23]=1;

    matriz [23][22]=1;

    monstros = monst(monstros); // Chama a funcao que cria os monstros
    monstros = mons_aleato(monstros,matriz); // chama a funcao que deixa os monstros aleatoriamente no grafo 
    caminho2 = dijkstra(matriz,&soma,&tam); // calcula o caminho minimo
    
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0m  Nêmesis, a deusa da vingança, irou-se contra Euterpe, a musa dos prazeres, e a pôs num labirinto \n\033[0m\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0m infestado de bestas. Agora, apenas Hércules poderá salvar Euterpe. Iniciando sua jornada em alguma \n\033[0m\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0mposição do labirinto, Hércules só pode avançar para uma posição do labirinto guardada por uma besta se \033[0m\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0mmatar a besta. Embora terrível, uma besta nunca deixa a posição que guarda. Ainda, bestas diferentes \033[0m\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0m podem exigir de Hércules quantias diferentes de energia para serem mortas. Ajude Hércules a salvar \033[0m\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0m    Euterpe gastando o mínimo de energia possível, sabendo que ele só pode se mover nas direções  \033[0m\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0mhorizontal e vertical e, apesar de ser um herói invencível e de possuir energia infinita, Hércules não \033[0m\n\n");
    printf("\t\t\t\t\t\t\t\033[38;2;255;165;0m                     consegue destruir as paredes do labirinto. \033[0m\n\n");


    
    do{

        printf("\n\t\t\033[38;2;255;255;0m(1) Jogar \033[m\n");
        printf("\n\t\t\033[38;2;0;255;195m(2) Novo Jogo \033[m\n");
        printf("\n\t\t\033[38;2;156;15;216m(3) Mostrar Matriz \033[m\n");
        printf("\n\t\t\033[38;2;15;216;21m(4) Mostrar monstros \033[m\n");
        printf("\n\t\t\033[38;2;230;28;91m(5) Caminho Mínimo \033[m\n");
        printf("\n\t\t\033[38;2;127;127;127m(6) Sair \033[m\n");
        scanf("%i", &op);

        switch(op){

            case 1:

                system("tput reset");
                custoj= jogar(matriz, monstros); //custoj guarda a soma das arestas percorridas pelo usuário
                if(custoj==soma){ //Se o usuário percorrer o menor caminho
                    printf("\n\n\t\t\t\t\t\t\t\t\033[38;2;242;48;219mPARABÉNS!!!\n\033[m\n");
                    printf("\n\n\t\t\t\t\t\t\033[38;2;242;48;219mHercules salvou Euterpe gastando o mínimo de energia possivel!!! \033[m\n");
                    printf("\n\n\t\t\t\t\t\t\033[38;2;100;242;155mEnergia gasta: %i  \n\n\n\033[m", custoj);
                }else if(custoj==0){ //Se o usuário desistir
                    printf("\n\n\t\t\t\t\t\t\033[38;2;200;45;36mHercules não foi bravo o bastante para chegar até o final, e Euterpe continuará presa por causa disso!:( \033[m\n");
                }else{ //Se o usuário chegar ao final por um caminho maior
                    printf("\n\n\t\t\t\t\t\t\033[38;2;200;45;36mHercules salvou Euterpe!!! Mas as batalhas gastaram mais energia do que o necessário! \033[m\n");
                    printf("\n\n\t\t\t\t\t\t\033[38;2;100;242;155mEnergia gasta: %i  \033[m", custoj);
                    printf("\n\n\t\t\t\t\t\t\033[38;2;48;242;155mEnergia que o melhor caminho gastaria: %i \n\n\n\n \033[m",soma);
                }

            break;

            case 2:

                system("tput reset");
                //"Reinicia" os valores e obtém novos
                monstros = mons_aleato(monstros,matriz);
                soma=0;
                tam=2;
                caminho2 = dijkstra(matriz,&soma,&tam);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[38;2;255;255;0mOs monstros trocaram de lugar!\n\033[m");
            break;

            case 3:
                //Imprime Matriz
                system("tput reset");
                for(int i=0; i<24; i++){
                    for(int j=0; j<24; j++){
                        printf("%i\t", matriz[j][i]);
                    }
                }
                printf("\n");

            break;

            case 4:

            //Imprime os monstros sorteados na rodada
            system("tput reset");
            for(int i=0; i<24; i++){
                for(int j=0; j<24; j++){
                    if(matriz[i][j]!=0){
                        for(p = monstros; p != NULL ; p=p->prox){
                            if(p->energia==matriz[i][j]){
                                if(j>i){
                                    printf("\n [%i][%i]=%s -> %i\n", i, j, p->monstro, p->energia);
                                }
                            }   
                        }
                    }
                }
            }

            break;

            case 5:

            //Imprime o caminho mínimo e o seu custo
            system("tput reset");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\033[38;2;255;255;0mO caminho com menos gasto de energia é:\n\033[m");
            for(int i=tam-1;i>=0; i--){
                if(caminho2[i]==0){
                    printf("\t\t\t\t\t\t%i", caminho2[i]);
                }else{
                    printf("-%i", caminho2[i]);
                }
            }
            printf("\n\n\t\t\t\t\t\t\033[38;2;255;255;0mCom um custo total de: %i \n\033[m", soma);

            break;

        }

    }while(op!=6);


    return 0;

}