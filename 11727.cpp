#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>

using namespace std;
int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i=0;i<tc;i++)
	{
		set<int> s;
		int cnt = 3;
		while (cnt--)
		{
			int tmp;
			scanf("%d", &tmp);
			s.insert(tmp);
		}
		printf("Case %d: %d\n", i + 1, *next(s.begin(), 1));
	}
}  
//AC