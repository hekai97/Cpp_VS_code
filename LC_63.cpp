#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        int L1=obstacleGrid.size(),L2=obstacleGrid[0].size();
        vector<vector<int>> dp(L1,vector<int>(L2));
        for(int i=0;i<L1;i++)
        {
            for(int j=0;j<L2;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(i==0&&j==0)dp[0][0]=1;
                    else if(i==0)dp[i][j]=dp[i][j-1];
                    else if(j==0)dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[L1-1][L2-1];
    }
};
int main()
{
    vector<vector<int>> a={{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(a);
    return 0;
}