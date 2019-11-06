#ifndef RBTREE_H
#define RBTREE_H

#include "../linked_list/linkedlist.h"

/*
Referenced - RB Tree
https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

https://ko.wikipedia.org/wiki/%EB%A0%88%EB%93%9C-%EB%B8%94%EB%9E%99_%ED%8A%B8%EB%A6%AC

https://hamait.tistory.com/412

https://web.stanford.edu/~blp/papers/libavl.pdf

Referenced - RB Tree Test HTML
https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

Referenced - Binary Tree
https://leeyongjeon.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89-%ED%8A%B8%EB%A6%ACBinary-Search-Trees-in-C
*/

typedef enum { BLACK = 1, RED = -1, null = 0 } color_t;

typedef struct node Node;
struct node {
	Node* parent;
	Node* left;
	Node* right;

	color_t color;
	char* key;
	List* values;
};

void scanfHandling();

//�Ҿƹ������
Node* GetGrandParent(Node*);
//�Ҿƹ����� �ٸ� �ڽ� -> ���̳��
Node* GetUncle(Node*);
//�θ��� �ٸ� �ڽ� -> �������
Node* GetSibling(Node*);
//���� üũ
int is_leaf(Node*);

//node rotate
void rotate_left(Node**);
void rotateleft(Node*);
void rotate_right(Node**);

//rotate�� ���� Root Change
void ChangeRoot(Node**);

#endif