#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
        int n=prices.size();
        int Min=prices[0];
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            Min=min(Min,prices[i]);
            dp[i]=max(dp[i-1],prices[i]-Min);
        }
        return dp[n-1];
    }
};
int main()
{
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}