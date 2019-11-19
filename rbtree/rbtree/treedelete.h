#ifndef RB_DELETE_H
#define RB_DELETE_H

#include "rbtree.h"
#include "../Stack/stack.h"
#include "treedisplay.h"

void delete_node(Node**, const char*, int);
//void destroy_node(Node**);
void destroy_node_stack(Node**);

#endif