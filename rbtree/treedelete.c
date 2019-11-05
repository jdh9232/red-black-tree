#include "treedelete.h"

void delete_node(Node **t, int data, const char *key)
{
    Node *temp = NULL;
    Node *p = NULL;
   
    // find the node that has the data.
    temp = search_node(*t, data, key);

    // if there is not data.
    if(temp == NULL)
    {
        printf("Can't find the data!\n");
        return;
    }
	else
	{
		delete_one_child(temp);
	}

  //  // if the node that has the data don't have children.
  //  if(temp->left == NULL && temp->right == NULL)
  //  {
		//delete_one_child(temp);
  //      /*if(temp == *t)
  //      {
  //          *t  = NULL;
  //      }
  //      else if((temp->parent)->value > data)
  //      {
  //          (temp->parent)->left = NULL;
  //      }
  //      else
  //      {
  //          (temp->parent)->right = NULL;
  //      }

  //      free(temp);
		//temp = NULL;*/
  //  }
  //  // if the node don't have a left child.
  //  else if(temp->left == NULL)
  //  {
  //      temp->value = (temp->right)->value;
  //     
  //      delete_node( &(temp->right), (temp->right)->value, key);
  //  }
  //  // if the node don't have a right child.
  //  else if(temp->right == NULL)
  //  {
  //      temp->value = (temp->left)->value;
  //     
  //      delete_node( &(temp->left), (temp->left)->value, key);
  //  }
  //  else // if the node have children.
  //  {
  //      p = temp;

  //      temp = temp->right;

  //      while(temp->left != NULL)
  //      {
  //          temp = temp->left;
  //      }

  //      p->value = temp->value;

  //      delete_node(&(p->right), temp->value, key);
  //  }
}

void destroy_node(Node **t)
{
	if((*t) == NULL)
	{
		return ;
	}
	if((*t)->left != NULL)
	{
		destroy_node(&(*t)->left);
	}
	if((*t)->right != NULL)
	{
		destroy_node(&(*t)->right);
	}
	free((*t)->key);
	free(*t);
	*t = NULL;
	//*t = NULL;
	return ;
}

void replace_node(Node *n, Node *child)
{
	child->parent = n->parent;
	if (n->parent->left == n)
	{
		n->parent->left = child;
	}
	else if (n->parent->right == n)
	{
		n->parent->right = child;
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

void delete_one_child(Node *n)
{
	if (n->right == NULL && n->left == NULL)
	{
		if (n->color == BLACK)
		{
			delete_case1(n);
		}
		free(n);
		n = NULL;
	}
	else
	{
		Node* child = is_leaf(n->right) ? n->left : n->right;
		replace_node(n, child);
		if (n->color == BLACK)
		{
			if (child->color == RED)
			{
				child->color = BLACK;
			}
			else
			{
				delete_case1(n);
			}
		}
		free(n);
		n = NULL;
	}
	
	//Node *child = is_leaf((*n)->right) ? (*n)->left:(*n)->right;
}

//루트노드이면
void delete_case1(Node **n)
{
	if((*n)->parent != NULL)
	{
		delete_case2(n);
	}
}

//형제가 빨간색인 경우 부모는 무조건 검은색
void delete_case2(Node **n)
{
	Node *sib = GetSibling(*n);
	if(sib->color == RED)
	{
		(*n)->parent->color = RED;
		sib->color = BLACK;
		if((*n) == (*n)->parent->left)
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

void delete_case3(Node **n)
{
	Node *sib = GetSibling(*n);
	//n의 부모가 BLACK, 형제의 right, left가 BLACK
	//어떤 노드로부터 시작되어 리프 노드에 도달하는 모든 경로에는 리프 노드를 제외하면 모두 같은 개수의 블랙 노드가 있다.
	//규칙을 맞춰주기 위하여 S의 색깔을 바꿈.
	if(((*n)->parent->color == BLACK) && (sib->right->color == BLACK) &&
        (sib->left->color == BLACK) && (sib->color == BLACK))
	{
		sib->color = RED;
		delete_case1(&(*n)->parent);
	}
	else
	{
		delete_case4(n);
	}
}

void delete_case4(Node **n)
{
	Node *sib = GetSibling(*n);
	//형제 및 형제의 자식들은 검은색이지만 부모가 빨간색일 때
	//형제와 부모의 색깔을 바꿈.
	if((*n)->parent->color == RED  && (sib->right->color == BLACK) &&
      (sib->left->color == BLACK) && (sib->color == BLACK))
	{
		sib->color = RED;
		(*n)->parent->color = BLACK;
	}
	else
	{
		delete_case5(n);
	}
}

void delete_case5(Node **n)
{
	Node *sib = GetSibling(*n);
	if(sib->color == BLACK)
	{
		/*
				/\
		    	 /\
		*/
		//형제노드가 검정색, n이 n의 부모노드의 왼쪽일 때
		//형제노드와 형제노드의 자식을 오른쪽을 몰아줌.
		if((*n) == (*n)->parent->left)
		{
			sib->color = RED;
			sib->left->color = BLACK;
			rotate_right(&sib);
		}
		//n이 n의 부모노드의 오른쪽에 있을 때 왼쪽으로 몰아줌
		else if((*n) == (*n)->parent->right)
		{
			sib->color = RED;
			sib->right->color = BLACK;
			rotate_left(&sib);
		}
	}
	//이후 6번 케이스 실행
	delete_case6(n);
}

void delete_case6(Node **n)
{
	Node *sib = GetSibling(*n);

	sib->color = (*n)->parent->color;
	
	if((*n) == (*n)->parent->left)
	{
		rotate_left(&(*n)->parent);
	}
	else
	{
		rotate_right(&(*n)->parent);
	}
}