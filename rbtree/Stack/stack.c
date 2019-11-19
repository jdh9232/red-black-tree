#include "stack.h"


void InitStack(Stack** stack)
{
	(*stack) == NULL;
}
void PushStack(Stack** stack, Node *node)
{
	if ((*stack) == NULL)
	{
		*stack = (Stack*)malloc(sizeof(Stack));
		(*stack)->before = NULL;
		(*stack)->node = node;
	}
	else
	{
		Stack* tmp;
		tmp = (Stack*)malloc(sizeof(Stack));
		tmp->before = (*stack);
		tmp->node = node;
		(*stack) = tmp;
	}
}

void PrintStack(Stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack is EMPTY!\n");
		return;
	}
	Stack* trees;
	InitStack(&trees);
	while (stack)
	{
		PushStack(&trees, stack->node);
		stack = stack->before;
	}
	while (trees)
	{
		printf("%s ", trees->node->key);
		trees = trees->before;
	}
	DestroyStack(&trees);
	//PrintStack(trees);

}

int PopStack(Stack** stack)
{
	if ((*stack) == NULL)
	{
		return false;
	}
	else
	{
		Stack* tmp;
		tmp = (*stack)->before;
		free(*stack);
		(*stack) = tmp;
		return true;
	}
}
void DestroyStack(Stack** stack)
{
	while ((*stack) != NULL)
	{
		PopStack(stack);
	}
}
