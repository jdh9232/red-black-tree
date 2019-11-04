#ifndef RB_DELETE_H
#define RB_DELETE_H

#include "common.h"
#include "treedisplay.h"

void delete_node(Node **, int);
void destroy_node(Node **);

void delete_one_child(Node **);

void delete_case1(Node **);
void delete_case2(Node **);
void delete_case3(Node **);
void delete_case4(Node **);
void delete_case5(Node **);
void delete_case6(Node **);

#endif