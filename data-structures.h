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
    int index; //This will be the index of the edge in the file
    int startVertex;  //This will be where the edge starts at 
    int endVertex;    // In an undirected graph, the order of startVertex and endVertex will not matter. 
    double weight; //Weight of the edge
    TAG_NODE *next;
    /* This is a linked list which will hold all the next nodes of a vertex, based off of startVertex

        If the flag is 1, insert at the beginning of the linked list
        If the flag is 2, insert at the end of the linked list

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