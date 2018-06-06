all: dijkstra.o TADmatriz.o
	gcc dijkstra.o TADmatriz.o -o dijkstra -g -I.

dijkstra.o: dijkstra.c
	gcc -c dijkstra.c

TADmatriz.o: TADmatriz.c
	gcc -c TADmatriz.c

run:all
	./dijkstra

clean:
	rm -rf *o dijkstra