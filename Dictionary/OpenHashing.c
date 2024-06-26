#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHashing.h"

int hash(char *word) {
    int hash = 0;
    int x;
    for(x = 0; word[x] != '\0'; x++) {
        hash = (hash * 31 + word[x]) % MAX;
    }
    return hash;
}

void initDict(Dictionary *D) {
	D->max = MAX;
	D->count = 0;
	D->data = (NodePtr *)malloc(MAX * sizeof(NodePtr));
	int x;
	for(x = 0; x < MAX; x++) {
		D->data[x] = NULL;
	}
}

Dictionary *create_Dict() {
	Dictionary *D = (Dictionary *)malloc(sizeof(Dictionary));
	D->max = MAX;
	D->count = 0;
	D->data = (NodePtr *)malloc(MAX * sizeof(NodePtr));
	int x;
	for(x = 0; x < MAX; x++) {
		D->data[x] = NULL;
	}
	return D;
}

void insertElem(Dictionary *D, char *word) {
	int index = hash(word);
    NodePtr node = D->data[index];
    while (node!= NULL) {
        if (strcmp(node->word, word) == 0) {
            return; // word already exists
        }
        node = node->next;
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(newNode->word, word);
    newNode->next = D->data[index];
    D->data[index] = newNode;
    D->count++;

    if ((double)D->count / D->max > THRESHOLD) {
        // resize the dictionary if the load factor exceeds the threshold
        D->max *= 2;
        NodePtr *newData = (NodePtr *)malloc(D->max * sizeof(NodePtr));
		int x, y;
        for (x = 0; x < D->max; x++) {
            newData[x] = NULL;
        }
        for (y = 0; y < MAX; y++) {
            NodePtr node = D->data[y];
            while (node!= NULL) {
                int newIndex = hash(node->word);
                NodePtr newNode = (NodePtr)malloc(sizeof(Node));
                newNode->word = node->word;
                newNode->next = newData[newIndex];
                newData[newIndex] = newNode;
                node = node->next;
            }
        }
        free(D->data);
        D->data = newData;
    }
}

void deleteElem(Dictionary *D, char *word) {
	
}

void findElem(Dictionary D, char *word) {
	
}

void displayDict(Dictionary *D) {
	NodePtr trav;
	int x;
	printf("\nWords found: ");
	for(x = 0; x < D->max; x++) {
		trav = D->data[x];
		while(trav != NULL) {
			printf("%s ", trav->word);
			trav = trav->next;
		}
	}
	printf("\n\n");
}

void visualizeDict(Dictionary *D) {
	NodePtr trav;
	int x;
	printf(" INDEX\t|   DATA\n");
	for(x = 0; x < D->max; x++) {
		trav = D->data[x];
		printf("   %d\t|   ", x);
		while(trav != NULL) {
			printf("%s - ", trav->word);
			trav = trav->next;
		}
		printf("\n");
	}
	printf("Current dictionary size: %d\n\n", D->max);
}

