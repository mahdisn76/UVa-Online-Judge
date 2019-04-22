#include<map>
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	for (int i = 0; i < tc; i++) 
	{
		if (i != 0)
			cout << endl;
		string s;
		map<string, int> m;
		double count=0;
		while (getline(cin, s), s != "")
		{
			++count;
			auto itr = m.find(s);
			if (itr != m.end())
				itr->second++;
			else
				m.insert(make_pair(s, 1));
		}

		for (auto itr = m.begin(); itr != m.end(); itr++)
			printf("%s %.4f\n", itr->first.c_str(), (double(itr->second)*100.0 / count));
	}
	return 0;
}

//AC