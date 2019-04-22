#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n;
		int max = 0;
		cin >> n;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			if (tmp > max)max = tmp;
		}
		printf("Case %d: %d\n", i + 1, max);
	}
}
//AC