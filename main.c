#include <stdlib.h>
#include <stdlib.h>
#include "graph.h"



int main(){
    int true = 1
    while(true){
        char c;
        scanf("%c",&c);
        if(c == 'A'){
            scanf("%c", &c);
            node head;
            pnode current_node = &head;
            pedge current_edge;
            int index_graph =0, index_node=0, curID, destID, weight;

            size_t size_graph;
            while(c != 'A' && c != 'B' && c != 'D' && c != 'S' && c != 'T'){
                if(index_graph == 0){
                    // converting the char to its number values
                    size_graph = atoi("%c", c);
                }
                else if(index_graph == 1){
                    curID = atoi("%c",c);

                }
                if(index_graph > 1){
                    if(c == 'n'){
                        node cur;
                        current_node->next = cur;
                        current_node = current_node.next;
                        edge first_edge;
                        current_edge = &first_edge;
                        index_node +=1;
                    }
                    // destid
                    else if(index_node % 2 == 1){
                        destID = atoi("%c,c");

                        index_node+=1;
                    }
                    else{
                        weight = atoi("%c",c);
                        
                    }

                }
                

            }
            build_graph_cmd()
            // 1) if a graph exists then delete it
            // 2) receive new Graph and make it
            
            /* Notes:
                if user types n then it gets one argument id and then it gets weight details (destID,Weight)
                a user may insert few edges that go out of a node each should be specified with a weight
                
            */    
        }
        if(c == 'B'){
            
            



        }
        if (c == 'D'){


        }
        if (c == 'S'){

        }
        if (c == 'T'){


        }


    }


}

