#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void build_graph_cmd(pnode *head){
    char next;
    int flag = 1;
    while(flag){
        // end of file then exit
        if(scanf("%c", &next) == EOF){
            break;
        }
        if(next == 'n'){
            insert_node_cmd(head);  
        }
        if(next != 'n' && 'A' <= next && next <= 'Z' ){
            flag = 0;
        }

    }    


}

void printGraph_cmd(pnode head){
    printf("printGraph_cmd");
    if(head == (pnode) NULL){
        return;
    }
    pnode * current_node = &head;
    printf("Starting to Print!");
    while(*current_node != (pnode) NULL){
        printf("%d", (*current_node)->node_num);
        current_node = &(*current_node)->next;
    }    
}
void deleteGraph_cmd(pnode* head){



}
void shortsPath_cmd(pnode head){


}
void TSP_cmd(pnode head){



}

