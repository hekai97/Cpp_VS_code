#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int Remaining(vector<vector<int>>& nums,int volumn,int weight)
    {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(volumn+1,vector<int>(weight+1)));
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=volumn;++j)
            {
                for(int k=1;k<=weight;++k)
                {
                    if(j>=nums[i][0]&&k>=nums[i][1])
                    {
                        dp[i][j][k]=max(dp[i-1][j-nums[i][0]][k-nums[i][1]]+nums[i][2],dp[i-1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[n-1][volumn][weight];
    }
};
int main()
{
    int volume,weight;
    cin>>volume>>weight;
    int n;
    cin>>n;
    vector<vector<int>> nums(n+1,vector<int>(3));
    for(int i=1;i<=n;++i)
    {
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }
    Solution s;
    cout<<s.Remaining(nums,volume,weight);
    return 0;
}