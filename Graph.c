#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void build_graph_cmd(pnode *head){
    


}

void printGraph_cmd(pnode head){
    pnode * current_node = &head;
    while(current_node != (pnode *) NULL){
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

