#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<sstream>
#define lli long long int
#define ulli unsigned long long int
#define rep(n) for(int i=0;i<n;i++)
#define iterate(x) for(auto itr=x.begin(); itr!=x.end();itr++)
using namespace std;

class op
{
	public:
	bool operator()(const int& a, const int& b)const {
		return a > b;
	}
};

int main()
{
	int tc;
	while (cin >> tc, tc != 0)
	{
		priority_queue<int, vector<int>, op> pq;
		int n=tc, ans = 0;
		rep(n)
		{
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}

		while (pq.size()!=1)
		{
			int sum = 0;
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			pq.push(sum);
			ans += sum;
		}
		cout << ans << endl;
	}
	return 0;
}

//AC