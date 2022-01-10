#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


int main(){
pnode head;
int flag=1, size;
int graph_built = 0;
char next;

while(flag != EOF && flag == 1){
    flag = scanf(" %c",&next);
    if(flag == EOF) break;
    switch(next){
        case 'A':
            if(graph_built == 1){
                deleteGraph_cmd(&head);
            }
            flag = scanf(" %d",&size);
            head = *(init_graph(size));
            build_graph_cmd(&head);
            graph_built = 1;
            break;
        case 'B':
            insert_node_b_cmd(&head);
            break;
        case 'D':
            printGraph_cmd(head);
            delete_node_cmd(&head);
            break;
        case 'S':
            shortsPath_cmd(head);
            break;
        case 'T':
            TSP_cmd(head);
            break;
    }
}
printGraph_cmd(head);
deleteGraph_cmd(&head);
return 0;

}