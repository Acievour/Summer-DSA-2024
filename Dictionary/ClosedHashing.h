#ifndef CLOSED_HASHING
#define CLOSED_HASHING

#define SIZE 20
#define THRESHOLDC 0.65
#define EMPTY "empty"
#define DELETED "deleted"

typedef struct {
	char data[128];
} DictData;

typedef struct {
	DictData table[SIZE];
	int last;
} DictionaryC;

int hashC(const char *word);
void initDictC(DictionaryC *D);
DictionaryC *createDictC();

void insertElemC(DictionaryC *D, char *word);
void deleteElemC(DictionaryC *D, char *word);

void displayDictC(DictionaryC D);
void visualizeDictC(DictionaryC D);

#endif
