#ifndef util_h
#define util_h 1
#include "data_structures.h"
#include "stack.h"
#include "heap.h"
#include "graph.h"

VERTEX** buildVertexList(int numOfVertex);
NODE**  buildAdjanceyList(istream& inputFile, int numOfVertex, int numeOfEdges, bool DirectedUndirected, int flag);
void printAdjanceyList(NODE** adjanceyList, int numeOfEdges);
int getNextInstruction(char* Word, int* parameter1, int* parameter2);

#endif