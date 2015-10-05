/*
 * edgequeue.c
 *
 *  Created on: Jun 8, 2015
 *      Author: david
 */


#include "edge.h"
#include "edgequeue.h"

/**
 * Create an edgequeue of the default size
 */
edgequeue * createDefaultEdgeQueue() {
	edgequeue *q = (edgequeue *) malloc(sizeof(edgequeue));
	q->qlen = 32;
	q->head = 0;
	q->tail = 0;
	q->queue = (edge **)malloc(32*sizeof(size_t));
	return q;
}

/**
 * Create an edgequeue of specified size
 */
edgequeue * createEdgeQueue(size_t eqlen) {
	if (eqlen <= 0) return NULL;
	edgequeue *q = (edgequeue *) malloc(sizeof(edgequeue));
	q->qlen = eqlen;
	q->head = 0;
	q->tail = 0;
	q->queue = (edge **)malloc(eqlen*sizeof(size_t));
	return q;
}

/**
 * Free up the resources used by this queue
**/
void freeEdgeQueue(edgequeue *q) {
	free(q->queue);
	free(q);
}


/**
 * Is the queue empty?
 */
bool eqEmpty(const edgequeue *eq) {
	return (eq->head == eq->tail);
}

/**
 * Does the queue contain the given edge?
 */
bool eqContains(const edge *e, const edgequeue *eq) {
	bool hasval = false;
	if (eqEmpty(eq)) return false;
	size_t index = eq->head;
	edge *curredge;
	while (index < eq->tail) {
		curredge = eq->queue[index];
		//null check
		if (curredge == NULL) {
			hasval = false;
			index = eq->tail;
		} else {
			hasval = curredge->u == e->u && curredge->v == e->v;
			if (hasval) index = eq->tail;  //jump out if found
		}
		++index;
	}
	return hasval;
}

/**
 * Add an edge to the queue
 */
void eqAdd(edge *e, edgequeue *eq) {
	//check length of current array--double size if we're full
	if (eq->tail > eq->qlen) {
		size_t olen = eq->qlen;
		size_t nlen = 2*olen;
		edge **currq = eq->queue;
		edge **newq = (edge **) malloc(nlen*sizeof(size_t));
		//Copy the pointers from old to new		
		size_t diff = eq->tail - eq->head;
		for (size_t i=0;i<diff;i++) {
			newq[i] = currq[eq->head + i];
		}
		free(eq->queue);
		eq->queue = newq;
		eq->qlen = nlen;
		eq->head = 0;
		eq->tail = diff;
	}
	//add the new element to the queue
	eq->queue[eq->tail] = e;
	eq->tail = eq->tail + 1;
}

/**
 * View but do not remove the top item
 *
 * Return pointer to null if queue is empty
 */
edge * eqPeek(edgequeue *eq) {
	if (eqEmpty(eq)) return NULL;
	return eq->queue[eq->head];	
}

/**
 * Retrieve the top item
 */
edge * eqPop(edgequeue *eq) {
	if (eqEmpty(eq)) return NULL;
	size_t tindex = eq->head;
	edge *top = eq->queue[tindex];
	eq->head = tindex+1;
	return top;
}

