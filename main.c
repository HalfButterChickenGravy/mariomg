#include <ncurses.h>
#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>
#include "gamedata.h"
#include "screen.h"

void *dino_runner (void *arg) {
	player *p = (player*) arg;

	while((p->ch = getch()) != 'q') {
		p->score++;
		clear();	
		disp(p);
		dino(p);
		p->i--;	
		timeout(70);
	}
	
	pthread_exit(0);
}

void *obs_runner (void *arg) {
	player *p = (player*) arg;
	if(p->score % 50 == 0) {
		addobstacles(p);

	}
	
	pthread_exit(0);
}


int main() {
	

	
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
	initobs(p->o);

	pthread_t t_dino, t_obs;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	
	//dinorunner
	pthread_create(&t_dino, &attr, dino_runner, p);

	//obsrunner
//	pthread_create(&t_obs, &attr, obs_runner, p);
	
	pthread_join(t_dino, NULL);
//	pthread_join(t_obs, NULL);
	endwin();
	return 0;
}
