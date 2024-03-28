#include "util.h"
#include "stack.h"
#include "heap.h"
#include "graph.h"
#include "data_structures.h"

int main(int argc, char **argv) {

    FILE* p_currentFile = NULL;
    int commandType, parameter1, parameter2, numOfVertex, sizeOfAdjList;
    char instructions[100];
    VERTEX** p_vertexList;
    NODE** p_adjacencyList;

    if(argc < 4) {
        fprintf(stderr, "Usage %s <InputFile> <GraphType> flag\n", argv[0]);
        exit(0);
    }

    p_currentFile = fopen(argv[1], "r");

    if(p_currentFile == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }

    if(fscanf(p_currentFile, "%d %d", &numOfVertex, &sizeOfAdjList) == 0) {
        fprintf(stderr, "Error: Could not find Vertex Size\n");
    }

    buildVertexList(p_currentFile, p_vertexList, numOfVertex);

    while(1) {

        int commandType = getNextInstruction(instructions, &parameter1, &parameter2);

         switch(commandType) {

            case 0:
                fprintf(stderr, "Invalid Instruction\n");
                break;
            case 1:
                printAdjanceyList(p_adjacencyList);
                break;
            case 2:
                computeSinglePair(p_vertexList, p_adjacencyList, parameter1, parameter2);
                break;
            case 3:
                computeSingleSource(p_vertexList, p_adjacencyList, parameter1);
                break;
            case 4:
                printLength();
                break;
            case 5:
                printPath();
                break;
         }       
            
    }


}
