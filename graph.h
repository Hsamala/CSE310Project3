#ifndef graph_h
#define graph_h 1
#include "data_structures.h"

void computeSingleSource(VERTEX** vertexList, int vertexSize, NODE** adjacencyList, int adjacencySize, int source);
void computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source);

#endif