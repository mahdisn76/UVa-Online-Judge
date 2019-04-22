#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		long long int ans = 0;
		multiset<int> ms;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				int tmp;
				cin >> tmp;
				ms.insert(tmp);
			}
			auto end = ms.end();
			end--;
			ans += (*end - *ms.begin());
			ms.erase(end);
			ms.erase(ms.begin());
		}
		cout << ans << endl;
	}

	return 0;
}

//AC