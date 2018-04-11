#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

//Funcao que inicializa a fila
void criaFila(t_fila* f){
	f->inicio = NULL;
	f->fim = NULL;
}

////Funcao que insere o elemento no fim da fila
void insereFila(t_fila* f, t_item item){
	t_apontador p = (t_apontador) malloc(sizeof(t_no));
	if (p == NULL){
		printf("Erro: memoria insuficiente\n");
		exit(EXIT_FAILURE);
	}
	p->item = item;
	p->prox = NULL;

	if(f->inicio == NULL) f->inicio = p;
	else f->fim->prox = p;
	f->fim = p;
}

//Funcao que pesquisa um elemento, percorrendo a estrutura
t_apontador pesquisa(t_fila* fila, int chave){
	t_apontador p = fila->inicio;
	while (p != NULL){
		if (p->item.chave != chave)
			p = p->prox;
		else
			break;
	}

	return p;
}

//Funcao que remove o primeiro elemento da fila
void removeFila(t_fila* f, t_item* item){
	if(f->inicio == NULL) return;

	*item = f->inicio->item;
	t_apontador temp = f->inicio;
	f->inicio = f->inicio->prox;

	free(temp);
	if(f->inicio == NULL) f->fim = NULL;
}