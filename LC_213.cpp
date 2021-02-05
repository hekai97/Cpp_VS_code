#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        else
        {
            vector<int> dp1(n),dp2(n);
            dp1[0]=nums[0];
            dp1[1]=max(nums[0],nums[1]);
            dp2[0]=nums[1];
            dp2[1]=max(nums[1],nums[2]);
            for(int i=2;i<n-1;i++)
            {
                dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
                dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i+1]);
            }
            return max(dp1[n-2],dp2[n-2]);
        }
    }
};
int main()
{
    vector<int> nums={1,2,3,1};
    Solution s;
    cout<<s.rob(nums);
    return 0;
}