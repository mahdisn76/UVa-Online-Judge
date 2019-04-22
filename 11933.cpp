#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	long long int n;
	while (cin >> n, n != 0)
	{
		long long int a=0, b=0;
		bool a_s = true;
		long long int nbits = ceil(log2(n))+1;
		for (long long int i = 0; i < nbits; i++)
		{
			if ((n&(1 << i)) > 0)
			{
				if (a_s)
					a |= (1 << i);
				else
					b |= (1 << i);
				a_s = !a_s;
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}

//AC