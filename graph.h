#ifndef graph_h
#define graph_h 1
#include "data_structures.h"

int relax(VERTEX* p_uVertex, VERTEX* p_vVertex, float edgeWeight);
int computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source, int numOfVertex);
int computeSinglePair(VERTEX** vertexList, NODE** adjacencyList, int source, int destination, int numOfVertex);
#endif