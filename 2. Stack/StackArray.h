#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 20

typedef struct {
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *S);
StackArrayList createStack();

bool stack_push(StackArrayList *S, int elem);
bool stack_pop(StackArrayList *S);
int stack_peek(StackArrayList S);

bool isEmpty(StackArrayList S);
bool isFull(StackArrayList S);

void display(StackArrayList S);
void visualize(StackArrayList S);

// ======================= other functions ======================= //
//      create a function that would get all the even numbers 	   //
//      and return as a new stack removing from the old stack	   //
// =============================================================== //

StackArrayList getAllEven(StackArrayList *S);

#endif
