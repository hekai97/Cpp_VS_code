#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(res,temp,nums,0);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
private:
    void backtracking(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int start)
    {
        if(temp.size()>=2)
        {
            res.push_back(temp);
        }
        for(int i=start;i<nums.size();++i)
        {
            if(!temp.empty()&&temp.back()>nums[i])
            {
                continue;
            }
            temp.push_back(nums[i]);
            backtracking(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
};
int main()
{
    vector<int> nums={4,6,7,7};
    Solution s;
    vector<vector<int>> res=s.findSubsequences(nums);
    for(auto a:res)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}