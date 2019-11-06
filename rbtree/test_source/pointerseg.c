#include <stdio.h>
int main() {
	char* p = "world";
	int n = 1;

	switch (n)
	{
	case 1:
		p = "one";
		if (0)
	case 2:
		p = "two";
		if (0)
	case 3:
		p = "three";
		printf("%s", p);
		break;
	}
}