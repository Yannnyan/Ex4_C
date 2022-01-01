#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
typedef enum bool {
    True=1,
    False=0
}bool;

int main(){
printf("Starting program!\n");
bool graph_exist = False;
char func='0';
pnode head;
while(func != EOF){
    func=getchar();
    if (func=='A'){
        printf("Got an A\n");
        if(graph_exist){
            head = getHead();
            deleteGraph_cmd(&head);
        }
        build_graph_cmd(&head);
        graph_exist=True;
    }else if(func=='B'){
        head = getHead();
        insert_node_cmd(&head);
        
    }else if(func=='D'){
        head = getHead();
        printGraph_cmd(head);
        delete_node_cmd(&head);
        head = getHead();
        printGraph_cmd(head);
    }else if(func=='S'){
        head = getHead();
        printGraph_cmd(head);
        shortsPath_cmd(head);
    }else if(func=='T'){
        head = getHead();
        TSP_cmd(head);
    }
    else if(func == 'Q'){
        head = getHead();
        if(head == (pnode) NULL){
            printf("head is null !\n");
            return 0;
        }
        printGraph_cmd(head);
        return 1;
    }
    /*
    else {
        printGraph_cmd();
    }
    */
}
return 1;
}



