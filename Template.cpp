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
private: vi parent, rank; int numOfSets; set<int> s;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		rep(i, N)
		{
			parent.push_back(i);
			s.insert(i);
		}
		numOfSets = N;
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
			numOfSets--;

			auto x_itr = s.find(x),
				y_itr = s.find(y);
			if (x_itr != s.end())
				s.erase(x_itr);
			if (y_itr != s.end())
				s.erase(y_itr);
		}
	}
	int getNumberOfSets()
	{
		return numOfSets;
	}

	int getNumOfAcorns()
	{
		return s.size();
	}

};

int main()
{

	return 0;
}