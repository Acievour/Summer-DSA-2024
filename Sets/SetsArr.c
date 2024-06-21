#include <stdio.h>
#include <stdlib.h>
#include "SetsArr.h"

void initSetArr(Set *S) {
	S->count = 0;
	
	// below is the statement for initializing all the elements to 0
	int x;
	for(x = 0; x < MAX; x++) {
		S->data[x] = 0;
	}
}

Set createSetArr() {
	Set S;
	S.count = 0;
	return S;
}

void addElemArr(Set *S, int elem) {
	if(elem > 0 && elem < MAX) { // checks the elem if it is in the range of the universal set
		if(S->count < MAX) { // checks if the set has space
			if(S->data[elem] != 1) { 
				S->data[elem] = 1;    // this if statement checks if value already exists and doesn't
				S->count++;           // update the count if it already exists
			} else {
				S->data[elem] = 1;
			}
		}
	}
}

void delElemArr(Set *S, int elem) {
	if(elem > 0 && elem < MAX) { // checks the elem if it is in the range of the universal set
		if(S->count < MAX) { // checks if the set has space
			if(S->data[elem] != 0) { 
				S->data[elem] = 0;    // this if statement checks if value already exists and doesn't
				S->count--;           // update the count if it already exists
			} else {
				S->data[elem] = 0;
			}
		}
	}
}

Set unionArr(Set A, Set B) {
	Set C;
	initSetArr(&C);
	int x;
	for(x = 0; x < MAX; x++) {
		if(A.data[x] | B.data[x] == 1) {
			C.data[x] = 1;
			C.count++;
		}
	}
	return C;
}

Set intersectionArr(Set A, Set B) {
	Set C;
	initSetArr(&C);
	int x;
	for(x = 0; x < MAX; x++) {
		if(A.data[x] && B.data[x] == 1) {
			C.data[x] = 1;
			C.count++;
		}
	}
	return C;
}

Set differenceArr(Set A, Set B) {
	
}

void visualizeSetArr(Set S) {
	int x;
	printf("\n           INDEX | DATA\n");
	for(x = 0; x < MAX; x++) {
		printf("             %d   |   %d\n", x, S.data[x]);
	}
	printf("\n           SET COUNT: %d\n\n", S.count);
}

void displaySetArr(Set S) {
	int x;
	printf("           The Values of the Set: { ");
	for(x = 0; x < MAX; x++) {
		if(S.data[x] != 0) {
			printf("%d ", x);
		}
	}
	printf("}");
	printf("\n\n");
}
