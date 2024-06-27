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
        NodePtr trav;
        for(trav = D->data[index]; trav->next != NULL; trav = trav->next) {}
		trav->next = newNode;
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
	        newDict.data[x] = NULL;
	    }
	    
	    int y;
	    for(y = 0; y < D->max; y++) {
			NodePtr trav3;
			for(trav3 = D->data[y]; trav3 != NULL; trav3 = trav3->next) {
				int hashval = hash(trav3->word);
				NodePtr newNode = (NodePtr)malloc(sizeof(Node));
				newNode->word = strdup(trav3->word);
				newNode->next = NULL;
		
				if(newDict.data[hashval] != NULL) {
					NodePtr trav;
					for(trav = newDict.data[hashval]; trav != NULL; trav = trav->next) {}
					trav->next = newNode;
				} else {
					newDict.data[hashval] = newNode;
				}
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

