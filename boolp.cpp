#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
 
using namespace std;
 
int ans,n,m,e,u,v,link[1005],use[1005],map[1005][1005];/*map数组为邻接矩阵，use表示当前点是否匹配，link[i]表示与顶点i所连的点*/ 
 
inline int read( )
{
	int x = 0;char c = getchar( );
	while (!isdigit(c))
	{
		c = getchar( );
	}
	while(isdigit(c))
	{
		x = (x<<3) + (x<<1) + (c^48);
		c = getchar( );
	}
	return x;
}
 
inline bool dfs(int x)
{
	for(int i = 1; i <= m; i++)
	{
		if(!use[i]&& map[x][i])//若不在交替路中 
		{
			use[i] = 1;//则加入交替路 
			if(!link[i] || dfs(link[i]))
			{
				link[i] = x;
				return true;
			}
		}
	}
	return false;
}
 
void xyl( )
{
	memset(link, 0, sizeof(link));
	for(int i = 1; i <= n; i++)
	{
		memset(use, 0, sizeof(use));
		if(dfs(i)) ans++;
	}
}
 
int main( )
{
	n = read( );
	m = read( );
	e = read( );
	for(int i = 1; i <= e; i++)
	{
		u = read( );
		v = read( );
		map[u][v] = true;
//		map[v][u]=true;
	}
	xyl( );
	printf("%d\n",ans);
	return 0;
}
