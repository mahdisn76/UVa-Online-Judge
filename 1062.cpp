#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int cnt = 1;
	string s;
	while (cin >> s, s != "end")
	{
		multiset<char> ms;
		printf("Case %d: ", cnt++);
		for (int i = 0; i < s.length(); i++)
		{
			auto res = lower_bound(ms.begin(), ms.end(), s[i]);
			if (res != ms.end())
			{
				ms.erase(res);
			}
			ms.insert(s[i]);
		}
		cout << ms.size() << endl;
	}
	return 0;
}
//AC