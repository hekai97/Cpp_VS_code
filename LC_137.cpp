#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(count==0&&nums[i]!=nums[i+1])
            {
                return nums[i];
            }
            else if(nums[i]==nums[i+1])
            {
                count++;
            }
            else
            {
                count=0;
            }
            
        }
        return nums[n-1];
    }
};
int main()
{
    vector<int> nums={30000,500,100,30000,100,30000,100};
    Solution s;
    cout<<s.singleNumber(nums);
    return 0;
}