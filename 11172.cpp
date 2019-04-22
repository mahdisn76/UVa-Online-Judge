#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	int a, b, c;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d %d", &a, &b);
		if (a < b)
			printf("<\n");
		else if(a>b)
			printf(">\n");
		else
			printf("=\n");
	}
}

//AC