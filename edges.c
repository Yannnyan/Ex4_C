#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* inserts an edge to the end of the linked list.
first tries to find the dest node then tries to find the tail of the linked list
then allocates new memory and creates the edge */
int insert_edge(pnode head, pnode current_node, int destID, int weight){
    printf("inserting edge!\n");
    int found = 0;
    while(head != (pnode)NULL){
        if(head->node_num == destID){
            found =1;
            break;
        }
        head = head->next;
    }
    if (!found) return 1;
    printf("Getting pos for next edge\n");
    if(current_node->edges == (pedge)NULL){
        current_node->edges = (pedge)malloc(sizeof(edge));
        current_node->edges->endpoint = head;
        current_node->edges->weight = weight;
        current_node->edges->next = (pedge)NULL;
        return 1;
    }
    pedge current_edge, next_edge;
    next_edge = current_node->edges;
    current_edge = next_edge;
    while(next_edge != (pedge)NULL){
        if(next_edge->endpoint->node_num == destID){
            next_edge->weight = weight;
            return 1;
        }
        current_edge = next_edge;
        next_edge = next_edge->next;
    }
    current_edge->next = (pedge)malloc(sizeof(edge));
    current_edge->next->endpoint = head;
    current_edge->next->weight = weight;
    current_edge->next->next = (pedge)NULL;
    return 1;
}
/*
receive a pointer to a pnode, then remove all its edges by freeing the memory its using
lastly assigning the pnode edges pointer to null
*/
void delete_all_edges(pnode head){
    pedge next_edge= head->edges, current_edge;
    current_edge =  next_edge;
    while(next_edge != (pedge)NULL){
        next_edge = next_edge->next;
        free(current_edge);
        current_edge = next_edge;
    }
    head->edges = (pedge) NULL;
}
