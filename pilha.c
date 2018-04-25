#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

//Funcao que insere o elemento no topo da pilha
void inserePilha(int visitado, pilha* p){
	nodeP* novo = (nodeP *)malloc(sizeof(nodeP));
	novo->num = visitado;
	novo->prox = p->head;

	if(p->head == NULL){
		p->head = novo;
		p->tail = novo;
	}
	else{
		p->head = novo;
	}

	p->size++;
}

//Funcao que remove o elemento que esta no topo da pilha
int removePilha(pilha* p){
	if(p == NULL || p->head == NULL){
		printf("Pilha vazia\n");
	}
	else{
		nodeP* aux;
		int resp;

		aux = p->head;
		resp = p->head->num;
		p->head = p->head->prox;

		free(aux);
		p->size--;

		return resp;
	}
}

//Funcao que inicializa a pilha
void criaPilha(pilha* p){
	p->size = 0;
	p->head = NULL;
	p->tail = NULL;
}

//Funcao que inverte a pilha e a printa
void printaPilhaInvertida(pilha p){
	nodeP* aux = p.head;
	int vet[p.size];
	int i = 0;
	while(aux != NULL){
		vet[i] = aux->num;
		aux = aux->prox;
		i++;
	}
	for(i = i-1; i >= 0; i--)
		printf("%d ", vet[i]);
}

//Funcao que printa a pilha normalmente
void printaPilha(pilha p){
	nodeP* aux = p.head;

	while(aux != NULL){
		printf("%d ", aux->num);
		aux = aux->prox;
	}
				
}