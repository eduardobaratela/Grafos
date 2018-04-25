#include <stdio.h>
#include <stdlib.h>
#include "TADlista.h"

//Funcao que aloca o TAD matriz
t_lista iniciaLista(int v){
  int i;

  t_lista L = malloc(sizeof(lista));
  L->vert = v;
  L->list = malloc(v * sizeof(link));

  for(i = 0; i < v; i++)
      L->list[i] = NULL;

  return L;
}

//Funcao que aloca um no na lista
link newNode(int viz, int p, link next){
  link aux = malloc(sizeof(node));

  aux->vizinho = viz;
  aux->peso = p;
  aux->prox = next;

  return aux;
}

//Funcao que insere um elemento direcionalmente na lista
void insereListaOrientada(t_lista L, int v, int viz, int peso){
  link aux = L->list[v];
  link temp;
  
  if(L->list[v] != NULL){
  	  if(viz < aux->vizinho){
  	  	temp = newNode(viz, peso, aux);
  	  	L->list[v] = temp;
  	  }
  	  else{
	      while(aux->prox != NULL && viz >= aux->prox->vizinho) aux = aux->prox;
	      if(aux->vizinho == viz) aux->peso = peso;
	      else if(aux->prox != NULL){
	      	temp = newNode(viz, peso, aux->prox);
	      	aux->prox = temp;
	      }
	      else{
	      	temp = newNode(viz, peso, NULL);
	      	aux->prox = temp;
	      }
	  }
  }
  else L->list[v] = newNode(viz, peso, L->list[v]);
}

//Funcao que insere um elemento sem ser direcionalmente na lista
void insereListaNaoOrientada(t_lista L, int v, int viz, int peso){
  link aux = L->list[v];
  link temp1, temp2;
  
  if(L->list[v] != NULL){
  	  if(viz < aux->vizinho){
  	  	temp1 = newNode(viz, peso, aux);
  	  	L->list[v] = temp1;
  	  }
  	  else{
	      while(aux->prox != NULL && viz >= aux->prox->vizinho){
	      	aux = aux->prox;
	      }
	      if(aux->vizinho == viz){
	      	aux->peso = peso;
	      } 
	      else if(aux->prox != NULL){
	      	temp1 = newNode(viz, peso, aux->prox);
	      	aux->prox = temp1;
	      }
	      else{
	      	temp1 = newNode(viz, peso, NULL);
	      	aux->prox = temp1;
	      }
	  }
  }
  else L->list[v] = newNode(viz, peso, L->list[v]);

	if(v != viz){
	  aux = L->list[viz];
	  if(L->list[viz] != NULL){
	  	  if(v < aux->vizinho){
	  	  	temp2 = newNode(v, peso, aux);
	  	  	L->list[viz] = temp2;
	  	  }
	  	  else{
		      while(aux->prox != NULL && v >= aux->prox->vizinho){ 
		      	aux = aux->prox;
		      }
		      if(aux->vizinho == v){
		      	aux->peso = peso;
		      } 
		      else if(aux->prox != NULL){
		      	temp2 = newNode(v, peso, aux->prox);
		      	aux->prox = temp2;
		      }
		      else{
		      	temp2 = newNode(v, peso, NULL);
		      	aux->prox = temp2;
		      }
		  }
	  }
	  else L->list[viz] = newNode(v, peso, L->list[viz]);
	}
}

//Funcao que printa a lista
void printaLista(t_lista L){
	int i;
	link aux;

	for (i = 0; i < L->vert; i++){
		aux = L->list[i];
		printf("%d. ", i);
		while(aux != NULL){
			printf("%d(%d) ", aux->vizinho, aux->peso);
			aux = aux->prox;
		}
		printf("\n");
	}
}

//Funcao que printa os vertices adjacentes de determinado vertice da lista
void printaAdjacentesList(t_lista L, int v){
  link aux = NULL;

  if(L->list[v] == NULL) return;
  for(aux = L->list[v]; aux != NULL; aux = aux->prox){
    printf("%d ", aux->vizinho);
  }
  printf("\n");
}

//Funcao que printa a lista transposta de um grafo digrafo
void listaTransposta(t_lista L, int v){
	int mat[v][v];
	int i, j;
	link aux;

	for(i = 0; i < v; i++){
		aux = L->list[i];
		for(j = 0; j < v; j++) mat[i][j] = -1;
		while(aux != NULL){
			mat[i][aux->vizinho] = aux->peso;
			aux = aux->prox;
		} 
	}

	for(i = 0; i < v; i++){
		printf("%d. ", i);
		for(j = 0; j < v; j++){
			if(mat[j][i] != -1) printf("%d(%d) ", j, mat[j][i]);
		}
		printf("\n");	
	}
}

//Funcao que busca a ligacao com menor peso e a printa
void menorPesoLista(t_lista L, char ori){
	int i, menor_i, menor_j, menorpeso = 999;
	link aux;

	for(i = 0; i < L->vert; i++){
		aux = L->list[i];
		while(aux != NULL){
			if(aux->peso < menorpeso){
				menor_i = i;
				menor_j = aux->vizinho;
				menorpeso = aux->peso;
			}
			aux = aux->prox;
		}
	}

	if(ori == 'G' && menor_j < menor_i){
		printf("%d %d\n", menor_j, menor_i);
	}
	else printf("%d %d\n", menor_i, menor_j);
}

//Funcao que remove um elemento direcinalmente na lista
void removeListaOrientada(t_lista L, int a, int b){
	link aux, temp;

	aux = L->list[a];
	if(aux == NULL) return;
	if(b == aux->vizinho){
		L->list[a] = aux->prox;
		free(aux);
	}
	else{
		while(aux != NULL && aux->prox->vizinho != b)
			aux = aux->prox;
		if(aux != NULL){
			temp = aux->prox;
			aux->prox = aux->prox->prox;
			free(temp);
		}
	}
}

//Funcao que remove um elemento sem ser direcinalmente na lista
void removeListaNaoOrientada(t_lista L, int a, int b){
	link aux, temp1, temp2;
	aux = L->list[a];
	if(aux == NULL) return;
	if(b == aux->vizinho){
		L->list[a] = aux->prox;
		free(aux);
	}
	else{
		while(aux->prox != NULL){
			if(aux->prox->vizinho != b)
				aux = aux->prox;
			else break;
		}
		if(aux != NULL && aux->prox != NULL){
			temp1 = aux->prox;
			aux->prox = aux->prox->prox;
			free(temp1);
		}
		else return;
	}

	if(a != b){
		aux = L->list[b];
		if(aux == NULL) return;
		if(a == aux->vizinho){
			L->list[b] = aux->prox;
			free(aux);
		}
		else{
			while(aux != NULL && aux->prox != NULL && aux->prox->vizinho != a)
				aux = aux->prox;
			if(aux != NULL){
				temp2 = aux->prox;
				aux->prox = aux->prox->prox;
				free(temp2);
			}	
		}
	}
}