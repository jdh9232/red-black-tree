#include "treeInsert.h"

void create_listnode(List** list, int data)
{
	if ((*list) == NULL)
	{
		LInit(list);
	}
	LAppendSort(list, data);
}

void create_node(Node **n, const char *key, int data)
{
	(*n) = (Node *)malloc(sizeof(Node));
	//색설정
	(*n)->color = RED;
	//키설정
	(*n)->key = (char *)malloc(sizeof(char)*strlen(key)+1);
	//strcpy_s(n->key, strlen(key), key);
	strncpy((*n)->key, key, strlen(key)+1);
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
void insert_node(Node **t, const char *key, int data)
{
    Node *n = NULL;	
    Node *temp = *t; // temporary node.

    // if there is not any node.
    if(temp == NULL)
    {
		create_node(&n, key, data);
        *t  = n;
		insert_case1(t);
        return;
    }
	int strv;
    // find the position that new node will be inserted.
    while(true)
    {
		strv = strncmp(temp->key, key, strlen(key));
		if(strv == STR_EQUAL)
		{
			if ((LExistValue(temp->values, data)) == false)
			{
				create_listnode(&(temp->values), data);
			}
			return;
		}
        else if(strv == STR_BIG)   //기존 tree의 key가 key보다 더 크면
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
    if((strncmp(n->parent->key, key, strlen(key)) == STR_BIG))
    {
        (n->parent)->left = n;
		insert_case1(&(n->parent)->left);
		ChangeRoot(t);
    }
    else
    {
        (n->parent)->right = n;
		insert_case1(&(n->parent)->right);
		ChangeRoot(t);
    }
}

void insert_case1(Node **n)
{
	if((*n)->parent == NULL)
	{
		(*n)->color = BLACK;
	}
	else
	{
		insert_case2(n);
	}
	
}
void insert_case2(Node **n)
{
	if ((*n)->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}
void insert_case3(Node **n)
{
	if(GetUncle(*n) != NULL && GetUncle(*n)->color == RED)
	{
		(*n)->parent->color = BLACK;
		GetUncle(*n)->color = BLACK;
		GetGrandParent(*n)->color = RED;
		insert_case1(&(*n)->parent->parent);
	}
	else
	{
		insert_case4(n);
	}
}
void insert_case4(Node **n)
{
	//   | / |
	//   | \ |
	//라인을 탔을 떄 부모를 중심으로 왼쪽회전
	if(((*n) == (*n)->parent->right) && ((*n)->parent == GetGrandParent(*n)->left))
	{
		//n이 아니다... 즉 잘못된 코드
		//n -> (*n) -> (*n)->parent
		//& ((*n)->parent) 인 것인데 이것은 n이 아니다...
		Node *tmp = (*n)->parent;
		rotate_left(&tmp);	
		(n) = &tmp;
	}
	//   | \ |
	//   | / |
	//라인을 탔을 때 부모를 중심으로 오른쪽 회전
	else if((*n) == (*n)->parent->left && (*n)->parent == GetGrandParent(*n)->right)
	{
		Node *tmp = (*n)->parent;
		rotate_right(&tmp);
		(n) = &tmp;
	}
	insert_case5(n);
}
void insert_case5(Node **n)
{
	(*n)->parent->color = BLACK;
	Node * g = (*n)->parent->parent;
	g->color = RED;
	//  |  / |
	//  | /  |
	//라인을 탔을 때 색 반전 후 오른쪽 회전
	if((*n) == (*n)->parent->left && (*n)->parent == GetGrandParent(*n)->left)
	{
		rotate_right(&g);
		//g = g -> parent;
		//rotateright(g);
	}
	//  | \  |
	//  |  \ |
	//라인을 탔을 때 색 반전 후 왼쪽 회전
	//(*n) == (*n)->parent->right && (*n)->parent == GetGrandParent(*n)->right
	else
	{
		rotate_left(&g);
	}
}
