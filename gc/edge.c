/*
 * edge.c
 *
 *  Created on: Jun 9, 2015
 *      Author: david
 */

#include "edge.h"

edge * createEdge() {
	edge *e = (edge *)malloc(sizeof(edge));
	return e;
}

void disposeEdge(edge *e) {
	free(e);
}



