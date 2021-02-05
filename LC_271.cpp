#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> nums={1,2,3,4};
    Solution s;
    cout<<s.containsDuplicate(nums);
    return 0;
}