all: dino
dino: dino.h screen.h main.c
	gcc main.c -lncurses -o main 
clean: 
	rm *.o
