#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include "gamedata.h"
#include "obstacles.h"

void initobs(obstacle *tree) {

tree = (obstacle *) malloc(5 * sizeof(obstacle));

///////////////////////////////////////////////////////////////////////////////////////
//Obstacle types (NO_OF_OBS)


/* Obstacle type 1

# |
|_|_#
  |

 * Collision points 
 * 1, 3
 * 2, 3
 * 3, 3
 * 4, 2
 * 5, 2

 */

tree[0].height = 3;
strcpy(tree[0].shape[0], "# |");
strcpy(tree[0].shape[1], "|_|_#");
strcpy(tree[0].shape[2], "  |");

tree[0].pcount = 5;
tree[0].p[0] = 3;
tree[0].p[1] = 3;
tree[0].p[2] = 3;
tree[0].p[3] = 2;
tree[0].p[4] = 2;

tree[0].p[5] = 2;
tree[0].p[6] = 2;
tree[0].p[7] = 2;
tree[0].p[8] = 2;
tree[0].p[9] = 2;
tree[0].p[10] = 2;
tree[0].p[11] = 2;


/* Obstacle type 2

  #
|_| #
  |/

 * Collision points 
 * 1, 3
 * 2, 3
 * 3, 3
 * 4, 2
 * 5, 2

 */

tree[1].height = 3;
strcpy(tree[1].shape[0], "  #");
strcpy(tree[1].shape[1], "|_| #");
strcpy(tree[1].shape[2], "  |/");

tree[1].pcount = 5;
tree[1].p[0] = 3;
tree[1].p[1] = 3;
tree[1].p[2] = 3;
tree[1].p[3] = 2;
tree[1].p[4] = 2;

tree[1].p[5] = 2;
tree[1].p[6] = 2;
tree[1].p[7] = 2;
tree[1].p[8] = 2;
tree[1].p[9] = 2;
tree[1].p[10] = 2;
tree[1].p[11] = 2;



/* Obstacle type 3

  #
|_| #_|
  | |

 * Collision points 
 * 1, 3
 * 2, 3
 * 3, 3
 * 4, 2
 * 5, 2
 * 6, 2
 * 7, 2

 */

tree[2].height = 3;
strcpy(tree[2].shape[0], "  #");
strcpy(tree[2].shape[1], "|_| #_|");
strcpy(tree[2].shape[2], "  | |");

tree[2].pcount = 7;
tree[2].p[0] = 3;
tree[2].p[1] = 3;
tree[2].p[2] = 3;
tree[2].p[3] = 2;
tree[2].p[4] = 2;
tree[2].p[5] = 2;
tree[2].p[6] = 2;

tree[2].p[7] = 2;
tree[2].p[8] = 2;
tree[2].p[9] = 2;
tree[2].p[10] = 2;
tree[2].p[11] = 2;
tree[2].p[12] = 2;
tree[2].p[13] = 2;



/* Obstacle type 4

  #
# #
|_|_#
  |

 * Collision points 
 * 1, 4
 * 2, 4
 * 3, 4
 * 4, 2
 * 5, 2

 */

tree[3].height = 4;
strcpy(tree[3].shape[0], "  #");
strcpy(tree[3].shape[1], "# #");
strcpy(tree[3].shape[2], "|_|_#");
strcpy(tree[3].shape[3], "  |");

tree[3].pcount = 5;
tree[3].p[0] = 4;
tree[3].p[1] = 4;
tree[3].p[2] = 4;
tree[3].p[3] = 2;
tree[3].p[4] = 2;

tree[3].p[5] = 2;
tree[3].p[6] = 2;
tree[3].p[7] = 2;
tree[3].p[8] = 2;
tree[3].p[9] = 2;
tree[3].p[10] = 2;
tree[3].p[11] = 2;



/* Obstacle type 5

  #     
# # # # 
|_|_# |_#
  |   |

 * Collision points 
 * 1, 4
 * 2, 4
 * 3, 4
 * 4, 3
 * 5, 3
 * 6, 3
 * 7, 3
 * 8, 2
 * 9, 2

 */

tree[4].height = 4;
strcpy(tree[4].shape[0], "  #");
strcpy(tree[4].shape[1], "# # # #");
strcpy(tree[4].shape[2], "|_|_# |_#");
strcpy(tree[4].shape[3], "  |   |");

tree[4].pcount = 7;
tree[4].p[0] = 4;
tree[4].p[1] = 4;
tree[4].p[2] = 4;
tree[4].p[3] = 3;
tree[4].p[4] = 3;
tree[4].p[5] = 3;
tree[4].p[6] = 3;
tree[4].p[7] = 2;
tree[4].p[8] = 2;

tree[4].p[9] = 2;
tree[4].p[10] = 2;
tree[4].p[11] = 2;
tree[4].p[12] = 2;
tree[4].p[13] = 2;
tree[4].p[14] = 2;
tree[4].p[15] = 2;






//Obstacle types end
///////////////////////////////////////////////////////////////////////////////////////


}



void printobstacle (obstacle *x, int obsloc) {

	int i, y;
	initscr();
	noecho();
	curs_set(0);
	for(i = 0; i < x->height; i++) {
		y = 16 - i;
		mvprintw(y, obsloc, x->shape[i]);
	}
	refresh();
}




int checkcollision (obstacle *x, int obsloc, int dinopos) {
	//dino pos 16,12
	//h = 5, b = 7
	//vertically 11 to 16
	//horizontally 12 to 19	
	int state, i;
	state = 19 - obsloc;	
		
	if (state < 0)
		return 0;
	
	for(i = 0; i < x->pcount + 7; i++) {
		if(state == i) {
			if(dinopos <= x->p[state])
				return 1;
			
		}
	}
	
	return 0;
}

int addobsctacles (player *p) {
	

	int type, i;		
	srand(time(NULL));		
	type = p->score > 300 ? rand() % 5 : rand() % 3 ;
	for(i = 99; i >= 0; i--) {
		printobstacle(&p->o[type], i);
		timeout(70);
		if(checkcollision(&p->o[type], i, p->dinopos))
			return 0;
	}
	return 1;
}













