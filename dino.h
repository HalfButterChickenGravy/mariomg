#include <ncurses.h>
#include <stdio.h>


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



/*
    __
   |0_|  
|\/ |_
\  /
 | \
    __
   |0_|  
|\/ |_
\  /
 \/ 
    __
   |0_|  
|\/ |_
\  /
 / | 


  O
 /|\
 / \

 */
