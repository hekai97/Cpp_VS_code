#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int Find(int x,vector<int>& grid);
    void Union(int x,int y,vector<int>& grid,vector<int>& rank);
};
int Solution::Find(int x,vector<int>& grid)
{
    int x_root=x;
    while(grid[x_root]!=-1)
    {
        x_root=grid[x_root];
    }
    return x_root;
}
void Solution::Union(int x,int y,vector<int>& grid,vector<int>& rank)
{
    int x_root=Find(x,grid);
    int y_root=Find(y,grid);
    if(x_root==y_root)
    {
        return;
    }
    else
    {
        if(rank[x_root]>rank[y_root])
        {
            grid[y_root]=x_root;
        }
        else if(rank[x_root]<rank[y_root])
        {
            grid[x_root]=y_root;
        }
        else
        {
            grid[x_root]=y_root;
            rank[y_root]++;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> grid(n+1,-1);
    vector<int> rank(n+1,0);
    Solution s;
    for(int i=0;i<m;++i)
    {
        int x,y,z;
        cin>>z>>x>>y;
        switch (z)
        {
        case 1:
            s.Union(x,y,grid,rank);
            break;
        case 2:
            if(s.Find(x,grid)==s.Find(y,grid))
            {
                cout<<"Y"<<endl;
            }
            else
            {
                cout<<"N"<<endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}