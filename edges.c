#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int insert_edge(pnode head){
    int weight, destID;
    pnode dest;
    if(scanf("%d", &destID) == 0){
        return 0;
    }
    dest = nod;
    while(dest != (pnode)NULL){
        if(dest->node_num == destID){
            break;
        }
    }
    // trying to connect to unresolved node
    if(dest == (pnode)NULL){
        return 1;
    }
    if(scanf("%d", &weight) == 0){
        return 0;
    }
    pedge current_edge = nod->edges;
    while(current_edge != (pedge) NULL){
        // if the edge allready exists then update its weight and return
        if(current_edge->endpoint == dest){
            current_edge->weight = weight;
            return 1;
        }
        current_edge = current_edge->next;
    }
    current_edge->weight = weight;
    current_edge->endpoint = dest;
    return 1;
}



