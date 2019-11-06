#include "linkedlist.h"

int main()
{
	List* list;
	LInit(&list);
	LAppendSort(&list, 4);
	LAppendSort(&list, 2);
	LPrint(list);
	printf("\n");
	LAppendSort(&list, 3);
	LPrint(list);
	printf("\n");
	LAppendSort(&list, 1);
	LPrint(list);
	printf("\n");
	LRemove(&list, 3);
	LPrint(list);
	printf("\n");
	SDestroy(&list);
	LPrint(list);
	printf("Success!\n");
	return 0;
}