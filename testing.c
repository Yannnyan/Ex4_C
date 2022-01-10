//
// Created by Yan on 09/01/2022.
//

#include <stdio.h>
#include "graph.h"

int main(){
    pnode * pointer_father;
    pnode pointer , pointer1, pointer2;
    node Node;
    printf("Node is: %x\n",&Node);
    printf("pointer is : %x\n", pointer);
    printf("pointer1 is : %x\n", pointer1);
    printf("pointer2 is : %x\n",pointer2);
    pointer = &Node;
    pointer->next = pointer1;
    pointer2 = pointer->next;
    pointer->next = (pnode)NULL;
    printf("Node is: %x\n",&Node);
    printf("pointer is : %x\n", pointer->next);
    printf("pointer1 is : %x\n", pointer1);
    printf("pointer2 is : %x\n",pointer2);



}

