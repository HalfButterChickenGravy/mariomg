#include <ncurses.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>


typedef struct player {
	int score;
//	p_character type;	
	
}player;





void disp (int no) {

	char bord;
	int i, maxheight, maxwidth, g_type;
	initscr();
	noecho();
	curs_set(0);
	

	//ground
	for(i = 2; i < 100; i++) {
		move(16, i);
		addch('_');
	}
	g_type = no % 3;
	for(i = (g_type + 2); i < 100; i += 3) {
		move(17, i);
		addch('`');
	}
	

	bord = (char) 219;

	//borders
	for(i = 0; i < 102; i++) {
		move(0, i);
		addch(bord);
	}
	for(i = 0; i < 102; i++) {
		move(21, i);
		addch(bord);
	}
	for(i = 0; i < 22; i++) {
		move(i, 0);
		addch(bord);addch(bord);
	}
	for(i = 0; i < 22; i++) {
		move(i, 100);
		addch(bord);addch(bord);
	}
	refresh();
}



void print_dino(int pos, int frameno) {

	int l_type, y;
	
	move(16, 12);

	y = 16 - pos;
	
	
	mvprintw(y-4, 12, "    __");
	mvprintw(y-3, 12, "   |0_|");
	mvprintw(y-2, 12, "|\\/ |_");
	mvprintw(y-1, 12, "\\  /");
	l_type = pos == 0 ? frameno % 3 : 9;
	switch(l_type) {
		case 0:	mvprintw(y, 12, " | \\");
			break;
		case 1:	mvprintw(y, 12, " \\/");
			break;
		case 2:	mvprintw(y, 12, " / |");
			break;
		case 9: mvprintw(y, 12, " | |");
			break;
	}

}


void dino (int no, char key) {

	int i, sum;
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	

	switch(key) {
		case ' ': {
			  sum = 100;
			  for(i = 0; i < 12; i+=4) {
				clear();
				disp(no);
				print_dino(i, no--);
				refresh();
				usleep(56000);
				//usleep((5500+(i*(sum+=200))));
				//usleep(7000);
			  	
			  }
			  for(i = 11; i >= 0; i-=4) {
				clear();
				disp(no);
				print_dino(i, no--);
				refresh();
				usleep(56000);
				//usleep((5500+(i*(sum-=200))));
				//usleep(7000);
			  }
			  
			  
			  }
			  
	}


	//dino
	clear();
	disp(no);
	print_dino(0, no);
	refresh();


}







































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
		disp(i);
		dino(i--, ch);
		timeout(70);
			
	}
	endwin();
}





















