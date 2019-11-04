#include "common.h"
#include "treeInsert.h"
#include "treedelete.h"

int main()
{
	Node *node = NULL;
	insert_node(&node, 1, "a");
	insert_node(&node, 2, "b");
	insert_node(&node, 3, "c");
	insert_node(&node, 4, "d");
	insert_node(&node, 1, "e");
	insert_node(&node, 2, "f");
	insert_node(&node, 3, "g");
	insert_node(&node, 1, "b");
	insert_node(&node, 2, "c");
	insert_node(&node, 3, "c");
	display_node(node);
	destroy_node(&node);
	display_node(node);
	return 0;
}