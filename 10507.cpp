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

vector<int> getNeigbors(int graph[][27], int i, int n)
{
	vector<int> ret;
	rep(j, n)
	{
		if(i==j)continue;
		if (graph[i][j])
			ret.push_back(j);
	}
	return ret;
}

int main()
{

	int n;
	while (cin >> n)
	{
		int graph[27][27] = { 0 };
		bool awake[27] = { false };
		int edges;
		cin >> edges;
		string str;
		cin >> str;
		map<char, int> dic;
		dic.insert(make_pair(str[0], 0));
		dic.insert(make_pair(str[1], 1));
		dic.insert(make_pair(str[2], 2));
		awake[0] = awake[1] = awake[2] = true;

		rep(i, edges)
		{
			cin >> str;
			if (dic.find(str[0]) == dic.end())
				dic.insert(make_pair(str[0], dic.size()));

			if (dic.find(str[1]) == dic.end())
				dic.insert(make_pair(str[1], dic.size()));

			graph[dic[str[0]]][dic[str[1]]] = graph[dic[str[1]]][dic[str[0]]] = 1;
		}

		int year_cnt = 0;
		bool status = true;
		while (status)
		{
			status = false;
			year_cnt++;
			vector<int> WillBeAwake;
			rep(i, n)
			{
				if (!awake[i])
				{
					int cnt = 0;
					vi nbr = getNeigbors(graph, i, n);
					rep(j, nbr.size())
						if (awake[nbr[j]])
							cnt++;
					if (cnt >= 3)
						WillBeAwake.push_back(i);
				}
			}
			rep(i, WillBeAwake.size())
			{
				awake[WillBeAwake[i]] = true;
			}

			if (WillBeAwake.size() > 0)
				status = true;
		}

		bool result = true;
		rep(i, n)
			if (!awake[i])
				result = false;

		if (result)
			printf("WAKE UP IN, %d, YEARS\n", year_cnt-1);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}


	return 0;
}

//AC