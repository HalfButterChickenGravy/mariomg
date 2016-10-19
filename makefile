dino.h:
	gcc dino.h -lncurses
screen.h:
	gcc screen.h -lncurses
main.c: dino.h screen.h
	gcc main.c -lncurses
