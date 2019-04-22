#include<vector>
#include<iostream>
using namespace std;
int mainasd()
{
	int t;
	cin >> t;
	vector<int>v;
	for (int i = 0; i < t; i++)
	{
		v.clear();
		int s;
		cin >> s;
		while (s-->1)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		int max_sum = 0, sum = 0, start=0, end=0;
		bool has_new_start = false;
		int new_start = 0;
		for (int j = 0; j < v.size(); j++)
		{
			sum += v[j];
			if (sum >= max_sum)
			{
				max_sum = sum;
				end = j;
				if (has_new_start)
				{
					start = new_start;
					has_new_start = false;
				}
			}
			if (sum < 0)
			{
				sum = 0;
				new_start = j+1;
				has_new_start = true;
			}
		}
		if (max_sum <= 0)
			printf("Route %d has no nice parts\n", i + 1);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", i + 1, start + 1, end + 2);
	}
	return 0;
}



//WA