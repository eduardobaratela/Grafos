#ifndef TADMATRIZ
#define TADMATRIZ
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
	int vertice;
	int** mat;
}matriz;

typedef matriz* t_matriz;

int** criaMatriz(int v);
t_matriz iniciaMatriz(int v);
void destroiMatriz(t_matriz M);
void insereMatOrientada(t_matriz M, int a, int b, int peso);
void insereMatNaoOrientada(t_matriz M, int a, int b, int peso);
void removeMatOrientada(t_matriz M, int a, int b);
void removeMatNaoOrientada(t_matriz M, int a, int b);
void printMatriz(t_matriz M);
void printaAdjacentesMat(t_matriz M, int v);
void printaMatrizTransposta(t_matriz M);
void menorPeso(t_matriz M, int flag);

#endif