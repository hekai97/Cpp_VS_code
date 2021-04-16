#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int Roads(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(i==0&&j==0)
                    {
                        dp[i][j]=1;
                    }
                    else if(i==0)
                    {
                        dp[i][j]=dp[i][j-1]%100003;
                    }
                    else if(j==0)
                    {
                        dp[i][j]=dp[i-1][j]%100003;
                    }
                    else
                    {
                        dp[i][j]=(dp[i][j-1]+dp[i-1][j])%100003;
                    }
                }
            }
        }
        return dp[n-1][n-1];
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        grid[x-1][y-1]=1;
    }
    Solution s;
    cout<<s.Roads(grid);
    return 0;
}