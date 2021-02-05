#include <iostream>
#include <vector>
using namespace std;
vector<int>s[10000];
int n,m;
int ans=0;
int vis[10000];
void dfs(int begin,int k,int num)
{
    if(num==2)
    {
        for(int i=0;i<s[k].size();i++)
        {
            if(!vis[s[k][i]]||s[k][i]==begin)
            {
                ans++;
            }
        }
        return;
    }for(int i=0;i<s[k].size();i++)
    {
        if(!vis[s[k][i]])
        {
            vis[s[k][i]]=1;
            dfs(begin,s[k][i],num+1);
            vis[s[k][i]]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        s[u].push_back(v);
        s[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(i,i,0);
        vis[i]=0;
    }
    cout<<ans<<endl;
    return 0;
}