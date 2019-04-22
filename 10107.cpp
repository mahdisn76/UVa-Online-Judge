#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

void print(int*arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[10010];
	int indx = 0;
	while (cin >> arr[indx])
	{
		stable_sort(arr, arr + indx+1);
		//print(arr, indx + 1);
		int half_indx = indx / 2;
		if (indx % 2 == 0)
			cout << arr[half_indx];
		else
			cout << (arr[half_indx] + arr[half_indx + 1]) / 2;
		cout << endl;
		indx++;
	}
	return 0;
}
//AC