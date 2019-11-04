#include "common.h"

const Node *LEAF = NULL;

Node* GetGrandParent(Node *n)
{
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
};

Node* GetUncle(Node *n)
{
    Node *g = GetGrandParent(n);
    if (g == NULL)
	{
		printf("why?");
        return NULL; // No grandparent means no uncle
	}
	if (n->parent == g->left)
	{
        return g->right;
	}
	else
	{
        return g->left;
	}
};

Node* GetSibling(Node *n)
{
	if(n == n->parent->left)
	{
		return n->parent->left;	
	}
	else
	{
		return n->parent->left;
	}
}

int is_leaf(Node *n)
{
	return (n == LEAF) ? true : false;
	return 0;
}

void replace_node(Node **n, Node *child)
{
	child->parent = (*n)->parent;
    if ((*n) == (*n)->parent->left)
        (*n)->parent->left = child;
    else if ((*n)->parent->right == (*n))
        (*n)->parent->right = child;
}


void rotate_left(Node **n)    //n을 부모
{
	Node *nnew = (*n)->right; //nnew를 자식
	Node *p = (*n)->parent;   //p를 할아버지

	if(nnew->left != NULL)      //자식노드의 왼쪽 노드가 있으면
	{
		nnew->left->parent = (*n); //세대교체를 대비해 미리 자식노드의 왼쪽->부모를 기존 부모로 설정
	}
	(*n)->right = nnew->left;   //자식노드의 왼쪽을 부모의 오른쪽으로 (부모의 오른쪽 정보(자식)이 사라짐. 자식과 결별 선언)
	(*n)->parent = nnew;        //빡친 자식이 부모를 자식으로 바꾸는(패륜) 과정에서 할아버지가 사라짐. (할아버지 잠시 p에 계세요. 당분간 소란스러울 겁니다.)
	nnew->left = (*n);          //위쪽에서 n의 부모가 자식이 되는 패륜을 저질렀으니 족보를 다시 정상적으로 만들기 위해선 자식의 왼쪽에다 부모를 연결시켜줘야겠쥬?
	nnew->parent = p;           //패륜하는 과정에서 사라졌던 할아버지 (원래 부모의 부모)를 자식이 데려옴.
	if(p != NULL)               //데려왔던 그 할아버지가 존재하면 족보 재설정
	{
		//잘못된 코드
		if(nnew->left == p->left){    //할아버지의 왼쪽이 기존부모였으면?
			p->left = nnew;     //할아버지의 왼쪽을 자식으로 다시 재설정.
			//(*n) = (*n) -> parent;
		}
		else{                   //그게 아니고 할아버지의 오른쪽이 기존 부모였으면?
			p->right = nnew;    //할아버지의 오른쪽을 자식으로 다시 재설정.
		}
	}
	//완전범죄 패륜스토리 완료
}

void rotateleft(Node *n)
{
	Node *nnew = n->right; //nnew를 자식
	Node *p = n->parent;   //p를 할아버지

	if(nnew->left != NULL)      //자식노드의 왼쪽 노드가 있으면
	{
		nnew->left->parent = n; //세대교체를 대비해 미리 자식노드의 왼쪽->부모를 기존 부모로 설정
	}
	n->right = nnew->left;   //자식노드의 왼쪽을 부모의 오른쪽으로 (부모의 오른쪽 정보(자식)이 사라짐. 자식과 결별 선언)
	n->parent = nnew;        //빡친 자식이 부모를 자식으로 바꾸는(패륜) 과정에서 할아버지가 사라짐. (할아버지 잠시 p에 계세요. 당분간 소란스러울 겁니다.)
	nnew->left = n;          //위쪽에서 n의 부모가 자식이 되는 패륜을 저질렀으니 족보를 다시 정상적으로 만들기 위해선 자식의 왼쪽에다 부모를 연결시켜줘야겠쥬?
	nnew->parent = p;           //패륜하는 과정에서 사라졌던 할아버지 (원래 부모의 부모)를 자식이 데려옴.
	if(p != NULL)               //데려왔던 그 할아버지가 존재하면 족보 재설정
	{
		//잘못된 코드
		if(nnew->left == p->left){    //할아버지의 왼쪽이 기존부모였으면?
			p->left = nnew;     //할아버지의 왼쪽을 자식으로 다시 재설정.
			n = n -> left;
		}
		else{                   //그게 아니고 할아버지의 오른쪽이 기존 부모였으면?
			p->right = nnew;    //할아버지의 오른쪽을 자식으로 다시 재설정.
		}
	}
	//완전범죄 패륜스토리 완료
}

void rotate_right(Node **n)
{
	Node *nnew = (*n)->left;
	Node *p = (*n)->parent;

    if (nnew->right != NULL)
        nnew->right->parent = (*n);

    (*n)->left = nnew->right;
    (*n)->parent = nnew;
    nnew->right = (*n);
    nnew->parent = p;

    if (p != NULL) {
        if (p->right == (*n))
            p->right = nnew;
        else
            p->left = nnew;
    }
}

void ChangeRoot(Node **n)
{
	while((*n)->parent != NULL)
	{
		(*n) = (*n)->parent;
	}
}