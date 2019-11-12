#include "treedelete.h"

void replace_node(Node*, Node*);
void delete_one_child(Node*);

void delete_case1(Node**);
void delete_case2(Node**);
void delete_case3(Node**);
void delete_case4(Node**);
void delete_case5(Node**);
void delete_case6(Node**);

void delete_node(Node** t, const char* key, int data)
{
	Node** temp = NULL;
	Node* memory = (*t);
	//Node *p = NULL;

	// find the node that has the data.
	temp = search_node(t, key, data);

	// if there is not data.
	if ((*temp) == NULL)
	{
		printf("해당 키 또는 값이 존재하지 않습니다.\n");
		return;
	}
	else
	{
		//삭제할 노드에 가장 인접하는 노드를 복사 후 복사된 노드를 제거
		// List의 Size가 1보다 많으면 List의 value만 제거
		if (LSize((*temp)->values) > 1)
		{
			LRemove(&(*temp)->values, data);
			return;
		}
		//그렇지 않으면 가장 인접하는 key값을 지닌 노드를 복사 후 복사된 노드 제거
		//같은 값을 가진 key는 존재하지 않음.
		else
		{
			Node* changer = NULL;
			
			changer = (*temp)->left;
			if (changer == NULL)
			{
				changer = (*temp)->right;
				if (changer == NULL)
				{
					if ((*temp)->parent->left == (*temp))
					{
						(*temp)->parent->left = NULL;
					}
					else
					{
						(*temp)->parent->right = NULL;
					}
					SDestroy(&(*temp)->values);
					free((*temp)->key);
					free((*temp));
					(*temp) = NULL;
					(*temp) = memory;
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
			SDestroy(&(*temp)->values);
			free((*temp)->key);
			(*temp)->values = changer->values;
			(*temp)->key = changer->key;

			delete_one_child(changer);
			(*temp) = memory;

			ChangeRoot(temp);
			////temp의 왼쪽이 복사된 노드이면
			//if (temp->left == changer)
			//{
			//	temp->left = NULL;
			//}
			//else if (temp->right == changer)
			//{
			//	temp->right = NULL;
			//}
			////temp의 왼쪽 또는 오른쪽에 여러 노드가 존재하면 그대로 놔두기.
		}
		printf("삭제 성공!\n");
	}
}

void destroy_node(Node** rmNode)
{
	if (!(*rmNode))
	{
		return;
	}

	if ((*rmNode)->left != NULL)
	{
		destroy_node(&(*rmNode)->left);
	}
	if ((*rmNode)->right != NULL)
	{
		destroy_node(&(*rmNode)->right);
	}
	SDestroy(&((*rmNode)->values));
	free((*rmNode)->key);
	free(*rmNode);
	*rmNode = NULL;
	//*t = NULL;
	return;
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
			delete_case1(&node);
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
				delete_case1(&node);
				//delete_case1(&child);
			}
		}
		free(node);
		node = NULL;
	}

	//Node *child = is_leaf((*n)->right) ? (*n)->left:(*n)->right;
}

//루트노드이면
void delete_case1(Node** n)
{
	if ((*n)->parent != NULL)
	{
		delete_case2(n);
	}
}

//형제가 빨간색인 경우 부모는 무조건 검은색
void delete_case2(Node** n)
{
	Node* sib = GetSibling(*n);
	if (sib->color == RED)
	{
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
	delete_case3(n);
}

void delete_case3(Node** n)
{
	Node* sib = GetSibling(*n);
	//n의 부모가 BLACK, 형제의 right, left가 BLACK
	//어떤 노드로부터 시작되어 리프 노드에 도달하는 모든 경로에는 리프 노드를 제외하면 모두 같은 개수의 블랙 노드가 있다.
	//규칙을 맞춰주기 위하여 S의 색깔을 바꿈.
	if (((*n)->parent->color == BLACK) && ((sib->right == NULL) || (sib->right->color == BLACK)) &&
		((sib->left == NULL) || (sib->left->color == BLACK)) && (sib->color == BLACK))
	{
		sib->color = RED;
		delete_case1(&(*n)->parent);
	}
	else
	{
		delete_case4(n);
	}
}

void delete_case4(Node** n)
{
	Node* sib = GetSibling(*n);
	//형제 및 형제의 자식들은 검은색이지만 부모가 빨간색일 때
	//형제와 부모의 색깔을 바꿈.
	if ((*n)->parent->color == RED && ((sib->right == NULL) || (sib->right->color == BLACK)) &&
		((sib->left == NULL) || (sib->left->color == BLACK)) && (sib->color == BLACK))
	{
		sib->color = RED;
		(*n)->parent->color = BLACK;
	}
	else
	{
		delete_case5(n);
	}
}

void delete_case5(Node** n)
{
	Node* sib = GetSibling(*n);
	if (sib->color == BLACK)
	{
		/*
				/\
				 /\
		*/
		//형제노드가 검정색, n이 n의 부모노드의 왼쪽일 때
		//형제노드와 형제노드의 자식을 오른쪽을 몰아줌.
		if ((*n) == (*n)->parent->left && 
			(sib->right == NULL || sib->right->color == BLACK) &&
			(sib->left != NULL && sib->left->color == RED))
		{
			sib->color = RED;
			if (sib->left != NULL)
			{
				sib->left->color = BLACK;
			}
			rotate_right(&sib);
		}
		//n이 n의 부모노드의 오른쪽에 있을 때 왼쪽으로 몰아줌
		else if ((*n) == (*n)->parent->right &&
			(sib->left == NULL || sib->left->color == BLACK) &&
			(sib->right != NULL && sib->right->color == RED))
		{
			sib->color = RED;
			if (sib->right != NULL)
			{
				sib->right->color = BLACK;
			}
			rotate_left(&sib);
		}
	}
	//이후 6번 케이스 실행
	delete_case6(n);
}

void delete_case6(Node** n)
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
	else
	{
		if (sib->left != NULL)
		{
			sib->left->color = BLACK;
		}
		rotate_right(&(*n)->parent);
	}
}