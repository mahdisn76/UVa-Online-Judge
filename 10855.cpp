#include<iostream>
#include<string>
using namespace std;

void rotate90(char** arr, int n)
{
	char**arr1 = new char*[n];
	for (int i = 0; i < n; i++)
	{
		arr1[i] = new char[n];
		for (int j = 0; j < n; j++)
			arr1[i][j] = arr[i][j];
	}
	
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			arr[j][n - i - 1] = arr1[i][j];
		}
}

bool match(char**arr1, char**arr2, int i, int j, int l)
{
	bool status = true;
	for(int ii=0;ii<l;ii++)
		for (int jj = 0; jj < l; jj++)
		{
			if (arr1[i + ii][j+jj] != arr2[ii][jj])
			{
				status = false;
				break;
			}
		}
	return status;
}

void print(char** arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	cout << endl;
}

int main()
{
	int s1, s2;
	while (1)
	{
		cin >> s1 >> s2;
		if (s1 == 0 && s2 == 0)break;
		char**arr1 = new char*[s1];
		for (int i = 0; i < s1; i++)
			arr1[i] = new char[s1];

		char**arr2 = new char*[s2];
		for (int i = 0; i < s2; i++)
			arr2[i] = new char[s2];

		for (int i = 0; i < s1; i++)
			cin >> arr1[i];
		
		for (int i = 0; i < s2; i++)
			cin >> arr2[i];

		for (int i = 0; i < 4; i++)
		{
			//print(arr2, s2);
			//cout << endl;
			int cnt = 0;
			for (int i = 0; i <= s1 - s2; i++)
			{
				for (int j = 0; j <= s1 - s2; j++)
				{
					if (match(arr1, arr2, i, j, s2))
					{
						//cout << "matched: " << i << " " << j << endl;
						cnt++;
					}
				}
			}
			cout << cnt;
			if (i != 3) {
				cout << " ";
				rotate90(arr2, s2);
			}
			else
				cout << endl;
		}


	}
	return 0;
}
//AC