#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#define MAX 100

void initAdjMatrix(int adjMatrix[MAX][MAX], int vertices);

void addEdge(int adjMatrix[MAX][MAX], int v, int u);

void displayAdjMatrix(int adjMatrix[MAX][MAX], int vertices);

#endif
