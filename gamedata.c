#include "gamedata.h"
#include <limits.h>
#include <stdlib.h>


void initgame(player *p) {
	p = (player*) malloc(sizeof(player));
	p->score = 0;	
	p->i = INT_MAX;
}
