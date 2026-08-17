#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define vazio ' '
#define linha_i 20
#define coluna_j 80

typedef struct  MatrizDesenho{
    char matriz_desenhos[linha_i][coluna_j];
} MatrizDesenho;


void InicalizaMatriz(MatrizDesenho *matriz);

void ImprimeMatriz(MatrizDesenho *matriz);

void GeraAsterisco(MatrizDesenho *matriz, int num);