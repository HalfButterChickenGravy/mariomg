all: demo
demo: main.o
	gcc main.o -o demo -lncurses
main.o: dino.h screen.h main.c
	gcc main.c -lncurses
clean: 
	rm *.o
