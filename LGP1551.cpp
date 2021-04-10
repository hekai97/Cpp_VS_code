#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int find(int x,vector<int>& grid)
    {
        if(grid[x]==x)
        {
            return x;
        }
        else
        {
            return grid[x]=find(grid[x],grid);
        }
    }
    void Union(int x,int y,vector<int>& grid)
    {
        grid[find(y,grid)]=find(x,grid);
    }
};
int main()
{
    int n,m,p;
    Solution s;
    cin>>n>>m>>p;
    vector<int> grid(n+1);
    for(int i=1;i<=n;++i)
    {
        grid[i]=i;
    }
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        s.Union(x,y,grid);
    }
    for(int i=0;i<p;++i)
    {
        int x,y;
        cin>>x>>y;
        if(s.find(x,grid)==s.find(y,grid))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}