#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row,column,stepnum=1;
        for(auto i=0;i<grid.size();i++)
        {
            for(auto j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    row=i;
                    column=j;
                }
                else if(grid[i][j]==0)
                {
                    stepnum++;
                }
            }
        }
        return backtracking(grid,row,column,stepnum);
    }
private:
    int backtracking(vector<vector<int>>& grid,int row,int column,int stepnum)
    {
        if(row<0||row>=grid.size()||column<0||column>=grid[0].size()||grid[row][column]==-1)return 0;
        if(grid[row][column]==2)
        {
            if(stepnum==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        grid[row][column]=-1;
        int sum=backtracking(grid,row-1,column,stepnum-1)+
                backtracking(grid,row+1,column,stepnum-1)+
                backtracking(grid,row,column-1,stepnum-1)+
                backtracking(grid,row,column+1,stepnum-1);
        grid[row][column]=0;
        return sum;
    }
};
int main()
{
    vector<vector<int>> grid{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    Solution s;
    cout<<s.uniquePathsIII(grid);
    return 0;
}