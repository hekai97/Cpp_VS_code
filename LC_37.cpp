#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        deque<deque<bool>> rows(9,deque<bool>(9));
        deque<deque<bool>> col(9,deque<bool>(9));
        deque<deque<bool>> block(9,deque<bool>(9));
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    int blockindex=i/3*3+j/3;
                    int num=board[i][j]-'1';
                    rows[i][num]=true;
                    col[j][num]=true;
                    block[blockindex][num]=true;
                }
            }
        }
        dfs(board,rows,col,block,0,0);
    }
private:
    bool dfs(vector<vector<char>>& board,deque<deque<bool>>& rows,deque<deque<bool>>& col,deque<deque<bool>>& block,int i,int j)
    {
        while(board[i][j]!='.')
        {
            if (++j>=9)
            {
                i++;
                j=0;
            }
            if (i>=9) 
            {
                return true;
            }
        }
        for (int num=0;num<9;num++) {
            int blockIndex=i/3*3+j/3;
            if (!rows[i][num]&&!col[j][num]&&!block[blockIndex][num])
            {
                board[i][j]=(char)('1'+ num);
                rows[i][num]=true;
                col[j][num]=true;
                block[blockIndex][num]=true;
                if(dfs(board,rows,col,block,i,j)) 
                {
                    return true;
                } 
                else
                {
                    rows[i][num] = false;
                    col[j][num] = false;
                    block[blockIndex][num] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<char>> board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(board);
    for(auto a:board)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}