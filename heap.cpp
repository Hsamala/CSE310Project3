#include "heap.h"

void minHeapify(HEAP* passedHeap, int currentIndex) {

   int left, right, smallest;
   left = 2 * currentIndex + 1;
   right = 2 * currentIndex + 2;

   smallest = currentIndex;

   if( (left < passedHeap->size) && (right < passedHeap->size) ) {

        if(passedHeap->p_A[left]->key < passedHeap->p_A[smallest]->key) {
        
            smallest  = left;

        }

        if(passedHeap->p_A[right]->key < passedHeap->p_A[smallest]->key) {
        
            smallest  = right;
        
        }   

        if(smallest != currentIndex) {

            ELEMENT* p_temp = passedHeap->p_A[currentIndex];
            passedHeap->p_A[currentIndex] = passedHeap->p_A[smallest];
            passedHeap->p_A[smallest] = p_temp;
            minHeapify(passedHeap, smallest);

        }

   }

}

void createMinHeap(HEAP* passedHeap) {

    int n = passedHeap->size;

    n--;

    for(int i = n / 2; i >= 0; i--) {
        minHeapify(passedHeap, i);
    }

}


void insertHeap(HEAP* passedHeap, VERTEX* p_currentVertex) {

    ELEMENT* p_newElement = new ELEMENT;
    p_newElement->key = p_currentVertex->key;
    p_newElement->vertexIndex = p_currentVertex->adjanceyIndex;

    int currentIndex = passedHeap->size;
    passedHeap->p_A[currentIndex] = p_newElement;
    passedHeap->size += 1;

    (void)decreaseIndexValue(passedHeap, passedHeap->size, p_newElement->key); 

}

ELEMENT* ExtractMinHeap(HEAP* passedHeap) {

    if(passedHeap->size == 1) {
        return passedHeap->p_A[0];
    }else if(passedHeap->size <= 2) {
        ELEMENT* p_temp = passedHeap->p_A[1];
        passedHeap->p_A[1] = passedHeap->p_A[0];
        passedHeap->p_A[0] = p_temp;  
        passedHeap->size -= 1;
    } else {
    
        ELEMENT* p_temp = passedHeap->p_A[passedHeap->size - 1];
        passedHeap->p_A[passedHeap->size - 1] = passedHeap->p_A[0];
        passedHeap->p_A[0] = p_temp;

        passedHeap->size -= 1;

        minHeapify(passedHeap, 0);
    }

    return passedHeap->p_A[passedHeap->size - 1];

}

int decreaseIndexValue(HEAP* passedHeap, int index, int decreasedValue) {

    int actualIndex = index - 1;

    if(actualIndex > passedHeap->size) {
        return 0;
    } else {

        if(passedHeap->p_A[actualIndex]->key < decreasedValue) {
            return 0;
        }

        passedHeap->p_A[actualIndex]->key = decreasedValue;

        int parent = (actualIndex - 1) / 2;

        while(passedHeap->p_A[actualIndex]->key < passedHeap->p_A[parent]->key) {
            ELEMENT* p_temp = passedHeap->p_A[actualIndex];
            passedHeap->p_A[actualIndex] = passedHeap->p_A[parent];
            passedHeap->p_A[parent] = p_temp;

            actualIndex = parent;
            parent = (actualIndex - 1) / 2;

        }

        return actualIndex;

    }

}