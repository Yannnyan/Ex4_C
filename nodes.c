#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


pnode *head;
int size = 0;
void insert_node_cmd(pnode *head){
    int id;
    if(scanf("%d", &id) == 0){
        printf("Failed to scan");
    }
    pnode *next_node = head;
    pnode *current_nod = next_node;
    while(next_node != (pnode *)NULL){
        // if got an id with the same as the id from the file
        // override it
        if((*next_node)->node_num == id){
            delete_all_edges(next_node);
            return;
        }
        (*current_nod) = (*current_nod)->next;
    }
    (*current_nod) = (pnode) malloc(sizeof(pnode));
    (*current_nod)->node_num = id;
}
void delete_node_cmd(pnode *head){
    if(size == 0){
        printf("Tried to delete Non existing node!");
        return;
    }
    size -=1;
    delete_all_edges(head);
}
int size_nodes(){
    return size;
}
pnode *getHead(){
    return head;
}
