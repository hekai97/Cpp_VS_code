#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size(),m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        queue<pair<int,int>> que;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=2;
                    que.push(make_pair(i,j));
                    break;
                }
            }
        }
        while(!que.empty())
        {
            auto temp=que.front();
            que.pop();
            int x=temp.first;
            int y=temp.second;
            for(int i=0;i<4;++i)
            {
                if(x+dx[i]>=0&&x+dx[i]<grid.size()&&y+dy[i]>=0&&y+dy[i]<grid[0].size())
                {
                    if(grid[x+dx[i]][y+dy[i]]==1)
                    {
                        grid[x+dx[i]][y+dy[i]]=2;
                        que.push(make_pair(x+dx[i],y+dy[i]));
                    }
                    else if(grid[x+dx[i]][y+dy[i]]==0)
                    {
                        res++;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    res++;
                }
                
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> grid{
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    Solution s;
    cout<<s.islandPerimeter(grid);
    return 0;
}