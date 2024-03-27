#include "util.h"


VERTEX** buildVertexList(FILE* p_currentFile, VERTEX** p_vertexList, int numOfVertex) {
    
}


int getNextInstruction(char* Word, int* passed1, int* passed2) {

    int commandSuccess = fscanf(stdin, "%s", Word);

    if(commandSuccess == 0) {
        return 0;
    } else {

        if(strcmp(Word, "PrintADJ")) {
            return 1;
        } else if(strcmp(Word, "SinglePair")) {
            commandSuccess = fscanf(stdin, "%lf", passed1); 
            commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 2;
            } 
        } else if(strcmp(Word, "SingleSource")) {
            commandSuccess = fscanf(stdin, "%lf", passed1);
            return 3;
        } else if(strcmp(Word, "PrintLength")) {
           commandSuccess = fscanf(stdin, "%lf", passed1); 
           commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 4;
            }  
        } else if(strcmp(Word, "PrintPath")) {
            commandSuccess = fscanf(stdin, "%lf", passed1); 
            commandSuccess = fscanf(stdin, "%lf", passed2);
            if(commandSuccess == 1) {
                return 5;
            } 
        } else {
            return 6;
        }


    }

}