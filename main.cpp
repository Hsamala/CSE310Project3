#include "util.h"

int main(int argc, char **argv) {

    cout << fixed;
    cout << setprecision(2);

    ifstream myCurrentFile;
    int commandType = 0, parameter1 = 0, parameter2 = 0, numOfVertex = 0, sizeOfAdjList = 0, flag = 0;
    bool directGraph = false;
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
    flag = *argv[3] - '0';
    if(strcmp(argv[2], "DirectedGraph") == 0) {
        directGraph = true;
    }

    p_vertexList = buildVertexList(numOfVertex);
    p_adjacencyList = buildAdjanceyList(myCurrentFile, numOfVertex, sizeOfAdjList, directGraph, flag);

    while(1) {

        int commandType = getNextInstruction(instructions, &parameter1, &parameter2);

         switch(commandType) {

            case 0:
                cerr << "Invalid Instruction" << endl;
                break;
            case 1:
                printAdjanceyList(p_adjacencyList, numOfVertex);
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
