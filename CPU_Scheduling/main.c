#include <stdio.h>
#include <stdlib.h>
#include "CPU_Scheduling.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, arrival_time, burst_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    Queue q = createQueue();

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time);
        enqueueFCFS(&q, i + 1, arrival_time, burst_time);
        printf("\n");
    }

    FCFS(&q, n);
	
	return 0;
}
