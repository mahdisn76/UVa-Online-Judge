#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		int nn = pow(2, n);
		vector<int> weights, potences;
		for (int i = 0; i < nn; i++)
		{
			int w;
			scanf("%d", &w);
			weights.push_back(w);
		}

		int m = 0;
		for (int i = 0; i < nn; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
				s += weights[i ^ (1 << j)];

			potences.push_back(s);
		}

		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int indx = i ^ (1 << j);
				int tmp = potences[i] + potences[indx];
				m = max(m, tmp);
			}
		}
		cout << m << endl;
	}
	return 0;
}
//AC