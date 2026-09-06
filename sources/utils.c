#include "../headers/utils.h"


int VerificaQntdValida(int *num){
    if (*num <= 0){
        printf("gerando um numero aleatorio de figuras\n");
        *num = (rand() % 100) + 1;
        printf("%d figuras foram geradas\n", *num);
    }

    else if (*num > 100){
        *num = 100;
    }

    return *num;
}


int VerificaVizinhos(MatrizDesenho *matriz, int aleatorio_i, int aleatorio_j, int control){
    if (control==1){ //estrela
        if (matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j - 1] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i][aleatorio_j + 1] == vazio){
        
            return 1;
        }
    }

    if (control==2){ //x
        if (matriz -> matriz_desenhos[aleatorio_i][aleatorio_j] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j - 1] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i - 1][aleatorio_j + 1] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j - 1] == vazio && 
            matriz -> matriz_desenhos[aleatorio_i + 1][aleatorio_j + 1] == vazio){
        
            return 1;
        }
    }

    return 0;
}