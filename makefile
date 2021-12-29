all: nodes edges Graph 

nodes: nodes.o main.o
	gcc -o nodes nodes.o
edges: edges.o main.o
	gcc -o edges edges.o
Graph: Graph.o main.o
	gcc -o Graph graph.o

edges.o: edges.c graph.h
	gcc -c -g -Wall edges.c graph.h
nodes.o: nodes.c graph.h
	gcc -c -g -Wall nodes.c graph.h

graph.o: graph.c graph.h
	gcc -c -g -Wall graph.c graph.h

main.o: main.c graph.h
	gcc -c -g -Wall main.c graph.h



clean:
	rm -f *.o *.gch Graph edges nodes

