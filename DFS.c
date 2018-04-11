#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"
#include "pilha.h"

//Funcao de percorrimento da DFS, onde se percorre de no em no
void visita(t_lista L, int i, int v2, int* cor, pilha* P){
	int flag = 0;

	inserePilha(i, P);
	cor[i] = 1;
	if(i == v2){
		printaPilha(*P);
		return;
	} 

	link aux = L->list[i];
	while(aux != NULL){
		if(cor[aux->vizinho] == 0)
			visita(L, aux->vizinho, v2, cor, P);
		aux = aux->prox;
	}
	cor[i] = 2;
	removePilha(P);
}

//Funcao que comeca a DFS, pintando todos os nos de branco no comeco e chamando o seu percorrimento a partir
//um no inicial ate um no destino.
void DFS(t_lista L, int v1, int v2){
	int cor[L->vert];
	int i;
	
	pilha P;
	criaPilha(&P);
	
	for(i = 0; i< L->vert; i++){
		cor[i] = 0;					//cor = 0 == branco /// cor = 1 == cinza /// cor = 2 == preto
	}

	visita(L, v1, v2, cor, &P);
}

int main(){
	int vertices, arestas, v1, v2;
	scanf("%d %d", &vertices, &arestas);

	t_lista L = iniciaLista(vertices);

	for (int i = 0; i < arestas; i++){		//insere os elementos no grafo
		scanf("%d %d", &v1, &v2);
		insereListaOrientada(L, v1, v2, 1);
	}

	while(scanf("%d %d\n", &v1, &v2) == 2){	//chama a dfs com um ponto de origem e um ponto de destino.
		DFS(L, v1, v2);
		printf("\n");
	}

	return 0;
}