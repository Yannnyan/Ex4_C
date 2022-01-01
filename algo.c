#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"


/*
 determines the minimal distance from src to dest.
 the matrix is a neighbor matrix nxn(when n is the length of the matrix and the heigh of the matrix).
*/
int dijkstra(int src, int dest, int **matrix){
    int *distance_from_src = (int *) malloc(sizeof(matrix[0]));
    // the start node is 0 and all other nodes are infinity
    destance_from_src[src] = 0;
    int *Queue_wannabe = (int *) malloc(sizeof(matrix[0]));
    int size = sizeof(distance_from_src) / 4;
    for(int i=0; i< size; i++){
        if(i != src){
            distance_from_src = INFINITY;
        }
        Queue_wannabe[i] = i;
    }
    int size_Queue = size;
    int min_id;
    while(size_Queue > 0){
        min_id = popMin(distance_from_src,Queue_wannabe,size);
        size_Queue-=1;
        if(min_id == -1) { printf("got -1 in min_id\n");break;}
        relax(min_id);
    }
    if(distance_from_src[dest] == INFINITY){
        return -1;
    }
    return distance_from_src[dest];
}
// returns the id of the node with the minimal distance
int popMin(int *distance_from_src, int *Queue_wannabe, int size){
    int minimum_id = -1, minimum_weight = INFINITY;
    for(int i=0; i< size; i++){
        if(Queue_wannabe[i] != -1){
            if(minimum_weight > distance_from_src[i]){
                minimum_id = i;
                minimum_weight = distance_from_src[i];
            }
        }
    }
    if(minimum_id != -1) Queue_wannabe[minimum_id] = -1;
    return minimum_id;
}

void relax(int *distance_from_src, int **matrix, int node_id,int size){
    for(int i=0; i< size; i++){
        if(matrix[node_id][i] != -1){
            if(distance_from_src[i] < distance_from_src[node_id] + matrix[node_id][i]){
                distance_from_src = distance_from_src[node_id] + matrix[node_id][i];
            }
        }
    }
}



