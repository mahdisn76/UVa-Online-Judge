#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	double k;
	set<pair<int, int>> ans;
	while (cin >> k)
	{
		ans.clear();
		for (double x = k + 1; x <= (2 * k); x++)
		{
			double number = (k*x) / (x - k);
			if (number == ((int)number))
				ans.insert(make_pair(x, int(number)));
		}
		printf("%d\n", ans.size());
		for (auto itr = ans.begin(); itr != ans.end(); itr++)
			cout << "1/" << k << " = 1/" << itr->second << " + 1/" << itr->first << endl;
	}
	return 0;
}