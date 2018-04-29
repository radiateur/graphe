#Makefile pour graphe -- compilateur GCC 
CC=gcc
CFLAGS=-Wall -Wextra -g

graphe : main.o graphe.o algo.o
	$(CC) $(CFLAGS) $^ -o graphe

main.o : main.c algo.c graphe.c
	$(CC) $(CFLAGS) -c main.c -o main.o

algo.o : algo.c
	$(CC) $(CFLAGS)  -c algo.c -o algo.o

graphe.o : graphe.c
	$(CC) $(CFLAGS) -c graphe.c -o graphe.o

clean :
	rm -f *.o
