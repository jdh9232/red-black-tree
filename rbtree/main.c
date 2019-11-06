#include "common.h"
#include "./rbtree/treeInsert.h"
#include "./rbtree/treedelete.h"

int main()
{
	Node *node = NULL;

	insert_node(&node, "a", 1);
	insert_node(&node, "b", 2);
	insert_node(&node, "c", 3);
	insert_node(&node, "d", 4);
	insert_node(&node, "e", 1);
	insert_node(&node, "f", 2);
	insert_node(&node, "g", 3);
	display_node(node, 0);
	printf("===========================================\n");
	insert_node(&node, "b", 1);
	insert_node(&node, "c", 2);
	insert_node(&node, "aa", 1);
	insert_node(&node, "b", 1);
	/*display_node(node, 0);
	printf("===========================================\n");*/

	//ï¾ Ù¤ - Íý ÙÊ ï½ Þû
	//delete_node(&node, "g", 3);
	//display_node(node);
	//printf("===========================================\n");


	//çó ëù : Á¨ ºÎ »þ ¾² - Æ® ¸® ÆÄ ±«
	destroy_node(&node);
	display_node(node, 0);
	printf("===========================================\n");
	return 0;
}

/*
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./rbtree.out
*/

/*
1. ÆÄÀÏ, ÇÔ¼ö ±¸Á¶ ¹Ù²Ù±â (¿Ï·á)
2. displayÇÔ¼ö depth Ç¥½Ã (¿Ï·á)
3. scanf¿¡¼­ Á÷Á¢ ÀÔ·Â
*/