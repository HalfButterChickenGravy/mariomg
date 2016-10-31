#ifndef __GAMEDATA_H
#define __GAMEDATA_H

#include "screen.h"
typedef struct obstacle obstacle;

typedef struct player {
	int score;
	int i; //reverseframeno
	char ch; //userinput
	int obsloc;
	int dinopos;
	obstacle *o;
//	p_character type;	
	
} player;

#include "obstacles.h"

void initgame(player *p);




#endif
