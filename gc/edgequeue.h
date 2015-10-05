/*
 * edgequeue.h
 *
 *  Created on: Jun 8, 2015
 *      Author: david
 */

#ifndef EDGEQUEUE_H_
#define EDGEQUEUE_H_

#include <stdlib.h>
#include <stdbool.h>
#include "edge.h"

struct equeue {
	size_t qlen;
	size_t head;
	size_t tail;
	edge **queue;
};

typedef struct equeue edgequeue;

/**
 * Create an edgequeue of the default size
 */
edgequeue * createDefaultEdgeQueue();

/**
 * Create an edgequeue of specified size
 */
edgequeue * createEdgeQueue(size_t eqlen);

/**
 * Free up the resources used by this queue
**/
void freeEdgeQueue(edgequeue *q);

/**
 * Is the queue empty?
 */
bool eqEmpty(const edgequeue *eq);

/**
 * Does the queue contain the given edge?
 */
bool eqContains(const edge *e, edgequeue const *eq);

/**
 * Add an edge to the queue
 */
void eqAdd(edge *e, edgequeue *eq);

/**
 * View but do not remove the top item
 *
 * Return pointer to null if queue is empty
 */
edge * eqPeek(edgequeue *eq);

/**
 * Retrieve the top item
 */
edge * eqPop(edgequeue *eq);

#endif /* EDGEQUEUE_H_ */
