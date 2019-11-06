#include "treedisplay.h"

Node* search_node(Node *t, const char *key, int data)
{
	if (t == NULL)
		return NULL;

	int strv;
	while(t != NULL || ((strv = strncmp(t->key, key, strlen(key))) != STR_EQUAL))
    {
		if (strv == STR_BIG)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
	if (t != NULL && LExistValue(t->values, data))
	{
		return t;
	}
    return t;
}

void display_node(Node *t, int depth)
{
    if(t == NULL)
    {
		printf("Tree is EMPTY\n");
        return;
    }
	int d;
	for (d = 0; d < depth; d++)
	{
		printf("    ");
	}

	printf("NODE [\"%s\" | ", t->key);
	LPrint(t->values);
	printf("| % s] > ", t->color == RED ? "RED" : "BLACK");

    if(t->left != NULL)
    {
		printf("NODE [\"%s\" | ", t->left->key);
		LPrint(t->left->values);
		printf("| % s] > ", t->left->color == RED ? "RED" : "BLACK");
    }
    if(t->right != NULL)
    {
		printf("NODE [\"%s\" | ", t->right->key);
		LPrint(t->right->values);
		printf("| % s] > ", t->right->color == RED ? "RED" : "BLACK");
    }
    printf("\n");

    if(t->left)
    {
        display_node(t->left, depth+1);
    }
    if(t->right)
    {
        display_node(t->right, depth+1);
    }
}