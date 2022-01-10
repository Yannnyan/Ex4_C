#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

void freeMatrix(int** matrix, int size_mat){
    for(int i=0; i< size_mat; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int ** adj_matrix(pnode head){
    pnode *node = &head;
    int max = 0;
    while((*node) != (pnode)NULL){
        if(((*node)->node_num) > max) max = (*node)->node_num;
        node = &((*node)->next);
    }
    int ** matrix = (int **) calloc(sizeof(int*),(max+1));
    int *vector;
    for (int i=0; i< max+1; i++){
        vector = (int *)calloc(sizeof(int) , (max+1));
        for(int j=0; j< max+1; j++){
            vector[j] = -1;
        }
        matrix[i] = vector;
    }
    node = &head;
    pedge *edge;
    while(*node != (pnode)NULL) {
        edge = &((*node)->edges);
        while((*edge) != (pedge)NULL){
            matrix[(*node)->node_num][(*edge)->endpoint->node_num] = (*edge)->weight;
            edge = &((*edge)->next);
        }
        node = &((*node)->next);
    }
    return matrix;
}
int pop_min(int *array,int *queue, int size_arr){
    int index_ret = -1;
    int weight = __INT_MAX__;
    for(int i=0; i< size_arr; i++){
        if(weight > array[i] && queue[i]!=-1){
            weight = array[i];
            index_ret = i;
        }
    }
    return index_ret;
}
void relax(int **matrix,int size_mat, int *distances, int index_to_relax){
    for(int i=0; i< size_mat; i++){
        if(matrix[index_to_relax][i] != -1)
        if(distances[i] > distances[index_to_relax] + matrix[index_to_relax][i]){
            distances[i] = distances[index_to_relax] + matrix[index_to_relax][i];
        }
    }
}

int *Dijkstra(int **matrix, int startID, int size_mat){
    int* distances = (int *)calloc(sizeof(int), size_mat);
    int *queue = (int *)calloc(sizeof(int),size_mat);
    for(int i=0; i< size_mat; i++){
        distances[i] = __INT_MAX__;
        queue[i] = 0;
    }
    distances[startID] = 0;
    int pops=0;
    int minimum_id;
    while(pops < size_mat){

        minimum_id = pop_min(distances,queue,size_mat);
        if(minimum_id == -1) break;
        pops+=1;
        queue[minimum_id] = -1;
        relax(matrix,size_mat,distances,minimum_id);
    }
    free(queue);
    return distances;
}

void shortsPath_cmd(pnode head){
    int **matrix = adj_matrix(head);

    int size_mat = 0;
    pnode node = &(*head);
    int max=0;
    while(node != (pnode)NULL){
        if(node->node_num > max) max = node->node_num;
        node = &(*(node->next));
    }
    size_mat = max;
    size_mat+=1;

    int src_id,dest_id;
    scanf("%d",&src_id);
    scanf("%d",&dest_id);
    int *dists_to_src = Dijkstra(matrix,src_id,size_mat);
    printf("Dijsktra shortest path: %d\n",dists_to_src[dest_id]);
    free(dists_to_src);
    freeMatrix(matrix,size_mat);
}
void swap(int *permutation, int index1, int index2){
    int temp = permutation[index1];
    permutation[index1] = permutation[index2];
    permutation[index2] = temp;
}
int* deep_copy(int *permutation,int size_per){
    int *per = (int *)calloc(sizeof(int) , size_per);
    for(int i=0; i< size_per; i++){
        per[i] = permutation[i];
    }
    return per;
}
int All_Permutations(int *permutation, int ** permutations,int l, int r, int index){
    if(l == r){
        permutations[index++] = deep_copy(permutation,r+1);
        return index;
    }
    else
        for(int i=l ;i<= r; i++){
            swap(permutation,l,i);
            index = All_Permutations(permutation,permutations,l+1,r,index);
            swap(permutation,l,i);

        }
    return index;
}
int minimalPermutation(int **Permutations, int** matrix, int sizeper, int sizeall){

    int weight, min_weight=__INT_MAX__;
   for(int i=0; i< sizeall; i++){
       weight = -1;
       for(int j=0; j< sizeper-1; j++){
           if(matrix[Permutations[i][j]][Permutations[i][j+1]]!= __INT_MAX__){
               if(matrix[Permutations[i][j]][Permutations[i][j+1]]!= -1 ) {
                   if (weight == -1)
                       weight = 0;
                   weight += matrix[Permutations[i][j]][Permutations[i][j + 1]];
               }
           }
           else{
               weight = -1;
               break;
           }
       }
       if(weight != -1 && weight < min_weight){
           min_weight = weight;
       }
   }
   if(min_weight == __INT_MAX__)
       return -1;
   else
       return min_weight;
}
int factorial(int r){
    int ret = 1, now=r;
    while(now > 0){
        ret = ret*now;
        now--;
    }
    return ret;
}
void TSP_cmd(pnode head){


    int cities[6], index=0;
    for(int i=0; i< 6; i++){
        cities[i] = -1;
    }


    int r =0;
    int x;
    scanf("%d",&x);
    int flag = scanf("%d",&cities[index++]);
    while(flag>0)
    {   r++;
        flag = scanf("%d",&cities[index++]);
    }
    int size_all = factorial(r);


    int **permutations = (int**)calloc(sizeof(int*),size_all);
    int *permutation,i=0, next = cities[i];

    permutation = (int *)calloc(sizeof(int),r);
    while(i < r)
    {
        permutation[i++]=next;
        next=cities[i];
    }


    int **temp_matrix = adj_matrix(head);


    int size_mat = 0;
    pnode node = &(*head);
    while(node != (pnode)NULL){
        if(node->node_num > size_mat){
            size_mat = node->node_num;
        }
        node = &(*(node->next));
    }
    size_mat+=1;

    int **matrix = (int**)calloc(sizeof(int*) , (size_mat));
    for(int i=0; i< size_mat; i++){
        matrix[i] = Dijkstra(temp_matrix,i, size_mat);
    }


    All_Permutations(permutation,permutations,0,r-1,0);

    int min_per = minimalPermutation(permutations, matrix,r,size_all);
    printf("TSP shortest path: %d\n",min_per);
    freeMatrix(temp_matrix,size_mat);
    freeMatrix(matrix,size_mat);
    for(int i=0; i< size_all; i++){
        free(permutations[i]);
    }
    free(permutations);
    free(permutation);
}



