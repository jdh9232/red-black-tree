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
	insert_node(&node, 3, "d");
	display_node(node);
	printf("===========================================\n");

	//ï¾ Ù¤ - Íý ÙÊ ï½ Þû
	delete_node(&node, 3, "g");
	display_node(node);
	printf("===========================================\n");


	//çó ëù : Á¨ ºÎ »þ ¾² - Æ® ¸® ÆÄ ±«
	destroy_node(&node);
	display_node(node);
	printf("===========================================\n");
	return 0;
}

/*
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./
*/