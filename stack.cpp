#include "stack.h"

void printLength() {

    fscanf(stdout, "This is the print Length command\n");

}

string printPath(VERTEX** p_vertexList, int source, int target, string currentPrintArray) {

    VERTEX* p_currentVertex = p_vertexList[target - 1];

    string printArray = currentPrintArray;

    if(p_currentVertex->pi == -5) {

        if(p_currentVertex->adjanceyIndex == source) {

            printArray = string("[") + to_string(p_currentVertex->adjanceyIndex) + string("    ") + to_string(p_currentVertex->key) + string("]") + printArray;
            cout << "This shortest path from " << source << " to " << target << "is:" << endl;
            return printArray;

        } else {
            cout << "There is no path from" << source << " to " << target << endl; 
            return "";       
        }

    } else {

        printArray = string("-->") + string("[") + to_string(p_currentVertex->adjanceyIndex) + string("    ") + to_string(p_currentVertex->key) + "]" + printArray;
        printArray = printPath(p_vertexList, source, p_currentVertex->pi, printArray);

    }

}