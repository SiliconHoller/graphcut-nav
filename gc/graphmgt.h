/*
 * graphmgt.h
 *
 *  Created on: Jun 11, 2015
 *      Author: david
 */

#ifndef GRAPHMGT_H_
#define GRAPHMGT_H_

#include <stdio.h>
#include <stdlib.h>
#include "ugraph.h"


/**
 * Create a navigation graph
**/
ugraph * create2dUNavGraph(int w, int h, int nLabels);

/**
 * Free the resources allocated to this graph structure
**/
void freeGraph(ugraph *g);
 
#endif /* GRAPHMGT_H_ */
