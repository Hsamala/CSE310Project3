#include "util.h"

VERTEX** buildVertexList(int numOfVertex)  {
    VERTEX**  p_newVertexList = new VERTEX*[numOfVertex];

    VERTEX* p_newVertex; 

    for(int i = 0; i < numOfVertex; i++) {
        p_newVertex = new VERTEX;
        p_newVertex->adjanceyIndex = i + 1;
        p_newVertex->color = White;
        p_newVertex->heapPosition = 0;
        p_newVertex->key = 9999999;
        p_newVertex->pi = 0;

        p_newVertexList[i] = p_newVertex;
    }

    return p_newVertexList;


}

NODE**  buildAdjanceyList(istream& inputFile, int numeOfEdges, bool DirectedUndirected, int flag) {

    int edgeNodeIndex, start, end, weight;
    NODE** p_newADJList = new NODE*[numeOfEdges];
    NODE* p_newNode;

    for(int i = 0; i < numeOfEdges; i++) {
        p_newADJList[i] = NULL;
    }

    for(int i = 0; i < numeOfEdges; i++) {
        inputFile >> edgeNodeIndex;
        inputFile >> start;
        inputFile >> end;
        inputFile >> weight;

        p_newNode = new NODE;

        p_newNode->index = edgeNodeIndex;
        p_newNode->startVertex = start;
        p_newNode->endVertex = end;
        p_newNode->weight = weight;

       if (DirectedUndirected == true && flag == 1) {

            if(p_newADJList[start - 1] == NULL) {
                p_newADJList[start - 1] = p_newNode;
            } else {
                p_newNode->next = p_newADJList[start - 1]->next;
                p_newADJList[start - 1]->next = p_newNode; 
            } 


       } else if (DirectedUndirected == true && flag == 2) {

            if(p_newADJList[start - 1] == NULL) {
                p_newADJList[start - 1] = p_newNode;
            } else {
                
                NODE* p_traverse = p_newADJList[start]->next;

                if(p_traverse == NULL) {
                    p_newADJList[start - 1]->next = p_traverse;
                } else {
                   while(p_traverse->next != NULL) {
                        p_traverse = p_traverse->next;
                    } 
                    p_traverse->next = p_newNode;
                }

            } 

       } else if(DirectedUndirected == false && flag == 1) {

            if(p_newADJList[start - 1] == NULL) {
                p_newADJList[start - 1] = p_newNode;
            } else {
                p_newNode->next = p_newADJList[start - 1]->next;
                p_newADJList[start - 1]->next = p_newNode; 
            } 

       } else {

           NODE* p_traverse = p_newADJList[start]->next;

                if(p_traverse == NULL) {
                    p_newADJList[start - 1]->next = p_traverse;
                } else {
                   while(p_traverse->next != NULL) {
                        p_traverse = p_traverse->next;
                    } 
                    p_traverse->next = p_newNode;
                } 

       }


    } 

    return p_newADJList;

}

void printAdjanceyList(NODE** adjanceyList, int numeOfEdges) {

    for(int i = 0; i < numeOfEdges; i++) {
        cout << "ADJ[" << i + 1 << "]" << ":-->";

       NODE* p_traverse = adjanceyList[i];

        cout << "[" << p_traverse->startVertex << " " << p_traverse->endVertex << ": " << p_traverse->weight << "]";

        if(p_traverse->next == NULL) {
            cout << endl;
        } else {

            cout << "-->";

            p_traverse = p_traverse->next;

            while(p_traverse->next != NULL) {
                cout << "[" << p_traverse->startVertex << " " << p_traverse->endVertex << ": " << p_traverse->weight << "]" << "-->";
                p_traverse = p_traverse->next;
            }

            cout << "[" << p_traverse->startVertex << " " << p_traverse->endVertex << ": " << p_traverse->weight << "]" << endl;    
        
        }


    }

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