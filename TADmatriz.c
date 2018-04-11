#include <stdio.h>
#include <stdlib.h>
#include "TADmatriz.h"

//Funcao que aloca a matriz do TAD matriz
int** criaMatriz(int v){
	int i, j;

	int** m = malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		m[i] = malloc(v * sizeof(int));
		for(j = 0; j < v; j++) m[i][j] = -1;
	}

	return m;
}

//Funcao que aloca o TAD matriz
t_matriz iniciaMatriz(int v){
	t_matriz M = malloc(sizeof(matriz));
	M->vertice = v;
	M->mat = criaMatriz(v);

	return M;
}

//Funcao que desaloca a matriz da heap
void destroiMatriz(t_matriz M){
	int i;
	for(i = 0; i < M->vertice; i++) free(M->mat[i]);
	free(M->mat);
}

//Funcao que insere um elemento direcionalmente na matriz
void insereMatOrientada(t_matriz M, int a, int b, int peso){
	M->mat[a][b] = peso;
}

//Funcao que insere um elemento sem ser direcionalmente na matriz
void insereMatNaoOrientada(t_matriz M, int a, int b, int peso){
	M->mat[a][b] = peso;
	M->mat[b][a] = peso;
}

//Funcao que remove um elemento direcinalmente na matriz
void removeMatOrientada(t_matriz M, int a, int b){
	M->mat[a][b] = -1;
}

//Funcao que remove um elemento sem ser direcinalmente na matriz
void removeMatNaoOrientada(t_matriz M, int a, int b){
	M->mat[a][b] = -1;
	M->mat[b][a] = -1;
}

//Funcao que printa a matriz
void printMatriz(t_matriz M){
	int i, j;

	for(i = 0; i < M->vertice; i++){
		for(j = 0; j < M->vertice; j++){
			if(M->mat[i][j] > -1) printf("%d ", M->mat[i][j]);
			else printf(". ");
		}
		printf("\n");
	}
}

//Funcao que printa os vertices adjacentes de determinado vertice da matriz
void printaAdjacentesMat(t_matriz M, int v){
	int i;

	for(i = 0; i < M->vertice; i++)
		if(M->mat[v][i] > -1) printf("%d ", i);
	
	printf("\n");
}

//Funcao que printa a matriz transposta de um grafo digrafo
void printaMatrizTransposta(t_matriz M){
	int i, j;

	for(i = 0; i < M->vertice; i++){
		for(j = 0; j < M->vertice; j++){
			if(M->mat[j][i] > -1) printf("%d ", M->mat[j][i]);
			else printf(". ");
		}
		printf("\n");
	}
}

//Funcao que busca a ligacao com menor peso e a printa
void menorPeso(t_matriz M, int flag){					
	int i, j, menor_i, menor_j, menor = 999;

	for(i = 0; i < M->vertice; i++){
		for(j = 0; j < M->vertice; j++){
			if(M->mat[i][j] != -1 && M->mat[i][j] < menor){ 
				menor_i = i;
				menor_j = j;
				menor = M->mat[i][j];
			}
		}
	}

	if(flag == 1 && menor_i > menor_j){
		printf("%d %d\n", menor_j, menor_i);
	}

	printf("%d %d\n", menor_i, menor_j);
}