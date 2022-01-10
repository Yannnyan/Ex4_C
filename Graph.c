#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


pnode* init_graph(int size){
    int count =0;
    if(size == 0)return (pnode*)NULL; // sanity check
    // add head node 
    pnode* head;
    pnode temp = (pnode)calloc(sizeof(node),1);
    temp->node_num = 0;
    temp->next = (pnode)NULL;
    temp->edges = (pedge)NULL;
    head = &temp;
    (*head)->node_num = count;
    (*head)->next = (pnode)NULL;
    (*head)->edges = (pedge)NULL;

    count+=1;
    pnode* next_node = head;

    while(count < size){ // initialize the linked list
        (*next_node)->next = (pnode)calloc(sizeof(node),1);
        (*next_node)->next->node_num = count;
        (*next_node)->edges = (pedge)NULL;
        next_node = &((*next_node)->next);
        count+=1;
    }
    (*next_node)->next = (pnode)NULL;
    (*next_node)->edges = (pedge)NULL;
    return head;
}


void build_graph_cmd(pnode *head){
    char next;
    int flag;
    flag =scanf(" %c",&next);
    while(flag){
        if(next == 'n'){
            insert_node_cmd(head);
        }
        else{
            ungetc(next,stdin);
            break;
        }
        flag = scanf(" %c",&next);
        if(flag == EOF){
            ungetc(next,stdin);
            break;
        }
    }
}

void printGraph_cmd(pnode head){
    pnode cur = head;
    pedge edg;
    while(cur != (pnode)NULL){ // print node
        edg = cur->edges;
        while(edg != (pedge)NULL){ // print edges
            edg = edg->next;
        }
        cur = cur->next;
    }
}

void deleteGraph_cmd(pnode* head){
    pnode * current_node = head, next_node;
    pedge * current_edge, next_edge;
    // go through all the nodes
    while(*current_node != (pnode) NULL){
        current_edge = &((*current_node)->edges);
        while(*current_edge != (pedge)NULL){// delete current_node edges
            next_edge = (*current_edge)->next;
            free(*current_edge);
            *current_edge = next_edge;
        }
        (*current_node)->edges = (pedge)NULL;
        next_node = (*current_node)->next;
        free(*current_node);
        *current_node = next_node;
    }
}

