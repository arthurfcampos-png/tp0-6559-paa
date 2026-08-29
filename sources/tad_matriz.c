#include "../headers/utils.h"


void InicalizaMatriz(MatrizDesenho *matriz){
    for (int i=0; i<linha_i; i++){
        for (int j=0; j<coluna_j; j++){
            if (i == 0 || i == linha_i-1){
                matriz -> matriz_desenhos[i][j] = '-';

            }

            else if (j == 0 || j == coluna_j-1){
                matriz -> matriz_desenhos[i][j] = '|';
            }

            else{
                matriz -> matriz_desenhos[i][j] = vazio;
            }
        }
    }
}


void GeraAsterisco(MatrizDesenho *matriz, int num, int min_j, int max_j){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % (max_j - min_j + 1)) + min_j;
        
        if (matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] == vazio){
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] = '*';

            count_validos++;
        }

        max--;
    }
}

void GeraEstrela(MatrizDesenho *matriz, int num, int min_j, int max_j){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % (max_j - min_j + 1)) + min_j;
        
        if (VerificaVizinhos(matriz, aleatorio_i, aleatorio_j, 1) == 1){

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


void GeraX(MatrizDesenho *matriz, int num, int min_j, int max_j){
    int max = 100;
    int count_validos = 0;

    while (count_validos < num && max > 0){
        int aleatorio_i = (rand() % lsup_i) + 1;
        int aleatorio_j = (rand() % (max_j - min_j + 1)) + min_j;
        
        if (VerificaVizinhos(matriz, aleatorio_i, aleatorio_j, 2) == 1){

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

void GeraFigurasAleatorias(MatrizDesenho *matriz, int num, int min_j, int max_j){
    for (int i=0; i<num; i++){  
        int controle_switch = (rand() % 3) + 1;
    
        switch (controle_switch){

        case 1:
            GeraAsterisco(matriz, 1, min_j, max_j);
            break;

        case 2:
            GeraEstrela(matriz, 1, min_j, max_j);
            break;
        
        case 3:
            GeraX(matriz, 1, min_j, max_j);
            break;
        
        default:
            break;
        }
    }
}


void GeraEspelhos(MatrizDesenho *matriz, int num){
    MatrizDesenho aux;

    InicalizaMatriz(&aux);
    
    for (int i=1; i<linha_i-1; i++){
        aux.matriz_desenhos[i][39] = '|';
        aux.matriz_desenhos[i][40] = '|';
    }

    GeraFigurasAleatorias(&aux, num, 1, 38);

    for (int i=1; i<linha_i-1; i++){
        for (int j=0; j<39; j++){
            if (aux.matriz_desenhos[i][j] == '*'){
                int j_espelho = coluna_j - 1 - j;

                matriz -> matriz_desenhos[i][j] = '*';
                matriz -> matriz_desenhos[i][j_espelho] = '*';
            }
        }
    }

    for (int i=1; i<linha_i-1; i++){
        matriz -> matriz_desenhos[i][39] = '|';
        matriz -> matriz_desenhos[i][40] = '|';
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
