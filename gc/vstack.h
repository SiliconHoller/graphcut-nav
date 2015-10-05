/**
 * Vertex stack structure and operations
**/

#ifndef VSTACK_H_
#define VSTACK_H_

#include <stdlib.h>
#include <stdbool.h>

struct vertexstack {
	size_t slen;
	size_t head;
	size_t *stack;
};

typedef struct vertexstack vstack;

/**
 * Create a new stack of default size
**/
vstack * createDefaultVertexStack();

/**
 * Create a new stack of a given size
**/
vstack * createVertexStack(size_t ssize);

/**
 * Push a vertex value on the stack
**/
void pushVertex(size_t *v, vstack *stack);

/**
 * Is the stack empty?
**/
bool vstackEmpty(vstack *stack);

/**
 * Does the stack contain the given value?
**/
bool vstackContains(size_t *v, vstack *stack);

/**
 * Look at, but do not remove, the top value of the stack
**/
size_t * vstackPeek(vstack *stack);

/**
 * Retrieve the top value (remove) of the stack
**/
size_t * vstackPop(vstack *stack);

/**
 * Free the memory associated with the vertexstack
**/
void freeVertexStack(vstack *stack);

#endif /*VSTACK_H_*/
