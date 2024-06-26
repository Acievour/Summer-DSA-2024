#ifndef OPEN_HASHING
#define OPEN_HASHING

#define MAX 10
#define THRESHOLD 0.65

typedef struct node {
	char *word;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr *data;
	int count;
	int max;
} Dictionary;

int hash(char *word);
void initDict(Dictionary *D);
Dictionary *create_Dict();

void insertElem(Dictionary *D, char *word);
void deleteElem(Dictionary *D, char *word);
void findElem(Dictionary *D, char *word);

void displayDict(Dictionary *D);
void visualizeDict(Dictionary *D);


#endif
