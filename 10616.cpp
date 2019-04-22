#include<iostream>
#include<algorithm>

using namespace std;
long long int n, q, d, m, arr[201];

long long int mem[201][21][11];


long long int solve(long long int index, long long int c_sum, long long int rem_numbers)
{
	if (mem[index][c_sum][rem_numbers] != -1)
		return mem[index][c_sum][rem_numbers];

	if (rem_numbers == 0)
	{
		if (c_sum == 0)
			return 1;
		else
			return 0;
	}

	if (index >= n) return 0;

	long long int ans = 0;
	ans = solve(index + 1, c_sum % d, rem_numbers); //not selected
	ans += solve(index + 1, (((c_sum + arr[index]) % d)+d)%d, rem_numbers - 1); //selected
	return mem[index][c_sum][rem_numbers] = ans;
}

int main()
{
	int s_counter = 1;
	while (true)
	{
		cin >> n >> q;
		if (n == 0 && q == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << "SET " << s_counter << ":" << endl;
		for (int i = 0; i < q; i++)
		{
			cin >> d >> m;

			for (int ii = 0; ii < 201; ii++)
				for (int jj = 0; jj < 21; jj++)
					for (int kk = 0; kk < 11; kk++)
						mem[ii][jj][kk] = -1;

			cout << "QUERY " << i + 1 << ": " << solve(0, 0, m) << endl;
		}

		s_counter++;
	}

	return 0;
}

//AC