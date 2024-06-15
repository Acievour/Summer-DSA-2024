#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStackLL(StackPtr *S) {
	*S = NULL;
}

StackPtr createStackLL() {
	StackPtr newStack;
	newStack = NULL;
	return newStack;
}

bool stack_pushLL(StackPtr *S, int elem) {
	StackPtr temp = malloc(sizeof(struct node));
	bool retval = 0;
	if(temp != NULL) { // always check if the malloc is successful
		temp->data = elem;
		temp->next = *S;
		*S = temp;
		retval = 1;
	}
	return retval;
}

bool stack_popLL(StackPtr *S) {
	bool retval = 0;
	if(*S != NULL) { // checks if linked list is not empty
		StackPtr temp = malloc(sizeof(struct node));
		if(temp != NULL) {
			temp = *S;
			*S = temp->next;
			free(temp);
		}
		retval = 1;
	}
	return retval;
}

int stack_peekLL(StackPtr S) {
	return S->data;
}

bool isEmptyLL(StackPtr S) {
	return (S == NULL);
}

void displayLL(StackPtr *S) {
	StackPtr tempStack;
	initStackLL(&tempStack);
	printf(" Display Stack: ");
	while((*S) != NULL) {
		stack_pushLL(&tempStack, (*S)->data);
		stack_popLL(&(*S));
	}
	while(tempStack != NULL) {
		stack_pushLL(&(*S), tempStack->data);
		printf("%d ", stack_peekLL(tempStack));
		stack_popLL(&tempStack);
	}
	printf("\n");
}

void visualizeLL(StackPtr S) {
	if(S != NULL) {
		StackPtr trav;
		printf("\n INDEX | DATA\n");
		int x;
		for(trav = S, x = 0; trav != NULL; trav = trav->next, x++) {
			printf("   %d   |  %d\n", x, trav->data);
		}
		printf("\n Current TOP: %d\n\n", stack_peekLL(S));
	} else {
		printf("\n INDEX | DATA\n\n");
	}
	
}

StackPtr getAllEvenLL(StackPtr *S) {
	
}
