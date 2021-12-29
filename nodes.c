#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


size_t size_ = 100;

// if malloc costs O(n)
// The idea of this is to create an array, that contains Nodes which assigned by their ids 
int insert(pnode nodesArray, pnode pnode1){
    if(pnode1 == NULL || nodesArray == NULL){
        return 0;
    }
    int id_node = pnode1->node_num
    if(size_ < id_node ){
        nodesArray = (pnode)realloc(nodesArray, (id_node + 100) * sizeof(node));
        size_+=100;
    }
    // Freeing all the current edges of the node
    if(nodesArray[id_node] != NULL){
        pedge curr_pedge = nodesArray[id_node] -> edges;
        while(curr_pedge != NULL){
            free(curr_pedge);
        }
        free(nodesArray[id_node]);
    }
    nodesArray[id_node] = pnode1;
    return 1;
}
// returns the size of the given node array
size_t size(){
    return size_;
}
// receives a linked list of nodes and translates it to an array
pnode makeArray(pnode head){
    pnode nodes = (pnode) malloc(100 * sizeof(pnode));
    pnode curr = head;
    while(curr != NULL){
        insert(nodes,curr);
        curr->next;
    }
    return nodes;
}
