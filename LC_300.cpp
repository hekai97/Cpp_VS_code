#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return n;
        vector<int> dp(n,1);
        int res=dp[0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
int main()
{
    vector<int> nums={10,9,2,5,3,7,101,18};
    Solution s;
    cout<<s.lengthOfLIS(nums);
    return 0;
}