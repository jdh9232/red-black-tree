#include "linkedlist.h"

//양방향 리스트는 추후 과제에 필요할 떄 업데이트 예정
void LInit(List** list)
{
	(*list) = (List*)malloc(sizeof(List));
	(*list)->head = NULL;
	(*list)->tail = NULL;
}

void CreateList(ListNode** list, int value)
{
	(*list) = (ListNode*)malloc(sizeof(ListNode));
	(*list)->data = value;
	(*list)->next = NULL;
	(*list)->prev = NULL;
}

int LExistValue(List* list, int value)
{
	ListNode* Current = list->head;
	while (Current->data != value)
	{
		Current = Current->next;
		if (Current == NULL)
			return false;
	}
	return true;
}

ListNode* LGetValue(List* list, int value)
{
	ListNode* Current = list->head;
	while (Current->data != value)
	{
		Current = Current->next;
		if (Current == NULL)
			return NULL;
	}
	return Current;
}

//int LAppend(List** list, int value)
//{
//	ListNode* newNode = NULL;
//	//값이 존재하면 삽입X.
//	if ((*list)->head == NULL)
//	{
//		CreateList(&newNode, value);
//		(*list)->head = newNode;
//		(*list)->tail = newNode;
//	}
//	else
//	{
//		if (LExistValue((*list), value))
//			return false;
//		CreateList(&newNode, value);
//		(*list)->tail->next = newNode;
//		newNode->prev = (*list)->tail;
//		(*list)->tail = newNode;
//	}
//	return true;
//}

//정렬하면서 추가
int LAppendSort(List** list, int value)
{
	ListNode* newNode = NULL;
	//값이 존재하면 삽입X.
	if ((*list)->head == NULL)
	{
		CreateList(&newNode, value);
		(*list)->head = newNode;
		(*list)->tail = newNode;
	}
	//첫번째 값보다 작으면 중복되는 값은 없음.
	else if ((*list)->head->data > value)
	{
		CreateList(&newNode, value);
		(*list)->head->prev = newNode;
		newNode->next = (*list)->head;
		(*list)->head = newNode;
	}
	else
	{
		if (LExistValue((*list), value))
			return false;
		CreateList(&newNode, value);
		ListNode* traversal = (*list)->head;
		while (traversal->next != NULL)
		{
			if (traversal->next->data > value)
				break;
			traversal = traversal->next;
		}
		newNode->prev = traversal;
		newNode->next = traversal->next;
		if (traversal->next != NULL)
			traversal->next->prev = newNode;
		else
			(*list)->tail = newNode;
		traversal->next = newNode;
	}
	return true;
}

void LPrint(List* list)
{
	if (list == NULL || list->head == NULL)
		return;
	ListNode* traversal = list->head;
	while (traversal != NULL)
	{
		printf("%d ", traversal->data);
		traversal = traversal->next;
	}
}
int LRemove(List** list, int value)
{
	ListNode* rm = LGetValue(*list, value);
	if (rm == NULL)
		return false;
	if ((*list)->head == rm)
	{
		(*list)->head = rm->next;
		if ((*list)->head != NULL)
			(*list)->head->prev = NULL;
	}
	else
	{
		ListNode* tmp = rm;
		rm->prev->next = tmp->next;
		if (rm->next != NULL)
			rm->next->prev = tmp->prev;
		else
			(*list)->tail = rm->prev;
	}
	printf("%d - Remove\n", rm->data);
	free(rm);
	return true;
}
void LDestroy(List** list)
{
	while ((*list)->head != NULL)
	{
		//printf("%d - destroyed\n", (*list)->head->data);
		ListNode* tmp = (*list)->head->next;
		free((*list)->head);
		(*list)->head = tmp;
	}
	(*list)->tail = NULL;
}
void SDestroy(List** list)
{
	if ((*list)->head)
	{
		//printf("S call LDestroy\n");
		LDestroy(list);
	}
	free(*list);
	(*list) = NULL;
}