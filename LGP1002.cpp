#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    std::size_t ways(vector<vector<int>>& board) {
        if(board[0][0]==1)
        return 0;
        int n=board.size(),m=board[0].size();
        vector<vector<std::size_t>> dp(n,vector<std::size_t>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(i==0&&j==0)dp[i][j]=1;
                    else if(i==0)dp[i][j]=dp[i][j-1];
                    else if(j==0)dp[i][j]=dp[i-1][j];
                    else
                    {
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                    
                }
                
            }
        }
        return dp[n-1][m-1];
    }
};
int main()
{
    int xb,yb,xh,yh;
    cin>>xb>>yb>>xh>>yh;
    vector<vector<int>> board(xb+1,vector<int>(yb+1));
    board[xh][yh]=1;
    if(xh-2>=0&&yh-1>=0)board[xh-2][yh-1]=1;
    if(xh-2>=0&&yh+1<=yb)board[xh-2][yh+1]=1;
    if(xh+2<=xb&&yh-1>=0)board[xh+2][yh-1]=1;
    if(xh+2<=xb&&yh+1<=yb)board[xh+2][yh+1]=1;
    if(xh-1>=0&&yh-2>=0)board[xh-1][yh-2]=1;
    if(xh-1>=0&&yh+2<=yb)board[xh-1][yh+2]=1;
    if(xh+1<=xb&&yh-2>=0)board[xh+1][yh-2]=1;
    if(xh+1<=xb&&yh+2<=yb)board[xh+1][yh+2]=1;
    Solution s;
    cout<<s.ways(board);
    return 0;
}