#ifndef TADLISTA
#define TADLISTA
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int vizinho;
  int peso;
  struct node* prox;
}node;

typedef struct node* link;

typedef struct lista{
  int vert;
  link* list;
}lista;

typedef lista* t_lista;

t_lista iniciaLista(int v);
link newNode(int viz, int p, link next);
void insereListaOrientada(t_lista L, int v, int viz, int peso);
void insereListaNaoOrientada(t_lista L, int v, int viz, int peso);
void printaLista(t_lista L);
void printaAdjacentesList(t_lista L, int v);
void listaTransposta(t_lista L, int v);
void menorPesoLista(t_lista L, char ori);
void removeListaOrientada(t_lista L, int a, int b);
void removeListaNaoOrientada(t_lista L, int a, int b);

#endif