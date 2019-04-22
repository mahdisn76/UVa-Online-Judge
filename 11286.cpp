#include<iostream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		map<set<int>, int> m;
		for (int i = 0; i < n; i++)
		{
			set<int> s;
			for (int j = 0; j < 5; j++)
			{
				int tmp;
				cin >> tmp;
				s.insert(tmp);
			}
			m[s]++;
		}
		int maxcnt = 0;
		for (auto itr = m.begin(); itr != m.end(); itr++)
			maxcnt = max(itr->second, maxcnt);
		
		int ans = 0;
		for (auto itr = m.begin(); itr != m.end(); itr++)
			if (itr->second == maxcnt)
				ans += itr->second;
		cout << ans << endl;
	}

	return 0;
}

//AC