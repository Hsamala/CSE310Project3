#ifndef _data_structures_h
#define _data_structures_h 1

enum COLOR {White, Gray, Black};
typedef struct TAG_VERTEX{
    int adjanceyIndex;
    COLOR color;
    double key;  
    int pi;
    int heapPosition;
}VERTEX;

typedef struct TAG_NODE{
    int index;
    int u;
    int v;
    double w;
    TAG_NODE *next;
}NODE;


typedef struct TAG_ELEMENT {
    double key;
    // other fields as you see fit
}ELEMENT;

typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */
    ELEMENT* p_A; /* array of pointers to ELEMENT */
    // other fields as you see fit
}HEAP;


#endif