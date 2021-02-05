#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(decltype(grid.size()) i=0;i<grid.size();i++)
        {
            for(decltype(grid[i].size()) j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char>>& grid,decltype(grid.size()) i,decltype(grid.size()) j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||grid[i][j]!='1')
        {
            return;
        }
        grid[i][j]='2';
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
    }
};
int main()
{
    vector<vector<char>> grid={{'1','1','1','1','0'},
                               {'1','1','0','1','0'},
                               {'1','1','0','0','0'},
                               {'0','0','0','0','0'}};
    Solution s;
    cout<<s.numIslands(grid);
    return 0;
}