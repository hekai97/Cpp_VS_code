#include <iostream>
#include <cstdio>
using namespace std;
int cell[100][100];
bool visited[101][101]={0};
int res=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x,int y)
{
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(cell[nextx][nexty]==0||visited[nextx][nexty]==1)
        {
            continue;
        }
        dfs(nextx,nexty);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&cell[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(cell[i][j]!=0&&visited[i][j]==0)
            {
                dfs(i,j);
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}