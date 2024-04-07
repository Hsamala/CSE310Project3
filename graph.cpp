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

    vertexList[source - 1]->key = 0;

    for(int i = 0; i < numOfVertex; i++) {
        insertHeap(p_graphHeap, vertexList[i]);
    }

    while(p_graphHeap->size != 0) {
        VERTEX* p_uVertex = ExtractMinHeap(p_graphHeap)->p_ElementVertex;

        p_vertexStack.push_back(p_uVertex);

        

    }

}