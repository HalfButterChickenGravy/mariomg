#ifndef __OBSTACLES_H
#define __OBSTACLES_H

#include <string.h>
#include "gamedata.h"


typedef struct obstacle {
	char shape[5][10];
	int p[17];
	int pcount;
	int height;
} obstacle;

void initobs(obstacle *tree);
void printobstacle (obstacle *x, int obsloc);
int checkcollision (obstacle *x, int obsloc, int dinopos);
int addobstacles (player *p);


#endif
