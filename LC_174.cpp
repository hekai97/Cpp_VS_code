//地下城游戏，反向DP
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        if(n==0||m==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m));
        
        for(int i=n-1;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                if(i==n-1&&j==m-1)
                {
                    if(dungeon[n-1][m-1]>=0)
                    {
                        dp[n-1][m-1]=1;
                    }
                    else
                    {
                        dp[n-1][m-1]=abs(dungeon[n-1][m-1])+1;
                    }
                }
                else if(i==n-1)
                {
                    if(dungeon[i][j]>=0)
                    {
                        dp[i][j]=dp[i][j+1]-dungeon[i][j];
                        if(dp[i][j]<=0)
                        {
                            dp[i][j]=1;
                        }
                    }
                    else
                    {
                        dp[i][j]=dp[i][j+1]+abs(dungeon[i][j]);
                    }
                }
                else if(j==m-1)
                {
                    if(dungeon[i][j]>=0)
                    {
                        dp[i][j]=dp[i+1][j]-dungeon[i][j];
                        if(dp[i][j]<=0)
                        {
                            dp[i][j]=1;
                        }
                    }
                    else
                    {
                        dp[i][j]=dp[i+1][j]+abs(dungeon[i][j]);
                    }
                }
                else
                {
                    if(dungeon[i][j]>=0)
                    {
                        dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                        if(dp[i][j]<=0)
                        {
                            dp[i][j]=1;
                        }
                    }
                    else
                    {
                        dp[i][j]=min(dp[i+1][j],dp[i][j+1])+abs(dungeon[i][j]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
int main()
{
    vector<vector<int>> dungeon={
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };
    Solution s;
    cout<<s.calculateMinimumHP(dungeon);
    return 0;
}