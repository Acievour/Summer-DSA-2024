#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"
#include "QueueCircularArr.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue newQueue;
	CircularQ circularQ;
	initQueue(&newQueue);
	initQueueArr(&circularQ);
	
	printf("\n ======================= Linked List =======================\n\n");
	
	enqueue(&newQueue, 10);
	enqueue(&newQueue, 4);
	enqueue(&newQueue, 3);
	enqueue(&newQueue, 7);
	enqueue(&newQueue, 14);
	
	display(newQueue);
	
	dequeue(&newQueue);
	
	display(newQueue);
	
	printf(" ======================= Circular Array =======================\n\n");
	
	displayArr(circularQ);
	
	enqueueArr(&circularQ, 80);
	enqueueArr(&circularQ, 20);
	enqueueArr(&circularQ, 35);
	enqueueArr(&circularQ, 25);
	enqueueArr(&circularQ, 55);
	
	displayArr(circularQ);
	
	dequeueArr(&circularQ);
	
	displayArr(circularQ);
	
	dequeueArr(&circularQ);
	dequeueArr(&circularQ);
	
	displayArr(circularQ);
	
	enqueueArr(&circularQ, 80);
	
	displayArr(circularQ);
	
	return 0;
}
