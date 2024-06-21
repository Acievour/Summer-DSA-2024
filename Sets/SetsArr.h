#ifndef SETS_ARR
#define SETS_ARR

#define MAX 10

typedef struct {
	int data[MAX];
	int count;
} Set;

void initSetArr(Set *S);
Set createSetArr();

void addElemArr(Set *S, int elem);
void delElemArr(Set *S, int elem);

Set unionArr(Set A, Set B);
Set intersectionArr(Set A, Set B);
Set differenceArr(Set A, Set B);

void visualizeSetArr(Set S);
void displaySetArr(Set S);

#endif
