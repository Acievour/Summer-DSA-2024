#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

int isEmpty(Queue Q) {
	return Q.front == NULL;
}

void enqueue(Queue *Q, int elem) {
	NodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->data = elem;
		temp->next = NULL;
		if(Q->rear == NULL) {
			Q->front = temp;
		} else {
			Q->rear->next = temp;
		}
		Q->rear = temp;
	}
}

void dequeue(Queue *Q) {
	NodePtr temp = malloc(sizeof(struct node));
	temp = Q->front;
	if(temp != NULL) {
		Q->front = temp->next;
		free(temp);
		if(isEmpty(*Q)) {
			Q->rear = NULL;
		}
	}
}

int frontQ(Queue Q) {
	return Q.front->data;
}

int rearQ(Queue Q) {
	return Q.rear->data;
}

void display(Queue Q) {
	NodePtr trav;
	printf(" Values of the Linked List: ");
	for(trav = Q.front; trav != NULL; trav = trav->next) {
		printf("%d ", trav->data);
	}
	printf("\n\n");
}

void visualize(Queue Q) {
	printf(" INDEX | DATA\n");
	NodePtr trav;
	int x;
	for(trav = Q.front, x = 0; trav != NULL; trav = trav->next, x++) {
		printf("   %d   |  %d\n", x, trav->data);
	}
	printf("\n Front: %d\n Rear: %d\n", frontQ(Q), rearQ(Q));
	printf("\n");
}
