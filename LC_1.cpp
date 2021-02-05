#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int>res;
        for(auto i=0;i<nums.size()-1;++i)
        {
            for(auto j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums={2,7,11,5};
    int target=9;
    vector<int> res=s.twoSum(nums,target);
    for(int a:res)
    {
        cout<<a<<" ";
    }
    return 0;
}