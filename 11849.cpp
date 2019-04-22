#include<iostream>
#include<set>

using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m, !(n == 0 && m == 0))
	{
		set<int> a;
		int tmp;;
		while (n--)
		{
			cin >> tmp;
			a.insert(tmp);
		}
		int ans = 0;
		while (m--)
		{
			cin >> tmp;
			if (a.find(tmp) != a.end())
				++ans;
		}

		cout << ans << endl;

	}
	return 0;
}
//AC