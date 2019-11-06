#include <stdio.h>

#define true 1
#define false 0

#define is_leaf(n)\
{ ((n == NULL) ? true : false) }

int main()
{
	char* c = NULL;
	int bools = is_leaf(c);
	printf("result : %s\n", is_leaf(c) ? "true" : "false");
	return 0;
}