#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHashing.h"

unsigned long hash(Dictionary *D, char *word) {
	unsigned long hash = 0;
	int x;
	while((x = *word++)) {
		hash = hash * 31 + x;
	}
	return hash % D->max;
}

void initDict(Dictionary *D) {
	int x;
	for(x = 0; x < MAX; x++) {
		D->data[x] = NULL;
	}
	D->count = 0;
	D->max = MAX;
}

Dictionary *create_Dict(int size) {
	Dictionary *D = (Dictionary *)malloc(sizeof(Dictionary));
	D->max = size;
	D->count = 0;
//	D->data = calloc(size, sizeof(NodePtr));
	return D;
}

void free_list(NodePtr list) {
	while(list != NULL) {
		NodePtr temp;
		temp = list;
		list = list->next;
		free(temp->word);
		free(temp);
	}
}

void free_dict(Dictionary *D) {
	int x;
	for(x = 0; x < D->max; x++) {
		if(D->data[x] != NULL) {
			free_list(D->data[x]);
		}
	}
	free(D->data);
	free(D);
}

void resize(Dictionary *D) {
	int old_max = D->max;
	D->max = D->max * 2;
	NodePtr *old_data = D->data;
//	D->data  = calloc(D->max, sizeof(NodePtr));
	D->count = 0;
	
	int x;
	for(x = 0; x < old_max; x++) {
		NodePtr list = old_data[x];
		if(list != NULL) {
			NodePtr next = list->next;
            unsigned long hashval = hash(D, list->word);
            list->next = D->data[hashval];
            D->data[hashval] = list;
            list = next;
            D->count++;
		}
	}
	
	free(old_data);
}

void insertElem(Dictionary *D, char *word) {
	if((float)D->count / D->max > THRESHOLD) {
		resize(D);
	}
	
	unsigned long hashval = hash(D, word);
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->word = strdup(word);
	temp->next = D->data[hashval];
	D->data[hashval] = temp;
	D->count++;
}

void deleteElem(Dictionary *D, char *word) {
	
}

void findElem(Dictionary D, char *word) {
	
}

void displayDict(Dictionary *D) {
	int x;
	printf(" INDEX | DATA\n");
	for(x = 0; x < D->max; x++) {
		printf("\n%d ", x);
		if(D->data[x] != NULL) {
			NodePtr trav;
			for(trav = D->data[x]; trav != NULL; trav = trav->next) {
				printf("%s -> ", trav->word);
			}
		}
	}
}

void visualizeDict(Dictionary D) {
	
}

