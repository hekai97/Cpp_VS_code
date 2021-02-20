#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totaltime=-1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        queue<pair<int,int>> que;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    que.push(make_pair(i,j));
                }
            }
        }
        while(!que.empty())
        {
            int length=que.size();
            for(int i=0;i<length;++i)
            {
                auto temp=que.front();
                que.pop();
                for(int j=0;j<4;++j)
                {
                    if(temp.first+dx[j]>=0&&temp.first+dx[j]<n&&temp.second+dy[j]>=0&&temp.second+dy[j]<m&&grid[temp.first+dx[j]][temp.second+dy[j]]==1)
                    {
                        grid[temp.first+dx[j]][temp.second+dy[j]]=2;
                        que.push(make_pair(temp.first+dx[j],temp.second+dy[j]));
                    }
                }
            }
            totaltime++;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return totaltime>=0?totaltime:0;
    }
};
int main()
{
    vector<vector<int>> grid{
        {0}
    };
    Solution s;
    cout<<s.orangesRotting(grid);
    return 0;
}