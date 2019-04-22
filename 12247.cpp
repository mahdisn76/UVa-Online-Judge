#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[3], b[2];
	while (1)
	{
		int cnt_zero = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> a[i];
			if (a[i] == 0) cnt_zero++;
		}

		for (int i = 0; i < 2; i++)
		{
			cin >> b[i];
			if (b[i] == 0)cnt_zero++;
		}

		if (cnt_zero == 5)
			break;
		
		int max = 0;
		int second_max = 0;
		bool lose = false;
		do {

			do {
				
				int cnt_lost = 0;

				for (int i = 0; i < 2; i++)
					if (b[i] < a[i]) cnt_lost++;

				if (a[2] >= max)
				{
					second_max = max;
					max = a[2] + 1;
				}
				else if (a[2] >= second_max)
					second_max = a[2] + 1;

				if (cnt_lost > 1)
				{
					lose = true;
					break;
				}

			} while (next_permutation(b, b + 2));

		} while (next_permutation(a, a + 3));

		cout << (lose ? -1 : second_max) << endl;


	}
	return 0;
}