/* mariomg -- A simple implementation of offline dino runner game of Google Chrome in c
   Copyright pratikmayekar4@gmail.com Pratik Mayekar
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <ncurses.h>
#include <unistd.h>
#include "gamedata.h"
#include "screen.h"




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
    __
   |0_|  
|\/ |_
\  /
 | |

 */



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

	mvprintw(2, 88, "Score: %d", p->score);
	mvprintw(3, 88, " Best: %d", p->best);
	mvprintw(2, 3, "'q' to quit");
	refresh();

}





void dino (player *p) {

	char key = p->ch;
	int i;
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	

	switch(key) {
		case ' ': {
			  for(i = 0; i < 10; i+=1) {
				p->score++;				
				clear();
				p->dinopos = i;
				disp(p);
				print_dino(i, p->i--);

				assignobs(p);	
				if(p->obsloc >= 0) {
					printobstacle(&p->o[p->obstype], p->obsloc);
					if(checkcollision(&p->o[p->obstype], i, p->dinopos)) {
						p->state = 0;
						refresh();
						return;
					}				
				}
				refresh();
				usleep(p->speed * 1000);
			  	
			  }
			  for(i = 9; i >= 0; i-=1) {
				p->score++;				
				clear();
				p->dinopos = i;
				disp(p);
				print_dino(i, p->i--);

				assignobs(p);	
				if(p->obsloc >= 0) {
					printobstacle(&p->o[p->obstype], p->obsloc);
					if(checkcollision(&p->o[p->obstype], p->obsloc, p->dinopos)) {
						p->state = 0;
						refresh();
						return;
					}				
				}
				refresh();
				usleep(p->speed * 1000);
			  }
			  
			  
			  }
			  
	}


	//dino
	p->score++;
	clear();
	disp(p);
	print_dino(0, p->i);

	assignobs(p);	
	if(p->obsloc >= 0) {
		printobstacle(&p->o[p->obstype], p->obsloc);
		if(checkcollision(&p->o[p->obstype], p->obsloc, p->dinopos)) {
			p->state = 0;
			refresh();
			return;
		}				
	}
	refresh();


}
