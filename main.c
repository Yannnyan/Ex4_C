#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
typedef enum bool {
    True=1,
    False=0
}bool;

    int main(){
    bool flag = True;
    bool graph_exist = False;
    char func='0';
    pnode * head;
    while(flag){
        func=getchar();
        if (func=='A'){
            if(graph_exist){
                head = getHead();
                deleteGraph_cmd(head);
            }
            head = (pnode *) malloc(sizeof(node));
            build_graph_cmd(head);
            graph_exist=True;
        }else if(func=='B'){
            head = getHead();
            insert_node_cmd(head);
        }else if(func=='D'){
            head = getHead();
            delete_node_cmd(head);
        }else if(func=='S'){
            head = getHead();
            shortsPath_cmd((*head));
        }else if(func=='T'){
            head = getHead();
            TSP_cmd((*head));
        }
        /*
        else {
            printGraph_cmd();
        }
        */
    }
}



