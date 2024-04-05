#include "graph.h"
#include "heap.h"

void computeSinglePair(VERTEX** vertexList, NODE** adjacencyList, int source, int destination) {

    fprintf(stdout, "This is the compute Single Pair command\n");

}

void computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source, int numOfVertex) {

    vector<VERTEX*> p_vertexStack;
    HEAP* p_graphHeap = new HEAP;
    p_graphHeap->size = 0;
    p_graphHeap->p_A = new ELEMENT*[numOfVertex];

    vertexList[source]->key = 0;

    for(int i = 0; i < numOfVertex; i++) {
        insertHeap(p_graphHeap, vertexList[i]);
    }

}