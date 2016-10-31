#ifndef __GAMEDATA_H
#define __GAMEDATA_H

#include "screen.h"
#include "obstacles.h"

typedef struct player {
	int score;
	int i; //reverseframeno
	char ch; //userinput
	int obsloc;
	int dinopos;
	obstacle *o;
//	p_character type;	
	
} player;



void initgame(player *p);

#endif
