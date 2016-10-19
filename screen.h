#include <ncurses.h>
#include "dino.h"
void disp (int no) {

	char bord;
	int i, maxheight, maxwidth, g_type;
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, maxheight, maxwidth);
	

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

	int i;
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	
//12 frames up after jump and 12 frames down after jump

	switch(key) {
		case KEY_UP: 
			  for(i = 0; i < 12; i++) {
				clear();
				disp(no);
				print_dino(i, no);
				refresh();
				timeout(1000000);
			  	
			  }
			  for(; i >= 12; i--) {
				clear();
				disp(no);
				print_dino(i, no);
				refresh();
				timeout(1000);
			  }
			  
	}


	//dino
	clear();
	disp(no);
	print_dino(0, no);
	refresh();

/*
	switch(key) {
		case ' ': print_dino(0, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(1, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(2, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(3, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(4, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(5, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(6, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(7, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(8, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(9, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(10, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(11, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  
			  initscr();
			  print_dino(10, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(9, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(8, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(7, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(6, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(5, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(4, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(3, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(2, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(1, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  initscr();
			  print_dino(0, no);
			  timeout(100);
			  refresh();
			  disp(no); 
			  
			  
			  
			  
	}
*/


}















