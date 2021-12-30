#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int insert_edge(pnode *head, int destID, int weight){
    pnode *dest;
    dest = head;
    while(dest != (pnode *)NULL){
        if((*dest)->node_num == destID){
            break;
        }
        (*dest) = (*dest)->next;
    }
    // trying to connect to unresolved node
    if( dest == (pnode *)NULL){
        return 1;
    }
    pedge *current_edge = &((*dest)->edges);
    while( current_edge != (pedge *) NULL){
        // if the edge allready exists then update its weight and return
        if( (*current_edge)->endpoint->node_num == (*dest)->node_num){
            (*current_edge)->weight = weight;
            return 1;
        }
        current_edge = &((*current_edge)->next);
    }
    (*current_edge)->weight = weight;
    (*current_edge)->endpoint = (*dest);
    return 1;
}
/*
receive a pointer to a pnode, then remove all its edges by freeing the memory its using
lastly assigning the pnode edges pointer to null
*/
void delete_all_edges(pnode *head){
    pedge  * next_edge= &((*head)->edges), *current_edge;
    current_edge =  next_edge;
    while(next_edge != (pedge *)NULL){
        next_edge = &((*next_edge)->next);
        free(current_edge);
        current_edge = next_edge;
    }
    (*head)->edges = (pedge) NULL;
}
