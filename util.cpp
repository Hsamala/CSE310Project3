#include "util.h"


VERTEX** buildVertexList(istream& inputFile, VERTEX** p_vertexList, int numOfVertex) {
    
    int vertexLength; 

}

NODE**  buildAdjanceyList(istream& inputFile, NODE** p_adjacencyList , int numeOfEdges) {

    fprintf(stdout, "Build Adjancey List Command\n");

}

void printAdjanceyList(NODE** adjanceyList) {

    fprintf(stdout, "print Adjancey List Command\n");

}

int getNextInstruction(char* Word, int* passed1, int* passed2) {

    cin >> Word;

    *passed1;
    *passed2;

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
            if(*passed1 != 0) {
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
        } else {
            return 0;
        }

}