#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHashing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary *Dict = create_Dict();
//	Dictionary *Dict2 = (Dictionary *)malloc(sizeof(Dictionary));
//	initDict(Dict2);
//	
//	displayDict(Dict2);
//	visualizeDict(Dict2);
	
	displayDict(Dict);
	visualizeDict(Dict);
	
	insertElem(Dict, "orange");
	insertElem(Dict, "apple");
	insertElem(Dict, "grapes");
	insertElem(Dict, "avocado");
	insertElem(Dict, "pineapple");
	insertElem(Dict, "tangerine");
	
	displayDict(Dict);
	visualizeDict(Dict);
	
	insertElem(Dict, "pineapple");
	insertElem(Dict, "banana");
	insertElem(Dict, "star fruit");
	insertElem(Dict, "mango");
	insertElem(Dict, "coconut");
	insertElem(Dict, "watermelon");
	insertElem(Dict, "papaya");
	
	displayDict(Dict);
	visualizeDict(Dict);
	
	return 0;
}
