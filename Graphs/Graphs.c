#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"

void initAdjMatrix(int adjMatrix[MAX][MAX], int vertices) {
	int x, y;
	for(x = 0; x < vertices; x++) {
		for(y = 0; y < vertices; y++) {
			adjMatrix[x][y] = 0;
		}
	}
}

void addEdge(int adjMatrix[MAX][MAX], int v, int u) {
	adjMatrix[u][v] = 1;
	adjMatrix[v][u] = 1;
}

void displayAdjMatrix(int adjMatrix[MAX][MAX], int vertices) {
	int x, y;
	for(x = 0; x < vertices; x++) {
		for(y = 0; y < vertices; y++) {
			printf("%d ", adjMatrix[x][y]);
		}
		printf("\n");
	}
}
