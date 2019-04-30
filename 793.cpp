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

class UnionFind
{
private: vi parent, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		rep(i, N)
			parent.push_back(i);
	}
	int findSet(int i)
	{
		return parent[i] == i ? i : parent[i] = findSet(parent[i]);
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				parent[y] = x;
			else
			{
				parent[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int main()
{
	int tc;
	cin >> tc;
	rep(i, tc)
	{
		if (i > 0)
			cout << endl;

		int n;
		cin >> n;
		int success = 0, unsuccess=0;

		UnionFind uf(n);
		string line;
		cin.ignore();
		while (getline(cin, line), line != "")
		{
			int a, b;
			stringstream ss;
			ss << line;
			char tmp;
			ss >> tmp >> a >> b;
			--a; --b;
			if (line[0] == 'q')
				uf.isSameSet(a, b) ? ++success : ++unsuccess;
			else
				uf.unionSet(a, b);
		}
		printf("%d,%d\n", success, unsuccess);
	}
	return 0;
}

//AC