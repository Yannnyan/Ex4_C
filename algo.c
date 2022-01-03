#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"


void printdistances(int *distance_from_src, int n){
    for(int i=0; i< n; i++){
        printf("for index %d dist is : %d\n", i, distance_from_src[i]);
    }
}
// returns the id of the node with the minimal distance
int popMin(int *distance_from_src, int *Queue_wannabe, int size_per){
    int minimum_id = -1, minimum_weight = __INT_MAX__;
    for(int i=0; i< size_per; i++){
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

void relax(int *distance_from_src, int **matrix, int node_id,int size_per){
    for(int i=0; i< size_per; i++){
        if(matrix[node_id][i] != -1){
            if(distance_from_src[i] > distance_from_src[node_id] + matrix[node_id][i]){
                distance_from_src[i] = distance_from_src[node_id] + matrix[node_id][i];
            }
        }
    }
}
/*
 determines the minimal distance from src to dest.
 the matrix is a neighbor matrix nxn(when n is the length of the matrix and the heigh of the matrix).
*/
int *dijkstra(int src, int **matrix,int size_per){
    printf("Dijkstra: \n");
    printf("size_per is : %d\n",size_per);
    printMatrix(matrix,size_per);
    int *distance_from_src = (int *) malloc(size_per * sizeof(int));
    // the start node is 0 and all other nodes are infinity
    distance_from_src[src] = 0;
    int *Queue_wannabe = (int *) malloc(size_per * sizeof(int));
    for(int i=0; i< size_per; i++){
        if(i != src){
            distance_from_src[i] =  __INT_MAX__;
        }
        Queue_wannabe[i] = i;
    }
    int size_per_Queue = size_per;
    int min_id;
    while(size_per_Queue > 0){
        min_id = popMin(distance_from_src,Queue_wannabe,size_per);
        printf("min id is : %d\n", min_id);
        size_per_Queue-=1;
        if(min_id == -1) { printf("got -1 in min_id\n");break;}
        relax(distance_from_src,matrix,min_id,size_per);
        printdistances(distance_from_src,size_per);
    }
    free(Queue_wannabe);
    return distance_from_src;
}
void swap(int *permutation, int index1, int index2){
    int temp = permutation[index1];
    permutation[index1] = permutation[index2];
    permutation[index2] = temp;
}
int calc_weight(int *permutation , int **matrix, int size_per){
    int weight = 0, cur_path_weight;
    for(int i=0; i<size_per-1; i++){
        //printMatrix(matrix));
        printf("iteration %d\n", i);
        printf("permutation[i] %d, permutation[i+1] %d\n",permutation[i],permutation[i+1]);
        cur_path_weight = matrix[permutation[i]][permutation[i+1]];
        printf("cur_path_weight %d\n", cur_path_weight);
        if(cur_path_weight != -1 && cur_path_weight != __INT_MAX__)
            weight+=cur_path_weight;
        else   
            return -1;
    }
    return weight;
}
void print_arr(int * arr, int k){
    for(int i=0; i< k; i++){
        if(i!= 0)
            printf(" -> %d ", arr[i]);
        else
            printf("%d",arr[i]);
    }
    printf("\n");
}
void print_permutations(int ** permutations,int num_perm, int size_perm){
    printf("size of perm is : %d\n",size_perm);
    for(int i=0; i<num_perm; i++){
        print_arr(permutations[i],size_perm);
    }
}
int* deep_copy(int *permutation,int size_per){
    int *per = (int *)malloc(sizeof(int) * size_per);
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
int factorial(int x){
    int ret = 1;
    for(int i=0; i<x; i++){
        ret *=(x-i);
    }
    return ret;
}
int TSP(int ** matrix, int *cities_to_visit, int size_per,int size_mat){
    printMatrix(matrix, size_mat);
    // number of all the permutations for size_per =4 receive 4! = 24 perm
    int num_permutations = factorial(size_per);
    int ** permutations = malloc(sizeof(int *) * num_permutations);
    for (int i=0; i< num_permutations; i++){
        permutations[i] = (int *)NULL;
    }
    All_Permutations(cities_to_visit,permutations,0,size_per-1,0);
    print_permutations(permutations, num_permutations, size_per);
    int min_weight = __INT_MAX__;
    int * minperm, cur_weight;
    for(int i=0; i< num_permutations; i++){
        cur_weight = calc_weight(permutations[i],matrix,size_per);
        printf("\n");
        if(cur_weight == -1) continue;
        if(cur_weight < min_weight){
            min_weight = cur_weight;
            minperm = permutations[i];
        }
    }
    if(min_weight == __INT_MAX__){
        printf("no path found between these cities\n %d",-1);
    }
    else{
        // print perm
        printf("minimum permutation is : ");
        for(int i=0; i< size_per; i++){
            if(i != 0)
                printf(" -> %d",minperm[i]);
            else
                printf("%d",minperm[i]);
        }
        printf("\n weight of the permutation is : %d \n",min_weight);
    }
    // free all memory stored in permutations
    for(int i=0; i< num_permutations; i++){
        free(permutations[i]);
    }
    free(permutations);
return 0;
}

