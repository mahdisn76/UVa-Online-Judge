//#include<iostream>
//#include<map>
//#include<string>
//#include<iomanip>
//
//using namespace std;
//int main()
//{
//
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		double ans = 0;
//		int n;
//		cin >> n;
//		map<char, double> m;
//		for (int i = 0; i < n; i++)
//		{
//			char c;
//			double x;
//			cin >> c >> x;
//			x /= 100.0;
//			m.insert(make_pair(c, x));
//		}
//
//		int l;
//		cin >> l;
//		cin.ignore();
//		for (int i = 0; i < l; i++)
//		{
//			string s;
//			getline(cin, s);
//			//cout << "__" << tmp << "__" << endl;
//			for (int j = 0; j < s.length(); j++)
//			{
//				if (m.find(s[j]) != m.end())
//					ans += m[s[j]];
//			}
//		}
//
//		cout << setprecision(2) << fixed << ans << '$' << endl;
//
//
//	}
//
//
//	return 0;
//}
////ACC


#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		map<char, int> dic;
		int n;
		cin >> n;
		while (n--)
		{
			char c;
			int i;
			cin.ignore();
			cin >> c >> i;
			dic.insert(make_pair(c, i));
		}

		double ans = 0;
		cin >> n;
		cin.ignore();
		while (n--)
		{
			string s;
			getline(cin, s);
			for (int i = 0; i < s.length(); i++)
				if (dic.find(s[i]) != dic.end())
					ans += dic.find(s[i])->second;
		}
		printf("%.2f$\n", double(ans)/100.0);
	}

	return 0;
}