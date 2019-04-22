#include<stack>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	while (true)
	{
		int cnt;
		cin >> cnt;
		if (cnt == 0)
			break;

		while (true)
		{
			vector<int> input;
			stack<int> ms;
			int tmp;
			cin >> tmp;
			if (tmp == 0)
			{
				cout << endl;
				break;
			}
			input.push_back(tmp);
			for (int i = 1; i < cnt; i++)
			{
				cin >> tmp;
				input.push_back(tmp);
			}

			bool result = true;
			int input_indx = 0;
			int counter = 1;

			while(1)
			{
				if (!ms.empty() && input_indx<input.size() && input[input_indx] == ms.top())
				{
					ms.pop();
					input_indx++;
					continue;
				}

				if (counter > cnt)
					break;

				if (input[input_indx] == counter)
				{
					input_indx++;
				}
				else if (!ms.empty() && input[input_indx] == ms.top())
				{
					ms.pop(); 
					input_indx++;
				}
				else
				{
					ms.push(counter);
				}
				counter++;
			}

			if (input_indx == cnt)
				cout << "Yes";
			else
				cout << "No";
			cout << endl;

		}
	}
	return 0;
}
//AC