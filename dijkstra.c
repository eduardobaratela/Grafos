#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TADmatriz.h"

void dijkstra(t_matriz M, int v, int dest){

	int vertMin, camMin;
	int peso[M->vertice];	
	int pred[M->vertice];
	int visitado[M->vertice];
	int prioridade[M->vertice];
	int aux, i, j;

	//seta os valores dos vetores de peso e predecessor
	for (i = 0; i < M->vertice; i++){  
		peso[i] = M->mat[v][i];
		visitado[i] = 0;
		if(peso[i]==inf)
			pred[i] = -1;
		else
			pred[i] = v;
	}

	visitado[v] = 1; // primeiro vértice é marcado como visitado
	vertMin = v; //primeiro vértice é setado como vértice de custo minimo


	for (i = 0; i < M->vertice; i++){
		camMin = inf;

		//laço que acha o vértice com menor peso e que ainda nao foi visitado
		for (j = 0; j < M->vertice; j++){	
			if(visitado[j] == 0 && peso[j] < camMin){
				camMin = peso[j];
				vertMin = j;
			}
		}

		visitado[vertMin] = 1; //marca o verrtice minimo como visitado

		//laço que atualiza todos os caminhos para vértices adjacentes a "vertMin",passando por este, que ainda não foram visitados
		for (j = 0; j < M->vertice; j++){
			aux = camMin + M->mat[vertMin][j];
			if(visitado[j] == 0 && M->mat[vertMin][j] != inf && aux < peso[j]){
				peso[j] = aux;
				pred[j] = vertMin; 
			}
		}
	}

	//fila de prioridades criada através do percorrimento do vetor de predecessores
	aux = 0;
	for (i = dest; pred[i] >= 0; i = pred[i]){
		prioridade[aux] = i;
		aux++;	
	}
	if(i != dest){							
		prioridade[aux] = i;
		aux++;
	}

	//printa a fila de prioridades
	if(aux != 0){
		for (i = aux-1; i >= 0; i--)
			printf("%d ", prioridade[i]);
	}
	printf("\n");
}

int main(){
	
	int vertices, arestas, v1, v2, peso, origem, dest;
	scanf("%d %d", &vertices, &arestas);

	t_matriz M = iniciaMatriz(vertices);

	//insere os elementos no grafo
	for (int i = 0; i < arestas; i++){		
		scanf("%d %d %d", &v1, &v2, &peso);
		insereMatOrientada(M, v1, v2, peso);
	}


	while(scanf("%d %d", &origem, &dest) == 2)
		dijkstra(M, origem, dest);
	
	destroiMatriz(M);

	return 0;
}