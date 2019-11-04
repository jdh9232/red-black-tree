#ifndef RB_INSERT_H
#define RB_INSERT_H

#include "common.h"

/*
1. 노드는 레드 혹은 블랙 중의 하나이다.
2. 루트 노드는 블랙이다.
3. 모든 리프 노드들(NIL)은 블랙이다. (필자는 NIL구현을 하지 않음.)
4. 레드 노드의 자식노드 양쪽은 언제나 모두 블랙이다. (즉, 레드 노드는 연달아 나타날 수 없으며, 블랙 노드만이 레드 노드의 부모 노드가 될 수 있다)
5. 어떤 노드로부터 시작되어 리프 노드에 도달하는 모든 경로에는 리프 노드를 제외하면 모두 같은 개수의 블랙 노드가 있다.
*/

//insert_node로 인해 모든 노드의 color는 RED의 초깃값을 가짐.
void insert_node(Node**, int);

//Level1 : 루트노드가 아닐 경우 ↓
//루트노드일 경우 insert_case1 실행
void insert_case1(Node *);
//Level2 : node의 parent->color가 BLACK이 아닐 경우 ↓
//부모가 BLACK일 경우 insert_case2 실행
void insert_case2(Node *);
//Level3 : 삼촌이 RED가 아닐 경우↓ (부모는 Level2를 통해 무조건 RED 확정)
//부모와 삼촌 모두 RED일 경우 insert_case3 실행
//(부모도 RED, 자식도 RED이기에 4번 규칙을 어김)
void insert_case3(Node *);
//Level4 : 할아버지와 부모, 자식이 차례로 / \ 라인을 타거나 \ / 라인을 탔을 때
//(부모도 RED, 자식도 RED이기에 4번규칙을 어김, 특정 확률로 5번도 어길 수 있음.)
void insert_case4(Node *);
//Level5 : 할아버지, 부모, 자식이 차례로 / / 또는 \ \ 라인을 탔을 때
//(부모도 RED, 자식도 RED이기에 4번 규칙을 어김, 특정 확률로 5번도 어길 수 있음.)
void insert_case5(Node *);

//node rotate
void rotate_left(Node **);
void rotate_right(Node **);

void ChangeRoot(Node **);

#endif