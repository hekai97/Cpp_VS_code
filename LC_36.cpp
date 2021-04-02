#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9,vector<int>(9));
        vector<vector<int>> col(9,vector<int>(9));
        vector<vector<int>> block(9,vector<int>(9));
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'1';
                    int blockindex=i/3*3+j/3;
                    if(rows[i][num]||col[j][num]||block[blockindex][num])
                    {
                        return false;
                    }
                    else
                    {
                        rows[i][num]=true;
                        col[j][num]=true;
                        block[blockindex][num]=true;
                    }
                }
            }
        }
        return true;
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
    cout<<s.isValidSudoku(board);
    return 0;
}