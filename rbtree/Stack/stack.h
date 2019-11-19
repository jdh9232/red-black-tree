#include "../common.h"
#include "../rbtree/rbtree.h"

typedef struct stack Stack;

struct stack
{
	Node* node;
	Stack* before;
};

void InitStack(Stack **);
void PushStack(Stack **, Node *);

void PrintStack(Stack *);

int PopStack(Stack **);
void DestroyStack(Stack **);
