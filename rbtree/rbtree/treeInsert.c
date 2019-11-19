#include "treeInsert.h"

void create_listnode(List**, int);
void create_node(Node**, const char*, int);
void insert_node(Node**, const char*, int);

void InsertCase(Node**);
// void InsertCase1(Node**);
// void InsertCase2(Node**);
//void InsertCase3(Node**);
//void InsertCase4(Node**);
//void InsertCase5(Node**);

void create_listnode(List** list, int data)
{
	if ((*list) == NULL)
	{
		LInit(list);
	}
	LAppendSort(list, data);
}

void create_node(Node** n, const char* key, int data)
{
	(*n) = (Node*)malloc(sizeof(Node));
	//색설정
	(*n)->color = RED;
	//키설정
	(*n)->key = (char*)malloc(sizeof(char) * strlen(key) + 1);
	//strcpy_s(n->key, strlen(key), key);
	strncpy((*n)->key, key, strlen(key) + 1);
	(*n)->key[strlen(key)] = '\0';
	//value설정
	(*n)->values = NULL;
	create_listnode(&(*n)->values, data);

	(*n)->parent = NULL;
	(*n)->left = NULL;
	(*n)->right = NULL;
}

//최종적인 반환은 t이기에	
//아무리 값이 바뀌었어도 기존 루트노드는 50을 위치하고 있기 때문에 50을 반환할 수밖에 없는 처지가 되어버린다.
void insert_node(Node** root, const char* key, int data)
{
	Node* n = NULL;
	Node* temp = *root; // temporary node.

	// if there is not any node.
	if (temp == NULL)
	{
		create_node(&n, key, data);
		*root = n;
		InsertCase(root);
		return;
	}
	int strv;
	// find the position that new node will be inserted.
	while (true)
	{
		strv = strncmp(key, temp->key, strlen(key));
		if (strv == STR_EQUAL)
		{
			if ((LExistValue(temp->values, data)) == false)
			{
				create_listnode(&(temp->values), data);
			}
			return;
		}
		else if (strv <= STR_SMALL)   //기존 tree의 key가 key보다 더 크면
		{
			if (!temp->left)
			{
				create_node(&n, key, data);
				break;
			}
			temp = temp->left;
		}
		else                       //기존 tree의 key가 key보다 더 작으면
		{
			if (!temp->right)
			{

				create_node(&n, key, data);
				break;
			}
			temp = temp->right;
		}
	}

	n->parent = temp;
	// insert new node in the tree.
	if ((strncmp(key, n->parent->key, strlen(key)) == STR_SMALL))
	{
		(n->parent)->left = n;
		InsertCase(&(n->parent)->left);
		ChangeRoot(root);
	}
	else
	{
		(n->parent)->right = n;
		InsertCase(&(n->parent)->right);
		ChangeRoot(root);
	}
}

void InsertCase(Node** n)
{
	Node* node = (*n);
	while(true)
	{
		//case 1
		if (node->parent == NULL)
		{
			node->color = BLACK;
			return;
		}
		//case 2
		if (node->parent->color == BLACK)
			return;
		//case 3
		if (GetUncle(node) != NULL && GetUncle(node)->color == RED)
		{
			node->parent->color = BLACK;
			GetUncle(node)->color = BLACK;
			GetGrandParent(node)->color = RED;
			node = node->parent->parent;
		}
		else
		{
			break;
		}
	}
	//case 4
	if ((node == node->parent->right) && (node->parent == GetGrandParent(node)->left))
	{
		Node* tmp = node->parent;
		rotate_left(&tmp);
		node = tmp;
	}
	else if (node == node->parent->left && node->parent == GetGrandParent(node)->right)
	{
		Node* tmp = node->parent;
		rotate_right(&tmp);
		node = tmp;
	}
	Node* g = GetGrandParent(node);
	g->color = RED;
	node->parent->color = BLACK;
	//g->color = BLACK;
	//  |  / |
	//  | /  |
	//라인을 탔을 때 색 반전 후 오른쪽 회전
	if (node == node->parent->left && node->parent == g->left)
	{
		rotate_right(&g);
		//g = g -> parent;
		//rotateright(g);
	}
	//  | \  |
	//  |  \ |
	//라인을 탔을 때 색 반전 후 왼쪽 회전
	else if (node == node->parent->right && node->parent == g->right)
	{
		rotate_left(&g);
	}

}