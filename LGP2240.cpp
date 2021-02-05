#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double Pack(int T,vector<vector<double>>& coins)
    {
        sort(coins.begin(),coins.end());
        reverse(coins.begin(),coins.end());
        double res=0;
        for(auto i=0;i<coins.size();i++)
        {
            if(T>=coins[i][1])
            {
                T-=coins[i][1];
                res+=coins[i][2];
            }
            else
            {
                res+=T*coins[i][0];
                break;
            }
        }
        return res;
    }
};
int main()
{
    int N,T;
    cin>>N>>T;
    vector<vector<double>> coins(N,vector<double>(3));
    for(int i=0;i<N;i++)
    {
        cin>>coins[i][1]>>coins[i][2];
        coins[i][0]=coins[i][2]/coins[i][1];
    }
    Solution s;
    cout<<fixed<<setprecision(2)<<s.Pack(T,coins)<<endl;
    return 0;
}