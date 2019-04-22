#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>

using namespace std;
int main()
{
	string s;
	map<char, int> dic;
	dic.insert(make_pair('A', 1));
	dic.insert(make_pair('T', 10));
	dic.insert(make_pair('J', 11));
	dic.insert(make_pair('Q', 12));
	dic.insert(make_pair('K', 13));
	
	dic.insert(make_pair('C', 0));
	dic.insert(make_pair('D', 1));
	dic.insert(make_pair('H', 2));
	dic.insert(make_pair('S', 3));


	while (getline(cin, s))
	{
		int arr[4][14];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 14; j++)
				arr[i][j] = 0;

		bool stopped[4];
		for (int i = 0; i < 4; i++)
			stopped[i] = false;

		stringstream ss;
		ss << s;
		while (!ss.eof())
		{
			
			string tmp;
			ss >> tmp;

			int indx_i, indx_j;

			indx_i = dic[tmp[1]];

			if (tmp[0] >= '2' && tmp[0] <= '9')
				indx_j = tmp[0] - '0';
			else
				indx_j = dic[tmp[0]];

			arr[indx_i][indx_j] = 1;
		}

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 14; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		int score = 0;

		int tmp = 0;

		for (int i = 0; i < 4; i++)
		{
			if (arr[i][1] == 1) //Ace
				score += 4;

			if (arr[i][13] == 1) //King
				score += 3;

			if (arr[i][12] == 1) //Queen
				score += 2;

			if (arr[i][11] == 1) //Jack
				score += 1;

			int count = 0;
			for (int j = 1; j < 14; j++)
			{
				if (arr[i][j] != 0)
				{
					count++;
				}
			}

			if (count == 1 && arr[i][13] == 1) //2
				score -= 1;

			if ((count == 1 || count == 2) && arr[i][12] == 1) //3
				score -= 1;

			if ((count == 1 || count == 2 || count == 3) && arr[i][11] == 1) //4
				score -= 1;

			if (count == 2) //5
			{
				score += 1;
				tmp += 1;
			}
			if (count <= 1) //6, 7
			{
				score += 2;
				tmp += 2;
			}
			//stoped:
			//it contains an ACE! BUG?!
			if ((arr[i][1]) || 
				(arr[i][13] && count >= 2) || 
				(arr[i][12] && count >= 3))

				stopped[i] = true;
		}

		int score2 = score - tmp;

		bool all_stopped = true;
		for (int i = 0; i < 4; i++)
			if (!stopped[i])
				all_stopped = false;

		if (score < 14)
			cout << "PASS" << endl;
		else if (all_stopped && score2 >= 16)
			cout << "BID NO-TRUMP" << endl;
		else
		{
			cout << "BID ";

			int max = 0;
			int indx_max = 0;
			for (int i = 3; i >= 0; i--)
			{
				int cnt = 0;
				for (int j = 1; j < 14; j++)
					if (arr[i][j])
						cnt++;
				if (cnt > max)
				{
					max = cnt;
					indx_max = i;
				}
			}

			switch (indx_max)
			{
			case 0:
				cout << "C";
				break;
			case 1:
				cout << "D";
				break;
			case 2:
				cout << "H";
				break;
			case 3:
				cout << "S";
				break;
			}
			cout << endl;

		}

	}
	return 0;
}

//AC