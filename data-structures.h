#ifndef _data_structures_h
#define _data_structures_h 1

enum COLOR {White, Black, Gray};

typedef struct TAG_VERTEX{
    int index;
    COLOR color;
    double key; //Must update everytime we relax the graph
    int pi;
    int position;
} VERTEX;


#endif