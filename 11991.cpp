#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<sstream>
#define lli long long int
#define ulli unsigned long long int
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define rep(i, n) for(int i=0;i<n;i++)
#define iterate(x) for(auto itr=x.begin(); itr!=x.end();itr++)
using namespace std;
int main()
{
	map<int, vi> v;
	int n, m;
	while (cin >> n >> m)
	{
		v.clear();
		rep(i, n)
		{
			int tmp;
			cin >> tmp;
			if (v.find(tmp) == v.end())
				v.insert(make_pair(tmp, vi()));
			v[tmp].push_back(i + 1);
		}
		rep(i, m)
		{
			int k, vv;
			cin >> k >> vv;
			if (v.find(vv) == v.end() || v[vv].size() < k)
				cout << "0\n";
			else
				cout << v[vv][k - 1] << endl;
		}
	}
	return 0;
}

//AC