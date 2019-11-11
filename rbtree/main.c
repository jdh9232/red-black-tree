#include "common.h"
#include "./rbtree/treeInsert.h"
#include "./rbtree/treedelete.h"

int main()
{
	Node* node = NULL;

	insert_node(&node, "a", 1);  //1
	insert_node(&node, "c", 1);  //3
	insert_node(&node, "e", 1);  //5
	
	insert_node(&node, "g", 1);  //7
	insert_node(&node, "i", 1);  //9
	insert_node(&node, "k", 1);  //11
	insert_node(&node, "m", 1);  //13
	insert_node(&node, "o", 1);  //15
	insert_node(&node, "q", 1);  //17
	insert_node(&node, "s", 1);  //19
	insert_node(&node, "u", 1);  //21
	insert_node(&node, "w", 1);  //23
	insert_node(&node, "y", 1);  //25

	//insert_node(&node, "d", 1);  //4
	/*insert_node(&node, "f", 1);
	insert_node(&node, "g", 1);*/
	
	/*insert_node(&node, "b", 2);
	insert_node(&node, "c", 2);
	insert_node(&node, "aa", 1);
	insert_node(&node, "b", 2);*/

	display_node(node, 0);
	printf("===========================================\n");

	//絶 命 - 果 木 節 削
	delete_node(&node, "g", 1);

	display_node(node, 0);
	printf("===========================================\n");


	//奧 義 : 젠 부 샤 쓰 - 트 리 파 괴
	destroy_node(&node);
	display_node(node, 0);
	printf("===========================================\n");
	return 0;

	//while (true)
	//{
	//	system("clear");
	//	printf("input [key value] : ");
	//	char buf[100];
	//	fgets(buf, sizeof(buf), stdin);
	//	buf[strlen(buf) - 1] = null;
	//	char* split = strtok(buf, " ");
	//	if (split == NULL)
	//		continue;

	//	const char* comstr = split;
	//	if (strncasecmp(comstr, "/quit", strlen(comstr)) == STR_EQUAL ||
	//		strncasecmp(comstr, "/exit", strlen(comstr)) == STR_EQUAL)
	//	{
	//		destroy_node(&node);
	//		return 0;
	//	}
	//	else if (strncasecmp(comstr, "/insert", strlen(comstr)) == STR_EQUAL)
	//	{
	//		split = strtok(NULL, " ");
	//		const char* key = split;
	//		if (key != NULL)
	//		{
	//			split = strtok(NULL, " ");
	//			if (split != NULL)
	//			{
	//				int value = atoi(split);
	//				insert_node(&node, key, value);
	//				printf("삽입 성공\n");
	//			}
	//			else
	//			{
	//				printf("잘못된 인수입니다.\n");
	//			}
	//		}
	//		else
	//		{
	//			printf("잘못된 인수입니다.\n");
	//		}
	//	}
	//	else if (strncasecmp(comstr, "/display", strlen(comstr)) == STR_EQUAL)
	//	{
	//		display_node(node, 0);
	//	}
	//	else if (strncasecmp(comstr, "/remove", strlen(comstr)) == STR_EQUAL ||
	//		strncasecmp(comstr, "/delete", strlen(comstr)) == STR_EQUAL)
	//	{
	//		split = strtok(NULL, " ");
	//		const char* key = split;
	//		//const char* const key = split;
	//		if (key != NULL)
	//		{
	//			split = strtok(NULL, " ");
	//			if (split != NULL)
	//			{
	//				int value = atoi(split);
	//				delete_node(&node, key, value);
	//				printf("삭제 성공\n");
	//			}
	//			else
	//			{
	//				printf("잘못된 인수입니다.\n");
	//			}
	//		}
	//		else
	//		{
	//			printf("잘못된 인수입니다.\n");
	//		}
	//	}
	//	else if (strncasecmp(comstr, "/destroy", strlen(comstr)) == STR_EQUAL)
	//	{
	//		destroy_node(&node);
	//		printf("삭제 성공\n");
	//	}
	//	else if (strncasecmp(comstr, "/help", strlen(comstr)) == STR_EQUAL)
	//	{
	//		help();
	//	}
	//	else
	//	{
	//		printf("명령어를 찾을 수 없습니다..\n");
	//		printf("/help를 눌러 명령어를 찾아보세요.\n");
	//	}
	//	getchar();
	//}
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