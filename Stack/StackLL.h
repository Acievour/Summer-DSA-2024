#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} StackLinkedList, *StackPtr;

void initStack(StackPtr *S);
StackLinkedList createStack();

bool stack_push(StackPtr *S, int elem);
bool stack_pop(StackPtr *S);
int stack_peek(StackPtr S);

bool isEmpty(StackPtr S);

void display(StackPtr S);
void visualize(StackPtr S);

// ======================= other functions ======================= //
//      create a function that would get all the even numbers 	   //
//      and return as a new stack removing from the old stack	   //
// =============================================================== //

StackPtr getAllEven(StackPtr *S);

#endif
