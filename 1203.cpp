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

struct node
{
	int time, qNum, add_time;
	bool operator<(const node& n) const {
		if (this->time > n.time)
			return true;
		if (this->time < n.time)
			return false;
		return this->qNum > n.qNum;
	}
};

int main()
{
	int arr[1001][2], i=0;
	string s;
	priority_queue<node> pq;

	while (getline(cin, s), s != "#")
	{
		stringstream ss;
		ss << s;
		ss >> s;
		int q, p;
		ss >> q >> p;

		node n;
		n.time = n.add_time = p;
		n.qNum = q;

		pq.push(n);
	}
	int k;
	cin >> k;
	rep(k)
	{
		node n = pq.top();
		pq.pop();
		cout << n.qNum << endl;

		n.time += n.add_time;
		pq.push(n);
	}
	return 0;
}
//AC