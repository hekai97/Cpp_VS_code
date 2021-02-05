#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        per(res,nums,0,nums.size());
        return res;
    }
    void per(vector<vector<int>>& res,vector<int>& nums,int first,int end)
    {
        if(first==end)
        {
            res.emplace_back(nums);
            return;
        }
        for(int i=first;i<end;i++)
        {
            swap(nums[i],nums[first]);
            per(res,nums,first+1,end);
            swap(nums[i],nums[first]);
        }
    }
};
int main()
{
    vector<int> a={1,2,3};
    Solution s;
    vector<vector<int>> res=s.permute(a);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}