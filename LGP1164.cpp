#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int Number(vector<int>& nums,int m)
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(m+1,0));
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(j==nums[i])
                {
                    dp[i][j]=dp[i-1][j]+1;
                }
                if(j>nums[i])
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]];
                }
                if(j<nums[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n-1][m];
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>nums[i];
    }
    Solution s;
    cout<<s.Number(nums,m);
    return 0;
}