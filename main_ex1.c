#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "TADmatriz.h"
#include "TADlista.h"

int main(){

	int v, a, vert1, vert2, peso, x, i;
	char ori, tipo, buffer[3],str1[3],str2[3],str3[3],str4[3],str5[3],str6[3];
	
	scanf("%c %c %d %d", &ori, &tipo, &v, &a); //le a primeira linha da entrada
	getchar();; //lixo

	t_matriz M = iniciaMatriz(v);		//inicia os TADs
	t_lista L = iniciaLista(v);

	//adiciona as arestas iniciais
	for(i = 0; i < a; i++){
		scanf("%d %d %d", &vert1, &vert2, &peso);
		if(tipo == 'M' && ori == 'D') insereMatOrientada(M, vert1, vert2, peso);
		else if(tipo == 'M' && ori == 'G') insereMatNaoOrientada(M, vert1, vert2, peso);
		else if(tipo == 'L' && ori == 'D') insereListaOrientada(L, vert1, vert2, peso);
		else insereListaNaoOrientada(L, vert1, vert2, peso);
	}

	strcpy(str1,"IG");
	strcpy(str2,"IT");
	strcpy(str3,"VA");
	strcpy(str4,"AA");
	strcpy(str5,"RA");
	strcpy(str6,"MP");

	//realiza as operacoes seguintes
	while(scanf("%s",buffer) != EOF){
		if(strcmp(buffer,str1)==0){
			if(tipo == 'M') printMatriz(M);
			else printaLista(L);
		}
		else if(strcmp(buffer,str2)==0 && ori == 'D'){
			if(tipo == 'M') printaMatrizTransposta(M);
			else listaTransposta(L, v); 
		}
		else if(strcmp(buffer,str3)==0){
			scanf("%d", &x);
			if(tipo == 'M') printaAdjacentesMat(M, x);
			else printaAdjacentesList(L, x);
		}
		else if(strcmp(buffer,str4)==0){
			scanf("%d", &vert1);
			scanf("%d", &vert2);
			scanf("%d", &peso);
			if(tipo == 'M' && ori == 'D') insereMatOrientada(M, vert1, vert2, peso);
			else if(tipo == 'M' && ori == 'G') insereMatNaoOrientada(M, vert1, vert2, peso);
			else if(tipo == 'L' && ori == 'D') insereListaOrientada(L, vert1, vert2, peso);
			else insereListaNaoOrientada(L, vert1, vert2, peso);
		}
		else if(strcmp(buffer,str5)==0){
			scanf("%d", &vert1);
			scanf("%d", &vert2);
			if(tipo == 'M' && ori == 'D') removeMatOrientada(M, vert1, vert2);
			else if(tipo == 'M' && ori == 'G') removeMatNaoOrientada(M, vert1, vert2);
			else if(tipo == 'L' && ori == 'D') removeListaOrientada(L, vert1, vert2);
			else removeListaNaoOrientada(L, vert1, vert2);
		}
		else if(strcmp(buffer,str6)==0){
			if(tipo == 'M' && ori == 'D') menorPeso(M, 0);
			else if(tipo == 'M' && ori == 'G') menorPeso(M, 1);
			else menorPesoLista(L, ori);
		}
	} 

	destroiMatriz(M);

	return 0;
}