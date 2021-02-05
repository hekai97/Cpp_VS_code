#include <iostream>
#include <vector>
using namespace std;
const int MAX=1000;
vector<int> edge[MAX];  //定义两点之间的边
int bridge[MAX][MAX];   //定义一个数组存放割边
int dfn[MAX],low[MAX];  //dfn数组用来保存访问到某一结点的时间戳，low数组用来保存该节点能后回溯道德最早的时间戳dfn
int n,m;                //n指的是该图中的节点个数，m指的是该图中的边的个数
int time=0,ans;         //time用来更新时间戳，ans保存共有多少个割点
int visited[MAX];       //该数组用于保存访问的节点状态，未访问过则为0，访问中则为1，访问过则为2
bool cut_point[MAX];    //该数组用来一一对应节点，若该节点为割点，则让该数组中对应的位置的元素变为true
int MIN(int a,int b)    //返回两个元素之间的最小值函数
{
    return a<b?a:b;
}
void tarjan(int now,int father)     //tarjan算法主体
{
    visited[now] = 1;               //每次访问一个节点，将该节点标记为正在访问：1
    dfn[now] = low[now] = ++time;   //time开始增加，并且让该节点的dfn和low都设置为time
    int children = 0;               //创建子树，开始记录一个节点子树的数目
    for(int i:edge[now])            
    {
        if(father == i && visited[i]==2)    //如果该点的下一个节点是自己的父节点，则无法回溯，或者节点已经访问过，则无需二次访问
        {
            continue;
        }
        if(visited[i]==1)                   //如果在递归过程中，该点的子节点访问到该条链中的节点，
        {
            low[now]=MIN(low[now],dfn[i]);  //则证明可以回溯，此时更新一下这个节点的时间戳
        }
        if(visited[i]==0)                   //如果子节点还未访问，则对子节点继续跑一下tarjan算法
        {
            tarjan(i,now);
            children++;                     //并且可得该子节点是上个节点的一个子树
            low[now]=MIN(low[now],low[i]);  //继续更新时间戳
            if((children > 1 && father == -1) || father != -1&&low[i]>=dfn[now])
            //如果该节点为根节点，并且有两个子树，那它一定是个割点
            //如果该点是一个普通节点，并且该点的low值大于等于父节点的dfn值，那它也是一个割点
            {
                if(cut_point[now]==false)   //全局数组声明出来的布尔数组全为false，如果该点是割点，
                {
                    ans++;
                }
                cut_point[now]=true;        //如果该点是割点，让cut_point数组中对应位置变成true
            }
            // if(low[i]>dfn[now]) ////判断割边 
			// {
			// 	bridge[now][i]=bridge[i][now]=true;  ////low[i]>dfn[cur]即说明(i,cur)是桥(割边)； 
			// } 
        }
    }
    visited[now]=2;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;    //该处的x，y指的是该线段两端的节点
        cin>>x>>y;
        edge[x].push_back(y);   
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            tarjan(i,-1);//该处的-1指的是根节点的父节点，在此定义成-1
        }
    }
    cout<<ans<<endl;           //输出割点的总数
    for(int i=0;i<=n;i++)      //循环输出割点
    {
        if(cut_point[i])
        {
            cout<<i<<" ";
        }
    }
    return 0;
}