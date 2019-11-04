#include "treedisplay.h"

Node* search_node(Node *t, int data)
{
	while(t != NULL && t->value != data)
    {
        if( t->value > data)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return t;
}

void display_node(Node *t)
{
    if(t == NULL)
    {
		printf("Tree is EMPTY\n");
        return;
    }

    printf("NODE [\"%s\", %d, %s] > ", t->key, t->value, t->color == RED ? "RED" : "BLACK");

    if(t->left != NULL)
    {
        printf("LEFT [\"%s\", %d, %s] ", (t->left)->key, (t->left)->value, (t->left)->color == RED ? "RED" : "BLACK");
    }
    if(t->right != NULL)
    {
        printf("RIGHT [\"%s\", %d, %s]", (t->right)->key, (t->right)->value, (t->right)->color == RED ? "RED" : "BLACK");
    }
    printf("\n");

    if(t->left)
    {
        display_node(t->left);
    }
    if(t->right)
    {
        display_node(t->right);
    }
}