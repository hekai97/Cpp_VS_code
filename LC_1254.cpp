#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==0)
                {
                    int temp=1;
                    dfs(grid,i,j,temp);
                    res+=temp;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid,int x,int y,int& temp){
        if(x<0||x==grid.size()||y<0||y==grid[x].size())
        {
            temp=0;
            return;
        }
        if(grid[x][y]!=0)return;
        grid[x][y]=1;
        dfs(grid,x+1,y,temp);
        dfs(grid,x-1,y,temp);
        dfs(grid,x,y+1,temp);
        dfs(grid,x,y-1,temp);
    }
};

int main()
{
    vector<vector<int>> grid{
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };
    Solution s;
    cout<<s.closedIsland(grid);
    return 0;
}