#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"
int* create_in_degrees(int a) {
    int* in_degrees = malloc(sizeof(int) * a);
    for (int i = 0; i < a; i++) {
        in_degrees[i] = 0;
        return in_degrees;
    }
}
void destroy_graph(Graph G) {
    for (int i = 0; i < G.V; i++) {
        EdgeNodePtr edge_node = G.edges[i].head;
        while (edge_node != NULL) {
            EdgeNodePtr temp = edge_node;
            edge_node = edge_node->next;
            free(temp);
        }
    }
    free(G.edges);
}
int main() {
	Graph G; // define a new graph
	scanf("%d", &G.V);// read the input.txt
	G.edges = malloc(sizeof(G.edges) * G.V);//
	//printf("%d\n", G.V); (for debugging)
	for (int i = 0; i < G.V; i++) {
		int edges_number;
		scanf("%d", &edges_number);

		// initialise a new graph new graph
		G.edges[i].head = NULL;

		//printf("%d\n", edges_number); (for debugging)

		for (int count = 0; count < edges_number; count = count + 1) {
			EdgeNodePtr edge_node = malloc(sizeof(EdgeNodePtr));

			scanf("%d,%d", &edge_node->edge.to_vertex, &edge_node->edge.weight);

			//add_edge()
			edge_node->next = G.edges[i].head;
			G.edges[i].head = edge_node;

		}
	}
    //initialise array and set all to 0
    int* in_degrees = create_in_degrees(&G.V);

    /*loop through all of the edges in the graph and increment
    *the in - degree for the to - vertex of each edge
    */
    for (int i = 0; i < G.V; i++) {
        EdgeNodePtr node = G.edges[i].head;
        while (node != NULL) {
            in_degrees[node->edge.to_vertex]++;
            node = node->next;
        }
    }

    //print
    for (int count = 0; count < G.V; count++) {
        printf(" %d in-degree of vertex %d\n",in_degrees[count], count);
    }

    //freeing memory
    free(in_degrees);

    destroy_graph(G);



	return 0;
}