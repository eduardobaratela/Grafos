all: DFS.o pilha.o TADlista.o
	gcc DFS.o pilha.o TADlista.o -o DFS -g -I.

DFS.o: DFS.c
	gcc -c DFS.c

pilha.o: pilha.c
	gcc -c pilha.c

TADlista.o: TADlista.c
	gcc -c TADlista.c

run:all
	./DFS

clean:
	rm -rf *o DFS