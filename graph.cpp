#include "graph.h"
#include "heap.h"

int computeSinglePair(VERTEX** vertexList, NODE** adjacencyList, int source, int destination, int numOfVertex) {

    VERTEX* p_uVertex; 
    VERTEX* p_vVertex;
    int relaxSuccess; 

    vector<VERTEX*> p_vertexStack;
    HEAP* p_graphHeap = new HEAP;
    p_graphHeap->size = 0;
    p_graphHeap->p_A = new ELEMENT*[numOfVertex];

    vertexList[source - 1]->key = 0;

    for(int i = 0; i < numOfVertex; i++) {
        insertHeap(p_graphHeap, vertexList[i]);
    }

    while(p_graphHeap->size != 0) {
        p_uVertex = ExtractMinHeap(p_graphHeap)->p_ElementVertex;

        if(p_uVertex->adjanceyIndex == destination) {
            break;
        }

        p_vertexStack.push_back(p_uVertex);

        NODE* p_vertexList = adjacencyList[p_uVertex->adjanceyIndex - 1];

        while(p_vertexList != NULL) {

            p_vVertex = vertexList[p_vertexList->endVertex - 1];

            relaxSuccess = relax(p_uVertex, p_vVertex, p_vertexList->weight);

            if(relaxSuccess == 1) {
                decreaseIndexValue(p_graphHeap, p_graphHeap->p_A[p_vVertex->heapPosition], p_vVertex->key);
            }

            p_vertexList = p_vertexList->next;

        }

    }

    return source;

}

int computeSingleSource(VERTEX** vertexList, NODE** adjacencyList, int source, int numOfVertex) {

    VERTEX* p_uVertex; 
    VERTEX* p_vVertex;
    int relaxSuccess; 

    vector<VERTEX*> p_vertexStack;
    HEAP* p_graphHeap = new HEAP;
    p_graphHeap->size = 0;
    p_graphHeap->p_A = new ELEMENT*[numOfVertex];

    vertexList[source - 1]->key = 0;

    for(int i = 0; i < numOfVertex; i++) {
        insertHeap(p_graphHeap, vertexList[i]);
    }

    while(p_graphHeap->size != 0) {
        p_uVertex = ExtractMinHeap(p_graphHeap)->p_ElementVertex;

        p_vertexStack.push_back(p_uVertex);

        NODE* p_vertexList = adjacencyList[p_uVertex->adjanceyIndex - 1];

        while(p_vertexList != NULL) {

            p_vVertex = vertexList[p_vertexList->endVertex - 1];

            relaxSuccess = relax(p_uVertex, p_vVertex, p_vertexList->weight);

            if(relaxSuccess == 1) {
                decreaseIndexValue(p_graphHeap, p_graphHeap->p_A[p_vVertex->heapPosition], p_vVertex->key);
            }

            p_vertexList = p_vertexList->next;

        }

    }

    return source;

}

int relax(VERTEX* p_uVertex, VERTEX* p_vVertex, float edgeWeight) {

    if( p_vVertex->key > (p_uVertex->key + edgeWeight) ) {
        p_vVertex->key = p_uVertex->key + edgeWeight;
        p_vVertex->pi = p_uVertex->adjanceyIndex;
        return 1;
    }

    return 0;

}