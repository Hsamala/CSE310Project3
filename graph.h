#ifndef graph_h
#define graph_h 1
#include "data_structures.h"

int relax(VERTEX* p_uVertex, VERTEX* p_vVertex, int edgeWeight);
void computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source, int numOfVertex);
void computeSinglePair(VERTEX** vertexList, NODE** adjacencyList, int source, int destination, int numOfVertex);
#endif