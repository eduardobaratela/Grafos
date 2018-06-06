#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TADmatriz.h"

void dijkstra(t_matriz M){

	int vertMin, camMin;
	int peso[M->vertice];	
	int pred[M->vertice];
	int visitado[M->vertice];
	int aux;

	for (int i = 0; i < M->vertice; i++){  //seta os valores dos vetores de peso e predecessor
		peso[i] = M->mat[0][i];
		visitado[i] = 0;
		if(peso[i]==inf)
			pred[i] = -1;
		else
			pred[i] = 0;
	}

	visitado[0] = 1; // primeiro vértice é marcado como visitado
	vertMin = 0; //primeiro vértice é setado como vértice de custo minimo


	for (int i = 0; i < M->vertice; i++){
		camMin = inf;
		
		for (int j = 0; j < M->vertice; j++){	//laço que acha o vértice com menor peso e que ainda nao foi visitado
			if(visitado[j] == 0 && peso[j] < camMin){
				camMin = peso[j];
				vertMin = j;
			}
		}

		visitado[vertMin] = 1; //marca o verrtice minimo como visitado

		for (int j = 0; j < M->vertice; j++){
			aux = camMin + M->mat[vertMin][j];
			if(visitado[j] == 0 && M->mat[vertMin][j] != inf && aux < peso[j]){
				peso[j] = aux;
				pred[j] = vertMin; 
			}
		}
	}

	for (int i = 0; i < M->vertice; i++){
		printf("%d \n", pred[i]);
	}

}

int main(){
	
	int vertices, arestas, v1, v2, peso;
	scanf("%d %d", &vertices, &arestas);

	t_matriz M = iniciaMatriz(vertices);

	//insere os elementos no grafo
	for (int i = 0; i < arestas; i++){		
		scanf("%d %d %d", &v1, &v2, &peso);
		insereMatOrientada(M, v1, v2, peso);
	}

	printMatriz(M);

	dijkstra(M);
	
	destroiMatriz(M);

	return 0;
}