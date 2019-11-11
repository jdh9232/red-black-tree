#include "../common.h"
#include "../rbtree/rbtree.h"

typedef struct stack Stack;

struct stack
{
	Node* node;
	int depth;
	Node* before;
};

void InitStack(Stack **);
void AddStack(Stack **);

void PrintStack(Stack *);

void DeleteStack(Stack **);
void DestroyStack(Stack **);
