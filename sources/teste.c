#include "../headers/teste.h"


void InicalizaMatriz(MatrizDesenho *matriz){
    for (int i=0; i<linha_i; i++){
        for (int j=0; j<coluna_j; j++){
            if (i==0 || i ==19){
                matriz -> matriz_desenhos[i][j] = '-';

            }

            else if (j==0 || j== 79){
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
    int temp = num;
    int count_validos;

    while (temp != 0 || count_validos == num || max == 0){
        int aleatorio_i = (rand() % 18) + 1;
        int aleatorio_j = (rand() % 78) + 1;
        
        if (matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] == ' '){
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] = '*';

            count_validos++;
            temp--;
        }

        max--;
    }
}