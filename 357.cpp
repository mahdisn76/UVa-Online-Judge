#include<iostream>
#include<algorithm>

using namespace std;

int coins[] = { 1, 5, 10, 25, 50 };

long long int mem[5][30001];

long long int ways(int coin_index, int value)
{
	if (value == 0)
		return 1;
	if (value < 0)
		return 0;
	if (coin_index == 5)
		return 0;
	if (mem[coin_index][value] != -1)
		return mem[coin_index][value];
	return mem[coin_index][value] = (ways(coin_index, value - coins[coin_index]) +
		ways(coin_index + 1, value));
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 30001; j++)
			mem[i][j] = -1;

	for (int i = 0; i < 30001; i++)
		ways(0, i);

	long long int input, result;
	while (cin >> input)
	{
		result = ways(0, input);
		if (result == 1)
			cout << "There is only 1 way to produce " << input << " cents change.";
		else
			cout << "There are " << result << " ways to produce " << input << " cents change.";
		cout << endl;
	}

	return 0;
}

//AC
