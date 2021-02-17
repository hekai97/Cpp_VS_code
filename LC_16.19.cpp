#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        for(int i=0;i<land.size();++i)
        {
            for(int j=0;j<land[0].size();++j)
            {
                if(land[i][j]==0)
                {
                    int count=0;
                    dfs(res,land,count,i,j);
                    res.push_back(count);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
private:
    void dfs(vector<int>& res,vector<vector<int>>& land,int& count,int i,int j)
    {
        if(i<0||i>=land.size()||j<0||j>=land[i].size()||land[i][j]!=0)
        {
            return;
        }
        land[i][j]=1;
        count++;
        dfs(res,land,count,i+1,j);
        dfs(res,land,count,i-1,j);
        dfs(res,land,count,i,j+1);
        dfs(res,land,count,i,j-1);
        dfs(res,land,count,i+1,j+1);
        dfs(res,land,count,i+1,j-1);
        dfs(res,land,count,i-1,j+1);
        dfs(res,land,count,i-1,j-1);
    }
};
int main()
{
    vector<vector<int>> land{
       {0,2,1,0},
       {0,1,0,1},
       {1,1,0,1},
       {0,1,0,1}
    };
    Solution s;
    vector<int> res=s.pondSizes(land);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}