#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int difference=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            difference=max(difference,nums[i+1]-nums[i]);
        }
        return difference;
    }
};
int main()
{
    vector<int> nums={1,100000};
    Solution s;
    cout<<s.maximumGap(nums);
    return 0;
}