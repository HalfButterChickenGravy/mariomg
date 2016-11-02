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


#ifndef __GAMEDATA_H
#define __GAMEDATA_H


typedef struct obstacle obstacle;

typedef struct player {
	int score;
	int best;
	int i; //reverseframeno
	char ch; //userinput
	int obsloc;
	int obstype;
	int dinopos;
	obstacle *o;
	int state;
	int speed;
	
} player;
#include "screen.h"
#include "obstacles.h"




#endif
