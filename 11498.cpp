#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	int c;
	while (1)
	{
		scanf("%d", &c);
		if (c == 0)break;
		int x, y;
		scanf("%d %d", &x, &y);


		while (c--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a > x && b > y)
				printf("NE\n");
			else if (a > x && b < y)
				printf("SE\n");
			else if (a < x && b>y)
				printf("NO\n");
			else if (a < x && b < y)
				printf("SO\n");
			else
				printf("divisa\n");
		}
	}

}

//AC