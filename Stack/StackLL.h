#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} StackLinkedList, *StackPtr;

void initStackLL(StackPtr *S);
StackPtr createStackLL();

bool stack_pushLL(StackPtr *S, int elem);
bool stack_popLL(StackPtr *S);
int stack_peekLL(StackPtr S);

bool isEmptyLL(StackPtr S);

void displayLL(StackPtr *S);
void visualizeLL(StackPtr S);

// ======================= other functions ======================= //
//      create a function that would get all the even numbers 	   //
//      and return as a new stack removing from the old stack	   //
// =============================================================== //

StackPtr getAllEvenLL(StackPtr *S);

#endif
