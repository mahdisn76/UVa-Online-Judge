#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		bool* arr = new bool[n];
		for (int i = 0; i < n; i++)
			arr[i] = false;

		int t1, t2;
		cin >> t1;
		if (n == 1)
		{
			cout << "Jolly" << endl;
			continue;
		}
		for (int i = 0; i < n-1; i++)
		{
			cin >> t2;
			if (abs(t2 - t1) >= n)
			{
				t1 = t2;
				continue;
			}
			//cout << "__ " << abs(t2 - t1) << endl;
			arr[abs(t2 - t1)] = true;
			t1 = t2;
		}

		bool status = true;
		for (int i = 1; i < n; i++)
		{
			if (!arr[i])
				status = false;
		}

		if (status)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		delete arr;
	}
	return 0;
}
//ACC
