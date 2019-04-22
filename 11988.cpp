#include<iostream>
#include<string>
#include<list>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		list<char> l;
		auto itr = l.begin();
		for (int i = 0; i < str.size(); i++)
			if (str[i] == '[')
				itr = l.begin();
			else if (str[i] == ']')
				itr = l.end();
			else
				l.insert(itr, str[i]);

		for (auto itr = l.begin(); itr != l.end(); itr++)
		{
			cout << *itr;
		}
		cout << endl;
	}
	return 0;
}

//AC