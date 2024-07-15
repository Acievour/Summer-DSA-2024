#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int adjMatrix[MAX][MAX];
	int vertices = 5;
	
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
	
	return 0;
}

