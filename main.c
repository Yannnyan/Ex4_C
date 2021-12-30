#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
typedef enum bool {
    True=1,
    False=0
}bool;


int main(){
printf("Starting program!\n");
bool flag = True;
bool graph_exist = False;
char func='0';
pnode * head;
while(func != EOF){
    func=getchar();
    if (func=='A'){
        printf("Got an A\n");
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
    else if(func == 'Q'){
        head = getHead();
        if(head == (pnode *) NULL){
            printf("head is null !");
            return 0;
        }
        printGraph_cmd(*head);
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



