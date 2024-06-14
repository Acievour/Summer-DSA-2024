#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue newQueue;
	initQueue(&newQueue);
	
	enqueue(&newQueue, 10);
	enqueue(&newQueue, 4);
	enqueue(&newQueue, 3);
	enqueue(&newQueue, 7);
	enqueue(&newQueue, 14);
	
	display(newQueue);
	
	dequeue(&newQueue);
	
	display(newQueue);
	
	return 0;
}
