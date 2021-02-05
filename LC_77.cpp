#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res,temp,n,k,1);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res,vector<int>& temp,int n,int k,int start)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }
        else
        {
            for(int i=start;i<=n;i++)
            {
                temp.push_back(i);
                dfs(res,temp,n,k,i+1);
                temp.pop_back();
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> res=s.combine(20,10);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}