#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"
#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList newStack;
	StackArrayList evenStack;
	StackPtr stackLL;
	initStack(&newStack);
	initStack(&evenStack);
	initStackLL(&stackLL);
	
	printf("|----------- Created new Stack Array -----------|\n");
	visualize(newStack);
	
	stack_push(&newStack, 4);
	stack_push(&newStack, 7);
	stack_push(&newStack, 1);
	stack_push(&newStack, 6);
	stack_push(&newStack, 2);
	stack_push(&newStack, 8);
	
	printf("|-------- Added elements to Stack Array --------|\n\n");
	display(newStack);
	visualize(newStack);
	
	stack_pop(&newStack);
	
	printf("|----------- Popped an element -----------|\n\n");
	display(newStack);
	visualize(newStack);
	
	evenStack = getAllEven(&newStack);
	
	printf("|--------- Get all even function ---------|\n\n");
	display(newStack);
	visualize(newStack);
	
	display(evenStack);
	visualize(evenStack);
	printf("====================================================================================\n\n");
	
	printf("|----------- Created new Stack LL -----------|\n");
	visualizeLL(stackLL);
	
	stack_pushLL(&stackLL, 4);
	stack_pushLL(&stackLL, 7);
	stack_pushLL(&stackLL, 4);
	stack_pushLL(&stackLL, 1);
	stack_pushLL(&stackLL, 2);
	stack_pushLL(&stackLL, 8);
	
	printf("|-------- Added elements to Stack LL --------|\n\n");
	displayLL(&stackLL);
	visualizeLL(stackLL);
	
	printf("|----------- Popped an element -----------|\n\n");
	stack_popLL(&stackLL);
	displayLL(&stackLL);
	visualizeLL(stackLL);
	
	return 0;
}
