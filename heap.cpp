#include "heap.h"

void minHeapify(HEAP* passedHeap, int currentIndex) {

   int left, right, smallest;
   left = 2 * currentIndex + 1;
   right = 2 * currentIndex + 2;

   smallest = currentIndex;

   if( (left < passedHeap->size) && (right < passedHeap->size) ) {

        if(passedHeap->p_A[left]->p_ElementVertex->key < passedHeap->p_A[smallest]->p_ElementVertex->key) {
        
            smallest  = left;

        }

        if(passedHeap->p_A[right]->p_ElementVertex->key < passedHeap->p_A[smallest]->p_ElementVertex->key) {
        
            smallest  = right;
        
        }   

        if(smallest != currentIndex) {

            ELEMENT* p_temp = passedHeap->p_A[currentIndex];
            passedHeap->p_A[currentIndex] = passedHeap->p_A[smallest];
            passedHeap->p_A[smallest] = p_temp;

            swapVertexIndex(passedHeap, currentIndex, smallest);

            minHeapify(passedHeap, smallest);

        }

   }

}

void createMinHeap(HEAP* passedHeap) {

    int n = passedHeap->size;

    n--;

    for(int i = n / 2; i >= 0; i--) {
        //minHeapify(passedHeap, i);
    }

}


void insertHeap(HEAP* passedHeap, VERTEX* p_currentVertex) {

    ELEMENT* p_newElement = new ELEMENT;
    p_newElement->p_ElementVertex = p_currentVertex;

    int currentIndex = passedHeap->size;
    p_newElement->p_ElementVertex->heapPosition = currentIndex;
    passedHeap->p_A[currentIndex] = p_newElement;

    passedHeap->size += 1;

    (void)decreaseIndexValue(passedHeap, p_newElement, p_newElement->p_ElementVertex->key);

}

ELEMENT* ExtractMinHeap(HEAP* passedHeap) {

    ELEMENT* p_temp;

    if(passedHeap->size == 1) {
        return passedHeap->p_A[0];
        passedHeap->size -= 1;
    }else if(passedHeap->size <= 2) {
        p_temp = passedHeap->p_A[1];
        passedHeap->p_A[1] = passedHeap->p_A[0];
        passedHeap->p_A[0] = p_temp;  
        passedHeap->size -= 1;

        swapVertexIndex(passedHeap, 0, 1);

    } else {
    
        p_temp = passedHeap->p_A[passedHeap->size - 1];
        passedHeap->p_A[passedHeap->size - 1] = passedHeap->p_A[0];
        passedHeap->p_A[0] = p_temp;

        swapVertexIndex(passedHeap, 0, passedHeap->size - 1);

        passedHeap->size -= 1;

        minHeapify(passedHeap, 0);
    }

    return passedHeap->p_A[passedHeap->size];

}

void decreaseIndexValue(HEAP* passedHeap, ELEMENT* p_passedVertex, int decreasedValue) {

    if(decreasedValue > p_passedVertex->p_ElementVertex->key) {
        cerr << "New key is larger than the current key" << endl;
    } else {

        int actualIndex = p_passedVertex->p_ElementVertex->heapPosition;
        int parent = (actualIndex - 1) / 2;

        while( (actualIndex > 0) && (passedHeap->p_A[actualIndex]->p_ElementVertex->key < passedHeap->p_A[parent]->p_ElementVertex->key) ) {

            ELEMENT* p_temp = passedHeap->p_A[actualIndex];
            passedHeap->p_A[actualIndex] = passedHeap->p_A[parent];
            passedHeap->p_A[parent] = p_temp;

            swapVertexIndex(passedHeap, parent, actualIndex);

            actualIndex = parent;
            parent = (actualIndex - 1) / 2;

        }


    }

}

void swapVertexIndex(HEAP* passedHeap, int vertex1Index, int  vertex2Index) {

   int temp = passedHeap->p_A[vertex1Index]->p_ElementVertex->heapPosition;
   passedHeap->p_A[vertex1Index]->p_ElementVertex->heapPosition = passedHeap->p_A[vertex2Index]->p_ElementVertex->heapPosition;
   passedHeap->p_A[vertex2Index]->p_ElementVertex->heapPosition = temp; 

}