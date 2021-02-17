#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(res,temp,nums,0);
        return res;
    }
private:
    void backtrace(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int start){
        res.push_back(temp);
        for(int i = start;i < nums.size();++i){
            temp.push_back(nums[i]);
            backtrace(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
};
int main()
{
    vector<int> nums={1,2,3};
    Solution s;
    vector<vector<int>> res=s.subsets(nums);
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