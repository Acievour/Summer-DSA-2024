#ifndef SETS_BITVECTOR
#define SETS_BITVECTOR

#define SIZE 10

typedef int BitVector[SIZE];
typedef int Set[SIZE];

void initSetBV(Set *S);
Set* createSetBV();

void addElemArr(Set *S, int elem);
void delElemArr(Set *S, int elem);

Set* unionBV(Set A, Set B);
Set* intersectionBV(Set A, Set B);
Set* differenceBV(Set A, Set B);

void visualizeSetBV(Set S);
void displaySetBV(Set S);

#endif
