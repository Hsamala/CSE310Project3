#ifndef heap_h
#define heap_h 1
#include "data_structures.h"

void minHeapify(HEAP* passedHeap, int currentIndex);
void createMinHeap(HEAP* passedHeap);
void insertHeap(HEAP* passedHeap, VERTEX* p_currentVertex);
ELEMENT* ExtractMinHeap(HEAP* passedHeap); 
int decreaseIndexValue(HEAP* passedHeap, int index, int decreasedValue);
#endif