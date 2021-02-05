#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(candidates,res,temp,target,0);
        return res;
    }
private:
    void dfs(vector<int>& candidates,vector<vector<int>>& res,vector<int>& temp,int target,int start)
    {
        if(target<0)return;
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            dfs(candidates,res,temp,target-candidates[i],i);
            temp.pop_back();
        }
    }
};
int main()
{
    vector<int> candidates={2,3,5};
    Solution s;
    vector<vector<int>> res=s.combinationSum(candidates,8);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}