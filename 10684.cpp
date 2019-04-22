#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    while(1)
    {
        v.clear();
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        long long int sum = 0, ans = 0;
        for(int i=0;i<n;i++)
        {
            sum += v[i];
            ans = max(ans, sum);
            if(sum<0)sum=0;
        }
        if(ans>0)
            cout<<"The maximum winning streak is " <<ans<<"."<<endl;
        else
            cout<<"Losing streak."<<endl;
    }
    return 0;
}
//AC