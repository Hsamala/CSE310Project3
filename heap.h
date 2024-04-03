#ifndef heap_h
#define heap_h 1
#include "data_structures.h"

void minHeapify(vector<VERTEX*>& currentHeap, int currentIndex);
VERTEX* ExtractMin(vector<VERTEX*>& currentHeap);
void Insert(vector<VERTEX*>& currentHeap, VERTEX* p_addNode);
void decreaseIndexValue(vector<VERTEX*>& currentHeap, int index, int decreasedValue);

#endif