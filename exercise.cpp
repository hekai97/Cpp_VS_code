#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        //vector<int> nums=candidates;
        sort(candidates.begin(),candidates.end());
        // int i;
        // for(i=0;i<candidates.size();++i)
        // {
        //     if(candidates[i]>target)break;
        // }
        // candidates.erase(candidates.begin()+i,candidates.end());
        backtracking(res,temp,candidates,target,0);
        //sort(res.begin(),res.end());
        //res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
private:
    void backtracking(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int target,int start){
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<nums.size();++i)
        {
            if(i>start&&nums[i]==nums[i-1])continue;
            if(nums[i]>target)continue;
            temp.push_back(nums[i]);
            backtracking(res,temp,nums,target-nums[i],i+1);
            temp.pop_back();
        }
    }
};
int main()
{
    vector<int> candidates={14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    int target=27;
    Solution s;
    vector<vector<int>> res=s.combinationSum2(candidates,target);
    for(int i=0;i<res.size();++i)
    {
        for(int j=0;j<res[i].size();++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}