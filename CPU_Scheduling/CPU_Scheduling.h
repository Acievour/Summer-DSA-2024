#ifndef CPU_SCHEDULING
#define CPU_SCHEDULING

typedef struct node {
	int pid;
	int AT;
	int BT;
	int WT;
	int TT;
	struct node *next;
} Process, *ProcessPtr;

typedef struct {
	ProcessPtr front;
	ProcessPtr rear;
} Queue;

ProcessPtr createProcess(int pid, int AT, int BT);

void initQueue(Queue *Q);
Queue createQueue();

void enqueueProcess(Queue *Q, int pid, int AT, int BT);
void enqueueFCFS(Queue *Q, int pid, int AT, int BT);
ProcessPtr dequeueProcess(Queue *Q);

void calculateTimes(Queue *Q);
void displayProcess(Queue *Q, int n); // n is the number of processes

void FCFS(Queue *Q, int n);

#endif
