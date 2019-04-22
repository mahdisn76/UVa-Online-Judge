#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	vector<int> v;
	int tc;
	cin >> tc;
	bool arr[201];
	cin.ignore();

	while (tc--)
	{
		for (int i = 0; i < 201; i++)
			arr[i] = false;

		v.clear();
		int sum = 0;
		
		string s;

		getline(cin, s);

		stringstream ss;
		ss << s;
		while (!ss.eof())
		{
			int tmp;
			ss >> tmp;
			v.push_back(tmp);
			sum += tmp;
		}
		if (sum % 2 == 1)
		{
			cout << "NO" << endl;
			continue;
		}

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 200; j > 0; j--)
			{
				if (arr[j])
					if (j + v[i] <= 200)
						arr[j + v[i]] = true;
			}
			arr[v[i]] = true;
		}

		//cout << endl;
		//for (int ii = 0; ii <= 200; ii++)
		//	cout << ii << ": " << arr[ii] << ", " << endl;
		//cout << endl;

		cout<< ((arr[sum / 2])? "YES" : "NO") << endl;
	}
	return 0;
}

//AC