#ifndef RB_DISPLAY_H
#define RB_DISPLAY_H

#include "rbtree.h"
#define space 5

Node** search_node(Node**, const char*, int);
void display_node(Node*, int);
void draw_tree_hor(Node*);

#endif