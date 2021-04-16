#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int PaintNum(vector<vector<char>> grid)
    {
        int res=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='#'&&!visited[i][j])
                {
                    dfs(grid,visited,i,j,i,j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int x,int y,int x0,int y0)
    {
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||visited[x][y]||((abs(x-x0)+abs(y-y0)>=2)&&grid[x][y]=='-'))
        {
            return;
        }
        if(grid[x][y]=='#')
        {
            visited[x][y]=1;
            x0=x;
            y0=y;
        }
        dfs(grid,visited,x+1,y,x0,y0);
        dfs(grid,visited,x-1,y,x0,y0);
        dfs(grid,visited,x,y+1,x0,y0);
        dfs(grid,visited,x,y-1,x0,y0);
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid;
    for(int i=0;i<n;++i)
    {
        string t;
        cin>>t;
        vector<char> temp;
        for(int j=0;j<m;++j)
        {
            temp.push_back(t[j]);
        }
        grid.push_back(temp);
    }
    Solution s;
    cout<<s.PaintNum(grid);
    return 0;
}
