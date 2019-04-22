#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define lli long long int
#define ulli unsigned long long int
#define rep(n) for(int i=0;i<n;i++)
#define iterate(x) for(auto itr=x.begin(); itr!=x.end();itr++)
using namespace std;

struct comprator {
	bool operator()(const int& a, const int& b)const {
		return a > b;
	}
};

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int bf, gc, bc;
		cin >> bf >> gc >> bc;
		multiset<int, comprator> green, blue;
		int tmp;
		rep(gc)
		{
			cin >> tmp;
			green.insert(tmp);
		}
		rep(bc)
		{
			cin >> tmp;
			blue.insert(tmp);
		}

		while (!(green.empty() || blue.empty()))
		{
			int bf_ = min(green.size(), blue.size());
			bf_ = min(bf_, bf);
			vector<int> remg, remb;
			rep(bf_)
			{
				int a = *green.begin(), b = *blue.begin();
				green.erase(green.begin());
				blue.erase(blue.begin());
				if (a > b)
					remg.push_back(a - b);
				else if (a < b)
					remb.push_back(b - a);
			}
			iterate(remg)
				green.insert(*itr);
			iterate(remb)
				blue.insert(*itr);
		}

		if (green.empty() && blue.empty())
			cout << "green and blue died\n";
		else if (green.empty())
		{
			cout << "blue wins\n";
			iterate(blue)
				cout << *itr << endl;
		}
		else
		{
			cout << "green wins\n";
			iterate(green)
				cout << *itr << endl;
		}
		if (tc)cout << endl;

	}
	return 0;
}
//AC