#include<iostream>
#include<vector>
#include<algorithm>

#define INT_MAX 2147483647

using namespace std;
int coins[41][2];
int m, s;

int mem[41][301][301];

int solve(int coin_index, int a_sum, int b_sum)
{
	int current_modulus = a_sum * a_sum + b_sum * b_sum;
	if (current_modulus == s)
		return 0;
	if (current_modulus > s)
		return INT_MAX;
	if (a_sum > 300 || b_sum > 300)
		return INT_MAX;
	
	if (mem[coin_index][a_sum][b_sum] != -1)
		return mem[coin_index][a_sum][b_sum];

	int ret = INT_MAX; // longlong
	for (int i = 0; i < m; i++)
		ret = min(ret, solve(i, a_sum + coins[i][0], b_sum + coins[i][1]));
	if (ret != INT_MAX)
		ret++;
	return mem[coin_index][a_sum][b_sum] = ret;
}


int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		for (int i = 0; i < 41; i++)
			for (int j = 0; j < 301; j++)
				for (int k = 0; k < 301; k++)
					mem[i][j][k] = -1;

		cin >> m >> s;
		s *= s;
		for (int i = 0; i < m; i++)
			cin >> coins[i][0] >> coins[i][1];
		int tmp = solve(0, 0, 0);
		if (tmp == INT_MAX)
			cout << "not possible";
		else
			cout << tmp;
		cout << endl;

	}

	return 0;
}

//AC