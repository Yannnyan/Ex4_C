#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void remove_edges_from_node(pnode node){
    pedge *current_edge, *next_edge;
    next_edge = &(node->edges);
    while(next_edge != (pedge*)NULL){ // remove edges from linked list
        current_edge=next_edge;
        next_edge= &((*next_edge)->next);
        free(current_edge);
    }
    node->edges = (pedge)NULL;
}

void insert_edges_to_node(pnode *head, pnode work_node){
    int flag, idDest, weight;
    pedge *current_edge, *next_edge;
    pnode *dest_node = head;

    flag = scanf(" %d", &idDest);
    if(flag == -1 || flag == 0) return;
    scanf(" %d",&weight);
    if(work_node->edges == (pedge)NULL) {
        work_node->edges = (pedge) malloc(sizeof(edge));
        while ((*dest_node)->node_num != idDest) { // go to the idDest node
            dest_node = &((*dest_node)->next);
        }
        work_node->edges->endpoint = *dest_node;
        work_node->edges->weight = weight;
        work_node->edges->next = (pedge)NULL;
        flag = scanf(" %d", &idDest);
        scanf(" %d",&weight);
    }

    while(flag == 1){
        dest_node = head;// reset values for loop
        current_edge= &(work_node->edges);
        next_edge=&(work_node->edges);
        while((*dest_node)->node_num != idDest){ // go to the idDest node
            dest_node = &((*dest_node)->next);
        }
        while((*next_edge) != (pedge)NULL){// go to the tail of the edges linked list
            current_edge = next_edge;
            next_edge = &((*next_edge)->next);
        }
        (*current_edge)->next = (pedge)malloc(sizeof(edge)); // make new edge
        (*current_edge)->next->endpoint = (*dest_node);
        (*current_edge)->next ->next = (pedge)NULL;
        (*current_edge)->next ->weight = weight;
        flag = scanf(" %d", &idDest); // if flag == 0 or -1 means that no more edges to read
        scanf(" %d",&weight);
    }
}
