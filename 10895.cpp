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
	int n, m;
	while(cin>>n>>m)
	{ 
		vector<vector<ii>> ans(10001);
		rep(i, n)
		{
			int r;
			cin >> r;
			vector<int> indexs;
			rep(j, r)
			{
				int tmp;
				cin >> tmp;
				indexs.push_back(tmp-1);
			}
			rep(j, r)
			{
				int tmp;
				cin >> tmp;
				ans[indexs[j]].push_back(make_pair(i, tmp));
			}
		}

		printf("%d %d\n", m, n);
		rep(i, m)
		{
			int size = ans[i].size();
			cout << size << (size>0?" ":"");
			sort(ans[i].begin(), ans[i].end());
			for(int k=0;k<ans[i].size();k++)
				cout << ans[i][k].first+1 << (k!=ans[i].size()-1?" ":"");
			cout << endl;
			for (int k = 0; k < ans[i].size(); k++)
				cout << ans[i][k].second << (k != ans[i].size()-1 ? " " : "");
			cout << endl;
		}

	}
	return 0;
}

//AC