#include "util.h"

int main() {

    VERTEX* p_1 = new VERTEX;
    p_1->adjanceyIndex = 1;
    p_1->pi = NULL;
    p_1->heapPosition = 0;
    p_1->color = White;
    p_1->key = 5;

   VERTEX* p_2 = new VERTEX;
    p_2->adjanceyIndex = 2;
    p_2->pi = NULL;
    p_2->heapPosition = 0;
    p_2->color = White;
    p_2->key = 2; 

    VERTEX* p_3 = new VERTEX;
    p_3->adjanceyIndex = 3;
    p_3->pi = NULL;
    p_3->heapPosition = 0;
    p_3->color = White;
    p_3->key = 4;

    VERTEX* p_4 = new VERTEX;
    p_4->adjanceyIndex = 4;
    p_4->pi = NULL;
    p_4->heapPosition = 0;
    p_4->color = White;
    p_4->key = 1;

    VERTEX*  p_5 = new VERTEX;
    p_5->adjanceyIndex = 5;
    p_5->pi = NULL;
    p_5->heapPosition = 0;
    p_5->color = White;
    p_5->key = 3;

   
    

}

/*
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

        commandType = getNextInstruction(instructions, &parameter1, &parameter2);

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
*/