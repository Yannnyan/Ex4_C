#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
typedef enum bool {
    True=1,
    False=0
}bool;

int main(){
    bool flag=True;
    bool graph_exist=False;
    char func='0';
    while(flag){
        func=getchar();
        if (func=='A'){
            if(graph_exist){
                deleteGraph_cmd();
            }
            build_graph_cmd();
            graph_exist=True;
        }else if(func=='B'){
            insert_node_cmd();
        }else if(func=='D'){
            delete_node_cmd();
        }else if(func=='S'){
            shortsPath_cmd();
        }else if(func=='T'){
            TSP_cmd();
        }else {
            printGraph_cmd();
        }
    }
}


