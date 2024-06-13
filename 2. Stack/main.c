#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList newStack;
	initStack(&newStack);
	
	visualize(newStack);
	
	stack_push(&newStack, 4);
	stack_push(&newStack, 7);
	stack_push(&newStack, 1);
	stack_push(&newStack, 7);
	
	visualize(newStack);
	display(newStack);
	
	stack_pop(&newStack);
	
	visualize(newStack);
	
	return 0;
}
