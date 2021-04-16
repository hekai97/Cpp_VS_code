#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int CellNum(vector<vector<int>>& grid)
    {
        int res=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]!=0&&!visited[i][j])
                {
                    dfs(grid,visited,i,j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int x,int y)
    {
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||visited[x][y]||grid[x][y]==0)
        {
            return;
        }
        visited[x][y]=1;
        dfs(grid,visited,x+1,y);
        dfs(grid,visited,x-1,y);
        dfs(grid,visited,x,y+1);
        dfs(grid,visited,x,y-1);
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for(int i=0;i<n;++i)
    {
        string t;
        cin>>t;
        vector<int> temp;
        for(int j=0;j<m;++j)
        {
            temp.push_back(t[j]-48);
        }
        grid.push_back(temp);
    }
    Solution s;
    cout<<s.CellNum(grid);
    return 0;
}
