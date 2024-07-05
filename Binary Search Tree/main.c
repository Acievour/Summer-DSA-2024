#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr newBST;
	initBST(&newBST);
	
	Product productArr[10] = {{"Piatos", 40.00, 53, {10, 5, 2024}},
							  {"Nova", 45.00, 78, {18, 3, 2024}},
							  {"Tomblerone", 90.00, 44, {22, 8, 2024}},
							  {"Lays", 75.00, 38, {24, 11, 2024}},
							  {"Mang Juan", 35.00, 99, {4, 6, 2024}},
							  {"Hansel", 9.00, 131, {18, 7, 2024}},
							  {"Fita", 9.00, 122, {27, 9, 2023}},
							  {"Ace", 9.00, 111, {1, 6, 2023}},
							  {"Oreos", 8.00, 140, {13, 7, 2023}},
							  {"SkyFlakes", 8.00, 138, {12, 12, 2024}},
							 };
	
	
	insertElem(&newBST, productArr[0]);
	insertElem(&newBST, productArr[1]);
	insertElem(&newBST, productArr[2]);
	insertElem(&newBST, productArr[3]);
	insertElem(&newBST, productArr[4]);
	insertElem(&newBST, productArr[6]);
	insertElem(&newBST, productArr[7]);
	insertElem(&newBST, productArr[8]);
	insertElem(&newBST, productArr[9]);
	
	printf("Preorder: { ");
	preorder(newBST);
	printf("}");
	printf("\n\n");
	printf("Inorder: { ");
	inorder(newBST);
	printf("}");
	printf("\n\n");
	printf("Postorder: { ");
	postorder(newBST);
	printf("}");
	
	return 0;
}
