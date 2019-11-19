#include "treedelete.h"

void replace_node(Node*, Node*);
void delete_one_child(Node*);

void DeleteCase(Node**);
//void DeleteCase1(Node**);
void DeleteCase2(Node**);
void DeleteCase3(Node**);
void DeleteCase4(Node**);
void DeleteCase5(Node**);
void DeleteCase6(Node**);

void delete_node(Node** root, const char* key, int data)
{
	Node** remover = NULL;
	Node* memory = (*root);

	// find the node that has the data.
	remover = search_node(root, key, data);

	// if there is not data.
	if (remover == NULL || (*remover) == NULL)
	{
		printf("해당 키 또는 값이 존재하지 않습니다.\n");
		return;
	}
	else
	{
		//삭제할 노드에 가장 인접하는 노드를 복사 후 복사된 노드를 제거
		// List의 Size가 1보다 많으면 List의 value만 제거
		if (LSize((*remover)->values) > 1)
		{
			LRemove(&(*remover)->values, data);
			return;
		}
		//그렇지 않으면 가장 인접하는 key값을 지닌 노드를 복사 후 복사된 노드 제거
		//같은 값을 가진 key는 존재하지 않음.
		else
		{
			Node* changer = NULL;
			
			changer = (*remover)->left;
			if (changer == NULL)
			{
				changer = (*remover)->right;
				if (changer == NULL)
				{
					if ((*remover)->parent->left == (*remover))
					{
						(*remover)->parent->left = NULL;
					}
					else
					{
						(*remover)->parent->right = NULL;
					}
					SDestroy(&(*remover)->values);
					free((*remover)->key);
					free((*remover));
					(*remover) = NULL;
					(*remover) = memory;
					return;
				}
			}
			while (true)
			{
				int strv = strncmp(key, changer->key, strlen(key));
				//부모 자식의 연결을 해제해주는 코드 작성
				if (strv == STR_SMALL)
				{
					if (changer->left == NULL)
					{
						break;
					}
					changer = changer->left;
				}
				else
				{
					if (changer->right == NULL)
					{
						break;
					}
					changer = changer->right;
				}
			}
			SDestroy(&(*remover)->values);
			free((*remover)->key);
			(*remover)->values = changer->values;
			(*remover)->key = changer->key;

			delete_one_child(changer);
			(*remover) = memory;

			ChangeRoot(remover);
		}
		printf("삭제 성공!\n");
	}
}

//void destroy_node(Node** rmNode)
//{
//	if (!(*rmNode))
//	{
//		return;
//	}
//	if ((*rmNode)->left != NULL)
//	{
//		destroy_node(&(*rmNode)->left);
//	}
//	if ((*rmNode)->right != NULL)
//	{
//		destroy_node(&(*rmNode)->right);
//	}
//	SDestroy(&((*rmNode)->values));
//	free((*rmNode)->key);
//	free(*rmNode);
//	*rmNode = NULL;
//	//*t = NULL;
//	return;
//}

void destroy_node_stack(Node** rmNode)
{
	if (!rmNode)
		return;
	Stack* recursiver = NULL;
	Node* prev = NULL;
	InitStack(&recursiver);
	PushStack(&recursiver, (*rmNode));
	while (recursiver != NULL)
	{
		Node* curr = recursiver->node;
		if (!prev || curr == prev->left || curr == prev->right)
		{
			if (curr->left)
			{
				PushStack(&recursiver, curr->left);
			}
			else if (curr->right)
			{
				PushStack(&recursiver, curr->right);
			}
		}
		else if (prev == curr->left)
		{
			if (curr->right)
			{
				PushStack(&recursiver, curr->right);
			}
		}
		else
		{
			//예전 코드의 stack으로 destroy하는 구문도
			//여기에서 해제된 메모리 접근을 하여 오류가 난 듯 하다.
			if (NULL == curr->parent)
			{
				prev = NULL;
			}
			else
			{
				if (curr == curr->parent->left)
				{
					recursiver->before->node->left = NULL;
				}
				else
				{
					recursiver->before->node->right = NULL;
				}
			}
			free(curr->key);
			SDestroy(&(curr->values));
			free(curr);
			curr = NULL;
			prev = NULL;
			PopStack(&recursiver);
			continue;
		}
		prev = curr;
	}
	DestroyStack(&recursiver);

}

void replace_node(Node* node, Node* child)
{
	child->parent = node->parent;
	if (node ->parent != NULL && node->parent->left == node)
	{
		node->parent->left = child;
	}
	else if (node->parent != NULL && node->parent->right == node)
	{
		node->parent->right = child;
	}
}
//void replace_node(Node **n, Node *child)
//{
//	child->parent = (*n)->parent;
//	if ((*n) == (*n)->parent->left)
//		(*n)->parent->left = child;
//	else if ((*n)->parent->right == (*n))
//		(*n)->parent->right = child;
//}

