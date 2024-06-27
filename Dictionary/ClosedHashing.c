#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClosedHashing.h"

int hashC(char *word) {
    int hash = 0;
    int x;
    for (x = 0; word[x] != '\0'; x++) {
        hash = (hash + word[x]) % SIZE;
    }
    return hash;
}

void initDictC(DictionaryC *D) {
    int x;
    for (x = 0; x < SIZE; x++) {
        strcpy(D->table[x].data, EMPTY);
    }
    D->last = -1;
}

DictionaryC *createDictC() {
    DictionaryC *D = (DictionaryC *)malloc(sizeof(DictionaryC));
    if (D != NULL) {
        initDictC(D);
    }
    return D;
}

void insertElemC(DictionaryC *D, char *word) {
    int hashval = hashC(word);
    if (strcmp(D->table[hashval].data, EMPTY) == 0 || strcmp(D->table[hashval].data, DELETED) == 0) {
        strcpy(D->table[hashval].data, word);
    } else if (D->last < SIZE - 1) {
        D->last++;
        strcpy(D->table[D->last].data, word);
    }
}

void deleteElemC(DictionaryC *D, char *word) {
    int hashval = hashC(word);
    int x;
    int found = 0;
    
    if (strcmp(D->table[hashval].data, word) == 0) {
        strcpy(D->table[hashval].data, DELETED);
        found = 1;
    } else {
        for (x = SIZE * THRESHOLDC; x <= D->last && !found; x++) {
            if (strcmp(D->table[x].data, word) == 0) {
                strcpy(D->table[x].data, D->table[D->last].data);
                D->last--;
                found = 1;
            }
        }
    }
}

void displayDictC(DictionaryC D) {
    int x;
    printf("Words found: ");
    for (x = 0; x < SIZE; x++) {
        if (strcmp(D.table[x].data, EMPTY) != 0 && strcmp(D.table[x].data, DELETED) != 0) {
            printf("%s ", D.table[x].data);
        }
    }
    printf("\n\n");
}

void visualizeDictC(DictionaryC D) {
    int x;
    printf(" INDEX\t|   DATA\n");
    for (x = 0; x < SIZE; x++) {
        printf("   %d\t|   %s\n", x, D.table[x].data);
    }
    printf("\n\n");
}

