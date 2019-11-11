#include "treedisplay.h"

Node** search_node(Node** findNode, const char* key, int data)
{
	if ((*findNode) == NULL)
		return NULL;

	int strv;
	while ((*findNode) != NULL && ((strv = strncmp((*findNode)->key, key, strlen(key))) != STR_EQUAL))
	{
		if (strv == STR_BIG)
		{
			(*findNode) = (*findNode)->left;
		}
		else
		{
			(*findNode) = (*findNode)->right;
		}
	}
	if ((*findNode) != NULL && LExistValue((*findNode)->values, data))
	{
		return findNode;
	}
	else
	{
		return NULL;
	}
}

void display_node(Node* viewNode, int depth)
{
	if (viewNode == NULL)
	{
		printf("Tree is EMPTY\n");
		return;
	}
	int d;
	for (d = 0; d < depth; d++)
	{
		printf("    ");
	}

	printf("NODE [\"%s\" | Size : %d | ", viewNode->key, LSize(viewNode->values));
	LPrint(viewNode->values);
	printf("| % s] > ", viewNode->color == RED ? "RED" : "BLACK");

	if (viewNode->left != NULL)
	{
		printf("NODE [\"%s\" | ", viewNode->left->key);
		LPrint(viewNode->left->values);
		printf("| % s] > ", viewNode->left->color == RED ? "RED" : "BLACK");
	}
	if (viewNode->right != NULL)
	{
		printf("NODE [\"%s\" | ", viewNode->right->key);
		LPrint(viewNode->right->values);
		printf("| % s] > ", viewNode->right->color == RED ? "RED" : "BLACK");
	}
	printf("\n");

	if (viewNode->left)
	{
		display_node(viewNode->left, depth + 1);
	}
	if (viewNode->right)
	{
		display_node(viewNode->right, depth + 1);
	}
}