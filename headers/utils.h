#ifndef UTILS_H
#define UTILS_H


#include "../headers/tad_matriz.h"


int VerificaQntdValida(int *num);

int VerificaVizinhosEstrela(MatrizDesenho *matriz, int aleatorio_i, int aleatorio_j);

int VerificaVizinhosX(MatrizDesenho *matriz, int aleatorio_i, int aleatorio_j);

#endif