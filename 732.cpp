#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

set<string> ans;
stack<char> stck;
void solve(string str1, int indx1, string str2, int indx2, string current)
{
	//if (current.size() > 2 * str1.size())
	//	return;

	if (indx2 == str2.size() && indx1 == str1.size() && stck.empty())
	{
		ans.insert(current);
		return;
	}

	if ((indx1 == str1.size() && stck.empty()) || indx2 == str2.size())
		return;

	if (indx1<str1.size() && indx2<str2.size() && str2[indx2] == str1[indx1])
	{
		current += "io";
		solve(str1, indx1+1, str2, indx2+1, current);
		current = current.substr(0, current.size() - 2);
		//current.erase(current.end());
		//current.erase(current.end());
	}
	if (!stck.empty() && indx2 < str2.size() && str2[indx2] == stck.top())
	{
		current += "o";
		stck.pop();
		solve(str1, indx1, str2, indx2+1, current);
		stck.push(str2[indx2]);
		current = current.substr(0, current.size() - 1);
		//current.erase(current.end());
	}
	
	if (indx1 < str1.size())
	{
		current += "i";
		stck.push(str1[indx1]);
		solve(str1, indx1 + 1, str2, indx2, current);
		stck.pop();
		current = current.substr(0, current.size() - 1);
		//current.erase(current.end());
	}
}

int main()
{
	string str1, str2;
	while (cin>>str1>>str2)
	{
		ans.clear();
		solve(str1, 0, str2, 0, "");
		cout << "[\n";
		for (auto itr = ans.begin(); itr != ans.end(); itr++)
			for (int i = 0; i < itr->size(); i++)
				cout << itr->at(i) << (i == itr->size() - 1 ? "\n" : " ");
		cout << "]\n";
	}
	return 0;
}
//AC