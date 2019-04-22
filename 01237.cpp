#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;

	int LH[10000][2];
	char names[10000][21];

	while (t--)
	{

		int d, q;
		cin >> d;
		for (int i = 0; i < d; i++)
		{
			cin >> names[i] >> LH[i][0] >> LH[i][1];
		}

		cin >> q;
		while (q--)
		{
			int count = 0;
			string ans;
			int tmp;
			cin >> tmp;
			for (int i = 0; i < d; i++)
			{
				if (tmp >= LH[i][0] && tmp <= LH[i][1])
				{
					count++;
					ans = string(names[i]);
				}
				if (count > 1)
					break;
			}
			if (count != 1)
				cout << "UNDETERMINED";
			else
				cout << ans;
			cout << endl;
		}

		if (t != 0)
			cout << endl;
	}
	return 0;
}

//AC