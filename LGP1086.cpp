#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int Nums(vector<vector<int>>& grid,int k)
    {
        sort(grid.begin(),grid.end());
        reverse(grid.begin(),grid.end());
        int res=0;
        for(int i=0;i<grid.size();++i)
        {
            int t=grid[i][1];
            if(i==0)
            {
                k=k-t-1;
            }
            else
            {
                k=k-(abs(grid[i][1]-grid[i-1][1])+abs(grid[i][2]-grid[i-1][2]))-1;
            }
            if(k-1>t)
            {
                res+=grid[i][0];
            }
        }
        return res;
    }
};
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>> grid;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            int t;
            cin>>t;
            if(t>0)
            {
                vector<int> temp;
                temp.push_back(t);
                temp.push_back(i);
                temp.push_back(j);
                grid.push_back(temp);
            }
        }
    }
    Solution s;
    cout<<s.Nums(grid,k);
    return 0;
}