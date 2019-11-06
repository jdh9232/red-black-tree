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

typedef enum { BLACK = 1, RED = -1 } color_t;

typedef struct node Node;
struct node {
	Node* parent;
	Node* left;
	Node* right;

	color_t color;
	char* key;
	List* values;
};

void help();

//할아버지노드
Node* GetGrandParent(Node*);
//할아버지의 다른 자식 -> 삼촌노드
Node* GetUncle(Node*);
//부모의 다른 자식 -> 형제노드
Node* GetSibling(Node*);
//리프 체크
int is_leaf(Node*);

//node rotate
void rotate_left(Node**);
void rotateleft(Node*);
void rotate_right(Node**);

//rotate를 통한 Root Change
void ChangeRoot(Node**);

#endif