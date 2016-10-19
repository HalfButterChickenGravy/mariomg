#include <ncurses.h>
#include <stdio.h>
#include <limits.h>
#include "screen.h"


int main() {
	

	int i;
	char ch;
	i = INT_MAX;
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	clear();
	while((ch = getch()) != 'q') {
		clear();
		dino(i--, ch);
		timeout(100);
			
	}
	endwin();
}
