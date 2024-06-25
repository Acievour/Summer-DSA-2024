#include <stdio.h>
#include <stdlib.h>
#include "CPU_Scheduling.h"

ProcessPtr createProcess(int pid, int AT, int BT) {
	ProcessPtr newProcess = (ProcessPtr)malloc(sizeof(Process));
	newProcess->pid = pid;
	newProcess->AT = AT;
	newProcess->BT = BT;
	newProcess->WT = 0;
	newProcess->TT = 0;
	newProcess->next = NULL;
	return newProcess;
}

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

Queue createQueue() {
	Queue newQueue;
	newQueue.front = NULL;
	newQueue.rear = NULL;
	return newQueue;
}

void enqueueProcess(Queue *Q, int pid, int AT, int BT) {
	ProcessPtr newProcess = createProcess(pid, AT, BT);
	if(Q->rear != NULL) {
		Q->rear->next = newProcess;
		Q->rear = newProcess;
	} else {
		Q->front = newProcess;
		Q->rear = newProcess;
	}
}

void enqueueFCFS(Queue *Q, int pid, int AT, int BT) {
	ProcessPtr newProcess = createProcess(pid, AT, BT);
	if(Q->front == NULL || Q->front->AT > newProcess->AT) {
		newProcess->next = Q->front;
		Q->front = newProcess;
		if(Q->rear == NULL) {
			Q->rear = newProcess;
		}
	} else {
		ProcessPtr curr = Q->front;
        while(curr->next != NULL && curr->next->AT <= newProcess->AT) {
            curr = curr->next;
        }
        newProcess->next = curr->next;
        curr->next = newProcess;
        if(newProcess->next == NULL) {
            Q->rear = newProcess;
        }
	}
}

ProcessPtr dequeueProcess(Queue *Q) {
	ProcessPtr temp = malloc(sizeof(Process));
	temp = Q->front;
	if(temp != NULL) {
		Q->front = temp->next;
		if(Q->front == NULL) {
			Q->rear = NULL;
		}
	}
	return temp;
}

void calculateTimes(Queue *Q) {
	ProcessPtr curr = Q->front;
	int currTime = 0;
	
	while(curr != NULL) {
		if(currTime < curr->AT) {
			currTime = curr->AT;
		}
		curr->WT = currTime - curr->AT;
        curr->TT = curr->WT + curr->BT;
        currTime = currTime + curr->BT;
        curr = curr->next;
	}
}

void displayProcess(Queue *Q, int n) {  // n is the number of processes
	ProcessPtr curr = Q->front;
	int totalWT = 0;
	int totalTT = 0;
	
	printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
	while(curr != NULL) {
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", curr->pid, curr->AT, curr->BT, curr->WT, curr->TT);
		totalWT = totalWT + curr->WT;
		totalTT = totalTT + curr->TT;
		curr = curr->next;
	}
	
	printf("Average Waiting Time: %.2f\n", (float)totalWT / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTT / n);
}

void FCFS(Queue *Q, int n) {
	calculateTimes(Q);
	displayProcess(Q, n);
}
