#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *S) {
	S->top = -1;
}

StackArrayList createStack() {
	StackArrayList newStack;
	newStack.top = -1;
	return newStack;
}

bool isEmpty(StackArrayList S) {
	return (S.top != -1) ? 0 : 1;
}

bool isFull(StackArrayList S) {
	return (S.top < MAX) ? 0 : 1;
}

bool stack_push(StackArrayList *S, int elem) {
	bool retval = 0;
	if(!isFull(*S)) {
		S->data[++S->top] = elem;
		retval = 1;
	}
	return retval;
}

bool stack_pop(StackArrayList *S) {
	bool retval = 0;
	if(!isEmpty(*S)) {
		--S->top;
		retval = 1;
	}
	return retval;
}

int stack_peek(StackArrayList S) {
	return S.data[S.top];
}

void display(StackArrayList S) { // displaying from index 0 to top
	StackArrayList tempStack;
	initStack(&tempStack);
	int x, y, ctr = S.top + 1;
	printf(" Display Stack: ");
	for(x = 0; x < ctr; x++) {
		stack_push(&tempStack, S.data[S.top]);
		stack_pop(&S);
	}
	for(y = 0; y < ctr; y++) {
		stack_push(&S, tempStack.data[tempStack.top]);
		printf("%d ", stack_peek(tempStack));
		stack_pop(&tempStack);
	}
	printf("\n");
}

void visualize(StackArrayList S) {
	int x;
	printf("\n INDEX | DATA\n");
	for(x = 0; x <= S.top; x++) {
		printf("   %d   |  %d\n", x, S.data[x]);
	}
	printf("\n Current TOP: %d\n\n", stack_peek(S));
}

StackArrayList getAllEven(StackArrayList *S) {
	
}
