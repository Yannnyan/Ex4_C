#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


void remove_out_edges_from_node(pnode *node){
    pedge next = &(*((*node)->edges)), next_next = (pedge)NULL;
    while(next != (pedge)NULL){
        next_next = next->next;
        free(next);
        next = next_next;
    }
    (*node)->edges = (pedge)NULL;
}
void insert_node_b_cmd(pnode *head){
    pnode *current_node = (pnode *)NULL, *next_node = (pnode*)NULL;
    int flag=0, nodeID=0;
    flag = scanf(" %d",&nodeID);
    if(flag != 1) return; // sanity check

    next_node = head;
    while(*next_node != (pnode)NULL){// find the node
        current_node = next_node;
        if(nodeID == (*current_node)->node_num){// found
            remove_out_edges_from_node(current_node);
            insert_edges_to_node(head, *current_node);
            return;
        }
        next_node = &((*next_node)->next);
    }
// helo world why valgrind is treating me bad

    (*current_node)->next = (pnode)calloc(sizeof(node),1);
    (*current_node)->next->node_num = nodeID;
    (*current_node)->next->edges = (pedge)NULL;
    (*current_node)->next->next = (pnode)NULL;
    current_node = &((*current_node)->next);
    insert_edges_to_node(head,*current_node);
}

void insert_node_cmd(pnode *head){
    pnode *current_node = (pnode *)NULL, *next_node = (pnode*)NULL;
    int flag=0, nodeID=0;
    flag = scanf(" %d",&nodeID);
    if(flag != 1) return; // sanity check

    next_node = head;
    while(*next_node != (pnode)NULL){// find the node
        current_node = next_node;
        if(nodeID == (*current_node)->node_num){// found
            // add remove edges function
            insert_edges_to_node(head, *current_node);
            return;
        }
        next_node = &((*next_node)->next);
    }
// helo world why valgrind is treating me bad

    (*current_node)->next = (pnode)calloc(sizeof(node),1);
    (*current_node)->next->node_num = nodeID;
    (*current_node)->next->edges = (pedge)NULL;
    (*current_node)->next->next = (pnode)NULL;
    current_node = &((*current_node)->next);
    insert_edges_to_node(head,*current_node);
}

void delete_node_cmd(pnode *head){
    int id;
    scanf("%d",&id);


    pnode *target_node;
    (target_node) = &(*head);

    while((*target_node)->node_num != id){
        (target_node) = &((*target_node)->next);
    }

    pedge *target_edge = &((*target_node)->edges);
    pedge *next_target_edge = target_edge;
    while((*target_edge) != (pedge)NULL){ // free all edges of the node
        next_target_edge = &((*target_edge)->next);
        (*target_edge)->endpoint = (pnode)NULL;
        free((*target_edge));
        target_edge = next_target_edge;
    }
    (*target_node)->edges = (pedge)NULL;




    pnode *current_node = head;
    pedge temp_ed;
    while((*current_node) != (pnode)NULL){ // deleting all the edges that point to the target node

        if((*current_node)->node_num == id){
            current_node = &((*current_node)->next);
            continue;
        }
        target_edge = &((*current_node)->edges);
        if((*current_node)->edges == (pedge)NULL){} // no edges dont do nothing
        else if ((*target_edge)->endpoint->node_num == id){ // first edge pointing to the target
            if(((*target_edge)->next == (pedge)NULL)){
                free((*target_edge));
                (*current_node)->edges = (*target_edge)->next;
            }
            else {
                temp_ed = (*target_edge)->next;
                free((*target_edge));
                (*current_node)->edges = temp_ed;
            }

        }
        else{
            next_target_edge = &((*target_edge)->next);
            while((*next_target_edge) != (pedge)NULL){
                if((*next_target_edge)->endpoint->node_num == id){

                    (temp_ed) = ((*next_target_edge)->next);
                    free((*next_target_edge));
                    (*target_edge)->next = temp_ed;
                    target_edge = &(temp_ed);

                }
                else{
                    temp_ed = (*next_target_edge)->next;
                }
                next_target_edge = &(temp_ed);
            }
        }

        current_node = &((*current_node)->next);
    }
    pnode temp_no = (*target_node)->next;

    if((*head) == (*target_node)){ // if the target node is the head
        free((*target_node));
        (*head) = temp_no;
    }
    else {
        (target_node) = &(*head);
        while ((*target_node)->node_num != id) {
            if ((*target_node)->next->node_num == id) {
                pnode temp = (*target_node)->next->next;
                free((*target_node)->next);
                (*target_node)->next = temp;
                break;
            }
            target_node = &((*target_node)->next);
        }
    }
}
