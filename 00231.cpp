#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;

#define MAX_N 10000

int main() {
	int ii = 0;
	while (true)
	{
		ii++;
		vector<int> v;
		int tmp;
		cin >> tmp; 
		if (tmp == -1)
			return 0;
			v.push_back(tmp);
		while (1)
		{
			cin >> tmp;
			if (tmp == -1)
				break;
			v.push_back(tmp);
		}

		int L[MAX_N];

		int lis = 0;
		for (int i = v.size() - 1; i >= 0;i-- ) {
			int pos = lower_bound(L, L + lis, v[i]) - L;
			L[pos] = v[i];

			if (pos + 1 > lis) {
				lis = pos + 1;
			}
		}
		if (ii != 1)
			printf("\n");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", ii, lis);
	}
	cin.ignore();
	cin.get();
	return 0;
}
//AC