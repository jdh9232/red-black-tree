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

void draw_tree_hor2(Node* tree, int depth, char* path, int right)
{
	// stopping condition
	if (tree == NULL)
		return;

	// increase spacing
	depth++;

	// start with right node
	draw_tree_hor2(tree->right, depth, path, 1);

	// set | draw map
	path[depth - 2] = 0;

	if (right)
		path[depth - 2] = 1;

	if (tree->left)
		path[depth - 1] = 1;

	// print root after spacing
	printf("\n");

	for (int i = 0; i < depth - 1; i++)
	{
		if (i == depth - 2)
			printf("+");
		else if (path[i])
			printf("|");
		else
			printf(" ");

		for (int j = 1; j < space; j++)
			if (i < depth - 2)
				printf(" ");
			else
				printf("-");
	}

	printf("%s/%s/%d\n", tree->key, tree->color == BLACK ? "B" : "R", LSize(tree->values));

	// vertical spacers below
	for (int i = 0; i < depth; i++)
	{
		if (path[i])
			printf("|");
		else
			printf(" ");

		for (int j = 1; j < space; j++)
			printf(" ");
	}

	// go to left node
	draw_tree_hor2(tree->left, depth, path, 0);
}

//primary fuction
void draw_tree_hor(Node* tree)
{
	// should check if we don't exceed this somehow..
	char path[255] = {};
	if (tree == NULL)
	{
		printf("Tree is EMPTY\n");
		return;
	}
	//initial depth is 0
	draw_tree_hor2(tree, 0, path, 0);
}