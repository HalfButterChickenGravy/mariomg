#include <ncurses.h>
#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include "gamedata.h"


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
	if(p->score % 150 == 0) {
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
	initgame(p);
	initobs(p->o);

	pthread_t t_dino, t_obs;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	
	//dinorunner
	pthread_create(&t_dino, &attr, dino_runner, p);

	//obsrunner
	pthread_create(&t_obs, &attr, obs_runner, p);
	
	pthread_join(t_obs, NULL);
	endwin();
}
