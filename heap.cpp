#include "heap.h"

void minHeapify(vector<VERTEX*>& currentHeap, int currentIndex) {

   int left, right, smallest;
   left = 2 * currentIndex + 1;
   right = 2 * currentIndex + 2;

   smallest = currentIndex;

   if( (left < currentHeap.size() ) && (right < currentHeap.size()) ) {

        if( currentHeap[left]->key < currentHeap[smallest]->key ) {
            smallest = left;
        }

        if( currentHeap[right]->key < currentHeap[smallest]->key ) {
            smallest = right;
        }

        if(smallest != currentIndex) {
            VERTEX* p_temp = currentHeap[currentIndex];
            currentHeap[currentIndex] = currentHeap[smallest];
            currentHeap[smallest] = p_temp;
            minHeapify(currentHeap, smallest);
        }

   }

}


VERTEX* ExtractMin(vector<VERTEX*>& currentHeap) {
    
    VERTEX* p_temp;
    
    if(currentHeap.size() == 1) {
        return currentHeap[0];
    } else {

        p_temp = currentHeap[0];
        currentHeap[0] = currentHeap[currentHeap.size() - 1];
        currentHeap[currentHeap.size() - 1] = p_temp;

        minHeapify(currentHeap, 0);

    }

    return p_temp;
}

void Insert(vector<VERTEX*>& currentHeap, VERTEX* p_addNode) {

    if(currentHeap.size() < 2) {
       currentHeap.push_back(p_addNode); 
       p_addNode->heapPosition = currentHeap.size() - 1;
    } else {
        currentHeap.push_back(p_addNode);
        p_addNode->heapPosition = currentHeap.size() - 1;
        decreaseIndexValue(currentHeap, p_addNode->heapPosition, p_addNode->key);
    }

}

void decreaseIndexValue(vector<VERTEX*>& currentHeap, int index, int decreasedValue) {

    currentHeap[index]->key = decreasedValue;

    int parent = index / 2;

    while(currentHeap[index]->key < currentHeap[parent]->key) {

        VERTEX* p_temp = currentHeap[index];
        currentHeap[index] = currentHeap[parent];
        currentHeap[parent] = p_temp;

        index = parent;
        parent = index / 2;

    }


}