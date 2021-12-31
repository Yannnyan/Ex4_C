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
       current_node->next->next = (pnode)NULL;
       current_node->next->edges = (pedge)NULL;
       current_node->next->node_num = i;
       current_node = current_node->next;
    }
}

void insert_edges_to_node(pnode *head){
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
    printf("%d\n",current_node->node_num);
    printf("%d\n",id);

    printf("inserting edges:\n");
    if(current_node->node_num == id) insert_edge(HEAD,current_node);
    else insert_edge(HEAD,current_node->next);
}

void insert_node_cmd(pnode *head){
    pnode current_node, next_node;
    current_node = *head;
   
    next_node = current_node;
    while(next_node != (pnode)NULL){
        current_node = next_node;
        next_node = next_node->next;
    }
    current_node->next = (pnode) malloc(sizeof(node));
    scanf("%d", &current_node->next->node_num);
    current_node->next->edges = (pedge)NULL;
    current_node->next->next = (pnode)NULL;
    size+=1;


    insert_edge(HEAD,current_node->next);
    
}
void delete_node_cmd(pnode *head){
    if(size == 0){
        printf("Tried to delete Non existing node!");
        return;
    }
    size -=1;
    printf("deleting all the edges\n");
    int id = delete_all_edges(*head);
    printf("deleting the node\n");
    pnode current_node = HEAD, last_node;
    if(HEAD->node_num == id){
        HEAD = HEAD->next;
        free(current_node);
        return;
    }
    
    last_node = current_node;
    current_node = current_node->next;
    while(current_node != (pnode)NULL){
        if(current_node->node_num == id){
            last_node -> next = current_node ->next;
            free(current_node);
        }
        last_node = current_node;
        current_node = current_node->next;
    }
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