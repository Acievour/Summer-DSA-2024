#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	int idNum;
	int age;
} info;

typedef struct node {
	info data;
	struct node *next; // struct node *link;
} *NodePtr, Node;

void initList(NodePtr *A) {
	*A = NULL;
}

void insertFront(NodePtr *A, info elem) {
	NodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->data = elem;
		temp->next = *A;
		*A = temp;
	}
}

void insertRear(NodePtr *A, info elem) {
	NodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		NodePtr *trav;
		for(trav = A; *trav != NULL; trav = &(*trav)->next) {}
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertAtPos(NodePtr *A, info elem, int pos) {
	NodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		NodePtr *trav;
		int x;
		for(trav = A, x = 0; *trav != NULL && x < pos; trav = &(*trav)->next, x++) {}
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertSorted(NodePtr *A, info elem) { // sort by age
	NodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL) {
		NodePtr *trav;
		int x;
		for(trav = A; *trav != NULL && (*trav)->data.age < elem.age; trav = &(*trav)->next) {}
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteElem(NodePtr *A, char name[]) { // delete using name
	if(*A != NULL) {
		NodePtr *trav;
		for(trav = A; *trav != NULL && strcmp((*trav)->data.name, name) != 0; trav = &(*trav)->next) {}
		
	}
}

void deleteFront() {
	
}

void deleteRear() {
	
}

void deleteAtPos() {
	
}

void displayList(NodePtr A) {
	NodePtr trav;
	int x;
	for(trav = A, x = 0; trav != NULL; trav = trav->next, x++) {
		printf("\n[%d] Name: %s", x, trav->data.name);
		printf("\n      ID: %d", trav->data.idNum);
		printf("\n     Age: %d\n", trav->data.age);
	}
}

int main() {
	NodePtr newLL;
	initList(&newLL);
	char inputName[50];
	int inputIDnum;
	int inputAge;
	
	info inputInfo;
	
	/* =================== Populate student list and sort =================== */
	info studArr[10] = {{"Josh", 1337, 17},
						{"Jacob", 3420, 21},
						{"Kyle", 6778, 19},
						{"James", 5512, 22},
						{"Jess", 4432, 19},
						};
	
	printf("\nPopulating and sorting student list...\n");
	insertSorted(&newLL, studArr[0]);
	insertSorted(&newLL, studArr[1]);
	insertSorted(&newLL, studArr[2]);
	insertSorted(&newLL, studArr[3]);
	insertSorted(&newLL, studArr[4]);
	
	printf("\nDisplaying updated student list...\n");
	displayList(newLL);
	
	/* =================== insertFront function =================== */
	printf("\nAdd new student to the front.\n");
	printf("Name: ");
	scanf("%s", &inputName);
	printf("ID: ");
	scanf("%d", &inputIDnum);
	printf("Age: ");
	scanf("%d", &inputAge);
	
	strcpy(inputInfo.name, inputName);
	inputInfo.idNum = inputIDnum;
	inputInfo.age = inputAge;
	
	printf("\nAdding new student to the front...\n");
	insertFront(&newLL, inputInfo);
	
	printf("\nDisplaying updated student list...\n");
	displayList(newLL);
	system("pause");
	
	/* =================== insertRear function =================== */
	printf("\nAdd new student to the rear.\n");
	printf("Name: ");
	scanf("%s", &inputName);
	printf("ID: ");
	scanf("%d", &inputIDnum);
	printf("Age: ");
	scanf("%d", &inputAge);
	
	strcpy(inputInfo.name, inputName);
	inputInfo.idNum = inputIDnum;
	inputInfo.age = inputAge;
	
	printf("\nAdding new student to the rear...\n");
	insertRear(&newLL, inputInfo);
	
	printf("\nDisplaying updated student list...\n");
	displayList(newLL);
	system("pause");
	
	return 0;
}
