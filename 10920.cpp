#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dir = { {0,1}, {-1, 0}, {0, -1}, {1, 0} };

int main()
{

	int sz, p;
	while (1)
	{
		cin >> sz >> p;
		if (sz == 0 && p == 0)
			break;
		int x, y;
		x = y = (sz / 2) + 1;
		int step = 1;
		int tmp = 0;
		int dir_indx = 0;
		int current_number = 1;
		int step_counter = 0;

		for (; current_number+step < p;)
		{
			//cout << current_number << endl;
			x += dir[dir_indx][0] * step;
			y += dir[dir_indx][1] * step;

			current_number += step;
			tmp++;
			if (tmp == 2)
			{
				step++;
				tmp = 0;
			}
			dir_indx++;
			dir_indx %= 4;
		}

		for (; current_number < p; current_number++)
		{
			//printf("%d: %d\n", x, y);
			x += dir[dir_indx][0];
			y += dir[dir_indx][1];
			
			step_counter++;
			if (step_counter == step)
			{
				tmp++;
				step_counter = 0;
				if (tmp == 2)
				{
					step++;
					tmp = 0;
				}
				dir_indx++;
				dir_indx %= 4;
			}
		}
		printf("Line = %d, column = %d.\n", y, x);
	}

	return 0;
}

//AC