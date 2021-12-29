#include <stdlib.h>
#include <stdio.h>
#include "edges.c"
#include "graph.h"


pnode *head;
int size = 0;

void insert_node_cmd(pnode *head){
    char id;
    if(scanf("%d", &id) == 0){
        return 0;
    }
    pnode next_node = head, current_nod = next_node;
    while(next_nod != (pnode)NULL){
        // if got an id with the same as the id from the file
        // override it
        if(next_node->node_num == id){
            pedge current_edge = next_nod->edges;
            while(current_edge != (pedge)NULL){
                free(current_edge);
            }
            next_node->edges = (pedge)NULL;
            return 1;
        }
        current_nod = current_nod->next;
    }
    current_nod = (pnode) malloc(sizeof(node));
    current_nod->node_num = id;
    return 1;
}
void delete_node_cmd(pnode *head){
    size -=1;
    delete_all_edges(head);
    

}
int size_nodes(){
    return size;
}
pnode *getHead(){
    return head;
}

int main(){
    return 0;
}