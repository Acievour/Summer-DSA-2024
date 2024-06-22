#include <stdio.h>
#include <stdlib.h>
#include "SetsArr.h"

void initSetArr(Set *S) {
	S->count = 0;
	
	// below is the statement for initializing all the elements to -1
	int x;
	for(x = 0; x < MAX; x++) {
		S->data[x] = -1;
	}
}

Set createSetArr() {
	Set S;
	S.count = 0;
	return S;
}

void addElemArr(Set *S, int elem) {
	if(elem > 0 && elem < MAX) {
		if(S->count < MAX) {
			int x;
			for(x = 0; x < S->count && S->data[x] != elem; x++) {}
			if(S->data[x] != elem) {
				S->data[x] = elem;
				S->count++;
			} else {
				S->data[x] = elem;
			}
		}
	}
}

void delElemArr(Set *S, int elem) {
	if(elem > 0 && elem < MAX) {
		if(S->count < MAX) {
			int x, y;
			for(x = 0; x < S->count && S->data[x] != elem; x++){}
			if(S->data[x] == elem) {
				for(y = x; y <= S->count; y++) {
					S->data[y] = S->data[y+1];
				}
				S->count--;
			}
		}
	}
}

Set unionArr(Set A, Set B) {
	Set C;
    int a = 0, b = 0;
    initSetArr(&C);
    while(a < A.count && b < B.count) {
        if(A.data[a] < B.data[b]) {
            C.data[C.count] = A.data[a];
            a++;
        } else {
            if(A.data[a] == B.data[b]) {
                a++;
            }
            C.data[C.count] = B.data[b];
            b++;
        }
        C.count++;
    }

    if(b < B.count) {
        A = B;
        a = b;
    }

    while(a < A.count) {
        C.data[C.count] = A.data[a];
        a++;
        C.count++;
    }

    return C;
}

Set intersectionArr(Set A, Set B) {
    Set C;
    int a, b;
    initSetArr(&C);
    for(a = 0; a < A.count; a++) {
        for(b = 0; b < B.count && A.data[a] < B.data[b]; b++) {}
        if(b < B.count && A.data[a] == B.data[b]) {
            C.data[C.count] = A.data[a];
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
		printf("             %d   |  %d\n", x, S.data[x]);
	}
	printf("\n           SET COUNT: %d\n\n", S.count);
}

void displaySetArr(Set S) {
	int x;
	printf("           The Values of the Set: { ");
	for(x = 0; x < S.count; x++) {
			printf("%d ", S.data[x]);
	}
	printf("}");
	printf("\n\n");
}
