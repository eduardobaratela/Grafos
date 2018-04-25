all: topologica.o pilha.o TADlista.o
	gcc topologica.o pilha.o TADlista.o -o topologica -g -I.

topologica.o: topologica.c
	gcc -c topologica.c

pilha.o: pilha.c
	gcc -c pilha.c

TADlista.o: TADlista.c
	gcc -c TADlista.c

run:all
	./topologica

clean:
	rm -rf *o topologica