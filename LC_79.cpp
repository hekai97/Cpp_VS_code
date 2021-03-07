#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(board[i][j]==word[0])
                {
                    string temp="";
                    deque<deque<bool>> visited(board.size(),deque<bool>(board[0].size()));
                    res=dfs(board,word,visited,temp,i,j,-1);
                }
                if(res)
                {
                    return res;
                }
            }
        }
        return res;
    }
private:
    bool dfs(vector<vector<char>>& board,string word,deque<deque<bool>>& visited,string temp,int i,int j,int count)
    {
        if(temp!=""&&temp[count]!=word[count])
        {
            return false;
        }
        if(temp.size()==word.size())
        {
            if(temp==word)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]==true)
        {
            return false;
        }
        visited[i][j]=true;
        temp+=board[i][j];
        bool res;
        res=dfs(board,word,visited,temp,i+1,j,count+1)||
            dfs(board,word,visited,temp,i-1,j,count+1)||
            dfs(board,word,visited,temp,i,j+1,count+1)||
            dfs(board,word,visited,temp,i,j-1,count+1);
            visited[i][j]=false;
        return res;
    }
};
int main()
{
    vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution s;
    cout<<s.exist(board,"ABCCED");
    return 0;
}