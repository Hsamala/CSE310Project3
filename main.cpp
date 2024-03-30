#include "util.h"

int main(int argc, char **argv) {

    ifstream myCurrentFile;
    int commandType = 0, parameter1 = 0, parameter2 = 0, numOfVertex = 0, sizeOfAdjList = 0;
    char instructions[100];
    VERTEX** p_vertexList;
    NODE** p_adjacencyList;

    if(argc < 4) {
        fprintf(stderr, "Usage %s <InputFile> <GraphType> flag\n", argv[0]);
        exit(0);
    }

    myCurrentFile.open(argv[1]);

    if(myCurrentFile.is_open() == false) {
        cerr << "Error: cannot open file " << argv[1] << endl;
        exit(0);
    }

    myCurrentFile >> numOfVertex;
    myCurrentFile >> sizeOfAdjList;

    p_vertexList = buildVertexList(myCurrentFile, numOfVertex);

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
            case 6:
                exit(0);
                break;

         }       
            
    }


}
