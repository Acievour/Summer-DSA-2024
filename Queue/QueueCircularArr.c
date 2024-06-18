#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueCircularArr.h"

void initQueueArr(CircularQ *Q) {
	Q->front = 0;
	Q->rear = -1;
}

bool isFullArr(CircularQ Q) {
	return (Q.rear + 2) % MAX == Q.front;
}

bool isEmptyArr(CircularQ Q) {
	return (Q.rear + 1) % MAX == Q.front;
}

void enqueueArr(CircularQ *Q, int elem) {
	if(!(isFullArr(*Q))) {
		Q->rear++;
		Q->data[Q->rear] = elem;
	}
}

void dequeueArr(CircularQ *Q) {
	if(!(isEmptyArr(*Q))) {
		Q->front = (Q->front + 1) % MAX; // when it reaches max it can go back to index 0;
	}
}

int frontQArr(CircularQ Q) {
	return Q.data[Q.front];
}

int rearQArr(CircularQ Q) {
	return Q.data[Q.rear];
}

void displayArr(CircularQ Q) {
	int x;
	printf(" INDEX | DATA\n");
	for(x = Q.front; x <= Q.rear; x++) {
		printf("   %d   |  %d\n", x, Q.data[x]);
	}
	printf("\n Front: %d\n Rear: %d\n", frontQArr(Q), rearQArr(Q));
	printf("\n\n");
}
