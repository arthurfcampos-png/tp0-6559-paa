#ifndef TAD_MATRIZ_H
#define TAD_MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define vazio ' '

#define linha_i 20
#define coluna_j 80

#define lsup_i 18
#define lsup_j 78


typedef struct  MatrizDesenho{
    char matriz_desenhos[linha_i][coluna_j];
} MatrizDesenho;


void InicalizaMatriz(MatrizDesenho *matriz);

void GeraAsterisco(MatrizDesenho *matriz, int num);

void GeraEstrela(MatrizDesenho *matriz, int num);

void GeraX(MatrizDesenho *matriz, int num);

void ImprimeMatriz(MatrizDesenho *matriz);

#endif