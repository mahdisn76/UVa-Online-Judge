#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	int j = 1;
	while (getline(cin, a)) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '\"' && j++ % 2 == 1) 
				cout << "``";
			else if (a[i] == '\"' && j++ % 2 == 0)
				cout << "''";
			else
				cout << a[i];
		}
		cout << endl;
	}
	return 0;
}

//AC