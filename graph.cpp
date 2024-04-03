#include "graph.h"

void computeSinglePair(VERTEX** vertexList, NODE** adjacencyList, int source, int destination) {

    fprintf(stdout, "This is the compute Single Pair command\n");

}

void computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source) {

    vector<VERTEX*> p_vertexStack;
    vector<VERTEX*> p_vertexHeap;

    VERTEX* p_startVertex = vertexList[source];
    p_startVertex->key =0;


}