GRAFOS: main.o grafo.o
	gcc main.o grafo.o -o GRAFOS

main.o: main.c
	gcc -c main.c

grafos.o: grafo.c grafo.h
	gcc -c grafo.c
