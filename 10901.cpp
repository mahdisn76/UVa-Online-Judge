#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define left 0
#define right 1

int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		if (i != 0)cout << endl;

		int n, t, m;
		cin >> n >> t >> m;
		queue<int> LQueue, RQueue, Rans, Lans, enters;
		for (int j = 0; j < m; j++)
		{
			int t;
			string d;
			cin >> t >> d;
			if (d == "left")
			{
				LQueue.push(t);
				enters.push(0);
			}
			else
			{
				RQueue.push(t);
				enters.push(1);
			}
		}

		int dir = left;
		int time = 0;

		while (!LQueue.empty() || !RQueue.empty())
		{
			if (dir == left && LQueue.empty())
			{
				if (time < RQueue.front())
					time = RQueue.front();
				time += t;
				dir = right;
			}
			else if (dir == right && RQueue.empty())
			{
				if (time < LQueue.front())
					time = LQueue.front();
				time += t;
				dir = left;
			}
			else if (dir == left && RQueue.empty())
			{
				time = max(time, LQueue.front());
				int cnt = 0;
				while (!LQueue.empty() && cnt < n && time >= LQueue.front())
				{
					cnt++;
					LQueue.pop();
					//cout << time << endl;
					Lans.push(time+t);
				}
				time += t;
				dir = right;
			}
			else if (dir == right && LQueue.empty())
			{
				time = max(time, RQueue.front());
				int cnt = 0;
				while (!RQueue.empty() && cnt < n && time >= RQueue.front())
				{
					cnt++;
					RQueue.pop();
					//cout << time << endl;
					Rans.push(time+t);
				}
				time += t;
				dir = left;
			}
			else if (dir == right && time < RQueue.front() && time >= LQueue.front())
			{
				time += t;
				dir = left;
			}
			else if (dir == left && time < LQueue.front() && time >= RQueue.front())
			{
				time += t;
				dir = right;
			}
			else if (dir == left && time >= LQueue.front())
			{
				int cnt = 0;
				while (!LQueue.empty() && cnt < n && time >= LQueue.front())
				{
					cnt++;
					LQueue.pop();
					//cout << time << endl;
					Lans.push(time+t);
				}
				time += t;
				dir = right;
			}
			else if (dir == right && time >= RQueue.front())
			{
				int cnt = 0;
				while (!RQueue.empty() && cnt < n && time >= RQueue.front())
				{
					cnt++;
					RQueue.pop();
					//cout << time << endl;
					Rans.push(time+t);
				}
				time += t;
				dir = left;
			}
			else if (time < RQueue.front() && time < LQueue.front())
			{
				int rt = (RQueue.empty() ? 1000000 : RQueue.front());
				int lt = (LQueue.empty() ? 1000000 : LQueue.front());
				time = min(rt, lt);
			}
		}

		while (!enters.empty())
		{
			if (enters.front() == 0)
			{
				cout << Lans.front() << endl;
				Lans.pop();
			}
			else
			{
				cout << Rans.front() << endl;
				Rans.pop();
			}
			enters.pop();
		}

	}
	return 0;
}

//AC!!! important point in the question description!