/**
 *
 * graphmgt.c
 * Created June 11, 2015
 * David Days
**/

#include "graphmgt.h"

/**
 * Create a navigation graph
**/
ugraph * create2dUNavGraph(int w, int h, int nLabels) {
	//Create the basic structure
	ugraph *g = (ugraph *)malloc(sizeof(ugraph));
	int vlen = w*h;
	int vtot = vlen + nLabels;
	g->numLabels = nLabels;
	g->numVertices = vlen;
	g->edges = (edge **)malloc(vtot*sizeof(size_t));
	g->labels = (size_t *)malloc(nLabels*sizeof(size_t));
	for (int i=0;i<nLabels;i++) {
		g->labels[i] = vlen+i;
	}
	g->parents = (size_t *)malloc(vlen*sizeof(size_t));
	return g;
}

/**
 * Free the resources allocated to this graph structure
**/
void freeGraph(ugraph *g) {
	
	//empty out the edge array
	size_t vtot = g->numLabels + g-> numVertices;
	edge *elist;
	edge *curre;	
	for (size_t i=0;i<vtot;i++) {
		elist = g->edges[i];
		curre = elist;
		while (curre != NULL) {
			edge *fe = curre;
			curre = fe->next;
			free(fe);
		}
	}
	//free up the edge array
	free(g->edges);
	//free up the labels array
	free(g->labels);
	//Free up the parents array
	free(g->parents);
	//Finally, free up the graph structure
	free(g);
}
