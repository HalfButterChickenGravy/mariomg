demo: main.o
	gcc main.o -o demo
main.o: dino.h screen.h main.c
	gcc main.c -lncurses
