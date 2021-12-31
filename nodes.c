#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


pnode HEAD = (pnode) NULL;
int size = 0;
void insert_node_cmd(pnode *head){
    printf("inserting Node:\n");
    int id;
    // the first node does not have any edges!
    scanf("%d",&id);
    if(HEAD == (pnode)NULL){
        (*head)->node_num = id;
        HEAD = *head;
        return;
    }
    pnode current_node, next_node;
    next_node = *head;
    current_node = next_node;
    while(next_node != (pnode)NULL){
        current_node = next_node;
        next_node = next_node->next;
    }
    current_node->next = (pnode)malloc(sizeof(node));
    current_node->next->node_num = id;
    current_node->next->edges = (pedge) NULL;
    

    printf("inserting edges:\n");
    int weight, destID;
    while(scanf("%d",&destID)){
        scanf("%d",&weight);
        insert_edge(HEAD,current_node->next,destID,weight);
    }

}
void delete_node_cmd(pnode *head){
    if(size == 0){
        printf("Tried to delete Non existing node!");
        return;
    }
    size -=1;
    delete_all_edges(*head);
}
int size_nodes(){
    return size;
}
pnode getHead(){
    return HEAD;
}
void set_size(int s){
    size = s;
}