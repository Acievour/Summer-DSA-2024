#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHashing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary *Dict = create_Dict(MAX);
//	initDict(Dict);
	
	insertElem(Dict, "orange");
	insertElem(Dict, "apple");
	insertElem(Dict, "grapes");
	
	displayDict(Dict);
	
	return 0;
}
