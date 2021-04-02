#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i]-i;
        }
        sum-=nums.size();
        return abs(sum);
    }
};
int main()
{
    vector<int> nums={9,6,4,2,3,5,7,0,1};
    Solution s;
    cout<<s.missingNumber(nums);
    return 0;
}