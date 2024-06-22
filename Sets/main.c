#include <stdio.h>
#include <stdlib.h>
#include "SetsArr.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Set A, B, C;
	initSetArr(&A);
	initSetArr(&B);
	
	printf("\n     Creating and Initializing new Set A and Set B...\n");
	printf("\n          SET A\n");
	visualizeSetArr(A);
	printf("\n          SET B\n");
	visualizeSetArr(B);
	
	system("pause");
	system("cls");
	printf("\n     Populating Set A with values 1 3 1 7 5 2...\n");
	printf("\n     Populating Set B with values 2 4 4 9 1 6...\n");
	addElemArr(&A, 1);
	addElemArr(&A, 3);
	addElemArr(&A, 1);
	addElemArr(&A, 7);
	addElemArr(&A, 5);
	addElemArr(&A, 2);
	
	addElemArr(&B, 2);
	addElemArr(&B, 4);
	addElemArr(&B, 4);
	addElemArr(&B, 9);
	addElemArr(&B, 1);
	addElemArr(&B, 6);
	
	printf("\n          SET A\n");
	visualizeSetArr(A);
	displaySetArr(A);
	printf("\n          SET B\n");
	visualizeSetArr(B);
	displaySetArr(B);
	
	system("pause");
	printf("\n     Deleted values 8 and 3 from Set A...\n");
	delElemArr(&A, 8);
	delElemArr(&A, 3);
	
	printf("\n          SET A\n");
	visualizeSetArr(A);
	displaySetArr(A);
	
	system("pause");
	system("cls");
	printf("\n     Union of Set A and Set B\n");
	visualizeSetArr(unionArr(A, B));
	displaySetArr(unionArr(A, B));
	
	printf("\n     Intersection of Set A and Set B\n");
	visualizeSetArr(intersectionArr(A, B));
	displaySetArr(intersectionArr(A, B));
	
	return 0;
}
