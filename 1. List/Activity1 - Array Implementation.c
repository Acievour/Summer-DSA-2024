#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char fName[20];
	char lName[20];
} studName;

typedef struct {
	int month;
	int year;
} bday;

typedef struct {
	studName name;
	bday birthdate;
	int age;
	int idNum;
} studInfo;

typedef struct {
	studInfo studList[20];
	int studCount;
} classRecord;

void initClassRecord(classRecord *A) {
	A->studCount = 0;
}

void insertRear(classRecord *A, studInfo stud) { // or insert last
	if(A->studCount < 20) {
		A->studList[A->studCount] = stud;
		A->studCount++;
	}
}

void insertFront(classRecord *A, studInfo stud) { // or insert first
	if(A->studCount < 20) {
		int x;
		for(x = A->studCount; x > 0; x--) {
			A->studList[x] = A->studList[x-1];
		}
		A->studList[0] = stud;
		A->studCount++;
	}
}

void insertSorted(classRecord *A, studInfo stud) { // sorted by age
	if(A->studCount < 20) {
		int x;
		for(x = A->studCount-1; x >= 0 && A->studList[x].age > stud.age ; x--) {
			A->studList[x+1] = A->studList[x];
		}
		A->studList[x+1] = stud;
		A->studCount++;
	}
}

void insertAtPos(classRecord *A, studInfo stud, int pos) { // insert at index
	if(A->studCount < 20) {
		int x;
		for(x = A->studCount-1; x > pos-1 ; x--) {
			A->studList[x+1] = A->studList[x];
		}
		A->studList[pos] = stud;
		A->studCount++;
	}
}

void deleteFront(classRecord *A) {
	if(A->studCount > 0) {
		int x;
		for(x = 0; x < A->studCount; x++) {
			A->studList[x] = A->studList[x+1];
		}
		A->studCount--;
	}
}

void deleteRear(classRecord *A) {
	if(A->studCount > 0) {
		A->studCount--;
	}
}

void deleteAtPos(classRecord *A, int pos) {
	if(A->studCount > 0 && pos < A->studCount) {
		int x;
		for(x = pos; x < A->studCount; x++) {
			A->studList[x] = A->studList[x+1];
		}
		A->studCount--;
	}
}

void displayClassRecord(classRecord A) {
	int x;
	printf("\nTotal students in the class: [ %d ]", A.studCount);
	for(x = 0; x < A.studCount; x++) {
		printf("\n [%d] Name: %s %s", x, A.studList[x].name.fName, A.studList[x].name.lName);
		printf(" | Age: %d", A.studList[x].age);
	} 
	printf("\n\n");
}

int main() {
	classRecord newClass;
	initClassRecord(&newClass);
	
	/* ============== Populate Student Record using insertSorted ============== */
	
	studInfo studArr[10] = {{{"John", "Doe"}, {4, 12}, 15, 3991},
							{{"Lisa", "Smith"}, {8, 7}, 17, 4117},
							{{"Henry", "Style"}, {6, 21}, 14, 8812},
							{{"James", "River"}, {12, 11}, 18, 9912},
							};
	
	printf("Populating the class record using insertSorted function...");

	insertSorted(&newClass, studArr[0]);
	insertSorted(&newClass, studArr[1]);
	insertSorted(&newClass, studArr[2]);
	insertSorted(&newClass, studArr[3]);
	
	printf("\n\nDisplaying updated class record after insertSorted function:");
	displayClassRecord(newClass);
	
	system("pause");
	
	/* ============== Inserting a student using insertFront ============== */
	
	char inputfName[20];
	char inputlName[20];
	int inputAge;
	
	printf("\n\n[ ============ Inserting student at the front ============ ]");
	printf("\n\nInput your first name: ");
	scanf("%s", &inputfName);
	printf("Input your last name: ");
	scanf("%s", &inputlName);
	printf("Input your age: ");
	scanf("%d", &inputAge);
	
	studInfo tempStud;
	strcpy(tempStud.name.fName, inputfName);
	strcpy(tempStud.name.lName, inputlName);
	tempStud.age = inputAge;
	
	printf("\nInserting [ %s %s (%d) ] into the front of the class record.", inputfName, inputlName, inputAge);
	
	insertFront(&newClass, tempStud);
	
	printf("\n\nDisplaying updated class record after insertFront:");
	displayClassRecord(newClass);
	
	system("pause");
	
	/* ============== Inserting a student using insertRear ============== */
	
	printf("\n\n[ ============ Inserting student at the rear ============ ]");
	printf("\n\nInput your first name: ");
	scanf("%s", &inputfName);
	printf("Input your last name: ");
	scanf("%s", &inputlName);
	printf("Input your age: ");
	scanf("%d", &inputAge);
	
	printf("\nInserting [ %s %s (%d) ] into the rear of the class record.", inputfName, inputlName, inputAge);
	
	strcpy(tempStud.name.fName, inputfName);
	strcpy(tempStud.name.lName, inputlName);
	tempStud.age = inputAge;
	
	insertRear(&newClass, tempStud);
	
	printf("\n\nDisplaying updated class record after insertRear:");
	displayClassRecord(newClass);
	
	system("pause");
	
	/* ============== Inserting a student using insertAtPos ============== */
	
	printf("\n\n[ ============ Inserting student at a postion ============ ]");
	printf("\n\nInput your first name: ");
	scanf("%s", &inputfName);
	printf("Input your last name: ");
	scanf("%s", &inputlName);
	printf("Input your age: ");
	scanf("%d", &inputAge);
	
	int inputPos;
	printf("Input position: ");
	scanf("%d", &inputPos);
	
	printf("\nInserting [ %s %s (%d) ] into the rear of the class record.", inputfName, inputlName, inputAge);
	
	strcpy(tempStud.name.fName, inputfName);
	strcpy(tempStud.name.lName, inputlName);
	tempStud.age = inputAge;
	
	insertAtPos(&newClass, tempStud, inputPos);
	
	printf("\n\nDisplaying updated class record after insertAtPos:");
	displayClassRecord(newClass);
	
	system("pause");
	
	/* ============== Deleting a student using deleteFront ============== */
	
	printf("\n\n[ ============ Deleting student at the front ============ ]");
	
	printf("\n\nExecuting deleteFront...");
	deleteFront(&newClass);
	
	printf("\n\nDisplaying updated class record after deleteFront:");
	displayClassRecord(newClass);
		
	system("pause");
		
	/* ============== Deleting a student using deleteFront ============== */
	
	printf("\n\n[ ============ Deleting student at the rear ============ ]");
	
	printf("\n\nExecuting deleteRear...");
	deleteRear(&newClass);
	
	printf("\n\nDisplaying updated class record after deleteRear:");
	displayClassRecord(newClass);
	
	system("pause");
	
	/* ============== Deleting a student using deleteFront ============== */
	
	printf("\n\n[ ============ Deleting student at a position ============ ]");
	
	printf("\n\nInput position: ");
	scanf("%d", &inputPos);
	
	printf("\nExecuting deleteAtPos...");
	deleteAtPos(&newClass, inputPos);
	
	printf("\n\nDisplaying updated class record after deleteAtPos:");
	displayClassRecord(newClass);
	
	return 0;
}
