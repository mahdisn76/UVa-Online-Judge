#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		map<int, int> m;

		int start = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			if (m.find(tmp) == m.end() || m[tmp]<start)
				m[tmp] = i;
			else
			{
				start = m[tmp]+1;
				m[tmp] = i;
			}
			ans = max(ans, i - start+1);
		}
		cout << ans << endl;
		
	}
	return 0;
}
//AC