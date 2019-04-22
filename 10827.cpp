#include<iostream>
#include<algorithm>

using namespace std;

void print(int**arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int** arr = new int*[n * 2];
		for (int i = 0; i < n * 2; i++)
			arr[i] = new int[n * 2];

		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				arr[i][j + n] = arr[i][j];
				arr[i + n][j] = arr[i][j];
				arr[i + n][j + n] = arr[i][j];
			}

		//print(arr, n * 2);

		for (int i = 0; i<2 * n; i++)
			for (int j = 0; j < 2 * n; j++)
			{
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}

		int sum = 0, _max = 75 * 75 * -100 - 1;
		for (int i = 0; i<n; i++)for (int j = 0; j<n; j++)
			for (int k = i; k < i + n; k++) for (int l = j; l < j + n; l++)
			{
				sum = arr[k][l];
				if (i > 0) sum -= arr[i - 1][l];
				if (j > 0) sum -= arr[k][j - 1];
				if (i > 0 && j > 0) sum += arr[i - 1][j - 1];
				_max = max(_max, sum);
			}

		if (n == 1)
			cout << arr[0][0] << endl;
		else
			cout << _max << endl;

	}
	return 0;
}

//AC