#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int right[100003], left[100003];
	int b, s;
	while (true)
	{
		cin >> s >> b;
		if (b == 0 && s == 0)
			break;

		for (int i = 1; i <= s; i++)
		{
			left[i] = i - 1;
			right[i] = i + 1;
		}
		left[1] = -1;
		right[s] = -1;

	
		for (int i = 0; i < b; i++)
		{
			int l, r;
			cin >> l >> r;

			right[l - 1] = right[r];
			left[r + 1] = left[l];
			right[left[l]] = right[r];
			left[right[r]] = left[l];
			//cout << "right: ";
			//for (int i = 1; i <= 10; i++)
			//	cout << right[i] << " ";
			//cout << endl <<"left";
			//for (int i = 1; i <= 10; i++)
			//	cout << left[i] << " ";
			//cout << endl;


			cout << (left[l] == -1 ? "*" : to_string(left[l])) << " ";
			cout << (right[r] == -1 ? "*" : to_string(right[r])) << endl;
		}
		cout << "-"<<endl;

	}
	return 0;
}

//ACC