#include<iostream>
#include<algorithm>

using namespace std;

int P[1001], W[1001];
int n;

int mem[1001][31];

int calc(int id, int rem_cap)
{
	if (id == n) return 0;
	if (rem_cap == 0) return 0;
	if (mem[id][rem_cap] != -1) return mem[id][rem_cap];
	if (rem_cap < W[id]) return calc(id + 1, rem_cap);
	return mem[id][rem_cap] = max(P[id] + calc(id + 1, rem_cap - W[id]), calc(id + 1, rem_cap));
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{

		for (int i = 0; i <= 1000; i++)
			for (int j = 0; j <= 30; j++)
				mem[i][j] = -1;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> P[i] >> W[i];

		int g;
		cin >> g;
		int ans = 0;
		while (g--)
		{
			int capacity;
			cin >> capacity;
			ans += calc(0, capacity);
		}
		cout << ans << endl;

	}

	return 0;
}

//AC