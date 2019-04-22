#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>


using namespace std;

int main()
{
	char str[100], str_cpy[100];
	while (true)
	{
		bool status = false;
		cin >> str;
		if (strcmp(str, "#") == 0)
			break;
		strcpy(str_cpy, str);
		while (next_permutation(str_cpy, str_cpy+strlen(str_cpy)))
		{
			if (strcmp(str_cpy, str) > 0)
			{
				cout << str_cpy << endl;
				status = true;
				break;
			}
		}
		if (!status)
			cout << "No Successor"<<endl;
	}
	return 0;
}

//AC