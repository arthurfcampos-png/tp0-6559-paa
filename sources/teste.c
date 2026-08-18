#include "../headers/utils.h"


void InicalizaMatriz(MatrizDesenho *matriz){
    for (int i=0; i<linha_i; i++){
        for (int j=0; j<coluna_j; j++){
            if (i == 0 || i == 19){
                matriz -> matriz_desenhos[i][j] = '-';

            }

            else if (j == 0 || j == 79){
                matriz -> matriz_desenhos[i][j] = '|';
            }

            else{
                matriz -> matriz_desenhos[i][j] = vazio;
            }
        }
    }
}

void ImprimeMatriz(MatrizDesenho *matriz){
    for (int i=0; i<linha_i; i++){
        for (int j=0; j<coluna_j; j++){
            printf("%c", matriz -> matriz_desenhos[i][j]);
        }
        printf("\n");
    }
}

void GeraAsterisco(MatrizDesenho *matriz, int num){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % lsup_j) + 1;
        
        if (matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] == vazio){
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] = '*';

            count_validos++;
        }

        max--;
    }
}

void GeraEstrela(MatrizDesenho *matriz, int num){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % lsup_j) + 1;
        
        if (VerificaVizinhosEstrela(matriz, aleatorio_i, aleatorio_j) == 1){

            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] = '*'; //centro

            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j] = '*'; //centro pra baixo
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j] = '*'; //centro pra cima
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j - 1] = '*'; //centro pra esquerda
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j + 1] = '*'; //centro pra direita

            count_validos++;
        }

        max--;
    }
}


void GeraX(MatrizDesenho *matriz, int num){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % lsup_j) + 1;
        
        if (VerificaVizinhosX(matriz, aleatorio_i, aleatorio_j) == 1){

            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] = '*'; //centro

            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j - 1] = '*'; //diagonal esquerda superior
            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j + 1] = '*'; //diagonal direita superior
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j - 1] = '*'; //diagonal esquerda inferior
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j + 1] = '*'; //diagonal direita inferior

            count_validos++;
        }

        max--;
    }
}