#include <iostream>
#include <vector>
using namespace std;
const int MAX=1000;
vector<int> edge[MAX];
int dfn[MAX],low[MAX];
int n,m;
int time=0,ans;
int visited[MAX];
bool cut_point[MAX];
int MIN(int a,int b)
{
    return a<b?a:b;
}
void tarjan(int now,int father)
{
    visited[now] = 1;
    dfn[now] = low[now] = ++time;
    int children = 0;
    for(int i:edge[now])            
    {
        if(father == i && visited[i]==2)
        {
            continue;
        }
        if(visited[i]==1)
        {
            low[now]=MIN(low[now],dfn[i]);
        }
        if(visited[i]==0)
        {
            tarjan(i,now);
            children++;
            low[now]=MIN(low[now],low[i]);
            if((children > 1 && father == -1) || father != -1&&low[i]>=dfn[now])
            {
                if(cut_point[now]==false)
                {
                    ans++;
                }
                cut_point[now]=true;
            }
        }
    }
    visited[now]=2;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);   
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            tarjan(i,-1);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<=n;i++)
    {
        if(cut_point[i])
        {
            cout<<i<<" ";
        }
    }
    return 0;
}