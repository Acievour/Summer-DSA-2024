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
	
	visualize(newQueue);
	display(newQueue);
	
	dequeue(&newQueue);
	
	visualize(newQueue);
	display(newQueue);
	
	printf(" ======================= Circular Array =======================\n\n");
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	enqueueArr(&circularQ, 80);
	enqueueArr(&circularQ, 20);
	enqueueArr(&circularQ, 35);
	enqueueArr(&circularQ, 25);
	enqueueArr(&circularQ, 55);
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	dequeueArr(&circularQ);
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	dequeueArr(&circularQ);
	dequeueArr(&circularQ);
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	enqueueArr(&circularQ, 80);
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	enqueueArr(&circularQ, 69);
	
	visualizeArr(circularQ);
	displayArr(circularQ);
	
	return 0;
}
