#include <ncurses.h>
#include <unistd.h>
#include "dino.h"

#ifndef GAMEDATA_H 
#include "gamedata.h"
#endif 

void disp (player *p) {

	int no = p->i;
	char bord;
	int i, g_type;
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

	//mvprintw(1, 88, "Score: %d", p->score);
	mvprintw(1, 3, "Score: %d", p->score);
	refresh();

}





void dino (player *p) {

	int no = p->i;
	char key = p->ch;
	int i;
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	

	switch(key) {
		case ' ': {
			  for(i = 0; i < 12; i+=4) {
				//clear();
				//sum=100;
				i = p->dinopos;
				disp(p);
				print_dino(i, no--);
				refresh();
				usleep(56000);
				//usleep((5500+(i*(sum+=200))));
				//usleep(7000);
			  	
			  }
			  for(i = 11; i >= 0; i-=4) {
				//clear();
				disp(p);
				print_dino(i, no--);
				refresh();
				usleep(56000);
				//usleep((5500+(i*(sum-=200))));
				//usleep(7000);
			  }
			  
			  
			  }
			  
	}


	//dino
	//clear();
	disp(p);
	print_dino(0, no);
	refresh();


}














