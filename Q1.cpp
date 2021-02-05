#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 123456;
int n, m, dfn[maxn], low[maxn], vis[maxn], ans, tim;
bool cut[maxn];
vector<int> edge[maxn];
void tarjan(int cur, int pop)
{
	vis[cur] = 1;
	dfn[cur] = low[cur] = ++tim;
	int children = 0; ////子树 
	for (int i : edge[cur]) ////对于每一条边 
	{
		if (i == pop || vis[cur] == 2) 
			continue;
		if (vis[i] == 1) ////遇到回边 
			low[cur] = min(low[cur], dfn[i]); ////回边处的更新 (有环)
		if (vis[i] == 0)
		{
			tarjan(i, cur);
			children++;  ////记录子树数目 
			low[cur] = min(low[cur], low[i]); ////父子节点处的回溯更新
			if ((pop == -1 && children > 1) || (pop != -1 && low[i] >= dfn[cur])) ////判断割点 
			{
				if (!cut[cur])
					ans++;		 ////记录割点个数
				cut[cur] = true; ///处理割点
			}
			// if(low[i]>dfn[cur]) ////判断割边 
			// {
			// 	bridge[cur][i]=bridge[i][cur]=true;  ////low[i]>dfn[cur]即说明(i,cur)是桥(割边)； 
			// } 
		}	
	}
	vis[cur] = 2; ////标记已访问 
}
int main()
{
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
			tarjan(i, -1); ////防止原来的图并不是一个连通块 
			////对于每个连通块调用一次cut_bri 
	}
    cout<<ans<<endl;
	for (int i = 1; i <= n; i++) ////输出割点 
		if (cut[i])
			cout<<i<<" ";
	return 0;
}