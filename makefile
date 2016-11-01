all: project
project: gamedata.o screen.o obstacles.o main.o
	gcc screen.c obstacles.c main.c -lncurses -pthread -o project -Wall
main: screen.h gamedata.h obstacles.h
	gcc main.c -o main -lncurses -Wall
screen: screen.h screen.c gamedata.h obstacles.h
	gcc screen.c -lncurses -Wall
obstacles: obstacles.h obstacles.c gamedata.h
	gcc obstacles.c -lncurses -Wall
clean: 
	rm *.o
