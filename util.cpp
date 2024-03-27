#include "util.h"


VERTEX** buildVertexList(FILE* p_currentFile, VERTEX** p_vertexList, int numOfVertex) {
    
    fprintf(stdout, "Building Vertex List Command");

}

NODE**  buildAdjanceyList(FILE* p_currentFile, NODE** p_adjacencyList , int numeOfEdges) {

    fprintf(stdout, "Build Adjancey List Command\n");

}

void printAdjanceyList(NODE** adjanceyList) {

    fprintf(stdout, "print Adjancey List Command\n");

}

int getNextInstruction(char* Word, int* passed1, int* passed2) {

    int commandSuccess = fscanf(stdin, "%s", Word);

    if(commandSuccess == 0) {
        return 0;
    } else {

        if(strcmp(Word, "PrintADJ") == 0) {
            return 1;
        } else if(strcmp(Word, "SinglePair") == 0) {
            commandSuccess = fscanf(stdin, "%lf", passed1); 
            commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 2;
            } else {
                return 0;
            }
        } else if(strcmp(Word, "SingleSource") == 0) {
            commandSuccess = fscanf(stdin, "%lf", passed1);
            if(commandSuccess == 1) {
                return 3;
            } else {
                return 0;
            }
        } else if(strcmp(Word, "PrintLength") == 0) {
           commandSuccess = fscanf(stdin, "%lf", passed1); 
           commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 4;
            } else {
                return 0;
            } 
        } else if(strcmp(Word, "PrintPath") == 0) {
            commandSuccess = fscanf(stdin, "%lf", passed1); 
            commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 5;
            } else {
                return 0;
            }
        } else {
            return 0;
        }


    }

}