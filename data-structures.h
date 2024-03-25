#ifndef _data_structures_h
#define _data_structures_h 1

enum COLOR {White, Gray, Black};
typedef struct TAG_VERTEX{
    int index;
    COLOR color;
    double key;  
    int pi;
    int position;
}VERTEX;

typedef struct TAG_NODE{
    int index;
    int u;
    int v;
    double w;
    TAG_NODE *next;
}NODE;

#endif