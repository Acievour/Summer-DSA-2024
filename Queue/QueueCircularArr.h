#ifndef QUEUE_CIRCULARARR
#define QUEUE_CIRCULARARR

#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
} CircularQ;

void initQueueArr(CircularQ *Q);
bool isFullArr(CircularQ Q);
bool isEmptyArr(CircularQ Q);

void enqueueArr(CircularQ *Q, int elem);
void dequeueArr(CircularQ *Q);

int frontQArr(CircularQ Q);
int rearQArr(CircularQ Q);

void displayArr(CircularQ Q);
void visualizeArr(CircularQ Q);

#endif
