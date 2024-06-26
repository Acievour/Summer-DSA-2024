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
    
	while(node!= NULL) {
        if (strcmp(node->word, word) == 0) {
            return; // word already exists
        }
        node = node->next;
    }
    
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->next = NULL;
    if(D->data[index] == NULL) {
        // If the list at this index is empty, set the new node as the head
        D->data[index] = newNode;
    } else {
        // Otherwise, find the last node in the list and append the new node
        NodePtr current = D->data[index];
        while(current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    D->count++;

    if((double)D->count / D->max > THRESHOLD) {
        // resize the dictionary if the load factor exceeds the threshold
        Dictionary newDict;
    	initDict(&newDict);
    	newDict.max = D->max * 2;
    	NodePtr *newData = (NodePtr *)malloc(newDict.max * sizeof(NodePtr));
	    int x;
	    for(x = 0; x < newDict.max; x++) {
	        newData[x] = NULL;
	    }
	    newDict.data = newData;
	    int y;
	    for(y = 0; y < D->max; y++) {
	        NodePtr node = D->data[y];
	        while (node!= NULL) {
	            int index = hash(node->word);
	            NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	            newNode->word = strdup(node->word);
	            newNode->next = NULL;
	            if (newDict.data[index] == NULL) {
	                // If the list at this index is empty, set the new node as the head
	                newDict.data[index] = newNode;
	            } else {
	                // Find the last node in the list and append the new node
	                NodePtr current = newDict.data[index];
	                while (current->next!= NULL) {
	                    current = current->next;
	                }
	                current->next = newNode;
	            }
            	node = node->next;
	        }
	    }
	    newDict.count = D->count;
	    free(D->data);
	    *D = newDict;
    }
}

void deleteElem(Dictionary *D, char *word) {
    int index = hash(word);
    NodePtr *trav;
    
    for(trav = &D->data[index]; *trav != NULL && strcmp((*trav)->word, word) != 0; trav = &(*trav)->next) {}

    if (*trav != NULL) {
        NodePtr nodeToFree = *trav;
    	*trav = (*trav)->next;
    	free(nodeToFree->word);
    	free(nodeToFree);
    	D->count--;
    }
}

void findElem(Dictionary *D, char *word) {
	int index = hash(word);
    NodePtr *trav;
    
    for(trav = &D->data[index]; *trav != NULL && strcmp((*trav)->word, word) != 0; trav = &(*trav)->next) {}
    
    if (*trav != NULL && strcmp((*trav)->word, word) != 1) {
    	printf("%s found in the dictionary.\n", word);
    } else {
    	printf("%s not found in the dictionary.\n", word);
	}
	printf("\n");
}

void displayDict(Dictionary *D) {
	NodePtr trav;
	int x;
	printf("Words found: ");
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
	printf("Current dictionary size: %d\n", D->max);
	printf("Number of elements: %d\n\n", D->count);
}

