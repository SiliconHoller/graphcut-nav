/*
 * edge.h
 *
 *  Created on: Jun 8, 2015
 *      Author: david
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <stdlib.h>

/**
 * data structure to hold edge data
 */
struct segment {
	size_t u;
	size_t v;
	double capacity;
	double available;
	struct segment *next;
	struct segment *prev;
	struct segment *facenext;
	struct segment *faceprev;
	struct segment *twin;
};

typedef struct segment edge;


edge * createEdge();

void disposeEdge(edge *e);

#endif /* EDGE_H_ */
