#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

// if malloc costs O(n), then the time complexity is O(n^2)
void append(GRAPH_NODE_ **nodesArray, GRAPH_NODE_ * node){
    nodesArray = realloc(nodesArray, (size(nodesArray) + 1)* sizeof(GRAPH_NODE_)));
    nodesArray[size(nodesArray)] = node;
}
// returns the size of the given node array
size_t size(GRAPH_NODE_ *nodesArray){
    return ( sizeof(nodesArray) / sizeof(nodesArray[0]) );
}
// deletes and returns the node at last index
// return node pointer if the deletion is successfull, else return NULL
GRAPH_NODE_ * pop(GRAPH_NODE_ ** nodesArray){
    
    size_t pastLength = size(nodesArray)
    if(pastLength == 0){
        return NULL;
    }
    GRAPH_NODE_ node = nodesArray[size(nodesArray) - 1]
    realloc(nodesArray, (size(nodesArray) - 1) * sizeof(GRAPH_NODE_))
    if(size(nodesArray) == pastLength - 1){
        return node;
    }
    else{
        return NULL;
    }
}
// if u want to remove from the top of the array use pop ONLY
// else remove manually



