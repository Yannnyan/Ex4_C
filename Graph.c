#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void build_graph_cmd(pnode *head){
    char next;
    int flag = 1;
    int size;
    scanf("%d",&size);
    set_size(size);
    create_list();
    while(flag){
        // end of file then exit
        if(scanf("%c", &next) == EOF){
            break;
        }
        if(next == 'n'){
            printf("got n:\n");
            pnode head = getHead();
            insert_edges_to_node(&head);  
        }
        if(next != 'n' && 'A' <= next && next <= 'Z' ){
            ungetc(next,stdin);
            flag = 0;
        }

    }    


}

void printGraph_cmd(pnode head){
    printf("printGraph_cmd\n");
    if(head == (pnode) NULL){
        return;
    }
    pnode current_node = head;
    pedge current_edge;
    int count=0;
    printf("Starting to Print!\n");
    while(current_node != (pnode) NULL){
        printf("current node: %d\n", (current_node)->node_num);
        current_edge = current_node->edges;
        while(current_edge != (pedge)NULL){
            printf("edge %d: ", count++);
            printf("dest: %d, w: %d \n", current_edge->endpoint->node_num, current_edge->weight);
            current_edge = current_edge->next;
        }
        count = 0;
        current_node = (current_node)->next;
    }    
}
void deleteGraph_cmd(pnode* head){



}
void shortsPath_cmd(pnode head){


}
void TSP_cmd(pnode head){



}

