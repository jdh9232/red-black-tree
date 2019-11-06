#ifndef LINKEDLIST_H
#define LINKEDLIST_C

#include "../common.h"
//https://neohtux.tistory.com/53

typedef struct linkedlist ListNode;
typedef struct saveNode List;

struct linkedlist
{
	int data;
	struct linkedlist* next;
	struct linkedlist* prev;
};
struct saveNode
{
	ListNode* head;
	ListNode* tail;
};

void LInit(List**);

//create and insert
void CreateList(ListNode**, int);
//int LAppend(List**, int);
int LAppendSort(List**, int);
//void LInsertLEN(List**, int, int);
//void LInsertValue(List**, int, int);

//find and print
int LExistValue(List*, int);
//ListNode* LGetLEN(List*);
ListNode* LGetValue(List*, int);
void LPrint(List*);

//remove and destroy
int LRemove(List**, int);
void LDestroy(List**);
void SDestroy(List**);

#endif