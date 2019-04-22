#include<iostream>
#include<string>
#include<vector>
#include<map> 
#include<algorithm>

using namespace std;

map<pair<string, string>, string> m;



int mainasadfsadfsd()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		string state = "+x";

		for (int i = 0; i < n - 1; i++)
		{
			string move;
			cin >> move;
			cout << state << ", ";
			if (move == "No")
				continue;

			if (state == "+x" || state == "-x")
				state = move;
			else if (state == "+y")
			{
				if (move == "+y")
					state = "-x";
				else if (move == "-y")
					state = "+x";
			}
			else if (state == "-y")
			{
				if (move == "+y")
					state = "+x";
				else if (move == "-y")
					state = "-x";
			}
			else if (state == "+z")
			{
				if (move == "+z")
					state = "-x";
				else if (move == "-z")
					state = "+x";
			}
			else if(state == "-z")
			{
				if (move == "+z")
					state = "+x";
				else if (move == "-z")
					state = "-x";
			}
			else
			{
				cout << "NOOOOOOOOOOOOOO WAy!" << endl;
			}
		}
		cout << endl; 
		cout << state << endl;

	}
	return 0;
}