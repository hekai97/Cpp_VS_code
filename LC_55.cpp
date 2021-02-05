#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()>1&&nums[0]==0)
        {
            return false;
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]!=0)
            {
                continue;
            }
            else
            {
                int j;
                for(j=i-1;j>=0;j--)
                {
                    if(nums[j]==0)
                    {
                        continue;
                    }
                    else if(nums[j]>i-j)
                    {
                        break;
                    }
                }
                if(j==-1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    vector<int> nums={2,0,0,0};
    Solution s;
    cout<<s.canJump(nums);
    return 0;
}