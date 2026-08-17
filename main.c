#include "./headers/teste.h"

int main(){
    srand(time(NULL));

    MatrizDesenho matriz;

    int num_aleatorio = 0;

    printf("Digite um numero aleatorio: \n");
    scanf("%d", &num_aleatorio);

    InicalizaMatriz(&matriz);

    GeraAsterisco(&matriz, num_aleatorio);

    ImprimeMatriz(&matriz);
}