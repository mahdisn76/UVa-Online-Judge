#include<iostream>
#include<algorithm>

using namespace std;

int** arr;
int n;

void arr_print()
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
	cin >> n;
	arr = new int*[n+10];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n+10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (i > 0) arr[i][j] += arr[i - 1][j];
			if (j > 0) arr[i][j] += arr[i][j - 1];
			if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
		}
	}

	int sum, _max = 100 * 100 * -127 - 1;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) //start point
	{
		for (int k = i + 1; k < n; k++) for (int l = j + 1; l < n; l++)// end point
		{
			sum = arr[k][l];
			if (i > 0) sum -= arr[i - 1][l];
			if (j > 0) sum -= arr[k][j - 1];
			if (i > 0 && j > 0)sum += arr[i - 1][j - 1];
			_max = max(_max, sum);
		}
	}

	if (n == 0)
		cout << "0" << endl;
	else if (n == 1)
		cout << arr[0][0] << endl;
	else
		cout << _max << endl;

	return 0;
}

//AC