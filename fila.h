#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int chave;
	// outros campos
} t_item;

typedef struct no {
	t_item item;
	struct no* prox;
} t_no;

typedef t_no* t_apontador;

typedef struct{
	t_apontador inicio;
	t_apontador fim;
}t_fila;

void criaFila(t_fila* f);
void insereFila(t_fila* f, t_item item);
t_apontador pesquisa(t_fila* fila, int chave);
void removeFila(t_fila* f, t_item* item);

#endif