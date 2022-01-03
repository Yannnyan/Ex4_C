#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void build_graph_cmd(pnode *head){
    char next;
    int flag = 1;
    int size;
    scanf("%d",&size);
    set_size(size);
    create_list();
    while(flag){
        // end of file then exit
        if(scanf("%c", &next) == EOF){
            break;
        }
        if(next == 'n'){
            printf("got n:\n");
            pnode head = getHead();
            insert_edges_to_node(&head);  
        }
        if(next != 'n' && 'A' <= next && next <= 'Z' ){
            ungetc(next,stdin);
            flag = 0;
        }

    }    


}

void printGraph_cmd(pnode head){
    printf("printGraph_cmd\n");
    if(head == (pnode) NULL){
        return;
    }
    pnode current_node = head;
    pedge current_edge;
    int count=0;
    printf("Starting to Print!\n");
    while(current_node != (pnode) NULL){
        printf("current node: %d\n", (current_node)->node_num);
        current_edge = current_node->edges;
        while(current_edge != (pedge)NULL){
            printf("edge %d: ", count++);
            printf("dest: %d, w: %d \n", current_edge->endpoint->node_num, current_edge->weight);
            current_edge = current_edge->next;
        }
        count = 0;
        current_node = (current_node)->next;
    }    
}
void deleteGraph_cmd(pnode* head){
    pnode current_node = *head;
    pedge current_edge, next_edge;
    while(current_node != (pnode)NULL){
        // delete the edges
        next_edge = current_node->edges;
        if(next_edge != (pedge)NULL)
        do{
            current_edge = next_edge;
            next_edge = next_edge->next;
            free(current_edge);

        }while(next_edge != (pedge)NULL);
        // delete the node
        *head = current_node->next;
        free(current_node);
        current_node = *head;
    }

}

int findById(int **keyToIndex, int n, int id){
    for(int i=0; i< n; i++){
        if(keyToIndex[i][1] == id){
            return i;
        }
    }
    return -1;
}
void printKeyToIndex(int **keyToIndex,int n){
    for(int i=0; i < n; i++){
        for(int j=0; j<2; j++){
            if(j==0) printf("index: %d, ",keyToIndex[i][j]);
            else printf("id: %d", keyToIndex[i][j]);
        }
        printf("\n");
    }
}
void printMatrix(int ** matrix, int n){
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int *shortPath(int src, int dest, pnode head , int ignore_dest){
     int **matrix;
    int n = size_nodes();
    printf("Shortest Path:\n");
    // printf("malloc matrix with n= %d\n", n);
    matrix = (int **)malloc(sizeof(int *) * n);
    int *temp;
    for(int i=0; i< n; i++){
        temp = (int *)malloc(sizeof(int) *n);
        matrix[i] = temp;
        for(int j=0; j<n;j++){
            matrix[i][j] = -1;
        }
    }
    // printf("malloc keytoindex, head is : %d\n",head->node_num);
    int **keyToIndex = malloc(sizeof(int *) * n);
    pnode cur_node = head;
    pedge cur_edge;
    int *temp1;
    // init keytoindex
    for(int i=0; i<n && cur_node != (pnode)NULL; i++){
        // tuple of [index at matrix,id]
        temp1 = malloc(sizeof(int) *2);
        temp1[0] = i;
        temp1[1] = cur_node->node_num;
        keyToIndex[i] = temp1;
        cur_node = cur_node->next;
    }
    printKeyToIndex(keyToIndex,n);
    // printf("initializing matrix\n");
    // init matrix
    cur_node = head;
    int j;
    for(int i=0; i< n; i++){
        cur_edge = cur_node->edges;
        while(cur_edge!= (pedge)NULL){
            j = findById(keyToIndex,n,cur_edge->endpoint->node_num);  
            matrix[i][j] = cur_edge->weight;
            cur_edge = cur_edge->next;
        }
        cur_node = cur_node->next;
    }
    // printf("printing matrix:\n");
    printMatrix(matrix,n);
    src = findById(keyToIndex,n,src);
    dest = findById(keyToIndex,n,dest);
    int *path_dist = dijkstra(src,matrix, n);
    if(!ignore_dest)
        printf("distance from node %d, to node %d, is : %d\n",keyToIndex[src][1], keyToIndex[dest][1], path_dist[dest]);
    int maxId = 0;
    // trying to allocate a matrix which has all the ids and put the weights there
    // get the size of the matrix by the maximum id
    for(int i= 0; i< n; i++){
        if(keyToIndex[i][1] > maxId){
            maxId = keyToIndex[i][1];
        }
    }
    int *distsByID = (int *)malloc(sizeof(int) * (maxId + 1));
    for(int i=0; i< n; i++){
        distsByID[keyToIndex[i][1]] = path_dist[i];
    }
    for(int i=0; i< n; i++){
        free(matrix[i]);
        free(keyToIndex[i]);
    }
    
    free(matrix);
    free(keyToIndex);
    free(path_dist);
    return distsByID;
}
void shortsPath_cmd(pnode head){
   
    int src,dest;
    scanf("%d",&src);
    scanf("%d",&dest);
    printf("got src: %d, dest: %d",src,dest);
    int * dists = shortPath(src,dest,head,0);
    //printf("%d",dists[dest]);
    free(dists);
    
}

void TSP_cmd(pnode head){
    int k;
    scanf("%d",&k);
    // value all the cities given
    int *nodes_neighbors = (int  *)malloc(k *sizeof(int));
    for(int i=0; i< k ; i++){
        scanf("%d",(nodes_neighbors+i));
    }
    int * dist_fori;
    int ** dist = (int **) malloc(sizeof(int*) * size_nodes());
    // calc the distance between each node to all other nodes
    for(int i=0; i<size_nodes(); i++){
        dist_fori = shortPath(i,-1,head,1);
        dist[i] = dist_fori;
    }
    // call Tsp Algorithm from algo.c
    TSP(dist, nodes_neighbors, k, size_nodes());
    // free all the memory stored in nodes_neighbors and dist
    free(nodes_neighbors);
    for(int i=0; i<size_nodes(); i++){
        free(dist[i]);
    }
    free(dist);
}

