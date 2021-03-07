#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n=M.size(),m=M[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        vector<vector<int>> direction{
            {-1,-1},
            {-1,0},
            {-1,1},
            {0,-1},
            {0,1},
            {1,-1},
            {1,0},
            {1,1}
        };
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int tempres=M[i][j],count=1;
                for(int k=0;k<8;++k)
                {
                    if(i+direction[k][0]>=0&&i+direction[k][0]<n&&j+direction[k][1]>=0&&j+direction[k][1]<m)
                    {
                        count++;
                        tempres+=M[i+direction[k][0]][j+direction[k][1]];
                    }
                }
                res[i][j]=tempres/count;
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> M={
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    Solution s;
    vector<vector<int>> res=s.imageSmoother(M);
    for(auto i=0;i<res.size();++i)
    {
        for(auto j=0;j<res[i].size();++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}