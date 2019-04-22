#include<iostream>
#include<queue>
#include<algorithm>
#include<string>

#define left 0
#define right 1

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int len, m;
		cin >> len >> m;
		len *= 100;
		int ans = 0;
		queue<int> RQ, LQ;

		while (m--)
		{
			int tmp;
			string s;
			cin >> tmp >> s;
			if (s == "left")
				LQ.push(tmp);
			else
				RQ.push(tmp);
		}

		int dir = left;
		while (!(LQ.empty() && RQ.empty()))
		{
			if (LQ.empty() && dir == left)
			{
					ans++;
					dir = right;
			}
			else if (RQ.empty() && dir == right)
			{
				ans++;
				dir = left;
			}
			else if (dir == right)
			{
				int sum = 0;
				while (!RQ.empty())
				{
					if (sum + RQ.front() > len)
						break;
					sum += RQ.front();
					RQ.pop();
				}
				ans++;
				dir = left;
			}
			else if (dir == left)
			{
				int sum = 0;
				while (!LQ.empty())
				{
					if (sum + LQ.front() > len)
						break;
					sum += LQ.front();
					LQ.pop();
				}
				ans++;
				dir = right;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

//AC