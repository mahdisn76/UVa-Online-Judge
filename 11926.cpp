#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
#include<map>

#define rep(n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, !(n == 0 && m == 0))
	{
		multiset<pair<int, int>> ms;
		rep(n)
		{
			int a, b;
			cin >> a >> b;
			ms.insert(make_pair(a, b));
		}
		rep(m)
		{
			int a, b, interval;
			cin >> a >> b >> interval;
			int m = 0;
			while ((b + m * interval) <= 1000000)
			{
				ms.insert(make_pair(a + m * interval, b + m * interval));
				m++;
			}
		}

		if (ms.empty())
		{
			cout << "NO CONFLICT" << endl;
			continue;
		}
		bool status = true;
		auto per = ms.begin();
		auto itr = ms.begin();
		itr++;
		for (; itr != ms.end(); itr++)
		{
			if (itr->first < per->second)
			{
				status = false;
				break;
			}
			per++;
		}

		cout << (status ? "NO CONFLICT" : "CONFLICT") << endl;
	}
	return 0;
}

//AC