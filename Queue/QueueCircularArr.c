#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueCircularArr.h"

#define EMPTY -1

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
		Q->rear = (Q->rear + 1) % MAX;
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
	if(!isEmptyArr(Q)) {
		printf(" Values of the Circular Array: ");
		for(x = Q.front; x != Q.rear; x = (x + 1) % MAX) {
			printf("%d ", Q.data[x]);
		}
		printf("%d \n", Q.data[x]);
	}
	printf("\n\n");
}

void visualizeArr(CircularQ Q) {
	int x;
	printf(" INDEX | DATA\n");
	if(!isEmptyArr(Q)) {
		for(x = 0; x < MAX; x++) {
			printf("   %d   |  %d \n", x, Q.data[x]);
		}
	}
	printf("\n Front: %d\n Rear: %d\n", frontQArr(Q), rearQArr(Q));
	printf("\n");
}
