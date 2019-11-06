#include "rbtree.h"

const Node* LEAF = NULL;

void scanfHandling()
{

}

Node* GetGrandParent(Node* n)
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
};

Node* GetUncle(Node* n)
{
	Node* g = GetGrandParent(n);
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

Node* GetSibling(Node* n)
{
	if (n == n->parent->left)
	{
		return n->parent->left;
	}
	else
	{
		return n->parent->left;
	}
}

int is_leaf(Node* n)
{
	return (n == LEAF) ? true : false;
}


void rotate_left(Node** n)    //n�� �θ�
{
	Node* nnew = (*n)->right; //nnew�� �ڽ�
	Node* p = (*n)->parent;   //p�� �Ҿƹ���

	if (nnew->left != NULL)      //�ڽĳ���� ���� ��尡 ������
	{
		nnew->left->parent = (*n); //���뱳ü�� ����� �̸� �ڽĳ���� ����->�θ� ���� �θ�� ����
	}
	(*n)->right = nnew->left;   //�ڽĳ���� ������ �θ��� ���������� (�θ��� ������ ����(�ڽ�)�� �����. �ڽİ� �Ằ ����)
	(*n)->parent = nnew;        //��ģ �ڽ��� �θ� �ڽ����� �ٲٴ�(�з�) �������� �Ҿƹ����� �����. (�Ҿƹ��� ��� p�� �輼��. ��а� �Ҷ������� �̴ϴ�.)
	nnew->left = (*n);          //���ʿ��� n�� �θ� �ڽ��� �Ǵ� �з��� ���������� ������ �ٽ� ���������� ����� ���ؼ� �ڽ��� ���ʿ��� �θ� ���������߰���?
	nnew->parent = p;           //�з��ϴ� �������� ������� �Ҿƹ��� (���� �θ��� �θ�)�� �ڽ��� ������.
	if (p != NULL)               //�����Դ� �� �Ҿƹ����� �����ϸ� ���� �缳��
	{
		//�߸��� �ڵ�
		if (nnew->left == p->left) {    //�Ҿƹ����� ������ �����θ�����?
			p->left = nnew;     //�Ҿƹ����� ������ �ڽ����� �ٽ� �缳��.
			//(*n) = (*n) -> parent;
		}
		else {                   //�װ� �ƴϰ� �Ҿƹ����� �������� ���� �θ�����?
			p->right = nnew;    //�Ҿƹ����� �������� �ڽ����� �ٽ� �缳��.
		}
	}
	//�������� �з����丮 �Ϸ�
}

void rotateleft(Node* n)
{
	Node* nnew = n->right; //nnew�� �ڽ�
	Node* p = n->parent;   //p�� �Ҿƹ���

	if (nnew->left != NULL)      //�ڽĳ���� ���� ��尡 ������
	{
		nnew->left->parent = n; //���뱳ü�� ����� �̸� �ڽĳ���� ����->�θ� ���� �θ�� ����
	}
	n->right = nnew->left;   //�ڽĳ���� ������ �θ��� ���������� (�θ��� ������ ����(�ڽ�)�� �����. �ڽİ� �Ằ ����)
	n->parent = nnew;        //��ģ �ڽ��� �θ� �ڽ����� �ٲٴ�(�з�) �������� �Ҿƹ����� �����. (�Ҿƹ��� ��� p�� �輼��. ��а� �Ҷ������� �̴ϴ�.)
	nnew->left = n;          //���ʿ��� n�� �θ� �ڽ��� �Ǵ� �з��� ���������� ������ �ٽ� ���������� ����� ���ؼ� �ڽ��� ���ʿ��� �θ� ���������߰���?
	nnew->parent = p;           //�з��ϴ� �������� ������� �Ҿƹ��� (���� �θ��� �θ�)�� �ڽ��� ������.
	if (p != NULL)               //�����Դ� �� �Ҿƹ����� �����ϸ� ���� �缳��
	{
		//�߸��� �ڵ�
		if (nnew->left == p->left) {    //�Ҿƹ����� ������ �����θ�����?
			p->left = nnew;     //�Ҿƹ����� ������ �ڽ����� �ٽ� �缳��.
			n = n->left;
		}
		else {                   //�װ� �ƴϰ� �Ҿƹ����� �������� ���� �θ�����?
			p->right = nnew;    //�Ҿƹ����� �������� �ڽ����� �ٽ� �缳��.
		}
	}
	//�������� �з����丮 �Ϸ�
}

void rotate_right(Node** n)
{
	Node* nnew = (*n)->left;
	Node* p = (*n)->parent;

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

void ChangeRoot(Node** n)
{
	while ((*n)->parent != NULL)
	{
		(*n) = (*n)->parent;
	}
}
