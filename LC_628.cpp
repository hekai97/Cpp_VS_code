#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        return max(nums[n]*nums[n-1]*nums[n-2],nums[0]*nums[1]*nums[n]);
    }
};
int main()
{
    vector<int> nums={-100,-98,-1,1,2,3,4};
    Solution s;
    cout<<s.maximumProduct(nums);
    return 0;
}