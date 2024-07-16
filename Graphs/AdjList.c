#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

AdjListNodePtr newAdjListNode(int node) {
	AdjListNodePtr temp = (AdjListNodePtr)malloc(sizeof(AdjListNode));
	temp->data = node;
	temp->next = NULL;
	return temp;
}

GraphPtr createGraph(int vertices) {
	GraphPtr graph = (GraphPtr)malloc(sizeof(Graph));
	graph->vertix = vertices;
	
	graph->array = (AdjListPtr)malloc(vertices * sizeof(AdjList));
	
	int x;
	for(x = 0; x < vertices; x++) {
		graph->array[x].head = NULL;
	}
	
	return graph;
}

void addEdgeAL(GraphPtr graph, int v, int u) {
	AdjListNodePtr temp = newAdjListNode(u);
	temp->next = graph->array[v].head;
	graph->array[v].head = temp;
	
	temp = newAdjListNode(v);
	temp->next = graph->array[u].head;
	graph->array[u].head = temp;
}

void displayAdjList(GraphPtr graph) {
	int x;
	for(x = 0; x < graph->vertix; x++) {
		AdjListNodePtr trav = graph->array[x].head;
		printf("Displaying list of vertix of %d\n head", x);
		while(trav) {
			printf(" -> %d", trav->data);
			trav = trav->next;
		}
		printf("\n\n");
	}
}
