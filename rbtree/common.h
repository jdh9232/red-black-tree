#ifndef COMMON_H
#define COMMON_H

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MYDEBUG(fmt, ...)\
{ printf("[%s:%d] %s "fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); }
#define true 1
#define false 0

typedef enum { BLACK = 1, RED = -1, null = 0 } color_t;

typedef struct node Node;
struct node {
  Node* parent;
  Node* left;
  Node* right;
  color_t color;
  char *key;

  int value;
};

extern const Node * LEAF;

//할아버지노드
Node* GetGrandParent(Node *);
//할아버지의 다른 자식 -> 삼촌노드
Node* GetUncle(Node *);
//부모의 다른 자식 -> 형제노드
Node* GetSibling(Node *);
//리프 체크
int is_leaf(Node *);
void replace_node(Node **, Node *);

//node rotate
void rotate_left(Node **);
void rotateleft(Node *);
void rotate_right(Node **);

//rotate를 통한 Root Change
void ChangeRoot(Node **);

#endif