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

void initobs(player *p);
void printobstacle (obstacle *x, int obsloc);
int checkcollision (obstacle *x, int obsloc, int dinopos);
int addobstacles (player *p);
void assignobs (player *p);

#endif
