#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"
#include "pilha.h"

//Funcao de percorrimento da DFS, onde se percorre de no em no, e insere todos os nos finalizados em uma pilha em ordem topologica
void visita(t_lista L, int i, int* cor, pilha* T){

	cor[i] = 1;

	link aux = L->list[i];
	while(aux != NULL){
		if(cor[aux->vizinho] == 0){
			visita(L, aux->vizinho, cor, T);
		}
		aux = aux->prox;
	}
	cor[i] = 2;
	inserePilha(i, T);
}

//Funcao que comeca a DFS, pintando todos os nos de branco no comeco e chamando o seu percorrimento a partir
//um no inicial ate um no destino.
void DFS(t_lista L){
	int cor[L->vert];
	int i, v1 = 0;
	
	pilha T;
	criaPilha(&T);
	
	for(i = 0; i< L->vert; i++){
		cor[i] = 0;					//cor = 0 == branco /// cor = 1 == cinza /// cor = 2 == preto
	}

	for (v1 = 0; v1 < L->vert; v1++){
		if(cor[v1] == 0)
			visita(L, v1, cor, &T);
	}

	printaPilha(T);
}

int main(){
	int vertices, arestas, v1, v2;
	scanf("%d %d", &vertices, &arestas);

	t_lista L = iniciaLista(vertices);

	for (int i = 0; i < arestas; i++){		//insere os elementos no grafo
		scanf("%d %d", &v1, &v2);
		insereListaOrientada(L, v1, v2, 1);
	}

	DFS(L);

	return 0;
}