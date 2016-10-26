#include <ncurses.h>
#include <unistd.h>
#include "dino.h"
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

