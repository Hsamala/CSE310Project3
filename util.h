#ifndef util_h
#define util_h 1
#include "data_structures.h"
#include "stack.h"
#include "heap.h"
#include "graph.h"

VERTEX** buildVertexList(ifstream& inputFile, int numOfVertex);
NODE**  buildAdjanceyList(istream& inputFile, NODE** p_adjacencyList , int numeOfEdges);
void printAdjanceyList(NODE** adjanceyList);
int getNextInstruction(char* Word, int* parameter1, int* parameter2);

#endif