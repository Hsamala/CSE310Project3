#ifndef _util.h
#define _util.h 1
#include "data_structures.h"

VERTEX** buildVertexList(FILE* p_currentFile, VERTEX** p_vertexList, int numOfVertex);
NODE**  buildAdjanceyList(FILE* p_currentFile, NODE** p_adjacencyList , int numeOfEdges);
void printAdjanceyList(NODE** adjanceyList);
int getNextInstruction(char* Word, int* parameter1, int* parameter2);

#endif