#ifndef _data_structures_h
#define _data_structures_h 1

enum COLOR {White, Gray, Black};
typedef struct TAG_VERTEX{
    int adjanceyIndex;
    int pi;
    int heapPosition;
    COLOR color;
    double key;  //Will be intialized to a really high number, change as you find the least weight to traverse thru the node
}VERTEX;

typedef struct TAG_NODE{
    int index; //This will be the number corresponding to the vertex, it will hold the adjancey list of that node 
    int startVertex; 
    int endVertex;    // In an undirected graph, the order of startVertex and endVertex will not matter. 
    double weight; //Weight of the edge
    TAG_NODE *next;
    /* This is a linked list which will hold  
    */
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