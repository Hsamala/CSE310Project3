#ifndef _util.h
#define _util.h 1
#include "data_structures.h"

VERTEX** buildVertexList(int numOfVertex);
NODE**  buildAdjanceyList(int numeOfEdges);
void printAdjanceyList(NODE** adjanceyList);
int getNextInstruction(char* Word, int* parameter1, int* parameter2);

#endif