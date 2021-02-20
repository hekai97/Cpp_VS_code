#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0][0]==1)
        {
            return -1;
        }
        int pathnum=1;
        vector<vector<int>> direction{
            {-1,-1},
            {-1,0},
            {-1,1},
            {0,-1},
            {0,1},
            {1,-1},
            {1,0},
            {1,1}
        };
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        while(!que.empty())
        {
            int length=que.size();
            for(int i=0;i<length;++i)
            {
                auto temp=que.front();
                que.pop();
                int x=temp.first;
                int y=temp.second;
                if(x==grid.size()-1&&y==grid[0].size()-1)
                {
                    return pathnum;
                }

                for(int j=0;j<8;j++)
                {
                    if(x+direction[j][0]>=0&&x+direction[j][0]<grid.size()&&y+direction[j][1]>=0&&y+direction[j][1]<grid[0].size()&&grid[x+direction[j][0]][y+direction[j][1]]==0)
                    {
                        que.push(make_pair(x+direction[j][0],y+direction[j][1]));
                        grid[x+direction[j][0]][y+direction[j][1]]=1;
                    }
                }
            }
            pathnum++;
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> grid{
        {0,0,0},
        {1,1,0},
        {1,1,0}
    };
    Solution s;
    cout<<s.shortestPathBinaryMatrix(grid);
    return 0;
}