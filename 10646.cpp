#include<iostream>
#include<stack>
#include<string>

using namespace std;

int eval(string card)
{
	if (card[0] >= '2' && card[0] <= '9')
		return card[0] - '0';
	else
		return 10;
}

int main()
{
	int tc;
	cin >> tc;
	for(int ii=1;ii<=tc;ii++)
	{
		stack<string> pile;
		int i = 52;
		while (i--)
		{
			string tmp;
			cin >> tmp;
			pile.push(tmp);
		}
		
		stack<string> hand;
		i = 25;
		while (i--) //1
		{
			hand.push(pile.top());
			pile.pop();
		}

		int y = 0;
		for (int i = 0; i < 3; i++)
		{
			int x = eval(pile.top());
			for(int j=0;j<1+(10-x);j++)
				pile.pop();
			y += x;
		}

		i = 25;
		while (i--)
		{
			pile.push(hand.top());
			hand.pop();
		}

		i = pile.size() - y;
		while (i--)
			pile.pop();

		printf("Case %d: %s\n", ii, pile.top().c_str());

	}


	return 0;
}

//AC