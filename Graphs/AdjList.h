#ifndef ADJLIST_H
#define ADJLIST_H

typedef struct node {
	int data;
	struct node *next;
} AdjListNode, *AdjListNodePtr;

typedef struct AdjList {
	AdjListNodePtr head;
} AdjList, *AdjListPtr;

typedef struct Graph {
	int vertix;
	AdjListPtr array;
} Graph, *GraphPtr;

AdjListNodePtr newAdjListNode(int node);
GraphPtr createGraph(int vertices);
void addEdgeAL(GraphPtr graph, int v, int u);
void displayAdjList(GraphPtr graph);

#endif
