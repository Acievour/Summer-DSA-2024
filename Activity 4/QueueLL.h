#ifndef QUEUE_LL
#define QUEUE_LL

typedef struct node {
	int data;
	struct node* next;
} Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
} Queue;

void initQueue(Queue *Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int frontQ(Queue Q);
int rearQ(Queue Q);

void display(Queue Q);

#endif
