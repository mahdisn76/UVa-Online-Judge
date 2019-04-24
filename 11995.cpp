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
#define rep(n) for(int i=0;i<n;i++)
#define iterate(x) for(auto itr=x.begin(); itr!=x.end();itr++)
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		bool stk = true, q = true, pq = true;
		stack<int> myStack;
		queue<int> myQ;
		priority_queue<int> myPQ;
		rep(n)
		{
			int cmd, tmp;
			cin >> cmd;
			if (cmd == 1)
			{
				cin >> tmp;
				myStack.push(tmp);
				myQ.push(tmp);
				myPQ.push(tmp);
			}
			else
			{
				int result;
				cin >> result;
				if (!myStack.empty() && myStack.top() == result)
					myStack.pop();
				else
					stk = false;
				
				if (!myQ.empty() && myQ.front() == result)
					myQ.pop();
				else
					q = false;

				if (!myPQ.empty() && myPQ.top() == result)
					myPQ.pop();
				else
					pq = false;
			}
		}
		if (!stk && !q && !pq)
			cout << "impossible";
		else if (stk && !q && !pq)
			cout << "stack";
		else if (!stk && q && !pq)
			cout << "queue";
		else if (!stk && !q && pq)
			cout << "priority queue";
		else
			cout << "not sure";
		cout << endl;

	}
	return 0;
}

//AC