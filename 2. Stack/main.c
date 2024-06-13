#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList newStack;
	initStack(&newStack);
	
	printf("|----------- Created new Stack -----------|\n");
	visualize(newStack);
	
	stack_push(&newStack, 4);
	stack_push(&newStack, 7);
	stack_push(&newStack, 1);
	stack_push(&newStack, 3);
	stack_push(&newStack, 2);
	stack_push(&newStack, 8);
	
	printf("|-------- Added elements to Stack --------|\n\n");
	display(newStack);
	visualize(newStack);
	
	stack_pop(&newStack);
	
	printf("|----------- Popped an element -----------|\n\n");
	display(newStack);
	visualize(newStack);
	
	return 0;
}
