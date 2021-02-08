#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
    
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for(int j=1;j<n-1;j++)
        {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='0') board[i][j]='O';
                else
                {
                    board[i][j]='X';
                }
            }
        }

    }
private:
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]=='O') 
        {
            board[i][j]='0';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }      
    }
};
int main()
{
    vector<vector<char>> board={
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
    };
    Solution s;
    s.solve(board);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}