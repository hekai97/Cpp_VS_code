//O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        //int maxnum=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                {
                    return i;
                }
            }
            else if(i==nums.size()-1)
            {
                if(nums[i]>nums[i-1])
                {
                    return i;
                }
            }
            else
            {
                if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                {
                    return i;
                }
            }
        }
        return 0;
    }
};
int main()
{
    vector<int> nums={1,2,1,3,5,6,4};
    Solution s;
    cout<<s.findPeakElement(nums);
    return 0;
}
//O(log(N))
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1])
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
int main()
{
    vector<int> nums={1,2,1,3,5,6,4};
    Solution s;
    cout<<s.findPeakElement(nums);
    return 0;
}