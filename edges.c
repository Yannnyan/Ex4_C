#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int insert_edge(pnode *head, pnode * current_node, int destID, int weight){
    pnode *dest;
    dest = head;
    printf("trying to get id on node\n");
    while((*dest) != (pnode)NULL){
        if((*dest)->node_num == destID){
            break;
        }
        (*dest) = (*dest)->next;
    }
    // trying to connect to unresolved node
    if( dest == (pnode *)NULL){
        return 1;
    }
    printf("trying to allocate memory for edge\n");
    // allocated memory in space if current_node doesnt have any edges
    if((*current_node)->edges == (pedge) NULL){
        printf("trying to malloc\n");
        //(*current_node)->edges = (pedge) malloc(sizeof(pedge));
        // (*current_node)->edges = (pedge) NULL;
        //(*current_node)->edges->endpoint = (pnode) NULL;
    }
    printf("trying to assign edge\n");
    printf("first iteration!\n");
    pedge *next_edge = &((*current_node)->edges);
    pedge * current_edge = next_edge;
    while( (*next_edge) != (pedge) NULL){
        //if the edge allready exists then update its weight and return
        if( (*next_edge)->endpoint != (pnode) NULL)
        if( (*next_edge)->endpoint->node_num == (*dest)->node_num){
            printf("already have this edge!\n");
            (*next_edge)->weight = weight;
            return 1;
        }
        printf("HELLOW\n");
        current_edge = next_edge;
        if((*next_edge)->next != (edge *) NULL){
        printf("next edge is not NULL!\n");
        (*next_edge) = (*next_edge)->next;
        }
    }
    (*current_edge)->next = (pedge)malloc(sizeof(pedge));
    (*current_edge) = (*current_edge)->next;
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
