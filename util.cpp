#include "util.h"

VERTEX** buildVertexList(ifstream& inputFile, int numOfVertex)  {
    int adjIndex = 0;
    VERTEX**  p_newVertexList = new VERTEX*[numOfVertex];

    VERTEX* p_newVertex; 

    if(inputFile.is_open() == false) {
        cerr << "Error: cannot open file " << endl;
        exit(0);
    }

    for(int i = 0; i < numOfVertex; i++) {
        p_newVertex = (VERTEX *)calloc(1, sizeof(VERTEX));
        p_newVertex->adjanceyIndex = i + 1;
        p_newVertex->color = White;
        p_newVertex->heapPosition = 0;
        p_newVertex->key = 9999999;
        p_newVertex->pi = NULL;

        p_newVertexList[i] = p_newVertex;
    }

    return p_newVertexList;


}

NODE**  buildAdjanceyList(istream& inputFile, NODE** p_adjacencyList , int numeOfEdges) {

    fprintf(stdout, "Build Adjancey List Command\n");

}

void printAdjanceyList(NODE** adjanceyList) {

    fprintf(stdout, "print Adjancey List Command\n");

}

int getNextInstruction(char* Word, int* passed1, int* passed2) {

    cin >> Word;

    *passed1 = 0;
    *passed2= 0;

    if(strcmp(Word, "PrintADJ") == 0) {
        return 1;
    } else if(strcmp(Word, "SinglePair") == 0) {
            cin >> *passed1;
            cin >> *passed2;
            if(*passed1 != 0 && *passed2 != 0) {
                return 2;
            } else {
                return 0;
            }
        } else if(strcmp(Word, "SingleSource") == 0) {
            cin >> *passed1;
            if(*passed1 != 0 && *passed2 == 0) {
                return 3;
            } else {
                return 0;
            }
        } else if(strcmp(Word, "PrintLength") == 0) {
            cin >> *passed1;
            cin >> *passed2;
            if(*passed1 != 0 && *passed2 != 0) {
                return 4;
            } else {
                return 0;
            } 
        } else if(strcmp(Word, "PrintPath") == 0) {
            cin >> *passed1;
            cin >> *passed2;
            if(*passed1 != 0 && *passed2 != 0) {
                return 5;
            } else {
                return 0;
            }
        } else if(strcmp(Word, "Stop") == 0) {
            return 6;
        } else {
            return 0;
        }

}