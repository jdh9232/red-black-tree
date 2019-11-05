#include "linkedlist.h"

int main()
{
	List* list;
	Init(&list);
	LAppendSort(&list, 1);
	LAppendSort(&list, 4);
	LAppendSort(&list, 3);
	LPrint(list);
	LAppendSort(&list, 2);
	LPrint(list);
	LRemove(&list, 3);
	LPrint(list);
	SDestroy(&list);
	LPrint(list);
	printf("Success!\n");
	return 0;
}