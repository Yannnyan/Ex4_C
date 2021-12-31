#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* inserts an edge to the end of the linked list.
first tries to find the dest node then tries to find the tail of the linked list
then allocates new memory and creates the edge */
int insert_edge(pnode head, pnode current_node){
   printf("current head is : %d, current_node is : %d\n",head->node_num, current_node->node_num );
   int id, weight;
   pnode dest_node;
   pedge connection_edge = current_node->edges, last_edge;
   do{
        connection_edge = current_node->edges;
        dest_node = head;
        if(!scanf("%d",&id)) return 0 ;
        scanf("%d",&weight);
        // get dest_node
        while(dest_node->node_num != id){
            dest_node = dest_node->next;
        }
        // get last edge or update current edge
        if(connection_edge == (pedge) NULL){
            current_node->edges = (pedge) malloc(sizeof(edge));
            current_node->edges->endpoint = dest_node;
            current_node->edges->next = (pedge)NULL;
            current_node->edges->weight = weight;
            continue;
        }
        while(connection_edge != (pedge)NULL){
            if(connection_edge->endpoint->node_num == dest_node->node_num){
                connection_edge->weight = weight;
                break;
            }
            last_edge = connection_edge;
            connection_edge = connection_edge->next;
        }
        last_edge->next = (pedge) malloc(sizeof(edge));
        last_edge->next->endpoint = dest_node;
        last_edge->next->weight = weight;
   }
   while(1);
}
/*
receive a pointer to a pnode, then remove all its edges by freeing the memory its using
lastly assigning the pnode edges pointer to null
*/
int delete_all_edges(pnode head){
    pnode current_node = head;
    int id, found=0;
    scanf("%d",&id);
    // finding my node
    printf("finding my node\n");
    while(current_node != (pnode) NULL){
        if(current_node->node_num == id){
            found =1;
            break;
        }
        current_node = current_node->next;
    }
    if(!found) return 1;
    // freeing all the edges which are connected to the my node
    pedge next_edge= current_node->edges, current_edge;
    printf("current node is : %d\n", current_node->node_num);
    current_edge =  next_edge;
    printf("do while\n");
    if(current_edge != (pedge)NULL){
    do{
        next_edge = next_edge->next;
        printf("freeing dest : %d\n", current_edge->endpoint->node_num);
        free(current_edge);
        current_edge = next_edge;
    }while(next_edge != (pedge)NULL);
    current_node->edges = (pedge) NULL;
    }
    printf("deleting all the edges that are pointing to the current node\n");
    // deleting all the edges that are pointing to the current node
    pnode connected_node = head;
    while(connected_node != (pnode)NULL){
        next_edge = connected_node->edges;
        current_edge = next_edge;
        printf("connected node is : %d\n", connected_node->node_num);
        if(connected_node->node_num == id){
            connected_node = connected_node->next;
            continue;
        }
        // if there is no edges connected to the node
        if(next_edge == (pedge)NULL){
            connected_node = connected_node->next;
            continue;
        }
        // the connected edge is the head
        if(next_edge->endpoint->node_num == id ){
            next_edge = next_edge->next;
            printf("Freeing src: %d, dest: %d\n",connected_node->node_num, current_edge->endpoint->node_num);
            free(current_edge);
            connected_node->edges = next_edge;
            continue;
        }
        // the connected edge is not the head
        next_edge = next_edge->next;
        while(next_edge != (pedge)NULL){
            if(next_edge->endpoint->node_num == id){
                current_edge->next = next_edge->next;
                printf("freeing src: %d, dest: %d\n",connected_node->node_num, next_edge->endpoint->node_num);
                free(next_edge);
                break;
            }
            current_edge = next_edge;
            next_edge = next_edge->next;
        }
        connected_node = connected_node->next;
    }
    return current_node->node_num;
}
