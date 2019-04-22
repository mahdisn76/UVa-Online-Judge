#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
	int n, b, h, w;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
	{
		int min = 20000;
		for (int i = 0; i < h; i++)
		{
			int p, tmp;
			scanf("%d", &p);
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &tmp);
				if (tmp >= n)
				{
					if (p < min)
						min = p;
					
				}
			}
		}
		if (min*n < b)
			printf("%d\n", min*n);
		else
			printf("stay home\n");
	}
}

/*
3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13
*/

//AC