#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"
#include "fila.h"

//Funcao que printa a BFS recursivamente, de acordo com o vetor de parentes.
void printaBFS(int* pi, int i, int dest){
	if(pi[dest] == -1){
		printf("%d ", dest);
		return;
	} 
	else printaBFS(pi, i, pi[dest]);

	printf("%d ", dest);
}

//Funcao que percorre a BFS,, checando os adjacentes, colocando-os em uma fila e pintando-os como visitados.
void visita(t_lista L, int i, int v2, int* visitado){
	t_fila f;
	criaFila(&f);
	int pi[L->vert];
	int vazio = 0;

	for (int i = 0; i < L->vert; i++){
		pi[i] = -1;
	}

	visitado[i] = 1;
	t_item* atual = (t_item*) malloc(sizeof(t_item));
	atual->chave = i;
	insereFila(&f, *atual);

	while(f.inicio != NULL){
		removeFila(&f, atual);
		link v = L->list[atual->chave];
		int aux = atual->chave;
		int flag = 0;

		while(v != NULL){
			if(visitado[v->vizinho] == 0){
				pi[v->vizinho] = aux;
				visitado[v->vizinho] = 1;
				if(v->vizinho == v2){
					flag = 1;
					break;
				}
				atual->chave = v->vizinho;
				insereFila(&f, *atual);
			}
			v = v->prox;
		}
		if(flag == 1){
			vazio = 1;
			break;
		} 
		else vazio = 0;
	}

	if(vazio == 1 || i == v2) printaBFS(pi, i, v2);
}

//Funcao que comeca a BFS, pintando todos os nos de branco no comeco e chamando o seu percorrimento a partir
//um no inicial ate um no destino.
void BFS(t_lista L, int v1, int v2){
	int visitado[L->vert];
	int i;

	for(i = 0; i < L->vert; i++)
		visitado[i] = 0;		//cor = 0 == branco /// cor = 1 == cinza 

	visita(L, v1, v2, visitado);
}

int main(){
	int vertices, arestas, v1, v2;
	scanf("%d %d", &vertices, &arestas);

	t_lista L = iniciaLista(vertices);

	for (int i = 0; i < arestas; i++){		//insere os elementos no grafo
		scanf("%d %d", &v1, &v2);			
		insereListaOrientada(L, v1, v2, 1);
	}

	while(scanf("%d %d\n", &v1, &v2) == 2){		//chama a dfs com um ponto de origem e um ponto de destino.
		BFS(L, v1, v2);
		printf("\n");
	}

	return 0;
}