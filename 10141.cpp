#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{
	int cnt = 1;
	while (1)
	{

		int n, p;
		set<string> s;
		cin >> n >> p;
		if (n == 0 && p == 0)
			break;
		
		if (cnt != 1)
			printf("\n");

		cin.ignore();
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string tmp;
			getline(cin, tmp);
			s.insert(tmp);
		}

		//for (auto itr = s.begin(); itr != s.end(); itr++)
		//	cout << *itr << ", ";
		//cout << endl;

		string ans;
		double compliance=0, price=2000000000;

		for (int i = 0; i < p; i++)
		{
			string tmp;
			getline(cin, tmp);
			double _p, c;
			double nn;
			cin >> _p >> nn;
			cin.ignore();

			for (int i = 0; i < nn; i++)
			{
				string ss;
				getline(cin, ss);
			}

			c = nn / n;
			if (c > compliance)
			{
				ans = tmp;
				compliance = c;
				price = _p;
			}
			else if (c == compliance && _p < price)
			{
				ans = tmp;
				compliance = c;
				price = _p;
			}
		}


		printf("RFP #%d\n%s\n", cnt, ans.c_str());
		cnt++;
	}

	return 0;
}

//AC