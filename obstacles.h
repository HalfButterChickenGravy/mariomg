#ifndef __OBSTACLES_H
#define __OBSTACLES_H

#include <string.h>

typedef struct obstacle {
	char shape[5][10];
	int p[17];
	int pcount;
	int height;
} obstacle;

#endif
