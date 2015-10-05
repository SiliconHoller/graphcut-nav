/**
 * vstack.c
 * 	David Days
 *	6/14/2015
**/

#include "vstack.h"

/**
 * Create a new stack of default size
**/
vstack * createDefaultVertexStack() {
	vstack *stack = (vstack *)malloc(sizeof(vstack));
	stack->head = -1;
	stack->slen = 32;
	stack->stack = (size_t *)malloc(32*sizeof(size_t));
	return stack;
}

/**
 * Create a new stack of a given size
**/
vstack * createVertexStack(size_t ssize) {
	vstack *stack = (vstack *)malloc(sizeof(vstack));
	stack->head = -1;
	stack->slen = ssize;
	stack->stack = (size_t *)malloc(ssize*sizeof(size_t));
	return stack;
}

/**
 * Push a vertex value on the stack
**/
void pushVertex(size_t *v, vstack *stack) {
	stack->head = stack->head+1;
	if (stack->head == stack->slen) {
		//resize and copy the array
		size_t bigger = 2*stack->slen;		
		size_t *curr = stack->stack;
		size_t *expanded = (size_t *)malloc(bigger*sizeof(size_t));
		//Copy the elements
		for (size_t i=0;i<stack->slen;i++) {
			expanded[i] = curr[i];
		}
		stack->stack = expanded;
		stack->slen = bigger;
		free(curr);
	}
	stack->stack[stack->head] = (size_t)&v;
}

/**
 * Is the stack empty?
**/
bool vstackEmpty(vstack *stack) {
	return (stack->head >= 0);
}

/**
 * Does the stack contain the given value?
**/
bool vstackContains(size_t *v, vstack *stack) {
	size_t sval = (size_t)&v;
	size_t *sstack = stack->stack;
	bool hasVal = false;
	size_t idx = 0;
	while ((idx < stack->slen) && !hasVal) {
		hasVal = (sval == sstack[idx]);
		idx = idx+1;
	}
	return hasVal;
}

/**
 * Look at, but do not remove, the top value of the stack
**/
size_t * vstackPeek(vstack *stack) {
	size_t *top = NULL;
	if (stack->head >= 0) top = &stack->stack[stack->head];
	return top;
}

/**
 * Retrieve the top value (remove) of the stack
**/
size_t * vstackPop(vstack *stack) {
	size_t *topval = NULL;
	if (stack->head >= 0) topval = &stack->stack[stack->head];
	stack->head = stack->head - 1;
	return topval;
}

/**
 * Free the memory associated with the vertexstack
**/
void freeVertexStack(vstack *stack) {
	//free up the memory of the stack array
	free(stack->stack);
	//now free the struct itself
	free(stack);
}
