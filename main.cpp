#include "util.h"
#include "data_structures.h"

int main(int argc, char **argv) {

    FILE* p_currentFile;
    int commandType, parameter1, parameter2, numOfVertex, sizeOfAdjList;
    char instructions[100];
    VERTEX** p_vertexList;
    NODE** p_adjacencyList;

    if(argc < 4) {
        fprintf(stderr, "Usage %s <ifile> <ofile> flag\n", argv[0]);
        exit(0);
    }

    while(1) {

        p_currentFile = fopen(argv[1], "r");

        if(p_currentFile == NULL) {
            fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
            exit(0);
        }

        int commandType = getNextInstruction(instructions, &parameter1, &parameter2);

         switch(commandType) {
            case 1:
                printAdjanceyList(p_adjacencyList);
                break;
           
         }       
            
    }


}