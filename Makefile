but : taquin

OFILES =  	main.o \
			Jeu.o \
			Victoire.o \

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g


fonctions.o : fonctions.h 
	gcc -c fonctions.h 

Jeu.o : Jeu.c
	gcc -c Jeu.c

Victoire.o : Victoire.c
	gcc -c Victoire.c

main.o : main.c 
	gcc -c main.c

taquin : $(OFILES)
	$(CC) $(CFLAGS) -o taquin $(OFILES) -lgraph
