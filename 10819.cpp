#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int P[101], F[101], mem[101][10201];
int n, m;

int solve(int index, int current_sum)
{
	/*
	if (index == n && current_sum<=m)
		return 0;

	if (current_sum > m)
		return -2;
	*/

	if (index == n)
	{
		if (current_sum > 2000)
			if (current_sum <= (m + 200))
				return 0;
			else
				return -2;
		else
			if (current_sum <= m)
				return 0;
			else
				return -2;
	}

	if (current_sum > m + 200)
		return -2;
	
/*
	if (current_sum > 2000)
		if (current_sum > (m + 200))
			return -2;
	
	if (current_sum <= 2000)
		if (current_sum > m)
			return -2;
*/

	if (mem[index][current_sum] != -1)
		return mem[index][current_sum];

	int ret = -2;// -2 means not possible

	int tmp = solve(index + 1, current_sum);
	if (tmp != -2)
		ret = tmp;

	tmp = solve(index + 1, current_sum + P[index]);
	if(tmp!=-2)
		ret = max(ret, F[index] + tmp);

	return mem[index][current_sum] = ret;
}


int main()
{
	while (cin >> m >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> P[i] >> F[i];

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 10201; j++)
				mem[i][j] = -1;

		cout << max(solve(0, 0), 0) << endl;
	}
	return 0;
}

//AC