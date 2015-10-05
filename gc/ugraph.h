/*
 * ugraph.h
 *
 *  Created on: Jun 8, 2015
 *      Author: david
 */

#ifndef UGRAPH_H_
#define UGRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

/**
 * Undirected graph structure
 */
struct undirgraph {
	size_t numLabels;
	size_t numVertices;
	edge **edges;
	size_t *labels;
	size_t *parents;
};

typedef struct undirgraph ugraph;
#endif /* UGRAPH_H_ */
