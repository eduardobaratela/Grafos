all: PRIM.o TADlista.o
	gcc PRIM.o TADlista.o -o PRIM -g -I.

PRIM.o: PRIM.c
	gcc -c PRIM.c

TADlista.o: TADlista.c
	gcc -c TADlista.c

run:all
	./PRIM

clean:
	rm -rf *o PRIM