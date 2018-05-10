#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"

void prim(t_lista L, int orig, int* pai){
	int primeiro, menorPeso, dest, firstOrig = orig;
	link aux;
	//seta inicicalmente o pais de todos os vertices como -1
	for(int i = 0; i < L->vert; i++)
		pai[i] = -1;

	//pai de origem é ele mesmo(raiz)
	pai[orig] = orig;	

	while(1){
		primeiro = 1;

		//percorre todos os vertices
		for(int i = 0; i < L->vert; i++){
			//acha um vertice visitado
			if(pai[i] != -1){
				//percorre os vizinhos do vertice
				aux = L->list[i];
				while(aux != NULL){
					//procura um vertice vizinho que ainda nao foi visitado
					if(pai[aux->vizinho] == -1){
						if(primeiro == 1){ //se for o primeiro vizinho
							menorPeso = aux->peso;
							orig = i;
							dest = aux->vizinho;
							primeiro = 0;	//mostra que o primeiro vizinho ja foi lido
						}
						else if(menorPeso > aux->peso){ //se o peso do vizinho atual for menor ele vira o novo destino
								menorPeso = aux->peso;
								orig = i;
								dest = aux->vizinho;
							}
						}
					}
					aux = aux->prox;
				}
			}
		}

		//se nao houver vertices nao visiados ou arestas a se analisar sai do loop
		if(primeiro == 1)
			break;

		//seta o pai do vizinho escolhido com a origem(vertice que dest é ligado pela aresta escolhida) 
		pai[dest] = orig;

		if(dest < orig) printf("(%d,%d) ", dest, orig);	
		else printf("(%d,%d) ", orig, dest);
	}
	pai[firstOrig] = -1;
}

int main(){

	int vertices, arestas, v1, v2, peso;
	scanf("%d %d", &vertices, &arestas);

	t_lista L = iniciaLista(vertices);

	//insere os elementos no grafo
	for (int i = 0; i < arestas; i++){		
		scanf("%d %d %d", &v1, &v2, &peso);
		insereListaNaoOrientada(L, v1, v2, peso);
	}

	int pai[vertices];

	prim(L, 0, pai);

	return 0;
}