void delete_one_child(Node* node)
{
	if (node->right == NULL && node->left == NULL)
	{
		if (node->color == BLACK)
		{
			DeleteCase(&node);
		}
		if (node->parent->left == node)
		{
			node->parent->left = NULL;
		}
		else if(node->parent->right == node)
		{
			node->parent->right = NULL;
		}
		free(node);
		node = NULL;
	}
	else
	{
		Node* child = is_leaf(node->right) ? node->left : node->right;
		replace_node(node, child);
		if (node->color == BLACK)
		{
			if (child->color == RED)
			{
				child->color = BLACK;
			}
			else
			{
				DeleteCase(&node);
				//DeleteCase1(&child);
			}
		}
		free(node);
		node = NULL;
	}

	//Node *child = is_leaf((*n)->right) ? (*n)->left:(*n)->right;
}
void DeleteCase(Node** n)
{
	Node* node = (*n);
	Node* sib = NULL;
	while (true)
	{
		if (node->parent == NULL)	//case 1
		{
			return;
		}
		sib = GetSibling(node);
		if (sib->color == RED)		//case 2
		{
			DeleteCase2(&node);
			break;
		}
		sib = GetSibling(node);
		if ((node->parent->color == BLACK) && ((sib->right == NULL) || (sib->right->color == BLACK)) &&
			((sib->left == NULL) || (sib->left->color == BLACK)) && (sib->color == BLACK))
		{							//case 3
			DeleteCase3(&node);
			node = node->parent;
		}
		else
		{
			break;
		}
	}
	sib = GetSibling(node);
	if (node->parent->color == RED && ((sib->right == NULL) || (sib->right->color == BLACK)) &&
		((sib->left == NULL) || (sib->left->color == BLACK)) && (sib->color == BLACK))
	{								//case 4
		DeleteCase4(&node);
		return;
	}
	sib = GetSibling(node);
	if ((sib->right == NULL || sib->right->color == BLACK) &&
		(sib->left != NULL && sib->left->color == RED) && (sib->color == BLACK))
	{								//case 5
		DeleteCase5(&node);
	}
	sib = GetSibling(node);
	if ((sib->right != NULL && sib->right->color == RED) &&
		(sib->left == NULL || sib->left->color == BLACK) && (sib->color == BLACK))
	{
		DeleteCase6(&node);
	}

}

//루트노드이면
//void DeleteCase1(Node** n)
//{
//	if ((*n)->parent != NULL)
//	{
//		DeleteCase2(n);
//	}
//}

//형제가 빨간색인 경우 부모는 무조건 검은색
void DeleteCase2(Node** n)
{
	Node* sib = GetSibling(*n);
	(*n)->parent->color = RED;
	sib->color = BLACK;
	if ((*n) == (*n)->parent->left)
	{
		rotate_left(&(*n)->parent);
	}
	else
	{
		rotate_right(&(*n)->parent);
	}
}

void DeleteCase3(Node** n)
{
	Node* sib = GetSibling(*n);
	sib->color = RED;
}

void DeleteCase4(Node** n)
{
	Node* sib = GetSibling(*n);
	sib->color = RED;
	(*n)->parent->color = BLACK;
}

void DeleteCase5(Node** n)
{
	Node* sib = GetSibling(*n);
	/*
			/\
				/\
	*/
	//형제노드가 검정색, n이 n의 부모노드의 왼쪽일 때
	//형제노드와 형제노드의 자식을 오른쪽을 몰아줌.
	if ((*n) == (*n)->parent->left)
	{
		sib->color = RED;
		if (sib->left != NULL)
		{
			sib->left->color = BLACK;
		}
		rotate_right(&sib);
	}
	//n이 n의 부모노드의 오른쪽에 있을 때 왼쪽으로 몰아줌
	else if ((*n) == (*n)->parent->right)
	{
		sib->color = RED;
		if (sib->right != NULL)
		{
			sib->right->color = BLACK;
		}
		rotate_left(&sib);
	}
	//이후 6번 케이스 실행
	DeleteCase6(n);
}

void DeleteCase6(Node** n)
{
	Node* sib = GetSibling(*n);

	sib->color = (*n)->parent->color;
	(*n)->parent->color = BLACK;

	if ((*n) == (*n)->parent->left)
	{
		if(sib->right != NULL)
		{
			sib->right->color = BLACK;
		}
		rotate_left(&(*n)->parent);
	}
	else if((*n) == (*n)->parent->right)
	{
		if (sib->left != NULL)
		{
			sib->left->color = BLACK;
		}
		rotate_right(&(*n)->parent);
	}
}