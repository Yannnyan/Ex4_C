#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int insert_node_cmd(pnode *head){
    char id;
    if(scanf("%d", &id) == 0){
        return 0;
    }
    pnode next_node = head, current_node = next_node;
    while(next_node != (pnode)NULL){
        // if got an id with the same as the id from the file
        if(next_node->node_num == id){
            pedge current_edge = next_node->edges;
            while(current_edge != (pedge)NULL){
                free(current_edge);
            }
            next_node->edges = (pedge)NULL;
            return 1;
        }
        current_node = current_node->next;
    }
    current_node = (pnode) malloc(sizeof(node));
    current_node->node_num = id;
    return 1;
}
void delete_node_cmd(pnode *head){


}


int main(){
    return 0;
}