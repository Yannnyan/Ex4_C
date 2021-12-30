#flags
LDFLAGS = -W
CCFLAGS = -g -Wall
#targets
all: .graph
.graph: edges.o nodes.o Graph.o algo.o main.o
	 gcc -o .graph main.o nodes.o edges.o Graph.o algo.o $(LDFLAGS)
check_graph: main.o nodes.o edges.o Graph.o
	gcc -o check_graph main.o nodes.o edges.o Graph.o $(LDFLAGS)
nodes: nodes.o main.o edges.o Graph.o
	gcc -o nodes nodes.o edges.o main.o Graph.o $(LDFLAGS)
edges: edges.o main.o nodes.o
	gcc -o edges edges.o nodes.o main.o $(LDFLAGS)
Graph: Graph.o main.o edges.o nodes.o
	gcc -o Graph Graph.o edges.o nodes.o $(LDFLAGS)
#compile
edges.o: edges.c graph.h
	gcc -c $(CCFLAGS) edges.c graph.h
nodes.o: nodes.c graph.h
	gcc -c $(CCFLAGS) nodes.c graph.h
Graph.o: Graph.c graph.h
	gcc -c $(CCFLAGS) Graph.c graph.h
main.o: main.c graph.h
	gcc -c $(CCFLAGS) main.c graph.h
algo.o: algo.c graph.h
	gcc -c $(CCFLAGS) algo.c main.c graph.h
#clean
.PHONY: clean
clean:
	rm -f *.o *.gch Graph edges nodes algo .graph check_graph