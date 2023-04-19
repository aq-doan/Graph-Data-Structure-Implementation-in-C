#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"
/*
* This file is for future usage
*/
Graph create_graph(int v) {
    
    Graph graph;
    graph.V = v;

    graph.edges = malloc(sizeof(graph.edges) * graph.V);

  
    for (int count = 0; count < graph.V; count = count +1) {
        graph.edges[count].head = NULL;
    }
    return graph;
}
void add_edge(Graph graph, int from, int to)
{
    EdgeNodePtr edge_node = malloc(sizeof * edge_node);
    edge_node->edge.to_vertex = to;
    edge_node->next = graph.edges[from].head;
    graph.edges[from].head = edge_node;
}