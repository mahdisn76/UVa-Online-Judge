#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

struct node
{
	int time = 0;
	bool solved = false;
};

struct team
{
	int indx=-1;
	int solved_count = 0;
	int pen_time = 0;
};


class myclass
{
public:
	bool operator()(const team& t1, const team& t2)
	{
		if (t1.solved_count != t2.solved_count)
			return t1.solved_count > t2.solved_count;

		if (t1.pen_time != t2.pen_time)
			return t1.pen_time < t2.pen_time;

		return t1.indx < t2.indx;
	}
};

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--)
	{
		team teams[101];
		node scoreBoard[101][10];
		string line;
		while(getline(cin, line), line != "")
		{
			stringstream ss;
			ss << line;
			int teamIndx, probIndx, time;
			ss >> teamIndx >> probIndx >> time;
			char status;
			ss >> status;

			if (!scoreBoard[teamIndx][probIndx].solved)
			{
				teams[teamIndx].indx = teamIndx;

				if (status == 'I')
					scoreBoard[teamIndx][probIndx].time += 20;
				else if (status == 'C')
				{
					scoreBoard[teamIndx][probIndx].solved = true;
					scoreBoard[teamIndx][probIndx].time += time;
					teams[teamIndx].solved_count++;
					teams[teamIndx].pen_time += scoreBoard[teamIndx][probIndx].time;
				}
			}
		}

		myclass m;
		sort(teams + 1, teams + 101, m);
		for (int i = 1; i < 101; i++)
		{
			if (teams[i].indx == -1)
				continue;
			printf("%d %d %d\n", teams[i].indx, teams[i].solved_count, teams[i].pen_time);
		}
		
		if (tc != 0) cout << endl;

	}
	return 0;
}

//AC