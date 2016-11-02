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

#include <stdio.h>
#include <limits.h>
#include <ncurses.h>
#include <stdlib.h>
#include "gamedata.h"
#include "screen.h"

int highscore = 0;

int main() {
	

	int continu;
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	clear();
	player *p;
	p = (player*) malloc(sizeof(player));

	p->score = 0;	
	p->i = INT_MAX;
	p->obsloc = -1;
	p->obstype = -1;
	p->dinopos = 0;
	p->state = -1;
	p->ch = 'f';
	initobs(p);	
	
	nodelay(stdscr, false);
	clear();	
	disp(p);
	dino(p);
	mvprintw(10, 40, "Press spacebar to play");
	continu = getch();
	if(continu != ' ') {
		free(p);
		endwin();
		return 0;	
	}
	nodelay(stdscr, true);
	do {	
		p->score = 0;	
		p->best = highscore;
		p->i = INT_MAX;
		p->obsloc = -1;
		p->obstype = -1;
		p->dinopos = 0;
		p->state = -1;
		p->ch = 'f';
		p->speed = 50;
		initobs(p);

		
		
		while((p->ch = getch()) != 'q' && p->state != 0) {
			p->score++;
			clear();	
			disp(p);
			dino(p);
			p->i--;	
			if(p->score % 1000 == 0)
				p->speed = (p->speed * 2)/3;
			timeout(p->speed);
			
		}
	
		if(p->score > highscore)
			highscore = p->score;	
	
		mvprintw(8, 40, "Your Score: %d", p->score);
		mvprintw(9, 40, "      Best: %d", highscore);
		mvprintw(10, 35, "Press spacebar to play again");
		
		nodelay(stdscr, false);
		continu = getch();
	
	} while (continu == ' ');	
	free(p);
	endwin();
	return 0;




}
