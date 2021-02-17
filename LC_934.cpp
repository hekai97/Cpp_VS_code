/*该代码超时
需要进行优化
题目思想是利用DFS先找到一个岛屿，然后BFS这座岛屿
向外扩张，当碰到另一座岛屿时返回结果
代码执行正确，就是超时较为严重*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int i,j;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int res=0;
        for(i=0;i<A.size();++i)
        {
            for(j=0;j<A[0].size();++j)
            {
                if(A[i][j]==1)
                {
                    break;
                }
            }
            if(j<A[0].size()&&A[i][j]==1)
            {
                break;
            }
        }
        dfs(A,i,j);
        queue<pair<int,int>> que;
        for(int i2=0;i2<A.size();++i2)
        {
            for(int j2=0;j2<A[0].size();++j2)
            {
                if(A[i2][j2]==2&&((i2+1<A.size()&&A[i2+1][j2]==0)||(i2-1>=0&&A[i2-1][j2]==0)||(j2+1<A[0].size()&&A[i2][j2+1]==0)||(j2-1>=0&&A[i2][j2-1]==0)))
                {
                    que.push(make_pair(i2,j2));
                }
            }
        }
        while(!que.empty())
        {
            int length=que.size();
            for(int y=0;y<length;++y)
            {
                auto temp=que.front();
                que.pop();
                for(int x=0;x<4;++x)
                {
                    if(temp.first+dx[x]>=0&&temp.first+dx[x]<A.size()&&temp.second+dy[x]>=0&&temp.second+dy[x]<A[0].size())
                    {
                        if(A[temp.first+dx[x]][temp.second+dy[x]]==0)
                        {
                            que.push(make_pair(temp.first+dx[x],temp.second+dy[x]));
                        }
                        else if(A[temp.first+dx[x]][temp.second+dy[x]]==1)
                        {
                            return res;
                        }
                    }
                }
            }
            res++;
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& A,int i,int j)
    {
        if(i<0||i>=A.size()||j<0||j>=A[i].size()||A[i][j]==0||A[i][j]==2)
        {
            return;
        }
        A[i][j]=2;
        dfs(A,i+1,j);
        dfs(A,i-1,j);
        dfs(A,i,j+1);
        dfs(A,i,j-1);
    }
};
int main()
{
    vector<vector<int>> A={
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,1,0,0},
        {0,0,0,1,1,0,1,0},
        {0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };
    Solution s;
    cout<<s.shortestBridge(A);
    return 0;
}