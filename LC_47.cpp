#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        perm(res,nums, 0, nums.size() - 1);
        return res;
    }
private:  
    void perm(vector<vector<int>>& res,vector<int> nums, int left, int right) {
        if (left == right)
            res.push_back(nums);
        else {
            for (int i = left; i <= right; i++) {
                if (i != left && nums[left] == nums[i]) continue;
                swap(nums[left], nums[i]);
                perm(res,nums, left + 1, right);
            }
        }
    }
};
int main()
{
    vector<int> nums={1,1,2};
    Solution s;
    vector<vector<int>> res=s.permuteUnique(nums);
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