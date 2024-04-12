#include "stack.h"

void printLength(VERTEX** p_vertexList, int source, int target) {

    VERTEX* p_currentVertex = p_vertexList[target - 1];
    double sumOfWeights = 0.00;
    sumOfWeights += p_currentVertex->key;
     

    while(p_currentVertex->pi != -5) {
       p_currentVertex = p_vertexList[p_currentVertex->pi - 1]; 
    } 

   if (p_currentVertex->adjanceyIndex != source) {
       cout << "There is no path from " << source << " to " << target << "." << endl; 
    } else {
        cout << "The length of the shortest path from " << source << " to " << target << " is:     " << sumOfWeights << endl;
    } 

}

void printPath(VERTEX** p_vertexList, int source, int target, string currentPrintArray) {

    VERTEX* p_currentVertex = p_vertexList[target - 1]; 

    string printArray = currentPrintArray;
    double roundedFloat;

    while(p_currentVertex->pi != -5) {
       roundedFloat = round(p_currentVertex->key * 100);
       roundedFloat = roundedFloat / 100; 
       printArray = string("-->") + string("[") + to_string(p_currentVertex->adjanceyIndex) + string(":    ") + to_string(roundedFloat).substr(0, (to_string(roundedFloat).find(".") + 3)) + "]" + printArray;
       p_currentVertex = p_vertexList[p_currentVertex->pi - 1]; 

    }

    if(p_currentVertex->adjanceyIndex != source) {
       cout << "There is no path from " << source << " to " << target << "." << endl; 
    } else {
        roundedFloat = round(p_currentVertex->key * 100); 
        printArray = string("[") + to_string(p_currentVertex->adjanceyIndex) + string(":    ") + to_string(roundedFloat).substr(0, (to_string(roundedFloat).find(".") + 3) ) + "]" + printArray;
        cout << "The shortest path from " << source << " to " << target << " is:" << endl;
        cout << printArray << endl;
    }


}