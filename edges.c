#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int insert_edge(pnode *head){
    int weight;int destID;
    pnode *dest;
    if(scanf("%d", &destID) == 0){
        return 0;
    }
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
    if(scanf("%d", &weight) == 0){
        return 0;
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

void delete_all_edges(pnode *head){
    pedge  * next_edge= &((*head)->edges), *current_edge;
    current_edge =  next_edge;
    while(next_edge != (pedge *)NULL){
        next_edge = &((*next_edge)->next);
        free(current_edge);
        current_edge = next_edge;
    }
}

int main(){

    return 0;

}
