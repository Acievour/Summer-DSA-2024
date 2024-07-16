#include <stdio.h>
#include <stdlib.h>
#include "AdjMatrix.h"
#include "AdjList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int adjMatrix[MAX][MAX];
	int vertices = 5;
	
	GraphPtr adjListGraph = createGraph(vertices);
	initAdjMatrix(adjMatrix, vertices);

	printf("Initial adjMatrix: \n");
	displayAdjMatrix(adjMatrix, vertices);
	
	addEdge(adjMatrix, 0, 2); // ( A, C )
	addEdge(adjMatrix, 0, 1); // ( A, B )
	addEdge(adjMatrix, 0, 3); // ( A, C )
	addEdge(adjMatrix, 1, 0); // ( B, A )
	addEdge(adjMatrix, 1, 2); // ( B, C )
	addEdge(adjMatrix, 1, 3); // ( B, D )
	addEdge(adjMatrix, 1, 4); // ( B, E )
	addEdge(adjMatrix, 2, 0); // ( C, A )
	addEdge(adjMatrix, 2, 1); // ( C, B )
	addEdge(adjMatrix, 2, 3); // ( C, D )
	addEdge(adjMatrix, 3, 0); // ( D, A )
	addEdge(adjMatrix, 3, 1); // ( D, B )
	addEdge(adjMatrix, 3, 2); // ( D, C )
	addEdge(adjMatrix, 3, 4); // ( D, E )
	addEdge(adjMatrix, 4, 1); // ( E, B )
	addEdge(adjMatrix, 4, 3); // ( E, D )
	
	printf("\n\nadjMatrix after adding elements: \n");
	displayAdjMatrix(adjMatrix, vertices);
	
	printf("\nPopulating adjList...\n\n");
	addEdgeAL(adjListGraph, 0, 2); // ( A, C )
	addEdgeAL(adjListGraph, 0, 1); // ( A, B )
	addEdgeAL(adjListGraph, 0, 3); // ( A, C )
	addEdgeAL(adjListGraph, 1, 0); // ( B, A )
	addEdgeAL(adjListGraph, 1, 2); // ( B, C )
	addEdgeAL(adjListGraph, 1, 3); // ( B, D )
	addEdgeAL(adjListGraph, 1, 4); // ( B, E )
	addEdgeAL(adjListGraph, 2, 0); // ( C, A )
	addEdgeAL(adjListGraph, 2, 1); // ( C, B )
	addEdgeAL(adjListGraph, 2, 3); // ( C, D )
	addEdgeAL(adjListGraph, 3, 0); // ( D, A )
	addEdgeAL(adjListGraph, 3, 1); // ( D, B )
	addEdgeAL(adjListGraph, 3, 2); // ( D, C )
	addEdgeAL(adjListGraph, 3, 4); // ( D, E )
	addEdgeAL(adjListGraph, 4, 1); // ( E, B )
	addEdgeAL(adjListGraph, 4, 3); // ( E, D )
	
	displayAdjList(adjListGraph);
	
	return 0;
}

