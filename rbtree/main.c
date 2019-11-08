#include "common.h"
#include "./rbtree/treeInsert.h"
#include "./rbtree/treedelete.h"

int main()
{
	Node *node = NULL;

	/*insert_node(&node, "a", 1);
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
	insert_node(&node, "b", 1);*/

	/*display_node(node, 0);
	printf("===========================================\n");*/

	//絶 命 - 果 木 節 削
	//delete_node(&node, "g", 3);
	//display_node(node);
	//printf("===========================================\n");


	//奧 義 : 젠 부 샤 쓰 - 트 리 파 괴
	/*destroy_node(&node);
	display_node(node, 0);
	printf("===========================================\n");
	return 0;*/

	while (true)
	{
		system("clear");
		printf("input [key value] : ");
		char buf[100];
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf) - 1] = null;
		char* split = strtok(buf, " ");
		if (split == NULL)
			continue;

		const char* comstr = split;
		if (strncmp(comstr, "/quit", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/QUIT", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/exit", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/EXIT", strlen(comstr)) == STR_EQUAL)
		{
			destroy_node(&node);
			return 0;
		}
		else if (strncmp(comstr, "/insert", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/insert", strlen(comstr)) == STR_EQUAL)
		{
			split = strtok(NULL, " ");
			const char* key = split;
			if (key != NULL)
			{
				split = strtok(NULL, " ");
				if (split != NULL)
				{
					int value = atoi(split);
					insert_node(&node, key, value);
					printf("삽입 성공\n");
				}
				else
				{
					printf("잘못된 인수입니다.\n");
				}
			}
			else
			{
				printf("잘못된 인수입니다.\n");
			}
		}
		else if (strncmp(comstr, "/display", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/DISPLAY", strlen(comstr)) == STR_EQUAL)
		{
			display_node(node, 0);
		}
		else if (strncmp(comstr, "/destroy", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/DESTROY", strlen(comstr)) == STR_EQUAL)
		{
			destroy_node(&node);
			printf("삭제 성공\n");
		}
		else if (strncmp(comstr, "/help", strlen(comstr)) == STR_EQUAL ||
			strncmp(comstr, "/HELP", strlen(comstr)) == STR_EQUAL)
		{
			help();
		}
		else
		{
			printf("명령어를 찾을 수 없습니다..\n");
			printf("/help를 눌러 명령어를 찾아보세요.\n");
		}
		getchar();
	}
}

/*
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./rbtree.out
*/

/*
1. 파일, 함수 구조 바꾸기 (완료)
2. display함수 depth 표시 (완료)
3. scanf에서 직접 입력
//read -n 1 -s -r -p "Press any key to continue";echo
*/