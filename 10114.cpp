#include<iostream>
#include<vector>
using namespace std;
int main()
{
	double n, down, amount, n_dep;
	while (1)
	{
		cin >> n >> down >> amount >> n_dep;
		if (n < 0)
			break;
		
		int nnn = n + 1;
		double* arr = new double[nnn];
		int per_index = 0;
		double per_val;
		for (int i = 0; i < n_dep; i++)
		{
			int indx;
			double val;
			cin >> indx >> val;

			for (int j = per_index + 1; j < indx; j++)
				arr[j] = per_val;

			arr[indx] = val;

			per_index = indx;
			per_val = val;
		}

		for (int i = per_index + 1; i <= n; i++)
			arr[i] = per_val;

		//for (int i = 0; i <= n; i++)
		//	cout << arr[i] << ", ";
		//cout << endl;


		double owe = amount, car_worth = (down+amount) * (1 - arr[0]);
		int cnt = 0;
		double every_mounth = amount / n;
		while (1)
		{
			//cout <<"cnt: " << cnt<< "\nowe: " << owe << endl << "car worth: " << car_worth << endl <<endl;
			if (owe < car_worth)
				break;

			cnt++;
			
			owe -= every_mounth;
			car_worth *= (1 - arr[cnt]);
		}

		cout << cnt << " month" << (cnt != 1 ? "s" : "") << endl;

	}
	return 0;
}

//AC