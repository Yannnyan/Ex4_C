#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


pnode HEAD = (pnode) NULL;
int size = 0;

void create_list(){
    if(size == 0){
        return;
    }
    HEAD = (pnode) malloc(sizeof(node));
    HEAD->edges = (pedge)NULL;
    HEAD->node_num = 0;
    HEAD->next = (pnode)NULL;
    pnode current_node = HEAD;
    for(int i=1; i< size; i++){
       current_node->next = (pnode) malloc(sizeof(node));
       current_node->next->edges = (pedge)NULL;
       current_node->next->node_num = i;
       current_node = current_node->next;
    }
}

void insert_node_cmd(pnode *head){
    printf("getting node:\n");
    int id;
    // the first node does not have any edges!
    scanf("%d",&id);
    if(HEAD == (pnode)NULL){
        return;
    }
    pnode current_node, next_node;
    next_node = *head;
    current_node = next_node;
    while(next_node->node_num != id){
        current_node = next_node;
        next_node = next_node->next;
    }


    
    int weight, destID;
    while(scanf("%d",&destID)){
        scanf("%d",&weight);
        printf("inserting edges:\n");
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