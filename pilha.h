#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeP{
	int num;
	struct nodeP* prox;
}nodeP;

typedef struct pilha{
	int size;
	nodeP* head;
	nodeP* tail;
}pilha;

void inserePilha(int num, pilha* p);
int removePilha(pilha* p);
void criaPilha(pilha* p);
void printaPilha(pilha p);

#endif