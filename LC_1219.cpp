#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=0,temp=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]!=0)
                {
                    temp=dfs(grid,i,j,0);
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid,int i,int j,int cur){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()|| grid[i][j] == 0)return cur;
        int tmp=grid[i][j];
        grid[i][j]=0;
        int sum=0;
        sum=max(sum,dfs(grid,i+1,j,cur+tmp));
        sum=max(sum,dfs(grid,i-1,j,cur+tmp));
        sum=max(sum,dfs(grid,i,j+1,cur+tmp));
        sum=max(sum,dfs(grid,i,j-1,cur+tmp));
        grid[i][j]=tmp;
        return sum;
    }
};
int main()
{
    vector<vector<int>> grid={
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    Solution s;
    cout<<s.getMaximumGold(grid);
    return 0;
}