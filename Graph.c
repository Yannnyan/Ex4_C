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
void shortsPath_cmd(pnode head){
    int **matrix;
    int n = size_nodes();
    printf("Shortest Path:\n");
    printf("malloc matrix with n= %d\n", n);
    matrix = (int **)malloc(sizeof(int *) * n);
    int *temp;
    for(int i=0; i< n; i++){
        temp = (int *)malloc(sizeof(int) *n);
        matrix[i] = temp;
        for(int j=0; j<n;j++){
            matrix[i][j] = -1;
        }
    }
    printf("malloc keytoindex, head is : %d\n",head->node_num);
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
    printf("initializing matrix\n");
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
    printf("printing matrix:\n");
    printMatrix(matrix,n);
    int src,dest;
    scanf("%d",&src);
    scanf("%d",&dest);
    printf("got src: %d, dest: %d",src,dest);
    src = findById(keyToIndex,n,src);
    dest = findById(keyToIndex,n,dest);
    printf("got index src: %d, index dest: %d\n",src,dest);
    printf("distance from node %d, to node %d, is : %d\n",src, dest, dijkstra(src,dest,matrix, n));
}

void TSP_cmd(pnode head){



}

