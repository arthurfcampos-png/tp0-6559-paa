#include "../headers/utils.h"


int VerificaQntdValida(int *num){
    if (*num <= 0){
        printf("erro: numero de figuras nao pode ser menor ou igual a zero");
        return 0;
    }

    else if (*num > 100){
        *num = 100;
        return 1;
    }

    return 1;
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